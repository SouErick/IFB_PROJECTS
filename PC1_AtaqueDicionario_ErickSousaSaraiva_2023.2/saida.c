#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "criptografico.h"
#include "quebra.h"
#include "saida.h"
#include <openssl/sha.h>
void saida(Usuario *usuarios, int numero_de_usuarios, char *arquivo) // Função que gerará o relatório 
{
    FILE *fp = fopen(arquivo, "w"); // Abrindo o arquivo e criando.
    for (int i = 0; i < numero_de_usuarios; i++)
    {
        if (usuarios[i].senha_quebrada[0] != '\0') // Verificar se a senha do usuário foi quebrada, se a senha não está vazia, ela foi quebrada.
        {
            // Escrevendo no relatório os campos que devem ser mostrados, ou seja, o login, senha quebrada, nome e o ultimo acesso.
            fprintf(fp, "%s\n%s\n", usuarios[i].login, usuarios[i].senha_quebrada);
            fprintf(fp, "%s\n%s\n---\n", usuarios[i].nome, usuarios[i].ultimo_acesso);
        }
    }
    fclose(fp);
}
