//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ test.cpp -o test -lglut -lGL -lGLU
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
using namespace std;



int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("第一个OpenGL程序");

	/* glOrtho2D(x1,y1,x2,y2)
	建立二维坐标系:(x1,y1)*/
	gluOrtho2D(-400,400,-300,300);
	glutDisplayFunc(&disPlay);
	glutMainLoop();
	return 0;
}
