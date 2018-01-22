#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QString>
#include <QThread>
#include <winsock2.h>

namespace Ui {
    class MainWindow;
}

struct Transfer_Data {
    int comando;
    char char1[80];
    char char2[80];
    int int1;
    int int2;
};

class MyThread : public QThread
{
    Q_OBJECT

public:
     void run();

protected:
     void Dados(char* buffer);

signals:
     void Menssagem(QString texto);
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void conectar();
    void personagem();
    void enviar();
    void EscreveMenssagem(QString texto);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    MyThread thread;
};

#endif // MAINWINDOW_H
