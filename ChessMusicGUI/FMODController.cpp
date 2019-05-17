#include "FMODController.h"
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include "./common/common.h"


const char *FMODController::INTENSITY_STR = "Intensity";
const char *FMODController::LEADING_STR = "Leading";
const char *FMODController::POSSIBLE_MOVES_STR = "Possible Moves";
const char *FMODController::IS_CHECK_STR = "Is Check";
const char *FMODController::MOVE_CATEGORY_STR = "Move Category";
const char *FMODController::ATTACKERS_COUNT_STR = "Attackers Count";
const int FMODController::LOW_INTENSITY = 100;
const int FMODController::MEDIUM_INTENSITY = 300;
const int FMODController::HIGH_INTENSITY = 1000;


FMODController::FMODController() {
	Common_Init(&m_extra_driver_data);
	m_system = NULL;
	ERRCHECK(FMOD::Studio::System::create(&m_system));

	// The example Studio project is authored for 5.1 sound, so set up the system output mode to match
	m_low_level_system = NULL;
	ERRCHECK(m_system->getLowLevelSystem(&m_low_level_system));
	ERRCHECK(m_low_level_system->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0));

	ERRCHECK(m_system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, m_extra_driver_data));

	m_masterBank = NULL;
	ERRCHECK(m_system->loadBankFile(Common_MediaPath("Master Bank.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &m_masterBank));

	m_stringsBank = NULL;
	ERRCHECK(m_system->loadBankFile(Common_MediaPath("Master Bank.strings.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &m_stringsBank));

	m_musicBank = NULL;
	m_result = m_system->loadBankFile(Common_MediaPath("Chess.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &m_musicBank);
	if (m_result != FMOD_OK)
	{
		// Music bank is not exported by default, you will have to export from the tool first
		Common_Fatal("Please export Chess.bank from the Studio tool to run this example");
	}

	m_eventDescription = NULL;
	ERRCHECK(m_system->getEvent("event:/Chess", &m_eventDescription));
	
	m_eventInstance = NULL;
	ERRCHECK(m_eventDescription->createInstance(&m_eventInstance));

	Common_Mutex_Create(&m_info.mMutex);

	ERRCHECK(m_eventInstance->setUserData(&m_info));
	//ERRCHECK(m_eventInstance->setCallback(markerCallback,
	//	FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_MARKER | FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_BEAT |
	//	FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED | FMOD_STUDIO_EVENT_CALLBACK_SOUND_STOPPED));
	ERRCHECK(m_eventInstance->start());

	//Set initial FMOD Parameters
	float fmod_intensity = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(INTENSITY_STR, fmod_intensity));
	float fmod_leadingPlayer = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(LEADING_STR, fmod_leadingPlayer));
	float fmod_possibleMoves = 100.0f;
	ERRCHECK(m_eventInstance->setParameterValue(POSSIBLE_MOVES_STR, fmod_possibleMoves));
	float fmod_isCheck = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(IS_CHECK_STR, fmod_isCheck));
	float fmod_moveCategory = 1.0f;
	ERRCHECK(m_eventInstance->setParameterValue(MOVE_CATEGORY_STR, fmod_moveCategory));
	float fmod_attackersCount = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(ATTACKERS_COUNT_STR, fmod_attackersCount));
}

// Obtain a lock and add a string entry to our list
void markerAddString(CallbackInfo* info, const char* format, ...)
{
	char buf[256];
	va_list args;
	va_start(args, format);
	Common_vsnprintf(buf, 256, format, args);
	va_end(args);
	buf[255] = '\0';
	Common_Mutex_Enter(&info->mMutex);
	if (info->mEntries.size() >= 6)
	{
		info->mEntries.erase(info->mEntries.begin());
	}
	info->mEntries.push_back(std::string(buf));
	Common_Mutex_Leave(&info->mMutex);
}

// Callback from Studio - Remember these callbacks will occur in the Studio update thread, NOT the game thread.
FMOD_RESULT F_CALLBACK FMODController::markerCallback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void *parameters)
{
	CallbackInfo* callbackInfo;
	ERRCHECK(((FMOD::Studio::EventInstance*)event)->getUserData((void**)&callbackInfo));

	if (type == FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_MARKER)
	{
		FMOD_STUDIO_TIMELINE_MARKER_PROPERTIES* props = (FMOD_STUDIO_TIMELINE_MARKER_PROPERTIES*)parameters;
		markerAddString(callbackInfo, "Named marker '%s'", props->name);
	}
	else if (type == FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_BEAT)
	{
		FMOD_STUDIO_TIMELINE_BEAT_PROPERTIES* props = (FMOD_STUDIO_TIMELINE_BEAT_PROPERTIES*)parameters;
		//markerAddString(callbackInfo, "beat %d, bar %d (tempo %.1f %d:%d)", props->beat, props->bar, props->tempo, props->timesignatureupper, props->timesignaturelower);
	}
	/*if (type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED || type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_STOPPED)
	{
	FMOD::Sound* sound = (FMOD::Sound*)parameters;
	char name[256];
	ERRCHECK(sound->getName(name, 256));
	unsigned int len;
	ERRCHECK(sound->getLength(&len, FMOD_TIMEUNIT_MS));

	markerAddString(callbackInfo, "Sound '%s' (length %.3f) %s",
	name, (float)len / 1000.0f,
	type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED ? "Started" : "Stopped");
	}*/

	return FMOD_OK;
}