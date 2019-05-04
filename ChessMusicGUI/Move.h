#pragma once

#include <QStandardItemModel>
#include <QObject>
#include <QString>
namespace Models {
	
	class Move : public QObject {
		Q_OBJECT
		Q_DISABLE_COPY(Move)

		Q_PROPERTY(QString turn READ turn)
		Q_PROPERTY(QString score READ score)
	public:
		explicit Move(QString turn, QString score, QObject* parent = nullptr);

		QString turn() const;
		QString score() const;

	private:
		QString m_turn;
		QString m_score;
	};
}