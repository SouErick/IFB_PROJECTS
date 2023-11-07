 INSTITUTO FEDERAL DE BRASÍLIA (TAGUATINGA)\
 PROFESSOR: RAIMUNDO VASCONCELOS\
 ALUNO: ERICK SOUSA SARAIVA\
 DISCIPLINA: COMPUTAÇÃO GRÁFICA\
 DATA: 04/11/2023
# Projeto de Computação Gráfica

Este é um projeto desenvolvido por Erick Sousa Saraiva como parte da disciplina de Computação Gráfica ministrada pelo professor Raimundo Vasconcelos no Instituto Federal de Brasília (Taguatinga).

## Objetivo
Este projeto consiste em criar um programa em OpenGL que permite ao usuário realizar transformações em um triângulo exibido na janela, incluindo translação, rotação, escala e espelhamento. O usuário pode controlar essas transformações por meio do teclado.

## Funcionalidades
O programa oferece as seguintes funcionalidades:

- **Translação:** Ao pressionar a tecla 't', o usuário pode transladar o objeto para qualquer posição da janela usando as teclas de seta (↑, ↓, ← e →).

- **Rotação:** Ao pressionar a tecla 'r', o objeto pode ser rotacionado no sentido anti-horário (tecla ↑) e horário (tecla ↓).

- **Escala:** Ao pressionar a tecla 's', o usuário pode redimensionar o objeto, aumentando (tecla ↑) ou diminuindo (tecla ↓) suas dimensões, mantendo o centro de massa como ponto de referência.

- **Espelhamento:** Ao pressionar a tecla 'm', o objeto é espelhado em relação ao eixo z. Pressionar a tecla 'i' retorna o objeto às configurações iniciais de posição e escala.

## Uso
Para executar o programa, siga as instruções abaixo:
1. Clone ou faça o download deste repositório.

2. Compile o código-fonte usando um compilador C/C++ que suporta a biblioteca OpenGL (GLUT). Certifique-se de que as bibliotecas OpenGL e GLUT estejam instaladas no seu sistema. Código compilação:
``` gcc -o triangulo triangulo.c -lglut -lGLU -lGL -lm```

4. Execute o programa.

5. Use as teclas 't', 'r', 's', 'm' e 'i' para aplicar as transformações desejadas no triângulo.

6. Use as teclas de seta (↑, ↓, ← e →) para controlar a direção das transformações de translação, rotação e escala, conforme aplicável.

