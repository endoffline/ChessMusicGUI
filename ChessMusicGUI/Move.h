#pragma once

#include <QStandardItemModel>
#include <QObject>
#include <QString>
#include <iostream>
namespace Models {
	
	class Move {

	public:
		Move(QString turn = "0", QString score = "0");
		//Move(const Move &move);
		//Move &operator=(const Move &other);
		QString turn() const;
		QString score() const;
		friend std::ostream& operator<<(std::ostream& out, const Move& move);

	private:
		QString m_turn;
		QString m_score;
	};
}