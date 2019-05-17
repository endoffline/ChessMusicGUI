#pragma once

#include <QtWidgets/QWidget>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>

#include "ui_ChessMusicGUI.h"
#include "Game.h"
class ChessMusicGUI : public QWidget
{
	Q_OBJECT

public:
	ChessMusicGUI(QWidget *parent = Q_NULLPTR);
	Models::Game game();
	void initValues(QString path);
public slots:
	void updateValues(QString path);

private:
	Ui::ChessMusicGUIClass ui;
	Models::Game m_game;
	QGraphicsSvgItem *m_svg;
	QGraphicsScene *m_scene;
};
