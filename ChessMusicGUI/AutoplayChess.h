#pragma once

#include <QTimer>
#include <QObject>

class AutoplayChess : public QObject {
	Q_OBJECT

public:
	AutoplayChess(int time = 5000, QObject *parent = 0);
	
public Q_SLOTS:
	void autoplay(bool autoplay);
	void play();
Q_SIGNALS:
	void nextMove();
	void startAutoplay();

private:
	QTimer *m_timer;
	int m_time;
	bool m_autoplay;
};