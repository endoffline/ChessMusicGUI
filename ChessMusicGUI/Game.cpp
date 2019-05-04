#include "Game.h"
#include "Move.h"
#include <qDebug>
namespace Models {

	Game::Game(QObject* parent) : QObject(parent) {

	}

	Move* Game::moves() {
		return m_moves;
	}

	void Game::setData(QString path) {
		qDebug() << "hello";
	}
}