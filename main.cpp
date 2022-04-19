#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Lista.h"
#include "Cancion.h"
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
        cout<< "[10] Salir"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        lista->desplegar();
        if(!lista->isEmpty()){
            lista->imprimirActual();
        }
        gotoxy(1, 12);
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
                    lista->siguiente();
                    break;
                case 4:
                    lista->anterior();
                    break;
                case 5:
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
                    break;
                case 6:
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
                        lista->modificar(id, cancion);
                        cout<< "Cancion actualizada correctamente"<<endl;
                        system("pause");
                        }
                    else {
                        noValor();
                        }
                    break;
                case 7:
                    lista->reproducir();
                    system("pause");
                    break;
                case 8:
                    lista->imprimirActual();
                    break;
                case 9:
                    lista->invertir();
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
    while(opc!=10);

    }


int main() {
    menu();
    return 0;
    }
