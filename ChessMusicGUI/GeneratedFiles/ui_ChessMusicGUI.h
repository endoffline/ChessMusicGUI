/********************************************************************************
** Form generated from reading UI file 'ChessMusicGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSMUSICGUI_H
#define UI_CHESSMUSICGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessMusicGUIClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QPlainTextEdit *logTextEdit;
    QFormLayout *formLayout;
    QLabel *turn_label;
    QLineEdit *turn_lineEdit;
    QLabel *san_label;
    QLineEdit *san_lineEdit;
    QLabel *lan_label;
    QLineEdit *lan_lineEdit;
    QLabel *score_label;
    QLineEdit *score_lineEdit;
    QLabel *move_count_label;
    QLineEdit *move_count_lineEdit;
    QLabel *best_move_label;
    QLineEdit *best_move_lineEdit;
    QLabel *best_move_score_label;
    QLineEdit *best_move_score_lineEdit;
    QLabel *best_move_score_difference_label;
    QLineEdit *best_move_score_difference_lineEdit;
    QLabel *best_move_score_difference_category_label;
    QLineEdit *best_move_score_difference_category_lineEdit;
    QLabel *is_check_label;
    QLineEdit *is_check_lineEdit;
    QLabel *is_capture_label;
    QLineEdit *is_capture_lineEdit;
    QLabel *is_castling_label;
    QLineEdit *is_castling_lineEdit;
    QLabel *possible_moves_count_label;
    QLineEdit *possible_moves_count_lineEdit;
    QLabel *is_capture_count_label;
    QLineEdit *is_capture_count_lineEdit;
    QLabel *attackers_label;
    QLineEdit *attackers_lineEdit;
    QLabel *attackers_count_label;
    QLineEdit *attackers_count_lineEdit;
    QLabel *threatened_pieces_label;
    QLineEdit *threatened_pieces_lineEdit;
    QLabel *threatened_pieces_count_label;
    QLineEdit *threatened_pieces_count_lineEdit;
    QLabel *guards_label;
    QLineEdit *guards_lineEdit;
    QLabel *guards_count_label;
    QLineEdit *guards_count_lineEdit;
    QLabel *guarded_pieces_label;
    QLineEdit *guarded_pieces_lineEdit;
    QLabel *guarded_pieces_count_label;
    QLineEdit *guarded_pieces_count_lineEdit;
    QLineEdit *threatened_guarded_pieces_lineEdit;
    QLabel *threatened_guarded_pieces_label;
    QLabel *threatened_guarded_pieces_count_label;
    QLabel *unopposed_threats_label;
    QLabel *unopposed_threats_count_label;
    QLineEdit *threatened_guarded_pieces_count_lineEdit;
    QLineEdit *unopposed_threats_lineEdit;
    QLineEdit *unopposed_threats_count_lineEdit;
    QLineEdit *fullmove_number_lineEdit;
    QLabel *fullmove_number_label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *autoplay_checkBox;
    QPushButton *backButton;
    QPushButton *nextButton;

    void setupUi(QWidget *ChessMusicGUIClass)
    {
        if (ChessMusicGUIClass->objectName().isEmpty())
            ChessMusicGUIClass->setObjectName(QString::fromUtf8("ChessMusicGUIClass"));
        ChessMusicGUIClass->resize(1088, 749);
        verticalLayout = new QVBoxLayout(ChessMusicGUIClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        graphicsView = new QGraphicsView(ChessMusicGUIClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(400, 400));
        graphicsView->setMaximumSize(QSize(600, 600));

        verticalLayout_2->addWidget(graphicsView);

        logTextEdit = new QPlainTextEdit(ChessMusicGUIClass);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setMaximumSize(QSize(600, 16777215));

        verticalLayout_2->addWidget(logTextEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(-1, -1, 20, -1);
        turn_label = new QLabel(ChessMusicGUIClass);
        turn_label->setObjectName(QString::fromUtf8("turn_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, turn_label);

        turn_lineEdit = new QLineEdit(ChessMusicGUIClass);
        turn_lineEdit->setObjectName(QString::fromUtf8("turn_lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, turn_lineEdit);

        san_label = new QLabel(ChessMusicGUIClass);
        san_label->setObjectName(QString::fromUtf8("san_label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, san_label);

        san_lineEdit = new QLineEdit(ChessMusicGUIClass);
        san_lineEdit->setObjectName(QString::fromUtf8("san_lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, san_lineEdit);

        lan_label = new QLabel(ChessMusicGUIClass);
        lan_label->setObjectName(QString::fromUtf8("lan_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lan_label);

        lan_lineEdit = new QLineEdit(ChessMusicGUIClass);
        lan_lineEdit->setObjectName(QString::fromUtf8("lan_lineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lan_lineEdit);

        score_label = new QLabel(ChessMusicGUIClass);
        score_label->setObjectName(QString::fromUtf8("score_label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, score_label);

        score_lineEdit = new QLineEdit(ChessMusicGUIClass);
        score_lineEdit->setObjectName(QString::fromUtf8("score_lineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, score_lineEdit);

        move_count_label = new QLabel(ChessMusicGUIClass);
        move_count_label->setObjectName(QString::fromUtf8("move_count_label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, move_count_label);

        move_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        move_count_lineEdit->setObjectName(QString::fromUtf8("move_count_lineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, move_count_lineEdit);

        best_move_label = new QLabel(ChessMusicGUIClass);
        best_move_label->setObjectName(QString::fromUtf8("best_move_label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, best_move_label);

        best_move_lineEdit = new QLineEdit(ChessMusicGUIClass);
        best_move_lineEdit->setObjectName(QString::fromUtf8("best_move_lineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, best_move_lineEdit);

        best_move_score_label = new QLabel(ChessMusicGUIClass);
        best_move_score_label->setObjectName(QString::fromUtf8("best_move_score_label"));

        formLayout->setWidget(7, QFormLayout::LabelRole, best_move_score_label);

        best_move_score_lineEdit = new QLineEdit(ChessMusicGUIClass);
        best_move_score_lineEdit->setObjectName(QString::fromUtf8("best_move_score_lineEdit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, best_move_score_lineEdit);

        best_move_score_difference_label = new QLabel(ChessMusicGUIClass);
        best_move_score_difference_label->setObjectName(QString::fromUtf8("best_move_score_difference_label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, best_move_score_difference_label);

        best_move_score_difference_lineEdit = new QLineEdit(ChessMusicGUIClass);
        best_move_score_difference_lineEdit->setObjectName(QString::fromUtf8("best_move_score_difference_lineEdit"));

        formLayout->setWidget(8, QFormLayout::FieldRole, best_move_score_difference_lineEdit);

        best_move_score_difference_category_label = new QLabel(ChessMusicGUIClass);
        best_move_score_difference_category_label->setObjectName(QString::fromUtf8("best_move_score_difference_category_label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, best_move_score_difference_category_label);

        best_move_score_difference_category_lineEdit = new QLineEdit(ChessMusicGUIClass);
        best_move_score_difference_category_lineEdit->setObjectName(QString::fromUtf8("best_move_score_difference_category_lineEdit"));

        formLayout->setWidget(9, QFormLayout::FieldRole, best_move_score_difference_category_lineEdit);

        is_check_label = new QLabel(ChessMusicGUIClass);
        is_check_label->setObjectName(QString::fromUtf8("is_check_label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, is_check_label);

        is_check_lineEdit = new QLineEdit(ChessMusicGUIClass);
        is_check_lineEdit->setObjectName(QString::fromUtf8("is_check_lineEdit"));

        formLayout->setWidget(10, QFormLayout::FieldRole, is_check_lineEdit);

        is_capture_label = new QLabel(ChessMusicGUIClass);
        is_capture_label->setObjectName(QString::fromUtf8("is_capture_label"));

        formLayout->setWidget(11, QFormLayout::LabelRole, is_capture_label);

        is_capture_lineEdit = new QLineEdit(ChessMusicGUIClass);
        is_capture_lineEdit->setObjectName(QString::fromUtf8("is_capture_lineEdit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, is_capture_lineEdit);

        is_castling_label = new QLabel(ChessMusicGUIClass);
        is_castling_label->setObjectName(QString::fromUtf8("is_castling_label"));

        formLayout->setWidget(12, QFormLayout::LabelRole, is_castling_label);

        is_castling_lineEdit = new QLineEdit(ChessMusicGUIClass);
        is_castling_lineEdit->setObjectName(QString::fromUtf8("is_castling_lineEdit"));

        formLayout->setWidget(12, QFormLayout::FieldRole, is_castling_lineEdit);

        possible_moves_count_label = new QLabel(ChessMusicGUIClass);
        possible_moves_count_label->setObjectName(QString::fromUtf8("possible_moves_count_label"));

        formLayout->setWidget(13, QFormLayout::LabelRole, possible_moves_count_label);

        possible_moves_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        possible_moves_count_lineEdit->setObjectName(QString::fromUtf8("possible_moves_count_lineEdit"));

        formLayout->setWidget(13, QFormLayout::FieldRole, possible_moves_count_lineEdit);

        is_capture_count_label = new QLabel(ChessMusicGUIClass);
        is_capture_count_label->setObjectName(QString::fromUtf8("is_capture_count_label"));

        formLayout->setWidget(14, QFormLayout::LabelRole, is_capture_count_label);

        is_capture_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        is_capture_count_lineEdit->setObjectName(QString::fromUtf8("is_capture_count_lineEdit"));

        formLayout->setWidget(14, QFormLayout::FieldRole, is_capture_count_lineEdit);

        attackers_label = new QLabel(ChessMusicGUIClass);
        attackers_label->setObjectName(QString::fromUtf8("attackers_label"));

        formLayout->setWidget(15, QFormLayout::LabelRole, attackers_label);

        attackers_lineEdit = new QLineEdit(ChessMusicGUIClass);
        attackers_lineEdit->setObjectName(QString::fromUtf8("attackers_lineEdit"));

        formLayout->setWidget(15, QFormLayout::FieldRole, attackers_lineEdit);

        attackers_count_label = new QLabel(ChessMusicGUIClass);
        attackers_count_label->setObjectName(QString::fromUtf8("attackers_count_label"));

        formLayout->setWidget(16, QFormLayout::LabelRole, attackers_count_label);

        attackers_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        attackers_count_lineEdit->setObjectName(QString::fromUtf8("attackers_count_lineEdit"));

        formLayout->setWidget(16, QFormLayout::FieldRole, attackers_count_lineEdit);

        threatened_pieces_label = new QLabel(ChessMusicGUIClass);
        threatened_pieces_label->setObjectName(QString::fromUtf8("threatened_pieces_label"));

        formLayout->setWidget(17, QFormLayout::LabelRole, threatened_pieces_label);

        threatened_pieces_lineEdit = new QLineEdit(ChessMusicGUIClass);
        threatened_pieces_lineEdit->setObjectName(QString::fromUtf8("threatened_pieces_lineEdit"));

        formLayout->setWidget(17, QFormLayout::FieldRole, threatened_pieces_lineEdit);

        threatened_pieces_count_label = new QLabel(ChessMusicGUIClass);
        threatened_pieces_count_label->setObjectName(QString::fromUtf8("threatened_pieces_count_label"));

        formLayout->setWidget(18, QFormLayout::LabelRole, threatened_pieces_count_label);

        threatened_pieces_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        threatened_pieces_count_lineEdit->setObjectName(QString::fromUtf8("threatened_pieces_count_lineEdit"));

        formLayout->setWidget(18, QFormLayout::FieldRole, threatened_pieces_count_lineEdit);

        guards_label = new QLabel(ChessMusicGUIClass);
        guards_label->setObjectName(QString::fromUtf8("guards_label"));

        formLayout->setWidget(19, QFormLayout::LabelRole, guards_label);

        guards_lineEdit = new QLineEdit(ChessMusicGUIClass);
        guards_lineEdit->setObjectName(QString::fromUtf8("guards_lineEdit"));

        formLayout->setWidget(19, QFormLayout::FieldRole, guards_lineEdit);

        guards_count_label = new QLabel(ChessMusicGUIClass);
        guards_count_label->setObjectName(QString::fromUtf8("guards_count_label"));

        formLayout->setWidget(20, QFormLayout::LabelRole, guards_count_label);

        guards_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        guards_count_lineEdit->setObjectName(QString::fromUtf8("guards_count_lineEdit"));

        formLayout->setWidget(20, QFormLayout::FieldRole, guards_count_lineEdit);

        guarded_pieces_label = new QLabel(ChessMusicGUIClass);
        guarded_pieces_label->setObjectName(QString::fromUtf8("guarded_pieces_label"));

        formLayout->setWidget(21, QFormLayout::LabelRole, guarded_pieces_label);

        guarded_pieces_lineEdit = new QLineEdit(ChessMusicGUIClass);
        guarded_pieces_lineEdit->setObjectName(QString::fromUtf8("guarded_pieces_lineEdit"));

        formLayout->setWidget(21, QFormLayout::FieldRole, guarded_pieces_lineEdit);

        guarded_pieces_count_label = new QLabel(ChessMusicGUIClass);
        guarded_pieces_count_label->setObjectName(QString::fromUtf8("guarded_pieces_count_label"));

        formLayout->setWidget(22, QFormLayout::LabelRole, guarded_pieces_count_label);

        guarded_pieces_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        guarded_pieces_count_lineEdit->setObjectName(QString::fromUtf8("guarded_pieces_count_lineEdit"));

        formLayout->setWidget(22, QFormLayout::FieldRole, guarded_pieces_count_lineEdit);

        threatened_guarded_pieces_lineEdit = new QLineEdit(ChessMusicGUIClass);
        threatened_guarded_pieces_lineEdit->setObjectName(QString::fromUtf8("threatened_guarded_pieces_lineEdit"));

        formLayout->setWidget(23, QFormLayout::FieldRole, threatened_guarded_pieces_lineEdit);

        threatened_guarded_pieces_label = new QLabel(ChessMusicGUIClass);
        threatened_guarded_pieces_label->setObjectName(QString::fromUtf8("threatened_guarded_pieces_label"));

        formLayout->setWidget(23, QFormLayout::LabelRole, threatened_guarded_pieces_label);

        threatened_guarded_pieces_count_label = new QLabel(ChessMusicGUIClass);
        threatened_guarded_pieces_count_label->setObjectName(QString::fromUtf8("threatened_guarded_pieces_count_label"));

        formLayout->setWidget(24, QFormLayout::LabelRole, threatened_guarded_pieces_count_label);

        unopposed_threats_label = new QLabel(ChessMusicGUIClass);
        unopposed_threats_label->setObjectName(QString::fromUtf8("unopposed_threats_label"));

        formLayout->setWidget(25, QFormLayout::LabelRole, unopposed_threats_label);

        unopposed_threats_count_label = new QLabel(ChessMusicGUIClass);
        unopposed_threats_count_label->setObjectName(QString::fromUtf8("unopposed_threats_count_label"));

        formLayout->setWidget(26, QFormLayout::LabelRole, unopposed_threats_count_label);

        threatened_guarded_pieces_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        threatened_guarded_pieces_count_lineEdit->setObjectName(QString::fromUtf8("threatened_guarded_pieces_count_lineEdit"));

        formLayout->setWidget(24, QFormLayout::FieldRole, threatened_guarded_pieces_count_lineEdit);

        unopposed_threats_lineEdit = new QLineEdit(ChessMusicGUIClass);
        unopposed_threats_lineEdit->setObjectName(QString::fromUtf8("unopposed_threats_lineEdit"));

        formLayout->setWidget(25, QFormLayout::FieldRole, unopposed_threats_lineEdit);

        unopposed_threats_count_lineEdit = new QLineEdit(ChessMusicGUIClass);
        unopposed_threats_count_lineEdit->setObjectName(QString::fromUtf8("unopposed_threats_count_lineEdit"));

        formLayout->setWidget(26, QFormLayout::FieldRole, unopposed_threats_count_lineEdit);

        fullmove_number_lineEdit = new QLineEdit(ChessMusicGUIClass);
        fullmove_number_lineEdit->setObjectName(QString::fromUtf8("fullmove_number_lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fullmove_number_lineEdit);

        fullmove_number_label = new QLabel(ChessMusicGUIClass);
        fullmove_number_label->setObjectName(QString::fromUtf8("fullmove_number_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fullmove_number_label);


        horizontalLayout_3->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        autoplay_checkBox = new QCheckBox(ChessMusicGUIClass);
        autoplay_checkBox->setObjectName(QString::fromUtf8("autoplay_checkBox"));

        horizontalLayout->addWidget(autoplay_checkBox);

        backButton = new QPushButton(ChessMusicGUIClass);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout->addWidget(backButton);

        nextButton = new QPushButton(ChessMusicGUIClass);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChessMusicGUIClass);

        QMetaObject::connectSlotsByName(ChessMusicGUIClass);
    } // setupUi

    void retranslateUi(QWidget *ChessMusicGUIClass)
    {
        ChessMusicGUIClass->setWindowTitle(QApplication::translate("ChessMusicGUIClass", "ChessMusicGUI", nullptr));
        logTextEdit->setPlainText(QString());
        turn_label->setText(QApplication::translate("ChessMusicGUIClass", "Turn", nullptr));
        san_label->setText(QApplication::translate("ChessMusicGUIClass", "SAN", nullptr));
        lan_label->setText(QApplication::translate("ChessMusicGUIClass", "LAN", nullptr));
        score_label->setText(QApplication::translate("ChessMusicGUIClass", "Score", nullptr));
        move_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of moves", nullptr));
        best_move_label->setText(QApplication::translate("ChessMusicGUIClass", "Best move", nullptr));
        best_move_score_label->setText(QApplication::translate("ChessMusicGUIClass", "Best move's score", nullptr));
        best_move_score_difference_label->setText(QApplication::translate("ChessMusicGUIClass", "Difference", nullptr));
        best_move_score_difference_category_label->setText(QApplication::translate("ChessMusicGUIClass", "Move category", nullptr));
        is_check_label->setText(QApplication::translate("ChessMusicGUIClass", "Is check?", nullptr));
        is_capture_label->setText(QApplication::translate("ChessMusicGUIClass", "Is capture?", nullptr));
        is_castling_label->setText(QApplication::translate("ChessMusicGUIClass", "Is castling?", nullptr));
        possible_moves_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of possible moves", nullptr));
        is_capture_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of possible captures", nullptr));
        attackers_label->setText(QApplication::translate("ChessMusicGUIClass", "Attackers", nullptr));
        attackers_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of Attackers", nullptr));
        threatened_pieces_label->setText(QApplication::translate("ChessMusicGUIClass", "Threatened pieces", nullptr));
        threatened_pieces_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of threatened pieces", nullptr));
        guards_label->setText(QApplication::translate("ChessMusicGUIClass", "Guards", nullptr));
        guards_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of guards", nullptr));
        guarded_pieces_label->setText(QApplication::translate("ChessMusicGUIClass", "Guarded pieces", nullptr));
        guarded_pieces_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of guarded pieces", nullptr));
        threatened_guarded_pieces_label->setText(QApplication::translate("ChessMusicGUIClass", "Threatened/guarded pieces", nullptr));
        threatened_guarded_pieces_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of Threatened/guarded pieces", nullptr));
        unopposed_threats_label->setText(QApplication::translate("ChessMusicGUIClass", "Unopposed threats", nullptr));
        unopposed_threats_count_label->setText(QApplication::translate("ChessMusicGUIClass", "No of unopposed threats", nullptr));
        fullmove_number_label->setText(QApplication::translate("ChessMusicGUIClass", "Full move number", nullptr));
        autoplay_checkBox->setText(QApplication::translate("ChessMusicGUIClass", "Autoplay", nullptr));
        backButton->setText(QApplication::translate("ChessMusicGUIClass", "Back", nullptr));
        nextButton->setText(QApplication::translate("ChessMusicGUIClass", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessMusicGUIClass: public Ui_ChessMusicGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSMUSICGUI_H
