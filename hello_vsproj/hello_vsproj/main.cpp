//
// mai.cpp : Ӧ�ó�����ڵ�
//

#include <iostream>

#include "glew.h"
#include "glut.h"   // glut.h������GL/GL.h��GL/GLU.h

using namespace std;

/*
* ���OpenGL��Ϣ
*/
void printInfo()
{
    // ���ظ���ǰOpenGLʵ�ֳ��̵�����  
    const GLubyte* strVendor = glGetString(GL_VENDOR);
    // ����һ����Ⱦ����ʶ����ͨ���Ǹ�Ӳ��ƽ̨
    const GLubyte* strRenderer = glGetString(GL_RENDERER);
    // ���ص�ǰOpenGLʵ�ֵİ汾�� 
    const GLubyte* strGLVersion = glGetString(GL_VERSION);

    cout << "OpenGLʵ�ֳ��̵����֣�" << strVendor << "\n";
    cout << "��Ⱦ����ʶ����" << strRenderer << "\n";
    cout << "OpenGL�汾�ţ�" << strGLVersion << '\n';
}

/*
* ��Ⱦͼ��
*/
void renderScene()
{
    // �����GL_COLOR_BUFFER_BIT��ʾ�����ɫ
    glClear(GL_COLOR_BUFFER_BIT);
    // ������ɫ�����������ֱ�ΪRGB
    glColor3f(0.0f, 1.0f, 1.0f);
    // ���ƾ���
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    // ��֤ǰ���OpenGL��������ִ�У��������������ڻ������еȴ���
    glFlush();
}

int main(int argc, char* argv[])
{
    // ��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��
    // ���������в������Ƴ�����glut�Ĳ���
    glutInit(&argc, (char**)argv);

    // ������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ��GLUT_SINGLE��ʾʹ�õ�����
    glutInitDisplayMode(GLUT_RGBA);
    // ���ô��ڴ�С
    glutInitWindowSize(512, 512);
    // ���ô�������Ļ�е�λ��
    glutInitWindowPosition(300, 300);

    //glutInitContextVersion(4, 3);
    //glutInitContextProfile(GLUT_CORE_PROFILE);

    // ����ǰ�����õ���Ϣ��������
    glutCreateWindow("Hello OpenGL");

    // �Զ��庯������ӡOpenGL��Ϣ
    printInfo();


    // �����л�ͼʱ�����ݵĺ����ᱻ����
    //glutDisplayFunc(&renderScene);
    // ����һ����Ϣѭ�����ȴ����ڹرպ�Ż᷵��
    //glutMainLoop();

    if (glewInit()) {
        cerr << "Unable to init GLEW ... exiting" << endl;
        exit(EXIT_FAILURE);
    }

    //init();

    glutDisplayFunc(renderScene);

    glutMainLoop();

    return 0;
}