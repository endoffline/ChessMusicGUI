#include "FMODSoundscapeController.h"
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include "./common/common.h"
#include "Move.h"
#include <qDebug>
//#include <thread>
#include <chrono>
#include <QThread>
#include <QtConcurrent\qtconcurrentrun.h>
const char *FMODSoundscapeController::FLUCTUATING_SCORE_STR= "fluctuating_score";
const char *FMODSoundscapeController::UNOPPOSED_THREATS_STR = "unopposed_threats";
const char *FMODSoundscapeController::IS_CAPTURE_STR = "is_capture";
const char *FMODSoundscapeController::MISTAKE_STR = "mistake";
const char *FMODSoundscapeController::POSSIBLE_MOVES_STR = "possible_moves";
const char *FMODSoundscapeController::INTENSITY_STR = "Intensity";
const char *FMODSoundscapeController::LEADING_STR = "Leading";

const char *FMODSoundscapeController::IS_CHECK_STR = "Is Check";
const char *FMODSoundscapeController::MOVE_CATEGORY_STR = "Move Category";
const char *FMODSoundscapeController::ATTACKERS_COUNT_STR = "Attackers Count";
const int FMODSoundscapeController::LOW_INTENSITY = 100;
const int FMODSoundscapeController::MEDIUM_INTENSITY = 300;
const int FMODSoundscapeController::HIGH_INTENSITY = 1000;


FMODSoundscapeController::FMODSoundscapeController() {
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
	ERRCHECK(m_system->getEvent("event:/Soundscape", &m_eventDescription));

	m_eventInstance = NULL;
	ERRCHECK(m_eventDescription->createInstance(&m_eventInstance));

	Common_Mutex_Create(&m_info.mMutex);

	ERRCHECK(m_eventInstance->setUserData(&m_info));
	//ERRCHECK(m_eventInstance->setCallback(markerCallback,
	//	FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_MARKER | FMOD_STUDIO_EVENT_CALLBACK_TIMELINE_BEAT |
	//	FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED | FMOD_STUDIO_EVENT_CALLBACK_SOUND_STOPPED));
	ERRCHECK(m_eventInstance->start());

	m_waveDirection = true;
	m_fluctuatingScore = false;
	//Set initial FMOD Parameters
	m_fmod_fluctuating_score = -1.0f;
	ERRCHECK(m_eventInstance->setParameterValue(FLUCTUATING_SCORE_STR, m_fmod_fluctuating_score));

	m_fmod_unopposedThreats = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(UNOPPOSED_THREATS_STR, m_fmod_unopposedThreats));
	m_fmod_isCapture = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(IS_CAPTURE_STR, m_fmod_isCapture));
	m_fmod_mistake = 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(MISTAKE_STR, m_fmod_mistake));
	m_fmod_possibleMoves = 100.0f;
	ERRCHECK(m_eventInstance->setParameterValue(POSSIBLE_MOVES_STR, m_fmod_possibleMoves));

	m_fmod_intensity = 0.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(INTENSITY_STR, m_fmod_intensity));
	m_fmod_leadingPlayer = 0.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(LEADING_STR, m_fmod_leadingPlayer));
	
	m_fmod_isCheck = 0.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(IS_CHECK_STR, m_fmod_isCheck));
	m_fmod_moveCategory = 1.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(MOVE_CATEGORY_STR, m_fmod_moveCategory));
	m_fmod_attackersCount = 0.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(ATTACKERS_COUNT_STR, m_fmod_attackersCount));

	ERRCHECK(m_system->update());

	//std::thread loopThread([&]() {this->fmodLoop(); });
	m_aborted = false;
	QFuture<void> sinus_thread = QtConcurrent::run(this, &FMODSoundscapeController::fmodLoop, QString("A"));

}

void FMODSoundscapeController::abortSinusWave() {
	qDebug() << "close 2";
	m_aborted = true;
}

// stop when signal is received
void FMODSoundscapeController::fmodLoop(QString name) {
	while (true) {
		if (m_aborted) return;
		if (m_fluctuatingScore) {
			if (m_fmod_fluctuating_score >= 1.0f) {
				m_waveDirection = false;
			}
			else if (m_fmod_fluctuating_score <= 0) {
				m_waveDirection = true;
			}

			if (m_waveDirection) {
				m_fmod_fluctuating_score += 0.01f;
			}
			else {
				m_fmod_fluctuating_score -= 0.01f;
			}
		}
		else {
			m_fmod_fluctuating_score = -1.0f;
		}
		ERRCHECK(m_eventInstance->setParameterValue(FLUCTUATING_SCORE_STR, m_fmod_fluctuating_score));

		ERRCHECK(m_system->update());
		QThread::msleep(50);
		qDebug() << "score_shift_category: " + QString::number(m_fmod_fluctuating_score);
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void FMODSoundscapeController::updateFMODValues(Models::Move move) {
	qDebug() << "3";
	int turn = move.turn();
	int score = move.score();
	float score_shift_category = move.score_shift_category();
	int unopposedThreatsCountWhite = move.unopposed_threats_count_white();
	int unopposedThreatsCountBlack = move.unopposed_threats_count_black();
	int is_capture = move.is_capture();
	int isCheck = 0;
	int moveCategory = 1;
	int attackersCount = 0;

	m_fluctuatingScore = score_shift_category > 1.0f;

	m_fmod_unopposedThreats = (float)(turn) ? (float)unopposedThreatsCountBlack : (float)unopposedThreatsCountWhite;
	ERRCHECK(m_eventInstance->setParameterValue(UNOPPOSED_THREATS_STR, m_fmod_unopposedThreats));

	m_fmod_isCapture = (float)move.is_capture();
	ERRCHECK(m_eventInstance->setParameterValue(IS_CAPTURE_STR, m_fmod_isCapture));
	ERRCHECK(m_eventInstance->setParameterValue(IS_CAPTURE_STR, 0.0f));

	moveCategory = move.best_move_score_difference_category();
	m_fmod_mistake = (moveCategory >= 3) ? 1.0f : 0.0f;
	ERRCHECK(m_eventInstance->setParameterValue(MISTAKE_STR, m_fmod_mistake));
	ERRCHECK(m_eventInstance->setParameterValue(MISTAKE_STR, 0.0f));

	m_fmod_possibleMoves = (float)move.possible_moves_count();
	ERRCHECK(m_eventInstance->setParameterValue(POSSIBLE_MOVES_STR, m_fmod_possibleMoves));





	m_fmod_leadingPlayer = (score < 0 ? 1.0f : 0.0f);
	//ERRCHECK(m_eventInstance->setParameterValue(LEADING_STR, m_fmod_leadingPlayer));

	int absScore = abs(score);
	m_fmod_intensity = (float)absScore / (float)HIGH_INTENSITY;
	if (m_fmod_intensity > 1.0f)
	{
		m_fmod_intensity = 1.0f;
	}
	//ERRCHECK(m_eventInstance->setParameterValue(INTENSITY_STR, m_fmod_intensity));



	isCheck = move.is_check() == true;
	if (isCheck)
	{
		m_fmod_isCheck = m_fmod_intensity;
	}
	else
	{
		m_fmod_isCheck = 0.0f;
	}
	//ERRCHECK(m_eventInstance->setParameterValue(IS_CHECK_STR, m_fmod_isCheck));

	moveCategory = move.best_move_score_difference_category();
	m_fmod_moveCategory = (float)moveCategory / 10.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(MOVE_CATEGORY_STR, m_fmod_moveCategory));

	attackersCount = move.attackers_count_white();
	m_fmod_attackersCount = (float)attackersCount / 100.0f;
	//ERRCHECK(m_eventInstance->setParameterValue(ATTACKERS_COUNT_STR, m_fmod_attackersCount));

	ERRCHECK(m_system->update());

	int position;
	ERRCHECK(m_eventInstance->getTimelinePosition(&position));


	Common_Draw("Timeline = %d", position);
	Common_Draw("");
	// Obtain lock and look at our strings
	Common_Mutex_Enter(&m_info.mMutex);
	for (size_t i = 0; i<m_info.mEntries.size(); ++i)
	{
		Common_Draw("  %s\n", m_info.mEntries[i].c_str());
	}
	Common_Draw("Turn: %d", turn);
	Common_Draw("Score: %d\n", score);
	Common_Draw("Is Check: %d\n", isCheck);
	Common_Draw("Move Category: %d\n", moveCategory);
	Common_Draw("Attackers Count: %d\n", attackersCount);
	Common_Draw("FMOD Intensity: %f\n", m_fmod_intensity);
	Common_Draw("FMOD Leading: %f\n", m_fmod_leadingPlayer);
	Common_Draw("FMOD Possible Moves: %f\n", m_fmod_possibleMoves);
	Common_Draw("FMOD Is Check: %f\n", m_fmod_isCheck);
	Common_Draw("FMOD Mistakes: %f\n", m_fmod_moveCategory);
	Common_Draw("FMOD Attackers Count: %f\n", m_fmod_attackersCount);
	Common_Mutex_Leave(&m_info.mMutex);
	Common_Draw("");
	Common_Draw("Press %s to toggle progression (currently %g)", Common_BtnStr(BTN_MORE), m_fmod_intensity);
	Common_Draw("Press %s to quit", Common_BtnStr(BTN_QUIT));
}

// Obtain a lock and add a string entry to our list
void FMODSoundscapeController::markerAddString(CallbackInfo* info, const char* format, ...)
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
FMOD_RESULT F_CALLBACK FMODSoundscapeController::markerCallback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void *parameters)
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
		markerAddString(callbackInfo, "beat %d, bar %d (tempo %.1f %d:%d)", props->beat, props->bar, props->tempo, props->timesignatureupper, props->timesignaturelower);
	}
	if (type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED || type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_STOPPED)
	{
		FMOD::Sound* sound = (FMOD::Sound*)parameters;
		char name[256];
		ERRCHECK(sound->getName(name, 256));
		unsigned int len;
		ERRCHECK(sound->getLength(&len, FMOD_TIMEUNIT_MS));

		markerAddString(callbackInfo, "Sound '%s' (length %.3f) %s",
			name, (float)len / 1000.0f,
			type == FMOD_STUDIO_EVENT_CALLBACK_SOUND_PLAYED ? "Started" : "Stopped");
	}

	return FMOD_OK;
}