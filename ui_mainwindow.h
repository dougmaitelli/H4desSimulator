/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 4. Jan 22:07:46 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *UsuarioText;
    QLineEdit *SenhaText;
    QPushButton *ConectarButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *CharacterText;
    QPushButton *CharacterButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *MenssagemText;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *EnviarText;
    QPushButton *EnviarButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 140, 220, 83));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        UsuarioText = new QLineEdit(layoutWidget);
        UsuarioText->setObjectName(QString::fromUtf8("UsuarioText"));

        verticalLayout->addWidget(UsuarioText);

        SenhaText = new QLineEdit(layoutWidget);
        SenhaText->setObjectName(QString::fromUtf8("SenhaText"));
        SenhaText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(SenhaText);


        horizontalLayout_2->addLayout(verticalLayout);

        ConectarButton = new QPushButton(layoutWidget);
        ConectarButton->setObjectName(QString::fromUtf8("ConectarButton"));

        horizontalLayout_2->addWidget(ConectarButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CharacterText = new QLineEdit(layoutWidget);
        CharacterText->setObjectName(QString::fromUtf8("CharacterText"));
        CharacterText->setEnabled(false);

        horizontalLayout->addWidget(CharacterText);

        CharacterButton = new QPushButton(layoutWidget);
        CharacterButton->setObjectName(QString::fromUtf8("CharacterButton"));
        CharacterButton->setEnabled(false);

        horizontalLayout->addWidget(CharacterButton);


        verticalLayout_2->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 10, 541, 411));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        MenssagemText = new QTextEdit(layoutWidget1);
        MenssagemText->setObjectName(QString::fromUtf8("MenssagemText"));
        MenssagemText->setEnabled(true);
        MenssagemText->setReadOnly(true);

        verticalLayout_3->addWidget(MenssagemText);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        EnviarText = new QLineEdit(layoutWidget1);
        EnviarText->setObjectName(QString::fromUtf8("EnviarText"));

        horizontalLayout_3->addWidget(EnviarText);

        EnviarButton = new QPushButton(layoutWidget1);
        EnviarButton->setObjectName(QString::fromUtf8("EnviarButton"));

        horizontalLayout_3->addWidget(EnviarButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(UsuarioText, SenhaText);
        QWidget::setTabOrder(SenhaText, ConectarButton);
        QWidget::setTabOrder(ConectarButton, CharacterText);
        QWidget::setTabOrder(CharacterText, CharacterButton);
        QWidget::setTabOrder(CharacterButton, EnviarText);
        QWidget::setTabOrder(EnviarText, EnviarButton);
        QWidget::setTabOrder(EnviarButton, MenssagemText);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulador", 0, QApplication::UnicodeUTF8));
        ConectarButton->setText(QApplication::translate("MainWindow", "Conectar", 0, QApplication::UnicodeUTF8));
        CharacterButton->setText(QApplication::translate("MainWindow", "Selecionar", 0, QApplication::UnicodeUTF8));
        MenssagemText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        EnviarButton->setText(QApplication::translate("MainWindow", "Enviar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
