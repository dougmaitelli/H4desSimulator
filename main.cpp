#include <pthread.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <winsock2.h>

using namespace std;

SOCKET s;
int BREAK=0;

struct Transfer_Data {
    int comando;
    char char1[80];
    char char2[80];
    int int1;
    int int2;
};

typedef enum {
    PRETO,
    AZUL_ESCURO,
    VERDE_ESCURO,
    TURQUESA_ESCURO,
    VERMELHO_ESCURO,
    VIOLETA_ESCURO,
    MARROM,
    CINZA,
    CINZA_ESCURO,
    AZUL,
    VERDE,
    TURQUESA,
    VERMELHO,
    VIOLETA,
    AMARELO,
    BRANCO
};

static int __BACKGROUND = PRETO;
static int __FOREGROUND = BRANCO;

void CorTexto(int Cor)
{
      __FOREGROUND = Cor;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Cor + (__BACKGROUND << 4));
}

void FundoTexto(int Cor)
{
     __BACKGROUND = Cor;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __FOREGROUND + (Cor << 4));
}

void *Envia(void *threadid)
{
     do {
         if (BREAK==1) {
            break;
         }
         Transfer_Data data;
         char nome[255];
         cin.getline(nome, 255);
         sprintf(data.char1, nome);
         data.comando = 1;
         send(s, (char*)&data, sizeof(data), 0);
     } while(1);
     pthread_exit(NULL);
}

void Dados(char* buffer) {
     Transfer_Data* data = (Transfer_Data*)buffer;
     switch(data->comando) {
         case 1:
             CorTexto(CINZA);
             cout << "Chat: " << data->char1 << endl;
             CorTexto(BRANCO);
             break;
         case 2:
             CorTexto(AZUL);
             cout << "Server: " << data->char1 << endl;
             CorTexto(BRANCO);
             break;
         case 3:
             CorTexto(VIOLETA);
             cout << "Private: " << data->char1 << endl;
             CorTexto(BRANCO);
             break;
         case 4:
             CorTexto(TURQUESA);
             cout << "Guild: " << data->char1 << endl;
             CorTexto(BRANCO);
             break;
         case 5:
             CorTexto(TURQUESA_ESCURO);
             cout << "Party: " << data->char1 << endl;
             CorTexto(BRANCO);
             break;
         default:
             //
             break;
     }
}

int main(int argc, char *argv[])
{
    WSADATA w;
	int error = WSAStartup (0x0202,&w);
	if (error) {
		MessageBox(NULL,"Error: You need WinSock 2.2!","Error",MB_OK);
		return EXIT_SUCCESS;
	}
	if (w.wVersion!=0x0202) {
		MessageBox (NULL,"Error:  Wrong WinSock version!","Error",MB_OK);
		WSACleanup();
		return EXIT_SUCCESS;
	}
    CorTexto(VERMELHO);
	cout << "Simulador de conexao criado por DougM" << endl;
    CorTexto(BRANCO);
    char ipdig[80];
    if (argc > 1) {
        strcpy(ipdig, argv[1]);
    } else {
        CorTexto(AMARELO);
        cout << "Digite o IP ao qual deseja se conectar" << endl;
        cin.getline(ipdig, 80);
        CorTexto(BRANCO);
    }

	s = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(5001);
    target.sin_addr.s_addr = inet_addr(ipdig);
    if (connect(s, (SOCKADDR*)&target, sizeof(target)) == SOCKET_ERROR) {
       MessageBox(NULL,"Error:  Nao foi possivel se conectar!","Error",MB_OK);
       WSACleanup();
       return EXIT_SUCCESS;
    }

    Transfer_Data data;
    char nome[255];
    char senha[255];
    if (argc > 2) {
       strcpy(nome, argv[2]);
    } else {
       CorTexto(VERDE);
       cout << "Digite seu login: ";
       cin.getline(nome, 255);
    }
    if (argc > 3) {
       strcpy(senha, argv[3]);
    } else {
       CorTexto(VERDE);
       cout << "Digite sua senha: ";
       cin.getline(senha, 255);
    }
    CorTexto(BRANCO);
    sprintf(data.char1, nome);
    sprintf(data.char2, senha);
    data.comando = 2;
    send(s, (char*)&data, sizeof(data), 0);

    system("CLS");

    char character[255];
    CorTexto(VERDE);
    cout << "Selecione um Character: ";
    cin.getline(character, 255);
    Transfer_Data data2;
    data2.comando = 3;
    data2.int1 = atoi(character);
    send(s, (char*)&data2, sizeof(data2), 0);

    pthread_t th[1];
    pthread_create(&th[1], NULL, Envia, (void *)1);

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
			cout << "A funcao \"select\" falhou... Erro: ";
		}
		if (atividade > 0) {
		   if (FD_ISSET(s, &fds)) {
              int recebido = recv(s,buffer,sizeof(buffer),0);
              if (recebido <= 0) {
                 closesocket(s);
                 BREAK=1;
                 break;
              } else {
                 Dados(buffer);
              }
           }
        }
    } while(1);
    cout << "Voce foi desconectado!" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
