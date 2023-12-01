#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "criptografico.h"
#include "quebra.h"
#include "saida.h"
#include <openssl/sha.h>
Usuario *Arquivo_Usuarios(char *arquivo, int *numero_de_usuarios) // Aqui está leitura do arquivo "usuarios.txt".
{
    FILE *fp = fopen(arquivo, "r"); // Abre o arquivo. * é o ponteiro para o arquivo.
    Usuario *usuarios = NULL; // Basicamente usando o bloco de cada usuários na struct Usuario. Começando com NULL para indicar que nenhum bloco de usuário foi escolhido.
    Usuario usuario; // A variável usuário usará a estrutura da struct Usuario. No do-while o bloco usuário será destrinchado em vários campos.
    int contador = 0;
    do
    {
        if (strlen(usuario.senha) == SHA256_DIGEST_LENGTH * 2) // Garante que a senha de um usuário esteja representada como um hash SHA-256 em formato de bytes, independentemente se ela foi originalmente fornecida nesse formato ou não. 
        // Isso é útil para garantir consistência nos dados e facilitar comparações futuras, por exemplo, se o usuário colocar uma senha não cryptada esse bloco fará a criptação em SHA-256.
        // Verifica se o comprimento da senha na estrutura do usuário é igual ao dobro do comprimento esperado de um hash SHA-256.
        {
            converter(usuario.senha, usuario.senha_criptografada); // Se verdadeiro, assume que a senha já está no formato hexadecimal e usa a função converter para transformá-la em bytes.
        }
        else
        {
            sha256(usuario.senha, usuario.senha_criptografada); // Caso contrário, recalcula o hash da senha usando a função sha256.
        }
        Usuario *memoria_temporaria = (Usuario *)realloc(usuarios, (contador + 1) * sizeof(Usuario)); // Aqui o realloc tenta alocar memória para um número de usuários igual a contador + 1.
        // (Usuario *)realloc(usuarios, (contador + 1) * sizeof(Usuario)) realloc - realocar memória previamente alocada dinamicamente, (contador + 1) * sizeof(Usuario) - calcula o novo tamanho necessário para armazenar contador + 1 na estruturas Usuario.
        if (memoria_temporaria == NULL) // Caso tratamento de erro, por se tratar de alocação dinâmica de memória é bom ter a presença de um free e fechar o arquivo, para assim não "arruinar" o sistema.
        {
            free(usuarios);
            fclose(fp);
            return NULL;
        }
        usuarios = memoria_temporaria; // Usuarios é atualizado, ou seja, um novo usuário e seu bloco será destrinchado no começo.
        usuarios[contador++] = usuario; // Em seguida, contador é incrementado para preparar a próxima posição para um possível novo usuário. Este processo é repetido enquanto houver usuários a serem lidos do arquivo.
    } while (fscanf(fp, "%50[^\n]\n%10[^\n]\n%20[^\n]\n%64[^\n]\n%10[^\n]\n---\n",
                    usuario.nome, usuario.data_nascimento, usuario.login,
                    usuario.senha, usuario.ultimo_acesso) == 5); // Fazendo a separçaõ de cada campo para verificar se os dados do usuário seguem o padrão nome, data de nascimento, login, senha e ultimo acesso.
    fclose(fp); // Fechando o arquivo.
    *numero_de_usuarios = contador; // O valor de contador indica quantos usuários já foram lidos do arquivo.
    return usuarios; // Retorna o ponteiro usuarios agora aponta para a estrutura de dados que contém os usuários lidos do arquivo.
}
Senhas_Fracas *Arquivo_Senhas(char *arquivo, int *numero_de_senhas) // Aqui está a leitura do arquivo "senhas_fracas.txt"
{
    FILE *fp = fopen(arquivo, "r"); // Abre o arquivo. * é o ponteiro para o arquivo.
    Senhas_Fracas *senhas = NULL; // Basicamente usando o bloco de senhas fracas na struct Senhas_Fracas. Começando com NULL para indicar que nenhuma senha foi escolhida.
    Senhas_Fracas senha;
    int contador = 0;
    do
    {
        Senhas_Fracas *memoria_temporaria = (Senhas_Fracas *)realloc(senhas, (contador + 1) * sizeof(Senhas_Fracas)); // Tenta realocar dinamicamente memória para acomodar mais uma senha na estrutura de dados senhas.
        if (memoria_temporaria == NULL)
        {
            free(senhas);
            fclose(fp);
            return NULL;
        }
        senhas = memoria_temporaria;
        senhas[contador++] = senha;
    } while (fscanf(fp, "%50[^\n]\n", senha.senha) == 1); // Fazendo a separação de cada campo para verificar se os dados da seguem o padrão que é apenas a senha..
    fclose(fp);
    *numero_de_senhas = contador;
    return senhas;
}