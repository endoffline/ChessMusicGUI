#include "Move.h"
#include <QObject>
#include <QString>

namespace Models {

	Move::Move(
		QString turn,
		QString score,
		QObject* parent
	) : QObject(parent),
		m_turn(turn),
		m_score(score)
	{

	}

	QString Move::turn() const {
		return m_turn;
	}

	QString Move::score() const {
		return m_score;
	}
}

