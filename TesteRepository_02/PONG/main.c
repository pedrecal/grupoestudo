#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_X 600
#define TAM_MAX_Y 400

GLint movebola=0;
GLint direcao=1;

void Inicializa(void);
void Desenha(void);
void Bola(GLint frame);
void Teclado(unsigned char tecla, GLint x, GLint y);

void Inicializa(void) {
  glClearColor(0.5, 1.0, 0.8, 0.0); //Especifica cor de fundo
  glOrtho (0, TAM_MAX_X, 0, TAM_MAX_Y, -1 ,1); //Sistema de referência: glOrtho(Xmin, Xmax, Ymin, Ymax, Zmin, Zmax)
}

void Desenha(void) {
  glClear(GL_COLOR_BUFFER_BIT); //Ordena a limpeza do buffer de cor vigente e o preenche com a cor de fundo
  glColor3ub(255, 255, 127);  //Especifica a cor de desenho como um inteiro sem sinal de 8 bits
  glLineWidth(40.0);
  glBegin(GL_LINE_LOOP);
        glVertex2i(2,2);  glVertex2i(599,2);
        glVertex2i(599,399); glVertex2i(2,399);
  glEnd();
  glColor3ub(0, 0, 0); //Especifica o início de nova cor de desenho
  glBegin(GL_LINES); //jogadores
        glVertex2i(100,190);  glVertex2i(100,240);
        glVertex2i(500,190);  glVertex2i(500,240);
  glEnd();
  glColor3ub(255, 255, 255);
  glPointSize(15.0);
  glBegin(GL_POINTS);
        glVertex2i(movebola+200,210);
  glEnd();
  //glFlush(); //Buferrização simples
  glutSwapBuffers();//Buferização dupla
 }

void Teclado(unsigned char tecla, GLint x, GLint y) {
  switch (tecla) {
  case 27: //ESC
	exit(0);
	break;
  case 'A':
    printf("Apertou-se A\n");
    break;
  }
}

void Bola(int frame) {
//    printf("Frame = %d\n",frame++);
    if (direcao==1) {
       movebola += 1;
       if (movebola==290) direcao = 0;
    } else {
           movebola -= 1;
           if(movebola==-90) direcao = 1;
      }
    glutPostRedisplay();
    glutTimerFunc(10,Bola, frame);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (TAM_MAX_X, TAM_MAX_Y);
  glutInitWindowPosition (500, 20); //Canto superior esquerdo
  glutCreateWindow ("PONG");
  Inicializa();
  glutDisplayFunc(Desenha);
  glutTimerFunc(30,Bola,0);
  glutKeyboardFunc(Teclado);
  //glutMouseFunc(Mouse);
  glutMainLoop();
  return 0;
}
