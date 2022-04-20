#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
#include "Cancion.h"

class Lista{
    private:
        class Nodo{
            public:

                Cancion song;
                Nodo *next;
                Nodo *prev;
        };
        Nodo *head;
        Nodo *actual;
        int pos;
        int id;
        void actualizarPos();
    public:
        Lista();
        ~Lista();
        void insertarPrimero(Cancion);
        void insertarUltimo(Cancion);
        bool isEmpty();
        void desplegar();
        int travel();
        void siguiente();
        void anterior();
        void eliminar(const int&);
        Cancion buscar(const int&);
        //void modificar(const int&,Cancion);
        void modificar(int,Cancion);
        void imprimir(int,Cancion);
        void imprimirActual();
        void play();
        void reproducir();
        void llenar();
        void invertir();

};






#endif // LISTA_H_INCLUDED
