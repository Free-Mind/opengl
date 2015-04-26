//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ translate.cpp -o translate -lglut -lGL -lGLU
#include <GL/glut.h>
void mydisplay() // 画初始图形 箭头
{
 glClear(GL_COLOR_BUFFER_BIT); 
  glBegin(GL_POLYGON);
    glVertex2f( 0.0, 0.5);
    glVertex2f( 0.4, 0.2);
    glVertex2f( 0.2, 0.2);
    glVertex2f( 0.2,-0.4);
    glVertex2f(-0.2,-0.4);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.4, 0.2);
 glEnd(); 
 glFlush();
}
// 初始化变量
void init()
{
  glClearColor (1.0, 1.0, 0.0, 0.0);
 glColor3f(0.5, 0.5, 0.5);
 // 指定坐标系为投影矩阵方式
 glMatrixMode (GL_PROJECTION);
 // 将当前矩阵初始化为单位矩阵
 glLoadIdentity ();
    // 设置投影区域(左右上下近远)
 glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
}
void mymenu(int value)
{
 switch(value)
 {
 case 1:  glTranslatef(0.1,0.0,0.0); glutPostRedisplay();break;
 case 2:  glTranslatef(-0.1,0.0,0.0); glutPostRedisplay();break;
 case 3:  glTranslatef(0.0,0.1,0.0); glutPostRedisplay();break;
 case 4:  glTranslatef(0.0,-0.1,0.0); glutPostRedisplay();break;
 case 5:  glRotatef(30,0.0,0.0,1.0); glutPostRedisplay();break;
 case 6:  glScalef(0.5,0.5,0.0); glutPostRedisplay();break;
 case 7:  glScalef(2,2,0.0); glutPostRedisplay();break;
 case 0:  exit(0);
 }
}
int main(int argc, char** argv)
{
 
  glutInit(&argc,argv);  // 初始化glut库
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // 设置单缓冲和RGB色彩空间
 glutInitWindowSize(500,500); // 窗口大小
 glutInitWindowPosition(100,100);  // 设置窗口左上角在屏幕中的位置
 glutCreateWindow("");  // 建立窗口
 glutDisplayFunc(mydisplay); // 执行函数
 init(); // 设置opengl状态
 int id, newid; // 设置鼠标右键弹出菜单
 
 newid = glutCreateMenu(mymenu);
 glutAddMenuEntry("left", 1); // 加菜单项
 glutAddMenuEntry("right", 2); // 加菜单项
 glutAddMenuEntry("down", 3); // 加菜单项
 glutAddMenuEntry("up", 4); // 加菜单项
 
 id = glutCreateMenu(mymenu);
 glutAddMenuEntry("xuanzhuan", 5); // 加菜单项
  glutAddMenuEntry("suoxiao", 6); // 加菜单项
 glutAddMenuEntry("fangda", 7); // 加菜单项
 glutAddSubMenu("pingyi",newid);
 glutAddMenuEntry("exit", 0);
 glutAttachMenu(GLUT_RIGHT_BUTTON); // 附加菜单到鼠标右键
 // 循环执行
 glutMainLoop();
 return 0;
}
