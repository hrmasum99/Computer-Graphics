#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

float pi = 3.1416;
float _rain = 0.0;
bool rainday = false;
float _cloud = 0.0f;
float y = 0.0f;
float _river = 0.001f;

void cloudUpdate(int value)
{
    _cloud -= 0.01f;

    if (_cloud < -22.0)
    {
        _cloud = 13.0f;
    }

    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(3, cloudUpdate, 0); // Call update function after 10 milliseconds
}

void riverUpdate(int value)
{
    if(rainday)
    {

        if (y < 6.5f)
            y += _river;
    }
    else
    {
        if(y > 0.0f)
        {
            y -= _river;
        }
    }
    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(10, riverUpdate, 0); // Call update function after 10 milliseconds
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

void circle(int R, int G, int B, float rad, float X, float Y)
{
    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3ub(R, G, B); // White color

    for (int i = 0; i < 200; i++)
    {
        float A = (i * 2 * pi) / 200;
        float r = rad;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + X, y + Y);
    }
    glEnd();
}

void land()
{
    rectangle(100, 150, 75, -5.0, 0.0, 25.0, 6.0);
}
void hill1()
{
    triangle(10, 100, 10, -5.0, 6.0, 16.0, 6.0, 6.0, 8.0);
}

void hill2()
{
    triangle(10, 100, 10, 10.0, 6.0, 25.0, 6.0, 20.0, 8.0);
}

void road()
{
    rectangle(81, 82, 83, -5.0, 2.0, 25.0, 4.0);
}

void river(float y)
{
    glBegin(GL_POLYGON);            // Draw a filled rectangle

    glColor3ub(67, 151, 222); // Set color

    glVertex2f(-5.0, -5.0);
    glVertex2f(25.0, -5.0);
    glVertex2f(25.0, -0.5 +y);
    glVertex2f(-5.0, -0.5 +y);

    glEnd();
}

void riverBank()
{
    rectangle(124, 119, 85, -5.0, -0.5, 25.0, 0.0);
}

void sky()
{
    rectangle(175, 215, 225, -5.0, 6.0, 25.0, 15.0);
}

void cloud(float x)
{
    circle(150, 150, 150, 1.2, 12.0 + x, 12.5);
    circle(150, 150, 150, 1.0, 12.5 + x, 13.5);
    circle(150, 150, 150, 1.0, 13.5 + x, 12.5);
    circle(150, 150, 150, 1.2, 14.0 + x, 13.6);
    circle(150, 150, 150, 1.0, 15.0 + x, 12.0);
    circle(150, 150, 150, 1.0, 15.0 + x, 13.5);
    circle(150, 150, 150, 1.0, 16.0 + x, 13.0);
}

void Rain(int value)
{
    if (rainday)
    {
        _rain += 0.1f;

        glBegin(GL_POINTS);
        for (int i = 1; i <= 1000; i++)
        {
            int x = rand(), y = rand();
            x %= 31; // Use window width for x-coordinate limit
            y %= 16; // Use window height for y-coordinate limit
            x -= 5;  // Adjust x-coordinate to start from -5
            y -= 5;  // Adjust y-coordinate to start from -5
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 0.2, y + 0.2);
            glEnd();
        }

        glutPostRedisplay();
        glutTimerFunc(2, Rain, 0);
        glFlush();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    land();
    sky();
    cloud(_cloud);
    hill1();
    hill2();
    road();
    riverBank();
    river(y); // Pass rain intensity to scale river

    glFlush();  // Render now
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        rainday = true;
        Rain(_rain);
        glutTimerFunc(2, Rain, 0); // Start the rain animation
        break;

    case 'e':
        rainday = false;
        break;

    case 27:     // ESC key
        exit(0);
        break;

    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(720, 520);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Rain And Flood Effect");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(3, cloudUpdate, 0); // Start the update loop for cloud animation
    glutTimerFunc(10, riverUpdate, 0); // Start the update loop for river scaling
    gluOrtho2D(-5, 25, -5, 15);
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
