#include "AutoplayChess.h"
#include <qDebug>

AutoplayChess::AutoplayChess(int time, QObject *parent) : m_time(time), m_autoplay(false), QObject(parent) {
	m_timer = new QTimer(this);
	connect(this, &AutoplayChess::startAutoplay, this, &AutoplayChess::play);
	connect(this, &AutoplayChess::nextMove, this, &AutoplayChess::play);
}

void AutoplayChess::autoplay(bool autoplay) {
	m_autoplay = autoplay;
	qDebug() << "autoplay:" << autoplay;
	emit startAutoplay();
}

void AutoplayChess::play() {
	if (m_autoplay) {
		qDebug() << "timer started";
		QTimer::singleShot(m_time, [&]() { 
			emit nextMove(); 
		});
	}
}