#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChessMusicGUI.h"
#include "Game.h"
class ChessMusicGUI : public QWidget
{
	Q_OBJECT

public:
	ChessMusicGUI(QWidget *parent = Q_NULLPTR);
	Models::Game game();
public slots:
	void updateValues();

private:
	Ui::ChessMusicGUIClass ui;
	Models::Game m_game;
};
