#include <iostream>
#include <GL/glut.h>
#include <windows.h>
#include "glutil.h"

int click = 0;
float y = 0.0f;

void riverUpdate(int value)
{
    if(click == 4)
    {
        if (y < 1.0)
    {
        y -= 0.0005f; // Decrease the water level
    }

    }
    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(20, riverUpdate, 0); // Call update function after 20 milliseconds
}

void triangle(int R, int G, int B, float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(R, G, B);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

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

void land()
{
    triangle(100, 150, 75, 3.0, 0.0, 5.0, 4.0, 0.0, 4.0);
    triangle(100, 150, 75, 0.0, 4.0, 0.0, 0.0, 3.0, 0.0);
    triangle(100, 150, 75, 10.0, 0.0, 13.0, 4.0, 8.0, 4.0);
    triangle(100, 150, 75, 10.0, 0.0, 13.0, 4.0, 13.0, 0.0);
}

void river(float y)
{
    rectangle(67, 151, 222, 0.0, 0.0, 13.0, 4.0);

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(255, 92, 1);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(3.0f, 3.99f + y);
    glVertex2f(10.0f, 3.99f + y);
    glVertex2f(10.0f, 4.0f);
    glEnd();
    glPopMatrix();  // Render now
}

void img(int a)
{
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 4.0f);
    glVertex2f(13.0f, 4.0f);
    glVertex2f(13.0f, 8.0f);
    glVertex2f(0.0f, 8.0f);
    glEnd();

    ApplyTexture(0.0f, 4.0f, 13.0f, 4.0f,  13.0f, 8.0f, 0.0f, 8.0f, textures[a].textureID); // Adjusted texture coordinates
    glutSwapBuffers();
}

// Function to handle mouse click events
void mouseClick(int button, int state, int x, int y) {
    if(click < 4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        click++;
    }
    }
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glClearColor(1.0, 1.0, 1.0, 1.0);

    river(y);
    land();
    img(click);

    glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(720, 520);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Rain And Flood Effect");  // Create window with the given title
    loadImageAndStore("C:/Users/Asus/Downloads/Volcano2.bmp");
    loadImageAndStore("C:/Users/Asus/Downloads/Volcano1.bmp");
    loadImageAndStore("C:/Users/Asus/Downloads/Volcano3.bmp");
    loadImageAndStore("C:/Users/Asus/Downloads/Volcano4.bmp");
    loadImageAndStore("C:/Users/Asus/Downloads/Volcano5.bmp");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset the projection matrix
    gluOrtho2D(0, 13, 0, 8);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutTimerFunc(20, riverUpdate, 0); // Start the update loop for river scaling
    glutMouseFunc(mouseClick); // Register mouse click callback function
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
