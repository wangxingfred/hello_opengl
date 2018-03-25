//
// mai.cpp : 应用程序入口点
//

#include <iostream>

#include "glew.h"
#include "glut.h"   // glut.h包含了GL/GL.h和GL/GLU.h

using namespace std;

/*
* 输出OpenGL信息
*/
void printInfo()
{
    // 返回负责当前OpenGL实现厂商的名字  
    const GLubyte* strVendor = glGetString(GL_VENDOR);
    // 返回一个渲染器标识符，通常是个硬件平台
    const GLubyte* strRenderer = glGetString(GL_RENDERER);
    // 返回当前OpenGL实现的版本号 
    const GLubyte* strGLVersion = glGetString(GL_VERSION);

    cout << "OpenGL实现厂商的名字：" << strVendor << "\n";
    cout << "渲染器标识符：" << strRenderer << "\n";
    cout << "OpenGL版本号：" << strGLVersion << '\n';
}

/*
* 渲染图形
*/
void renderScene()
{
    // 清除，GL_COLOR_BUFFER_BIT表示清除颜色
    glClear(GL_COLOR_BUFFER_BIT);
    // 设置颜色，三个参数分别为RGB
    glColor3f(0.0f, 1.0f, 1.0f);
    // 绘制矩形
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    // 保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）
    glFlush();
}

int main(int argc, char* argv[])
{
    // 对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次
    // 处理命令行参数，移除控制glut的部分
    glutInit(&argc, (char**)argv);

    // 设置显示方式，其中GLUT_RGB表示使用RGB颜色，GLUT_SINGLE表示使用单缓冲
    glutInitDisplayMode(GLUT_RGBA);
    // 设置窗口大小
    glutInitWindowSize(512, 512);
    // 设置窗口在屏幕中的位置
    glutInitWindowPosition(300, 300);

    //glutInitContextVersion(4, 3);
    //glutInitContextProfile(GLUT_CORE_PROFILE);

    // 根据前面设置的信息创建窗口
    glutCreateWindow("Hello OpenGL");

    // 自定义函数，打印OpenGL信息
    printInfo();


    // 当进行画图时，传递的函数会被调用
    //glutDisplayFunc(&renderScene);
    // 进行一个消息循环，等待窗口关闭后才会返回
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