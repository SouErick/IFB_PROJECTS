// INSTITUTO FEDERAL DE BRASÍLIA (CAMPUS TAGUATINGA)
// PROFESSOR: DANIEL SAAD
// ALUNO: ERICK SOUSA SARAIVA
// DATA: 22/11/2023
// DISCIPLINA: PROGRAMAÇÃO DE COMPUTADORES I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "criptografico.h"
#include "quebra.h"
#include "saida.h"
#include <openssl/evp.h>
#include <openssl/sha.h>
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        return 1;
    }
    int numero_de_usuarios, numero_de_senhas;
    char *arquivo_saida = argv[3]; 
    // Arquivos que serão abertos.
    Usuario *usuarios = Arquivo_Usuarios(argv[1], &numero_de_usuarios);
    Senhas_Fracas *senhas = Arquivo_Senhas(argv[2], &numero_de_senhas);
    // Chamando as funções que serão usadas nesse código.
    quebrar(usuarios, numero_de_usuarios, senhas, numero_de_senhas);
    saida(usuarios, numero_de_usuarios, arquivo_saida);
    // Liberando a memória.
    free(usuarios);
    free(senhas);
    return 0;
}