#pragma once

#include <QtWidgets/QWidget>
#include "ui_ChessMusicGUI.h"

class ChessMusicGUI : public QWidget
{
	Q_OBJECT

public:
	ChessMusicGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChessMusicGUIClass ui;
};
