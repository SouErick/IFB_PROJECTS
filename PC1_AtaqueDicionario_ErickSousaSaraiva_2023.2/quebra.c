#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "criptografico.h"
#include "quebra.h"
#include "saida.h"
#include <openssl/sha.h>
void quebrar(Usuario *usuarios, int numero_de_usuarios, Senhas_Fracas *senha_fraca, int numero_de_senhas) // Função que vai "quebrar" a senha.
{
    for (int coluna = 0; coluna < numero_de_usuarios; coluna++) 
    {
        for (int percorrer_string = 0; percorrer_string < numero_de_senhas; percorrer_string++) // Percorrendo todas as senhas.
        {
            if (verifica(&usuarios[coluna], &senha_fraca[percorrer_string]) == 1) // Verificando se a senha do usuário é igual a senha fraca.
            {
                strncpy((char *)usuarios[coluna].senha_quebrada, senha_fraca[percorrer_string].senha, sizeof(usuarios[coluna].senha_quebrada)); // Senha foi quebrada, copie a senha fraca para o usuário.
                // / Cópia da senha quebrada da estrutura Senhas_Fracas para a estrutura Usuario, sendo copiada no campo "senha_quebrada".
                break;
            }
        }
    }
}
