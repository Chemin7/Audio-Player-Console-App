#ifndef GOTOXY_H_INCLUDED
#define GOTOXY_H_INCLUDED
#include <windows.h>
#include <mmsystem.h>

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

#endif // GOTOXY_H_INCLUDED
