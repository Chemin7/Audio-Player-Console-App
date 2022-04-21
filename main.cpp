#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Lista.h"
#include "Cancion.h"
#pragma comment(lib, "user32")
using namespace std;


Cancion cancion;
Lista *lista = new Lista();
void menu();
void imprimirActual();
void gotoxy(int x, int y);



void noValor() {
    cout<< "Ingrese un digito valido"<<endl;
    system("pause");
    system("cls");
    }

void menu() {
    ///Font
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y =14;                  // Height
    cfi.FontFamily = FF_DECORATIVE;//FF_DONTCARE
    cfi.FontWeight = FW_BOLD;
    std::wcscpy(cfi.FaceName, L"Biome"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
///---------------------------
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int id=1;
    int opc, num;
    int puntero=1;
    string aux;
    char opcion[100], numero[100];
    do {
        system("cls");

        SetConsoleTextAttribute(hConsole, 10);
        cout<< "---------- ESPORIFAY----------"<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout<< "[1] Llenar lista"<<endl;
        cout<< "[2] Ingresar cancion"<<endl;
        cout<< "[3] Siguiente"<<endl;
        cout<< "[4] Anterior"<<endl;
        cout<< "[5] Eliminar"<<endl;
        cout<< "[6] Modificar"<<endl;
        cout<< "[7] Reproducir cancion"<<endl;
        cout<< "[8] Mostrar cancion actual"<<endl;
        cout<< "[9] Invertir"<<endl;
        cout<< "[10] Obtener primero"<<endl;
        cout<< "[11] Obtener ultimo"<<endl;
        cout<< "[12] Reproductor"<<endl;
        cout<< "[13] Salir"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        lista->desplegar();
        if(!lista->isEmpty()){
            lista->imprimirActual();
        }
        gotoxy(1, 16);
        cout<< "Seleccione una opcion: ";
        cin>>opcion;
        if(opc=atoi(opcion)) {
            switch(opc) {
                case 1:
                    lista->llenar();
                    break;
                case 2:
                    cout<< "ID: "<< id<<endl;
                    cout<< "Nombre: "<<endl;
                    cin.sync();
                    getline(cin, aux);
                    cancion.setNombre(aux);
                    cout<< "Artista: ";
                    getline(cin, aux);
                    cancion.setAutor(aux);
                    cout<< "Album: ";
                    getline(cin, aux);
                    cancion.setAlbum(aux);
                    cout<< "Genero: ";
                    getline(cin, aux);
                    cancion.setGenero(aux);
                    cout<< "Ingrese direccion: ";
                    getline(cin, aux);
                    cancion.setDireccion(aux);

                    lista->insertarUltimo(cancion);
                    id++;
                    system("pause");
                    system("cls");
                    break;
                case 3:
                     if(!lista->isEmpty())
                    lista->siguiente();

                    break;
                case 4:
                     if(!lista->isEmpty())
                    lista->anterior();

                    break;
                case 5:
                    if(!lista->isEmpty()){
                    cout<< "Ingrese el ID que desea eliminar: ";
                    cin>>numero;
                    if(num=atoi(numero)) {
                        if(puntero==1) {

                            }
                        else {
                            puntero--;
                            }
                        cancion.setID(num);
                        lista->eliminar(num);
                        }
                        else {
                        noValor();
                        }
                    }

                    break;
                case 6:
                     if(!lista->isEmpty()){
                    cout<< "Ingrese el ID que desea modificar: ";
                    cin>>numero;
                    if(num=atoi(numero)) {
                        cout<< "Nombre nuevo: ";
                        cin.sync();
                        getline(cin, aux);
                        cancion.setNombre(aux);
                        cout<< "Artista nuevo: ";
                        getline(cin, aux);
                        cancion.setAutor(aux);
                        cout<< "Album nuevo: ";
                        getline(cin, aux);
                        cancion.setAlbum(aux);
                        cout<< "Genero nuevo: ";
                        getline(cin, aux);
                        cancion.setGenero(aux);
                        cout<< "Direccion nueva: ";
                        getline(cin, aux);
                        cancion.setDireccion(aux);
                        cancion.setID(num);
                        lista->modificar(num, cancion);
                        cout<< "Cancion actualizada correctamente"<<endl;
                        system("pause");
                        }
                        else {
                        noValor();
                        }
                     }

                    break;
                case 7:
                     if(!lista->isEmpty()){
                    lista->reproducir();
                    system("pause");
                     }
                    break;
                case 8:
                     if(!lista->isEmpty())
                    lista->imprimirActual();
                    break;
                case 9:
                    lista->invertir();
                    break;
                case 10:
                    cout<<lista->getFirst()->song.getNombre();
                    system("pause");
                    break;
                case 11:
                     cout<<lista->getLast()->song.getNombre();
                     system("pause");
                     break;
                case 12:
                    lista->reproductor();
                    break;
                case 0:
                    cout<< "Saliendo del programa"<<endl;
                    cout<< "Hasta luego"<<endl;
                    system("pause");
                    system("cls");
                    break;

                }
            }
        else {
            noValor();
            }
        }
    while(opc!=13);

    }
void reproductor(){
    char soundfile1[]="open \"C:/Users/user/Downloads/spirit-blossom-15285.mp3\" type mpegvideo alias mp3";
   string meh;
   int opc;
   //open \"C:/SEDDI/musicProject/1x1.mp3\" type mpegvideo alias mp3
   //cin.sync();
   //getline(cin,meh);
   //strcpy(soundfile1,meh.c_str());
   mciSendString((LPCSTR)soundfile1, NULL, 0, NULL);
   mciSendString("play mp3", NULL, 0, NULL);
   cout<<"escoje una"<<endl;
   cout<<"1.-Pause"<<endl<<"2.-continuar"<<endl<<"3.-detener"<<endl;
   do{
   cin>>opc;
   switch(opc)
   {
   case 1:
    {
        mciSendString("pause mp3", NULL, 0, NULL);
    }break;
   case 2:
    {
        mciSendString("resume mp3", NULL, 0, NULL);
    }break;
   case 3:
    {
        mciSendString("stop mp3", NULL, 0, NULL);
    }break;
   }
   }while(opc!=3);
   mciSendString("close mp3", NULL, 0, NULL);
   system("pause");
}

int main() {
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    menu();
    //reproductor();
    return 0;
    }
