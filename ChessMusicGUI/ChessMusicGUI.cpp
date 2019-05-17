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
	
	//CSVReader reader("./csv/kasparov_karpov_1986.csv");
	CSVReader reader("./games/kasparov_karpov_1986/");
	m_game = reader.loadGame();

	
	m_game.print();

	
	connect(ui.nextButton, &QPushButton::clicked, &m_game, &Models::Game::nextMoveReceived);
	connect(ui.backButton, &QPushButton::clicked, &m_game, &Models::Game::previousMoveReceived);
	//connect(&m_game, &Models::Game::gameLoaded, this, &ChessMusicGUI::initValues);
	connect(&m_game, &Models::Game::valuesChanged, this, &ChessMusicGUI::updateValues);
	initValues(m_game.currentImagePath());
}

void ChessMusicGUI::initValues(QString path) {
	m_svg = new QGraphicsSvgItem(path);
	m_svg->setScale(1);

	m_scene = new QGraphicsScene();
	m_scene->addItem(m_svg);
	//ui.graphicsView->setGeometry(400, 400, 400, 400);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();
}

void ChessMusicGUI::updateValues(QString path) {
	ui.turn_lineEdit->setText(QString::number(m_game.current_move().turn()));
	ui.score_lineEdit->setText(QString::number(m_game.current_move().score()));
	m_scene->removeItem(m_svg);
	m_svg->~QGraphicsSvgItem();
	m_svg = new QGraphicsSvgItem(path);
	m_scene->addItem(m_svg);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();
}


