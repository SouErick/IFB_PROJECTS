#ifndef CRIPTOGRAFICO_H
#define CRIPTOGRAFICO_H
void sha256(const char *senha, unsigned char *hash);
void converter(const char *string_hash, unsigned char *conversao);
void criptografar_senhas(Usuario *usuarios, int numero_de_usuarios);
int verifica(Usuario *usuario, Senhas_Fracas *senha_fraca);
#endif