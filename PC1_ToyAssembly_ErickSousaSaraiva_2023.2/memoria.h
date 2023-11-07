#ifndef MEMORIA_h
#define MEMORIA_h
#define TAMANHO 100
extern int linhas;
extern int registro[32];
extern char opcode[100];
extern int indiceRegistroX;
extern int indiceRegistroY;
extern int indiceRegistroZ;
void mov(char linha[TAMANHO]);
void load(char linha[TAMANHO]);
void store(char linha[TAMANHO]);
#endif