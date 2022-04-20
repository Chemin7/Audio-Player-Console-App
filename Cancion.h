#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Cancion{

    private:
        int id;
        string nombre;
        string autor;
        string album;
        string genero;
        string direccion;
    public:
        int pos;
        void setID(const int&);
        void setNombre(const string&);
        void setAutor(const string&);
        void setAlbum(const string&);
        void setGenero(const string&);
        void setDireccion(const string&);

        int getID();
        string getNombre();
        string getAutor();
        string getAlbum();
        string getGenero();
        string getDireccion();
        string toString();

        //Cancion& operator = (Cancion&);

};


#endif // CANCION_H_INCLUDED
