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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessMusicGUIClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QFormLayout *formLayout;
    QLineEdit *turn_lineEdit;
    QLineEdit *score_lineEdit;
    QLabel *turn_label;
    QLabel *score_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *nextButton;

    void setupUi(QWidget *ChessMusicGUIClass)
    {
        if (ChessMusicGUIClass->objectName().isEmpty())
            ChessMusicGUIClass->setObjectName(QString::fromUtf8("ChessMusicGUIClass"));
        ChessMusicGUIClass->resize(1088, 624);
        verticalLayout = new QVBoxLayout(ChessMusicGUIClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        graphicsView = new QGraphicsView(ChessMusicGUIClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_3->addWidget(graphicsView);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(-1, -1, 20, -1);
        turn_lineEdit = new QLineEdit(ChessMusicGUIClass);
        turn_lineEdit->setObjectName(QString::fromUtf8("turn_lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, turn_lineEdit);

        score_lineEdit = new QLineEdit(ChessMusicGUIClass);
        score_lineEdit->setObjectName(QString::fromUtf8("score_lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, score_lineEdit);

        turn_label = new QLabel(ChessMusicGUIClass);
        turn_label->setObjectName(QString::fromUtf8("turn_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, turn_label);

        score_label = new QLabel(ChessMusicGUIClass);
        score_label->setObjectName(QString::fromUtf8("score_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, score_label);


        horizontalLayout_3->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
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
        turn_label->setText(QApplication::translate("ChessMusicGUIClass", "Turn", nullptr));
        score_label->setText(QApplication::translate("ChessMusicGUIClass", "Score", nullptr));
        backButton->setText(QApplication::translate("ChessMusicGUIClass", "Back", nullptr));
        nextButton->setText(QApplication::translate("ChessMusicGUIClass", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessMusicGUIClass: public Ui_ChessMusicGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSMUSICGUI_H
