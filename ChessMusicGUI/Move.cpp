#include "Move.h"
#include <QObject>
#include <QString>

namespace Models {

	Move::Move(
		QString turn,
		QString score
	) : m_turn(turn),
		m_score(score)
	{

	}

	QString Move::turn() const {
		return m_turn;
	}

	QString Move::score() const {
		return m_score;
	}

	std::ostream& operator<<(std::ostream& out, const Move& move) {
		out << "Move " << move.m_turn << ": " << ", Score: " << move.m_score << std::endl;
		return out;
	}
	//Move::Move(const Move & move) {
	//	m_turn = move.turn;
	//	m_score = move.score;
	//}

	//Move &Move::operator=(const Move &other) {
	//	if (this != &other) {
	//		m_turn = other.turn;
	//		m_score = other.score;
	//	}
	//	return *this;
	//}
}

