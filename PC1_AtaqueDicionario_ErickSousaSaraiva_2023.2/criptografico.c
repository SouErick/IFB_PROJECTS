#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "criptografico.h"
#include "quebra.h"
#include "saida.h"
#include <openssl/evp.h>
#include <openssl/sha.h>
void sha256(const char *senha, unsigned char *hash) // Função importada para manuseio do sha256 - OPENSSL - essa função função implementa o cálculo do hash SHA-256 de uma senha
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    for (size_t i = 0; i < strlen(senha); i++) // Loop através de cada caractere na senha.
    {
        if (senha[i] != '\n' && senha[i] != '\r') // Ignorando a quebra de linha e fazendo cada digito da senha ser "cryptada".
        {
            EVP_DigestUpdate(mdctx, &senha[i], 1);
        }
    }
    EVP_DigestFinal_ex(mdctx, hash, NULL);
    EVP_MD_CTX_free(mdctx);
}
void converter(const char *string_hash, unsigned char *conversao) // Converte uma representação hexadecimal de uma string de hash SHA-256 para um array de bytes. Útil para verificar se uma senha já foi cryptada
// e a comparação de hashes.
{
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sscanf(string_hash + 2 * i, "%2hhx", &conversao[i]); // Modelo usado para transformar cada par de digito da string Hexadecimal em um byte.
        // string_hash + 2 * i (deslocamento correto na string em hexadecimal) "%2hhx" (dois caracteres devem ser lidos e armazenando como um unsigned char).
    }
}
void criptografar_senhas(Usuario *usuarios, int numero_de_usuarios) // Calcula o hash SHA-256 de cada senha e armazena o resultado no campo senha_criptografada de cada usuário.
{
    for (int i = 0; i < numero_de_usuarios; i++)
    {
        sha256(usuarios[i].senha, (unsigned char *)usuarios[i].senha_criptografada); // Guardando o hash da senha do usuário na senha criptografada.
        // unsigned char * (Por se tratar de um SHA-256 está apontando na memória que o valor não poderá ser negativo, padrão de uso na criptografia de senhas em sistemas distintos).
    }
}
int verifica(Usuario *usuario, Senhas_Fracas *senha_fraca) // Função que vai verificar se a senha do usuário é igual a senha criptografada (senha fraca).
{
    unsigned char hash_da_senha[SHA256_DIGEST_LENGTH];
    sha256(senha_fraca->senha, hash_da_senha);
    if (memcmp(hash_da_senha, usuario->senha_criptografada, SHA256_DIGEST_LENGTH) == 0) // Memcmp para comparar os hashes. Se o hash da senha fraca e hash da senha do usuário, resultará em 0.
    {
        return 1; // Retorna 1 se os hashes coincidirem
    }
    return 0; // Retorna 0 se os hashes não coincidirem
}