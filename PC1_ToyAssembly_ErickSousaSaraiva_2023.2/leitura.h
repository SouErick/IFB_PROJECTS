#ifndef LEITURA_H
#define LEITURA_H
#define TAMANHO 100
extern int linhas;
extern int registro[32];
extern char opcode[100];
extern int indiceRegistroX;
extern int indiceRegistroY;
extern int indiceRegistroZ;
void leitura(char matriz[TAMANHO][TAMANHO], int linhas);
#endif