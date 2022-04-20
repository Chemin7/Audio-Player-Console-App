#include "Cancion.h"


void Cancion::setID(const int& i){
    id=i;
}

void Cancion::setNombre(const string& name){
    nombre=name;
}

void Cancion::setAutor(const string& author){
    autor=author;
}

void Cancion::setAlbum(const string& al){
    album=al;
}

void Cancion::setGenero(const string& gen){
    genero=gen;
}

void Cancion::setDireccion(const string& direction){
    direccion=direction;
}

int Cancion::getID(){
    return id;
}

string Cancion::getNombre(){
    return nombre;
}

string Cancion::getAutor(){
    return autor;
}

string Cancion::getAlbum(){
    return album;
}

string Cancion::getGenero(){
    return genero;
}

string Cancion::getDireccion(){
    return direccion;
}

string Cancion::toString(){
    string impresion;

    impresion += "\nNombre: ";
    impresion += nombre;
    impresion += "\nAutor: ";
    impresion +=autor;
    impresion += "\nAlbum: ";
    impresion +=album;
    impresion += "\n Genero: ";
    impresion += genero;
    impresion += "\nDireccion: ";
    impresion += direccion;
    return impresion;
}
/*
Cancion& Cancion::operator=(Cancion& c)
{
    this->nombre=c.getNombre();
    this->autor=c.getAutor();
    this->album=c.getAlbum();
    this->genero=c.getDireccion();

    return *this;
}*/
