#include "ChessMusicGUI.h"
#include "Game.h"
#include "CSVReader.h"
#include <qDebug>


Models::Game ChessMusicGUI::game() {
	return m_game;
}

ChessMusicGUI::ChessMusicGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	CSVReader reader("./csv/kasparov_karpov_1986.csv");
	m_game = reader.loadGame();

	
	m_game.print();

	connect(ui.nextButton, &QPushButton::clicked, &m_game, &Models::Game::nextMoveReceived);
	connect(ui.backButton, &QPushButton::clicked, &m_game, &Models::Game::previousMoveReceived);
	connect(&m_game, &Models::Game::valuesChanged, this, &ChessMusicGUI::updateValues);

	updateValues();
}

void ChessMusicGUI::updateValues() {
	ui.turn_lineEdit->setText(m_game.current_move().turn());
	ui.score_lineEdit->setText(m_game.current_move().score());
}


