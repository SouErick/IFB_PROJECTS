#ifndef LEITURA_H
#define LEITURA_H
typedef struct
{
    char nome[50];
    char data_nascimento[11];
    char login[50];
    char senha[65];
    char ultimo_acesso[11];
    unsigned char senha_criptografada[65];
    unsigned char senha_quebrada[65]; 
} Usuario;
typedef struct
{
    char senha[50];
} Senhas_Fracas;
Usuario *Arquivo_Usuarios(char *arquivo, int *numero_de_usuarios);
Senhas_Fracas *Arquivo_Senhas(char *arquivo, int *numero_de_senhas);
#endif