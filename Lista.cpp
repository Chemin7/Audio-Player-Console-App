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


void Lista::insertarUltimo(Cancion cancion) {
    Nodo *nuevo=new Nodo();

    nuevo->song= cancion;
    nuevo->song.pos= this->pos;
    nuevo->song.setID(id++);
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

            gotoxy(50,2);
            for(int i=48; i<=130; i++)
                cout<<"-";




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
            for(int i=1; i<=posicion-1; i++) {
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

void Lista::modificar(int id, Cancion c) {
    if(!this->isEmpty()) {
        Nodo* aux(head);
        int pos ;

        do {

            if(aux->song.getID() == id) {
                pos=aux->song.pos;
                aux->song=c;
                aux->song.pos=pos;

                return;
                }
            cout<<"b"<<endl;
            aux=aux->next;
            }
        while(aux!=head);

        }
    }
/*
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

    }*/

void Lista:: imprimirActual() {
    gotoxy(70, 20);
    cout<<"Nombre: " <<actual->song.getNombre();
    gotoxy(70, 21);
    cout<< "Artista: "<<actual->song.getAutor();
    gotoxy(70, 22);
    cout<< "Album: "<<actual->song.getAlbum();
    gotoxy(70, 23);
    cout<< "Genero: "<<actual->song.getGenero();

    //actual->Obj(Flor);
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
    string nombre= "Spirit B.";
    string artista= "Yuna";
    string album= "Red";
    string genero="Instrumental";
    cancion.setNombre(nombre);
    cancion.setAutor(artista);
    cancion.setAlbum(album);
    cancion.setGenero(genero);
    cancion.setDireccion("spirit-blossom-15285.wav");
    this->insertarUltimo(cancion);

    string nombre1 ="slow trap";
    string artista1= "OHio";
    string album1= "PAlM";
    string genero1= "Trap";
    cancion.setNombre(nombre1);
    cancion.setAutor(artista1);
    cancion.setAlbum(album1);
    cancion.setGenero(genero1);
    cancion.setDireccion("slow-trap-18565.wav");
    this->insertarUltimo(cancion);

    string nombre2= "Let it go";
    string artista2="Elsa";
    string album2="Frozen";
    string genero2="Disney";
    cancion.setNombre(nombre2);
    cancion.setAutor(artista2);
    cancion.setAlbum(album2);
    cancion.setGenero(genero2);
    cancion.setDireccion("let-it-go-12279.wav");
    this->insertarUltimo(cancion);

    string nombre3= "into the night";
    string artista3="Good Blue";
    string album3="QWERTY";
    string genero3="instrument";
    cancion.setNombre(nombre3);
    cancion.setAutor(artista3);
    cancion.setAlbum(album3);
    cancion.setGenero(genero3);
    cancion.setDireccion("into-the-night.wav");
    this->insertarUltimo(cancion);

    string nombre4= "Ever Flowing";
    string artista4="PIsck";
    string album4="For ever";
    string genero4="Instument";
    cancion.setNombre(nombre4);
    cancion.setAutor(artista4);
    cancion.setAlbum(album4);
    cancion.setGenero(genero4);
    cancion.setDireccion("ever-flowing.wav");
    this->insertarUltimo(cancion);
    Nodo* aux(head);

    }

void Lista::invertir() {

    if(head != NULL) {
        Nodo* prevNode = head;
        Nodo* tempNode = head;
        Nodo* curNode = head->next;


        prevNode->prev = prevNode;

        while(curNode != head) {

            tempNode = curNode->next;

            curNode->next = prevNode;
            prevNode->prev = curNode;
            head->next = curNode;
            curNode->prev = head;

            prevNode = curNode;
            curNode = tempNode;
            }

        head = prevNode;
        actual= prevNode;
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
Lista::Nodo* Lista::getLast() {
    return head->prev;
    }

Lista::Nodo* Lista::getFirst() {
    return head;
    }

void Lista::reproductor()
{
     char soundfile1[]="open \"C:/Users/user/Downloads/spirit-blossom-15285.mp3\" type mpegvideo alias mp3";
   string meh;
   int opc;
   //open \"C:/SEDDI/musicProject/1x1.mp3\" type mpegvideo alias mp3
   //cin.sync();
   //getline(cin,meh);
   //strcpy(soundfile1,meh.c_str());
   mciSendString((LPCSTR)soundfile1, NULL, 0, NULL);
   mciSendString("play mp3", NULL, 0, NULL);
    gotoxy(1, 16);
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
