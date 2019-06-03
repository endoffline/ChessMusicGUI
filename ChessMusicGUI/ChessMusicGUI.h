#pragma once

#include <QtWidgets/QWidget>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>

#include "ui_ChessMusicGUI.h"
#include "Game.h"
#include "Move.h"
#include "FMODController.h"
#include "AutoplayChess.h"

class ChessMusicGUI : public QWidget
{
	Q_OBJECT

public:
	ChessMusicGUI(QWidget *parent = Q_NULLPTR);
	~ChessMusicGUI();
	Models::Game game();
	void initValues();
	void ChessMusicGUI::appendLogMessage(QPlainTextEdit *textEdit, const std::string& lan);
public Q_SLOTS:
	void updateValues();
Q_SIGNALS:
	void updateFMOD(Models::Move current_move);
private:
	Ui::ChessMusicGUIClass ui;
	Models::Game m_game;
	QGraphicsSvgItem *m_svg;
	QGraphicsScene *m_scene;
	FMODController m_fmod_controller;
	AutoplayChess *m_autoplay;
	QThread *m_autoplay_thread;
};
