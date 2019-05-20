#include "ChessMusicGUI.h"
#include "Game.h"
#include "CSVReader.h"
#include <QThread>
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
	initValues();
	
	m_game.print();
	m_autoplay_thread = new QThread(this);
	m_autoplay = new AutoplayChess();
	m_autoplay->moveToThread(m_autoplay_thread);
	
	
	
	connect(ui.nextButton, &QPushButton::clicked, &m_game, &Models::Game::nextMoveReceived);
	connect(ui.backButton, &QPushButton::clicked, &m_game, &Models::Game::previousMoveReceived);
	connect(ui.autoplay_checkBox, &QCheckBox::clicked, m_autoplay, &AutoplayChess::autoplay);
	connect(&m_game, &Models::Game::valuesChanged, this, &ChessMusicGUI::updateValues);
	connect(this, &ChessMusicGUI::updateFMOD, &m_fmod_controller, &FMODController::updateFMODValues);
	connect(m_autoplay, &AutoplayChess::nextMove, &m_game, &Models::Game::nextMoveReceived);
	
	
	m_autoplay_thread->start();
	
	
}

ChessMusicGUI::~ChessMusicGUI() {
	m_autoplay_thread->quit();
	m_autoplay_thread->wait();
}

void ChessMusicGUI::initValues() {
	
	m_svg = new QGraphicsSvgItem(m_game.currentImagePath());
	m_svg->setScale(1);

	m_scene = new QGraphicsScene();
	m_scene->addItem(m_svg);
	//ui.graphicsView->setGeometry(400, 400, 400, 400);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();

	
}

void ChessMusicGUI::updateValues() {
	qDebug() << "1";
	qDebug() << QString::number(m_game.current_move().turn()) << QString::fromStdString(m_game.current_move().san()) << m_game.current_move().is_check() << m_game.current_move().is_capture() << m_game.current_move().is_castling();
	ui.turn_lineEdit->setText(QString::number(m_game.current_move().turn()));
	ui.san_lineEdit->setText(QString::fromStdString(m_game.current_move().san()));
	ui.lan_lineEdit->setText(QString::fromStdString(m_game.current_move().lan()));
	ui.score_lineEdit->setText(QString::number(m_game.current_move().score()));
	ui.move_count_lineEdit->setText(QString::number(m_game.current_move().move_count()));
	ui.best_move_lineEdit->setText(QString::fromStdString(m_game.current_move().best_move()));
	ui.best_move_score_lineEdit->setText(QString::number(m_game.current_move().best_move_score()));
	ui.best_move_score_difference_lineEdit->setText(QString::number(m_game.current_move().best_move_score_difference()));
	ui.best_move_score_difference_category_lineEdit->setText(QString::number(m_game.current_move().best_move_score_difference_category()));
	ui.is_check_lineEdit->setText(QVariant(m_game.current_move().is_check()).toString());
	ui.is_capture_lineEdit->setText(QVariant(m_game.current_move().is_capture()).toString());
	ui.is_castling_lineEdit->setText(QVariant(m_game.current_move().is_castling()).toString());
	ui.possible_moves_count_lineEdit->setText(QString::number(m_game.current_move().possible_moves_count()));
	ui.is_capture_count_lineEdit->setText(QString::number(m_game.current_move().is_capture_count()));
	ui.attackers_lineEdit->setText(QString::fromStdString(m_game.current_move().attackers()));
	ui.attackers_count_lineEdit->setText(QString::number(m_game.current_move().attackers_count()));
	ui.threatened_pieces_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_pieces()));
	ui.threatened_pieces_count_lineEdit->setText(QString::number(m_game.current_move().threatened_pieces_count()));
	ui.guards_lineEdit->setText(QString::fromStdString(m_game.current_move().guards()));
	ui.guards_count_lineEdit->setText(QString::number(m_game.current_move().guards_count()));
	ui.guarded_pieces_lineEdit->setText(QString::fromStdString(m_game.current_move().guarded_pieces()));
	ui.guarded_pieces_count_lineEdit->setText(QString::number(m_game.current_move().guarded_pieces_count()));
	ui.threatened_guarded_pieces_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_guarded_pieces()));
	ui.threatened_guarded_pieces_count_lineEdit->setText(QString::number(m_game.current_move().threatened_guarded_pieces_count()));
	ui.unopposed_threats_lineEdit->setText(QString::fromStdString(m_game.current_move().unopposed_threats()));
	ui.unopposed_threats_count_lineEdit->setText(QString::number(m_game.current_move().unopposed_threats_count()));
	m_scene->removeItem(m_svg);
	m_svg->~QGraphicsSvgItem();
	m_svg = new QGraphicsSvgItem(m_game.currentImagePath());
	m_scene->addItem(m_svg);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();
	qDebug() << "2";
	emit updateFMOD(m_game.current_move());
}


