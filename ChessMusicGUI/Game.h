#pragma once

#include <QObject>
#include <QList>
#include "Move.h"
#include "iostream"
namespace Models {

	class Game : public QObject {
		Q_OBJECT
		//Q_DISABLE_COPY(Game)

		Q_PROPERTY(Move current_move READ current_move)
	public:
		
		Game(QString path = "", QList<Move> moves = QList<Move>(), int current_move = c_min_index, QObject* parent = nullptr);
		Game(const Game &game);
		Game &operator=(const Game &other);
		//Game(QString path, QLinkedList<Move> moves, QLinkedListIterator<Move> moves_iterator, QObject * parent);

		//QLinkedList<Move> &moves() const;
		Move current_move() const;
		void setData(QString path);
		void addMove(Move move);
		Move nextMove();
		Move previousMove();
		void print();
		friend std::ostream& operator<<(std::ostream& out, const Game& game);
		QString currentImagePath();

		
	public Q_SLOTS:
		void nextMoveReceived();
		void previousMoveReceived();
	Q_SIGNALS:
		void valuesChanged(QString path);
	private:
		//QString path() const;
		//QLinkedList<Move> moves() const;
		//QLinkedListIterator<Move>& moves_iterator() const;
		//Move& current_move() const;
		static const int c_min_index = -1;
		QString m_path;
		QList<Move> m_moves;
		int m_current_move;
	};
}