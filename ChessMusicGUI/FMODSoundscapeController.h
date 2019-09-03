#pragma once

#include <fmod_studio.hpp>
#include <fmod.hpp>
#include "./common/common.h"
#include <string>
#include <vector>
#include "Move.h"

struct CallbackInfo
{
	Common_Mutex mMutex;
	std::vector<std::string> mEntries;
};

class FMODSoundscapeController : public QObject {
	Q_OBJECT
public:

	FMODSoundscapeController();

	void markerAddString(CallbackInfo* info, const char* format, ...);
	FMOD_RESULT F_CALLBACK markerCallback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void *parameters);

	public Q_SLOTS:
	void updateFMODValues(Models::Move move);
	void abortSinusWave();
private:
	void fmodLoop(QString name);

	static const int MAX_ENTRIES = 6;
	static const char *FLUCTUATING_SCORE_STR;
	static const char *UNOPPOSED_THREATS_STR;
	static const char *IS_CAPTURE_STR;
	static const char *BLUNDER_STR;
	static const char *MISTAKE_STR;
	static const char *INACCURACY_STR;
	static const char *POSSIBLE_MOVES_STR;
	static const char *CHIME_STR;
	static const char *ATTACK_DEFENSE_RELATION_STR;

	static const char *INTENSITY_STR;
	static const char *LEADING_STR;
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

	bool m_waveDirection;
	bool m_fluctuatingScore;
	bool m_aborted;
	float m_score;
	float m_fmod_fluctuating_score;
	float m_fmod_unopposedThreats;
	float m_fmod_isCapture;
	float m_fmod_blunder;
	float m_fmod_mistake;
	float m_fmod_inaccuracy;
	float m_fmod_possibleMoves;
	float m_fmod_chime;
	float m_fmod_attack_defense_relation;

	float m_fmod_intensity;
	float m_fmod_leadingPlayer;
	
	float m_fmod_isCheck;
	float m_fmod_moveCategory;
	float m_fmod_attackersCount;
};