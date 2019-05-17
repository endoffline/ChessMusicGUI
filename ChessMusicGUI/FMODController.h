#pragma once

#include <fmod_studio.hpp>
#include <fmod.hpp>
#include "./common/common.h"
#include <string>
#include <vector>

struct CallbackInfo
{
	Common_Mutex mMutex;
	std::vector<std::string> mEntries;
};

class FMODController {
public:

	FMODController();
	FMOD_RESULT F_CALLBACK markerCallback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void *parameters);
private:
	static const int MAX_ENTRIES = 6;
	static const char *INTENSITY_STR;
	static const char *LEADING_STR;
	static const char *POSSIBLE_MOVES_STR;
	static const char *IS_CHECK_STR;
	static const char *MOVE_CATEGORY_STR;
	static const char *ATTACKERS_COUNT_STR;
	static const int LOW_INTENSITY;
	static const int MEDIUM_INTENSITY;
	static const int HIGH_INTENSITY;

	void *m_extra_driver_data;
	FMOD::Studio::System *m_system;
	FMOD::System *m_low_level_system;
	FMOD::Studio::Bank *m_masterBank;
	FMOD::Studio::Bank *m_stringsBank;
	FMOD::Studio::Bank *m_musicBank;
	FMOD_RESULT m_result;
	FMOD::Studio::EventDescription *m_eventDescription;
	FMOD::Studio::EventInstance *m_eventInstance;
	CallbackInfo m_info;
};