#include "mainwindow.h"
#include "ui_mainwindow.h"

SOCKET s;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->MenssagemText->hide();
    ui->EnviarText->hide();
    ui->EnviarButton->hide();

    connect(ui->UsuarioText, SIGNAL(returnPressed()), this, SLOT(conectar()));
    connect(ui->SenhaText, SIGNAL(returnPressed()), this, SLOT(conectar()));
    connect(ui->ConectarButton, SIGNAL(clicked()), this, SLOT(conectar()));
    connect(ui->CharacterText, SIGNAL(returnPressed()), this, SLOT(personagem()));
    connect(ui->CharacterButton, SIGNAL(clicked()), this, SLOT(personagem()));
    connect(ui->EnviarText, SIGNAL(returnPressed()), this, SLOT(enviar()));
    connect(ui->EnviarButton, SIGNAL(clicked()), this, SLOT(enviar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::conectar()
{
    WSADATA w;
    int error = WSAStartup(0x0202, &w);
    if (error) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error: You need WinSock 2.2!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    if (w.wVersion != 0x0202) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error: Wrong WinSock version!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        WSACleanup();
        return;
    }

    s = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(5001);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (::connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("Error: Connection failed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        WSACleanup();
        return;
    }

    Transfer_Data data;
    strcpy(data.char1, (const char*)ui->UsuarioText->text().toUtf8());
    strcpy(data.char2, (const char*)ui->SenhaText->text().toUtf8());
    data.comando = 2;
    send(s, (char*)&data, sizeof(data), 0);

    ui->ConectarButton->setEnabled(false);
    ui->UsuarioText->setEnabled(false);
    ui->SenhaText->setEnabled(false);
    ui->CharacterText->setEnabled(true);
    ui->CharacterButton->setEnabled(true);

    ui->CharacterText->setFocus();
}

void MainWindow::personagem()
{
    Transfer_Data data;
    bool ok;
    data.int1 = ui->CharacterText->text().toInt(&ok, 10);
    data.comando = 3;
    send(s, (char*)&data, sizeof(data), 0);

    ui->ConectarButton->hide();
    ui->UsuarioText->hide();
    ui->SenhaText->hide();
    ui->CharacterText->hide();
    ui->CharacterButton->hide();
    ui->MenssagemText->show();
    ui->EnviarText->show();
    ui->EnviarButton->show();

    ui->EnviarText->setFocus();

    thread.start();

    connect(&thread, SIGNAL(Menssagem(QString)), this, SLOT(EscreveMenssagem(QString)));
}

void MainWindow::enviar()
{
    Transfer_Data data;
    strcpy(data.char1, (const char*)ui->EnviarText->text().toUtf8());
    data.comando = 1;
    send(s, (char*)&data, sizeof(data), 0);

    ui->EnviarText->clear();
}

void MainWindow::EscreveMenssagem(QString texto)
{
    ui->MenssagemText->append(texto);
}

void MyThread::run()
{
    fd_set fds;
    timeval timeout;
    char buffer[10000];
    do {
        timeout.tv_sec = 0;
        timeout.tv_usec = 1000;
        FD_ZERO(&fds);
        FD_SET(s, &fds);
        int atividade = select(s+1, &fds, NULL, NULL, &timeout);
        if (atividade == SOCKET_ERROR) {
            emit Menssagem("A funcao \"select\" falhou.\n");
        }
        if (atividade > 0) {
            if (FD_ISSET(s, &fds)) {
                int recebido = recv(s,buffer,sizeof(buffer),0);
                if (recebido <= 0) {
                    closesocket(s);
                    break;
                } else {
                    Dados(buffer);
                }
            }
        }
    } while(1);
    emit Menssagem("Voce foi desconectado!\n");

    exec();
}

void MyThread::Dados(char* buffer)
{
     Transfer_Data* data = (Transfer_Data*)buffer;
     switch(data->comando) {
        case 1:
            emit Menssagem("<span style='font-size:8pt; font-weight:600;'>Chat: " + QString(data->char1) + "</span>");
            break;
        case 2:
            emit Menssagem("<span style='font-size:8pt; font-weight:600; color:#ff0000;'>Server: " + QString(data->char1) + "</span>");
            break;
        case 3:
            emit Menssagem("<span style='font-size:8pt; font-weight:600; color:#ff00ff;'>Private: " + QString(data->char1) + "</span>");
            break;
        case 4:
            emit Menssagem("<span style='font-size:8pt; font-weight:600; color:#ff5500;'>Guild: " + QString(data->char1) + "</span>");
            break;
        case 5:
            emit Menssagem("<span style='font-size:8pt; font-weight:600; color:#00007f;'>Party: " + QString(data->char1) + "</span>");
            break;
        default:
            //
            break;
     }
}
