#include "Game.h"
#include "Move.h"
#include <qDebug>

namespace Models {
	
	Game::Game(QString path, QList<Move> moves, int current_move, QObject* parent) : m_path(path), m_moves(moves), m_current_move(current_move), QObject(parent) {
		
	}

	Game::Game(const Game& game) {
		m_path = game.m_path;
		m_moves = game.m_moves;
		m_current_move = game.m_current_move;
	}

	Game &Game::operator=(const Game &other) {
		if (this != &other) {
			m_path = other.m_path;
			m_moves = other.m_moves;
			m_current_move = other.m_current_move;
		}
		return *this;
	}

	Move Game::current_move() const {
		return (m_moves.at(m_current_move));
	}

	void Game::setData(QString path) {
		qDebug() << "hello";
	}

	void Game::addMove(Move move) {
		m_moves.append(move);
	}

	Move Game::nextMove() {
		
		if (m_current_move < m_moves.size() -1) {
			m_current_move++;
		}
		return m_moves.at(m_current_move);
	}

	Move Game::previousMove() {
		if (m_current_move > c_min_index + 1) {
			m_current_move--;
		}
		return m_moves.at(m_current_move);
	}

	std::ostream& operator<<(std::ostream& out, const Game& game) {
		Move move;
		foreach(move, game.m_moves) {
			out << move;
		}

		return out;
	}

	void Game::print() {
		Move move;
		qDebug() << "hello world";
		foreach(move, m_moves) {
			qDebug() << move.turn() << " " << move.score();
		}
	}

	void Game::nextMoveReceived() {
		this->nextMove();
		qDebug() << "next clicked" << m_current_move;
		emit valuesChanged();
	}

	void Game::previousMoveReceived() {
		this->previousMove();
		qDebug() << "previous clicked" << m_current_move;
		emit valuesChanged();
	}

	QString Game::currentImagePath() {
		return m_path + "images/" + QString::number(m_current_move+1) + ".svg";
	}

	/*QString Game::path() const {
		return m_path;
	}
	QLinkedList<Move> Game::moves() const {
		return m_moves;
	}

	QLinkedListIterator<Move> moves_iterator();
	Move current_move();*/
}