#pragma once

#include <QObject>
#include "Move.h"
namespace Models {

	class Game : QObject {
		Q_OBJECT
		Q_DISABLE_COPY(Game)

		Q_PROPERTY(Move* moves READ moves)
	public:
		explicit Game(QObject* parent = nullptr);

		Move* moves();
		void setData(QString path);
	private:
		Move* m_moves;
	};
}