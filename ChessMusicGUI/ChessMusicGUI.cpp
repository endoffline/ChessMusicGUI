#include "ChessMusicGUI.h"
#include "Game.h"
#include "CSVReader.h"
#include <QThread>
#include <qDebug>
#include <qfiledialog.h>

Models::Game ChessMusicGUI::game() {
	return m_game;
}

ChessMusicGUI::ChessMusicGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QString folder = "";

	while (folder == "") {
		folder = QFileDialog::getExistingDirectory(this, tr("Open Game folder"), ".");
	}
	
	//CSVReader reader("./csv/kasparov_karpov_1986.csv");
	//CSVReader reader("./games/kasparov_karpov_1986/");
	CSVReader reader(folder.toStdString());
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
	//connect(this, &ChessMusicGUI::updateFMOD, &m_fmod_controller, &FMODController::updateFMODValues);
	connect(this, &ChessMusicGUI::updateFMOD, &m_fmod_controller, &FMODSoundscapeController::updateFMODValues);
	connect(this, &ChessMusicGUI::closeWindow, &m_fmod_controller, &FMODSoundscapeController::abortSinusWave);
	connect(m_autoplay, &AutoplayChess::nextMove, &m_game, &Models::Game::nextMoveReceived);
	
	m_autoplay_thread->start();
}

ChessMusicGUI::~ChessMusicGUI() {
	m_autoplay_thread->quit();
	m_autoplay_thread->wait();
}

void ChessMusicGUI::closeEvent(QCloseEvent *event) {
	qDebug() << "close1";
	emit closeWindow();
	
	QWidget::closeEvent(event);
}

void ChessMusicGUI::initValues() {
	
	m_svg = new QGraphicsSvgItem(m_game.currentImagePath());
	m_svg->setScale(1);

	m_scene = new QGraphicsScene();
	m_scene->addItem(m_svg);
	//ui.graphicsView->setGeometry(400, 400, 400, 400);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();
	ui.logTextEdit->ensureCursorVisible();

}

void ChessMusicGUI::appendLogMessage(QPlainTextEdit *textEdit, const std::string& lan) {
	std::string text;
	std::map<char, std::string> conversionMap = {
		{'N', "Knight"},
		{'B', "Bishop"},
		{'R', "Rook"},
		{'Q', "Queen"},
		{'K', "King"},
		{'-', ""},
		{'x', " and captures a piece"},
		{'+', " and checks the king"},
		{'O', "Castling"}
	};
	/*conversionMap['N'] = "Knight";
	conversionMap['B'] = "Bishop";
	conversionMap['R'] = "Rook";
	conversionMap['Q'] = "Queen";
	conversionMap['K'] = "King";
	conversionMap['-'] = "";
	conversionMap['x'] = "and captures a piece";
	conversionMap['+'] = "and checks the king";*/
	int i = 0;

	char c = lan.at(i++);
	std::string s = conversionMap[c];
	
	if (s == "") {
		s = "Pawn";
		i = 0;
	}
	text += lan;
	text += ": ";
	text += s;
	if (c != 'O') {
		text += " moved from ";
		text += lan.at(i++);
		text += lan.at(i++);
		text += " to ";
		std::string captured = conversionMap[lan.at(i++)];
		text += lan.at(i++);
		text += lan.at(i++);
		text += captured;
		
		if (i < lan.length()) {
			text += conversionMap[lan.at(i++)];
		}
	}
	textEdit->appendPlainText(QString::fromStdString(text));

}

void ChessMusicGUI::updateValues() {
	qDebug() << "1";
	qDebug() << QString::number(m_game.current_move().turn()) << QString::fromStdString(m_game.current_move().san()) << m_game.current_move().is_check() << m_game.current_move().is_capture() << m_game.current_move().is_castling();
	ui.fullmove_number_lineEdit->setText(QString::number(m_game.current_move().fullmove_number()));
	ui.turn_lineEdit->setText(QString::number(m_game.current_move().turn()));
	ui.san_lineEdit->setText(QString::fromStdString(m_game.current_move().san()));
	ui.lan_lineEdit->setText(QString::fromStdString(m_game.current_move().lan()));
	ui.score_lineEdit->setText(QString::number(m_game.current_move().score()));
	ui.score_shift_lineEdit->setText(QString::number(m_game.current_move().score_shift()));
	ui.score_shift_category_lineEdit->setText(QString::number(m_game.current_move().score_shift_category()));
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
	ui.attackers_white_lineEdit->setText(QString::fromStdString(m_game.current_move().attackers_white()));
	ui.attackers_count_white_lineEdit->setText(QString::number(m_game.current_move().attackers_count_white()));
	ui.threatened_pieces_white_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_pieces_white()));
	ui.threatened_pieces_count_white_lineEdit->setText(QString::number(m_game.current_move().threatened_pieces_count_white()));
	ui.guards_white_lineEdit->setText(QString::fromStdString(m_game.current_move().guards_white()));
	ui.guards_count_white_lineEdit->setText(QString::number(m_game.current_move().guards_count_white()));
	ui.guarded_pieces_white_lineEdit->setText(QString::fromStdString(m_game.current_move().guarded_pieces_white()));
	ui.guarded_pieces_count_white_lineEdit->setText(QString::number(m_game.current_move().guarded_pieces_count_white()));
	ui.threatened_guarded_pieces_white_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_guarded_pieces_white()));
	ui.threatened_guarded_pieces_count_white_lineEdit->setText(QString::number(m_game.current_move().threatened_guarded_pieces_count_white()));
	ui.unopposed_threats_white_lineEdit->setText(QString::fromStdString(m_game.current_move().unopposed_threats_white()));
	ui.unopposed_threats_count_white_lineEdit->setText(QString::number(m_game.current_move().unopposed_threats_count_white()));
	ui.attackers_black_lineEdit->setText(QString::fromStdString(m_game.current_move().attackers_black()));
	ui.attackers_count_black_lineEdit->setText(QString::number(m_game.current_move().attackers_count_black()));
	ui.threatened_pieces_black_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_pieces_black()));
	ui.threatened_pieces_count_black_lineEdit->setText(QString::number(m_game.current_move().threatened_pieces_count_black()));
	ui.guards_black_lineEdit->setText(QString::fromStdString(m_game.current_move().guards_black()));
	ui.guards_count_black_lineEdit->setText(QString::number(m_game.current_move().guards_count_black()));
	ui.guarded_pieces_black_lineEdit->setText(QString::fromStdString(m_game.current_move().guarded_pieces_black()));
	ui.guarded_pieces_count_black_lineEdit->setText(QString::number(m_game.current_move().guarded_pieces_count_black()));
	ui.threatened_guarded_pieces_black_lineEdit->setText(QString::fromStdString(m_game.current_move().threatened_guarded_pieces_black()));
	ui.threatened_guarded_pieces_count_black_lineEdit->setText(QString::number(m_game.current_move().threatened_guarded_pieces_count_black()));
	ui.unopposed_threats_black_lineEdit->setText(QString::fromStdString(m_game.current_move().unopposed_threats_black()));
	ui.unopposed_threats_count_black_lineEdit->setText(QString::number(m_game.current_move().unopposed_threats_count_black()));
	m_scene->removeItem(m_svg);
	m_svg->~QGraphicsSvgItem();
	m_svg = new QGraphicsSvgItem(m_game.currentImagePath());
	m_scene->addItem(m_svg);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->show();
	appendLogMessage(ui.logTextEdit, m_game.current_move().lan());
	qDebug() << "2";
	emit updateFMOD(m_game.current_move());
}


