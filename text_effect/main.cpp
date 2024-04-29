#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include <string>
#include "glutil.h"

using namespace std;


void rectangle(int R, int G, int B, float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);            // Draw a filled rectangle

    glColor3ub(R, G, B); // Set color

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}


void img()
{
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(13.0f, 0.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(0.0f, 8.0f);
    glEnd();

    ApplyTexture(0.0f, 0.0f, 13.0f, 0.0f,  13.0f, 8.0f, 0.0f, 8.0f, textures[0].textureID); // Adjusted texture coordinates

    glColor3ub(0, 255, 66);
    typedText(1,3,"AIUB was established in 1994 in Dhaka, Bangladesh as AMA International University Bangladesh, a joint \nventure between AMA Computer University of the Philippines, and local initiator Anwarul Abedin. The first \ncampus of this university was in Mohakhali, then it shifted to Banani. Regular academic classes started in 1995. \nAMA Computer University later left the partnership, and in 2001 the university was renamed American \nInternational University-Bangladesh. In 2017, AUIB moved to its permanent campus at Kuratoli Road, Kuril, \nKhilkhet, Dhaka. As the university grew, it increased the number of programs and introduced master's degrees.");

    glutSwapBuffers();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glClearColor(1.0, 1.0, 1.0, 1.0);

    img();

    glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(720, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Text Effect");  // Create window with the given title
    loadImageAndStore("C:/Users/Asus/Downloads/text.bmp");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset the projection matrix
    gluOrtho2D(0, 13, 0, 8);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event

    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);
    glutTimerFunc(_tDelay,_keyboard_timer,0);

    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
