#pragma once

#include <QtWidgets/QWidget>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>

#include "ui_ChessMusicGUI.h"
#include "Game.h"
#include "Move.h"
#include "FMODController.h"

class ChessMusicGUI : public QWidget
{
	Q_OBJECT

public:
	ChessMusicGUI(QWidget *parent = Q_NULLPTR);
	Models::Game game();
	void initValues(QString path);
public Q_SLOTS:
	void updateValues(QString path);
Q_SIGNALS:
	void updateFMOD(Models::Move current_move);
private:
	Ui::ChessMusicGUIClass ui;
	Models::Game m_game;
	QGraphicsSvgItem *m_svg;
	QGraphicsScene *m_scene;
	FMODController m_fmod_controller;
};
