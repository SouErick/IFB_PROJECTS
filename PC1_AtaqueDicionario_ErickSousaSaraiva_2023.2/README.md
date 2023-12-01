*INSTITUTO FEDERAL DE BRASÍLIA (CAMPUS TAGUATINGA)*\
*PROFESSOR: DANIEL SAAD*\
*ALUNO: ERICK SOUSA SARAIVA*\
*DATA: 22/11/2023*\
*DISCIPLINA: PROGRAMAÇÃO DE COMPUTADORES I*\

# Projeto "Ataque de dicionário"

Este projeto implementa um sistema de quebra de senhas que utiliza criptografia SHA-256 e senhas fracas predefinidas. O sistema lê informações de usuários e senhas fracas a partir de arquivos, realiza a quebra das senhas e gera um relatório de saída.

## Estrutura do Projeto

O projeto é organizado em vários arquivos C, cada um contendo funções específicas. Abaixo está a descrição de cada arquivo:

- **criptografico.c:** Contém funções relacionadas à criptografia SHA-256, incluindo a geração e verificação de hashes.

- **leitura.c:** Lida com a leitura de informações de usuários e senhas fracas a partir de arquivos.

- **quebra.c:** Implementa a lógica para quebrar as senhas utilizando as informações de usuários e senhas fracas.

- **saida.c:** Responsável pela geração do relatório de saída.

- **main.c:** Arquivo principal que coordena a execução do programa, lê os usuários e senhas, realiza a quebra e gera o relatório final.

## Compilação e Execução

O projeto utiliza a biblioteca OpenSSL para operações criptográficas. Certifique-se de ter a biblioteca instalada no seu sistema. 
```bash
sudo apt-get install libssl-dev
```
Para compilar o projeto, execute o seguinte comando:
```bash
make
./main <arquivo_entrada1> <arquivo_entrada2> <arquivo_entrada3>
make clean (para remover a pasta objeto)
