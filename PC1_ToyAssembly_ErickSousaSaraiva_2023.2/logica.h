#ifndef LOGICA_H
#define LOGICA_H
#define TAMANHO 100
#include "controle.h"
extern int linhas;
extern int registro[32];
extern char opcode[100];
extern int indiceRegistroX;
extern int indiceRegistroY;
extern int indiceRegistroZ;
void comparacao(char linha[TAMANHO], int *linhas);
void jump(char linha[TAMANHO], int *linhas);
#endif