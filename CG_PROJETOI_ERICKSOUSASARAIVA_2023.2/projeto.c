// INSTITUTO FEDERAL DE BRASÍLIA (TAGUATINGA)
// PROFESSOR: RAIMUNDO VASCONCELOS
// ALUNO: ERICK SOUSA SARAIVA
// DISCIPLINA: COMPUTAÇÃO GRÁFICA
// DATA: 04/11/2023
#include <GL/glut.h>
#include <stdlib.h>
// Configuração inicial do triângulo.
float rotacao = 0;
float escala = 1;
float posicaoX = 0.55; 
float posicaoY = 0.55; 
int sinal = 0;
/* Translação:
Ao pressionar a tecla t, transladar o objeto presente de uma determinada posição da janela para qualquer outra posição. 
Para isso, basta o usuário utilizar as teclas ↑, ↓,← e → para mover o objeto pela tela.
Rotação:
Ao pressionar a tecla r, rotacionar o objeto considerando seu centro de massa como o ponto fixo (de referência). 
O usuário deverá pressionar as teclas ↑ e ↓para rotacionar o objeto no sentido anti-horário e horário, respectivamente.
Escala:
Ao pressionar a tecla s, redimensionar o objeto considerando seu centro de massa como o ponto fixo (de referência). 
As teclas ↑ e ↓ incrementam ou diminuem as dimensões do objeto, respectivamente.
Espelhamento:
Ao pressionar a tecla m, espelhar o objeto em relação ao eixo z. 
Além disso, se o usuário pressionar a tecla i, o objeto deverá retomar suas configurações iniciais de posição e escala.
*/
// Função desenha, aqui desenharemos o triângulo.
void desenha() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(posicaoX, posicaoY, 0); // Função GL que faz a translação do objeto, será definida pelas variáveis posicaoX,Y ao pressionar "t".
    glRotatef(rotacao, 0, 0, 1); // Função GL que faz a rotação do objeto, será definida pelas variável rotacao ao pressionar "r".
    glScalef(escala, escala, 1); // Função GL que faz a escala do objeto, aumentando/diminuindo, será definida pela variável escala ao pressionar "s".
    glBegin(GL_TRIANGLES); // Desenhando o triângulo com os vértices.
        glColor3f(0.5, 0, 0.95);  // Cor roxa
        glVertex2f(0, 0.25);
        glVertex2f(-0.25, -0.25);
        glVertex2f(0.25, -0.25);
    glEnd();
    glutSwapBuffers();
}
void transformacoes(unsigned char tecla, int x, int y) 
// Função que contém as teclas especiais (t, r, s, m, i) que serão chamadas na main na função glutKeyboardFunc(unsigned char *, int *, int *).
{
    switch (tecla) 
    {
        case 't': // Translação:
            sinal = 1;
            break;
        case 'r': // Rotação:
            sinal = 2;
            break;
        case 's': // Escala: 
            sinal = 3;
            break;
        case 'm': // Espelhamento:
            posicaoX = -posicaoX; // Espelhamento do objeto em relação ao eixo z, ou seja, se o objeto estiver no lado esquerdo ele irá para o lado direito ao pressionar a tecla "m".
            break;
        case 'i': // Configuração resetada:
            rotacao = 0;
            escala = 1;
            posicaoX = 0.55;
            posicaoY = 0.55;
            break;
    }
    glutPostRedisplay();
}
void teclado(int tecla, int x, int y) // Nessa função o usuário irá fazer as alterações desejadas com as teclas ↑, ↓,← e →.
{
    switch (sinal) // Recebendo o sinal da tecla que o usuário pressionou "t" = 1, "r" = 2, "s" = 3.
    {
        case 1: // Transformação (translação):
            if (tecla == GLUT_KEY_LEFT)  // Movimentos no teclado, ↑, ↓,← e →.
            {
                posicaoX -= 0.1;
            }
            else if (tecla == GLUT_KEY_RIGHT) 
            {
                posicaoX += 0.1;
            }
            else if (tecla == GLUT_KEY_UP) 
            {
                posicaoY += 0.1;
            }
            else if (tecla == GLUT_KEY_DOWN) 
            {
                posicaoY -= 0.1;
            }
            break;
        case 2: // Transformação (rotação):          
            if (tecla == GLUT_KEY_UP)   // Movimentos no teclado, ↑ (sentido horário) e ↓ (sentido anti-horário). 
            {
                rotacao += 5;
            }
            else if (tecla == GLUT_KEY_DOWN)
            {
                rotacao -= 5;
            } 
            break;
        case 3: // Transformação (escala):
            if (tecla == GLUT_KEY_UP) // Movimentos no teclado, ↑ (aumenta escala) e ↓ (diminui escala). 
            {
                escala += 0.1;
            }
            else if (tecla == GLUT_KEY_DOWN) 
            {
                escala -= 0.1;
            }
            break;
    }
    glutPostRedisplay();
}
int main(int argc, char **argv)  // Função main
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projeto 1");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Definindo os limites/dimensões desse projeto.
    glutDisplayFunc(desenha);
    glutKeyboardFunc(transformacoes);
    glutSpecialFunc(teclado);
    glutMainLoop();
    return 0;
}