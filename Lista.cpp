#include "Lista.h"
#include "gotoxy.h"
Lista::Lista() {
    head=nullptr;
    pos=5;
    id=1;
    }

Lista::~Lista() {
    if(head!=nullptr) {
        Nodo *temp=head->next;
        Nodo *temp2;
        while(temp!=head) {
            temp2=temp;
            temp=temp->next;
            delete temp2;
            }
        delete head;
        }
    }

void Lista::insertarPrimero(Cancion cancion) {
    Nodo *nuevo=new Nodo();
    nuevo->song= cancion;
    nuevo->song.pos= this->pos;
    pos++;
    if(head == nullptr) {
        nuevo->next=nuevo;
        nuevo->prev= nuevo;
        head=nuevo;
        }
    else {
        Nodo *last = head->prev;
        nuevo->next=head;
        nuevo->prev=last;
        head->prev=nuevo;
        last->next=nuevo;
        head=nuevo;
        }
    actual=nuevo;

    }

void Lista::insertarUltimo(Cancion cancion) {
    Nodo *nuevo= new Nodo();
    nuevo->song = cancion;
    nuevo->song.pos= this->pos;
    nuevo->song.setID(id++);
    pos++;
    if(head==nullptr) {
        nuevo->next=nuevo;
        nuevo->prev=nuevo;
        head=nuevo;
        }
    else {
        Nodo *last = head->prev;
        nuevo->next=head;
        nuevo->prev=last;
        head->prev=nuevo;
        last->next=nuevo;
        }
    actual=nuevo;
    }

bool Lista::isEmpty() {
    if(head==nullptr) {
        return true;
        }
    else {
        return false;
        }
    }

void Lista::desplegar() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!isEmpty()) {
        int n(5),a;
        int id(1);
        Nodo *temp=head;
        SetConsoleTextAttribute(hConsole, 13);
        gotoxy(46, actual->song.pos);
        cout<<"->";
        SetConsoleTextAttribute(hConsole, 15);
        Cancion cancion;
        do {
            cancion =temp->song;
            SetConsoleTextAttribute(hConsole, 14);
            gotoxy(50,2);
            for(int i=48; i<=130; i++)
                cout<<"-";
            SetConsoleTextAttribute(hConsole, 15);



            gotoxy(50, 3);
            cout<< "ID  |   Nombre      Artista      Album      Genero      Direccion";
            if(n == actual->song.pos)
                SetConsoleTextAttribute(hConsole, 13);

            gotoxy(50, n);
            cout<<id<<"   |";
            gotoxy(58, n);
            cout<<cancion.getNombre();
            gotoxy(70, n);
            cout<<cancion.getAutor();
            gotoxy(85, n);
            cout<<cancion.getAlbum();
            gotoxy(98, n);
            cout<<cancion.getGenero();
            gotoxy(112, n);
            cout<<cancion.getDireccion();
            SetConsoleTextAttribute(hConsole, 15);
            temp=temp->next;
            n++;
            id++;

            }
        while(temp!= head);
        gotoxy(50,n+1);
        for(int i=48; i<=130; i++)
            cout<<"-";



        }
    else {
        gotoxy(50,5);
        cout<< "La lista esta vacia"<<endl;
        }
    }

int Lista::travel() {
    int contador=0;
    if(!isEmpty()) {
        Nodo *temp=head;
        do {
            contador++;
            temp=temp->next;
            }
        while(temp!=head);
        }
    return contador;
    }

void Lista::eliminar(const int& posicion) {
    if(posicion<=travel()) {
        if(posicion==1) {
            if(travel()==1) {
                delete head;
                head=nullptr;
                }
            else {
                Nodo *tempo = head;
                Nodo *last =head->prev;
                head=head->next;
                last->next=head;
                head->prev=last;
                delete tempo;
                }
            }
        else {
            Nodo *temp=head;
            for(int i=1; i<=posicion; i++) {
                temp=temp->next;
                }
            Nodo *tempo=temp;
            Nodo *anterior=temp->prev;
            temp=temp->next;
            anterior->next=temp;
            temp->prev=anterior;
            delete tempo;
            }
        }
    actualizarPos();
    }

Cancion Lista::buscar(const int& posicion) {
    Nodo *temp =head;
    for(int i =1; i<=posicion; i++) {
        temp=temp->next;
        }
    return temp->song;
    }

/*void Lista::modificar(const int& posicion, Cancion cancion){
    Nodo *temp =head;
    for (int i =1; i<=posicion; i++){
        temp=temp->next;
    }
    int pos =temp->song.pos;
    temp->song =cancion;
    temp->song.pos=pos;
    actualizarPos();
}*/
void Lista::modificar(int id, Cancion c) {
    //if(!this->isEmpty()) {
        Nodo* aux(head);
        int pos ;
        cout<<"a"<<endl;

        do {
                cout<<"Id: "<<id<<"  id aux: "<<aux->song.getID()<<endl;
            if(aux->song.getID() == id) {
                pos=aux->song.pos;
                aux->song=c;
                aux->song.pos=pos;
                cout<<"x"<<endl;
                return;
                }
                 cout<<"b"<<endl;
            aux=aux->next;
            }
        while(aux!=head);
        cout<<"c"<<endl;
           /* int pos=actual->song.pos;

            this->actual->song=c;

                actual->song.pos=pos;*/
       // }
    }

void Lista::imprimir(int puntero, Cancion cancion) {
    Nodo* temp = head;
    if(puntero <= travel() && puntero>=1) {
        if(puntero==1) {
            if(travel()==1) {
                cancion = temp->song;
                gotoxy(60,15);
                cout<<"Nombre: " << cancion.getNombre();
                gotoxy(60,16);
                cout<<"Artista: " << cancion.getAutor();
                gotoxy(60,17);
                cout<<"Album: " << cancion.getAlbum();
                gotoxy(60,18);
                cout<<"Genero: " << cancion.getGenero();
                }
            else {
                cancion = temp->song;
                gotoxy(60,15);
                cout<<"Nombre: " << cancion.getNombre();
                gotoxy(60,16);
                cout<<"Artista: " << cancion.getAutor();
                gotoxy(60,17);
                cout<<"Album: " << cancion.getAlbum();
                gotoxy(60,18);
                cout<<"Genero: " << cancion.getGenero();
                }
            }
        else {
            for(int i=1; i<puntero; i++) {
                temp = temp->next;
                cancion = temp->song;
                }
            gotoxy(60,15);
            cout<<"Nombre: " << cancion.getNombre();
            gotoxy(60,16);
            cout<<"Artista: " << cancion.getAutor();
            gotoxy(60,17);
            cout<<"Album: " << cancion.getAlbum();
            gotoxy(60,18);
            cout<<"Genero: " << cancion.getGenero();
            }
        }

    }

void Lista:: imprimirActual() {
    gotoxy(70, 20);
    cout<<"Nombre: " <<actual->song.getNombre();
    gotoxy(70, 21);
    cout<< "Artista: "<<actual->song.getAutor();
    gotoxy(70, 22);
    cout<< "Album: "<<actual->song.getAlbum();
    gotoxy(70, 23);
    cout<< "Genero: "<<actual->song.getGenero();
    }

void Lista::play() {
    string temp=actual->song.getDireccion();
    string d;
    for(int i=0; i<temp.length(); i++) {
        d+=temp[i];
        if(temp[i]== '\\') {
            d+='\\';
            }
        const char* dir=d.c_str();
        system(dir);
        }
    }

void Lista::siguiente() {
    actual=actual->next;
    }

void Lista::anterior() {
    actual=actual->prev;
    }

void Lista::reproducir() {
    string s=actual->song.getDireccion();
    int n= s.length();
    char char_array[n+1];
    strcpy(char_array, s.c_str());
    for(int i=0; i<n; i++) {
        cout<< char_array[i];
        }

    PlaySound(TEXT(char_array), NULL, SND_FILENAME | SND_ASYNC);
    }

void Lista:: llenar() {
    Cancion cancion;
    string nombre= "Gods plan";
    string artista= "Drake";
    string album= "Scorpion";
    string genero="Rap";
    cancion.setNombre(nombre);
    cancion.setAutor(artista);
    cancion.setAlbum(album);
    cancion.setGenero(genero);
    cancion.setDireccion("7-GodsPlan.wav");
    this->insertarUltimo(cancion);

    string nombre1 ="Sunflower";
    string artista1= "Post Malone";
    string album1= "SpiderMan";
    string genero1= "Hip Hop";
    cancion.setNombre(nombre1);
    cancion.setAutor(artista1);
    cancion.setAlbum(album1);
    cancion.setGenero(genero1);
    cancion.setDireccion("6-Sunflower.wav");
    this->insertarUltimo(cancion);

    string nombre2= "Without me";
    string artista2="Eminem";
    string album2="Eminem show";
    string genero2="Rap";
    cancion.setNombre(nombre2);
    cancion.setAutor(artista2);
    cancion.setAlbum(album2);
    cancion.setGenero(genero2);
    cancion.setDireccion("3-WithoutMe.wav");
    this->insertarUltimo(cancion);

    string nombre3= "Solia";
    string artista3="Bad Bunny";
    string album3="YHLQMDLG";
    string genero3="Reggaeton";
    cancion.setNombre(nombre3);
    cancion.setAutor(artista3);
    cancion.setAlbum(album3);
    cancion.setGenero(genero3);
    cancion.setDireccion("1-Solia.wav");
    this->insertarUltimo(cancion);

    string nombre4= "Un millon de primaveras";
    string artista4="Vicente Fernandez";
    string album4="Para siempre";
    string genero4="Mariachi";
    cancion.setNombre(nombre4);
    cancion.setAutor(artista4);
    cancion.setAlbum(album4);
    cancion.setGenero(genero4);
    cancion.setDireccion("8-UnMillonDePrimaveras.wav");
    this->insertarUltimo(cancion);

    }

void Lista::invertir() {
    if(head!=nullptr) {
        Nodo *prevNodo =head;
        Nodo *temp=head;
        Nodo *curNodo= head->next;

        prevNodo->next=prevNodo;
        prevNodo->prev=prevNodo;
        while(curNodo != head) {
            temp=curNodo->next;
            curNodo->next=prevNodo;
            prevNodo->prev=curNodo;
            head->next=curNodo;
            prevNodo =curNodo;
            curNodo =temp;
            }

        head=prevNodo;
        actualizarPos();
        }
    }
void Lista::actualizarPos() {

    Nodo *index(head);
    int i(5),id(1);
    do {
        index->song.pos=i;
        index->song.setID(id);
        index=index->next;
        id++;
        i++;
        }
    while(index!=head);

    actual=head;
    this->desplegar();
    }
