#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/gl.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <math.h>
#include<mmsystem.h>
#include "glutil.h"

//#include <SOIL/SOIL.h>
using namespace std;

// Window dimensions
int windowWidth = 1920; ///1280;
int windowHeight = 1080; ///650;

// Current orthographic projection and display function
int currentProjection = 1;

// Function declarations
void handleKeypress(unsigned char key, int x, int y);
void reshape(int width, int height);

//void DisplayDeep();
//void DisplayMustakim();

float pi=3.1416;

///deep's variable start

float _angle1D = 0.0f; // Angle for wheel rotation

float waveSpeedD = 0.5f; // Speed of the wave animation
float waveHeightD = 5.0f; // Amplitude of the wave
float waveOffsetD = 0.0f; // Initial offset of the wave

float _carPositionX1D = -20.0f;
float _carPositionX2D = -200.0f;
float _carPositionX3D = 0.0f;
//float _angle1D = 0.0f; // Angle for wheel rotation
bool carMovingD = true; // Variable to track car movement status

bool moveForwardD = false;
bool moveBackwardD = false;

float sunMoonD = 0.0f;
bool nightD = false; // Initially, it's Day

float _rainD = 0.0;
bool raindayD = false;

float boat_runD = -20.0f;

float cloudXD = -20.0f;
float cloudYD = 0.0f;
bool cloudMovingD = true;

float starXD = -20.0f; // Initial position of the star
float starYD = 0.0f;

float birdXD = 0.0f;
float birdYD = 0.0f;

float balloonPositionY1 = 0.0f;
float balloonPositionY2 = -30.0f;
float balloonPositionY3 = -60.0f;
float balloonPositionY4 = -90.0f;
float balloonPositionY5 = -120.0f;
float balloonPositionY6 = -130.0f;

float umbrellaScale = 1.0f;

float atmScale = 1.0f;
float atmPositionX = 0.0f;

float treeScale = 1.0f;
float treePositionsY[11] = { 0.0f, 35.0f,  30.0f, 17.0f, 40.0f,  45.0f,  0.0f,   25.0f,  35.0f,   35.0f,  15.0f };
float treePositionsX[11] = { 0.0f, 200.0f, 25.0f, 60.0f, 100.0f, 150.0f, 190.0f, 230.0f, 270.0f, -20.0f, -50.0f };

float trainPositionX[6] = {  0.0f, 34.0f, 68.0f, 102.0f, 136.0f, 170.0f };
bool trainMovingForwardD = false;
bool trainMovingBackwardD = false;

///deep's variable end

///mustakim' variable start

    float x,y,r;//circle
    int i;//circle loop

    float _run = 0.0;
    float _run4 = 0.0;
    float _run1 = 0.0;
    float _run2 = 0.0;
    float _run3 = 0.0;
    float _rainS = 0.0;
    float _nt = 0.0;
    float _ang_tri = 0.0;
    float position_sun =1; // for sun
    float speed_sun =0.1;
    float position_moon =1; // for moon
    float speed_moon =0.1;
    char text[] = "Hospital";
    bool onOff;
    bool frd = false;
    bool bck = false;
    bool raindayS = false;
    bool nightS = false;

///mustakim' variable end

///Masum's variables star

bool night_M=false;
bool rain_M=false;
bool train_F=false;
bool train_B=false;

float move_train_M = 0.0;
float move_frigate = 0.0;
float move_fighter_jet = 0.0;
float move_cloud_M = 0.0;
float move_sun_moon = 0.0;
float move_rain_M = 0.0;
float water_level = 0.0;
float move_river = 0.1f;

///Masum's Variables end

///Redwan's Variables start
/// Boolean Variables
bool dayR = false, nightR = true, signBoard = false, on = true, laser = false, rainR = false, rainSoundR = false;

/// Float Variables for Translation
float cloudTime1 = 0;
float cloudTime2 = 0;
float plane_RPosition = 3600;
float carrierPosition = 00;
float carrierTwoPosition = 400;
float GhostPosition = 1;
float DonutePosition = 0;
float objectPositionXR = 0;
float objectPositionYR = 0;
float rainPositionR = 0;

/// Timer Function for making the First Building's Window ColorR Toggle
int  j, k= 0; //i
bool two, three = true;

///Redwan's Variables end

void Sprint( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}

///Deep's code start

//part1
void birdD(){

    if (nightD)
    {

    }

    else
    {
    glPushMatrix();
    glTranslatef(birdXD, birdYD, 0.0f);

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(80,90);
    glVertex2f(80,95);
    glVertex2f(80,95);
    glVertex2f(85,95);
    glVertex2f(85,95);
    glVertex2f(85,100);
    glVertex2f(85,100);
    glVertex2f(90,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(90,105);
    glVertex2f(90,110);
    glVertex2f(90,110);
    glVertex2f(95,110);
    glVertex2f(95,110);
    glVertex2f(95,115);
    glVertex2f(95,115);
    glVertex2f(100,115);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(105,90);
    glVertex2f(105,95);
    glVertex2f(105,95);
    glVertex2f(110,95);
    glVertex2f(110,95);
    glVertex2f(110,100);
    glVertex2f(110,100);
    glVertex2f(115,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(115,105);
    glVertex2f(115,110);
    glVertex2f(115,110);
    glVertex2f(120,110);
    glVertex2f(120,110);
    glVertex2f(120,115);
    glVertex2f(120,115);
    glVertex2f(125,115);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(130,90);
    glVertex2f(130,95);
    glVertex2f(130,95);
    glVertex2f(135,95);
    glVertex2f(135,95);
    glVertex2f(135,100);
    glVertex2f(135,100);
    glVertex2f(140,100);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.14, 0.14, 0.14); //bird
    glVertex2f(140,105);
    glVertex2f(140,110);
    glVertex2f(140,110);
    glVertex2f(145,110);
    glVertex2f(145,110);
    glVertex2f(145,115);
    glVertex2f(145,115);
    glVertex2f(150,115);
    glEnd();

    glPopMatrix();
    }


}

void updateBirdD(int value){
    // Update the bird's position here
    // Example:
    birdXD -= 0.1f; // Adjust the bird's horizontal movement speed
    if (birdXD < -320.0f) { // Adjust based on the screen width
        birdXD = 320.0f;   // Adjust based on the screen width
    }

    // You can add vertical movement or other modifications as needed

    glutPostRedisplay();
    glutTimerFunc(20, updateBirdD, 0); // Call updateBird again after 20 milliseconds
}

void RainD(int value){

if(raindayD){

    _rainD += 5.0f;

    glBegin(GL_POINTS);
    for(int i=1;i<=50;i++)
    {
        int x=rand(),y=rand();
         x %= 340; // Adjusted to the screen width (320 - (-20) + 20)
         y %= 195; // Adjusted to the screen height (120 - (-75) + 75)
         x -= 20;  // Offset to match the screen coordinates
         y -= 75;  // Offset to match the screen coordinates
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(2, RainD, 0);

    glFlush();

    }
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void cloudD(){
    if (nightD)
    {
    // First cloud
    glPushMatrix();
    glTranslatef(cloudXD, cloudYD, 0);

    // Set cloud color to a lighter shade of gray
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    // Second cloud
    glPushMatrix();
    glTranslatef(cloudXD - 50, cloudYD - 25, 0);

    // Set cloud color to a slightly darker shade of gray
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    // Third cloud
    glPushMatrix();
    glTranslatef(cloudXD + 90, cloudYD - 20, 0);

    // Set cloud color to a slightly darker shade of gray
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    }

    else
    {
    // First cloud
    glPushMatrix();
    glTranslatef(cloudXD, cloudYD, 0);

    // Set cloud color to a lighter shade of gray
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    // Second cloud
    glPushMatrix();
    glTranslatef(cloudXD - 50, cloudYD - 25, 0);

    // Set cloud color to a slightly darker shade of gray
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    // Third cloud
    glPushMatrix();
    glTranslatef(cloudXD + 90, cloudYD - 21, 0);

    // Set cloud color to a slightly darker shade of gray
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(36, 102, 8, 100);
    drawCircle(42, 110, 8, 100);
    drawCircle(52, 108, 8, 100);
    drawCircle(52, 100, 8, 100);
    drawCircle(42, 96, 8, 100);

    glPopMatrix();

    }

}

void updateCloudD(int value) {
    if (cloudMovingD) {
        cloudXD += 0.08f; // Adjust the movement speed as desired

        // Reset position to the left side when it reaches the right side
        if (cloudXD > 320.0f) {
            cloudXD = -20.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateCloudD, 0);
}

void sun_moonD(){
    glPushMatrix();
    glTranslatef(0.0f, -sunMoonD, 0.0f);
    if (nightD)
    {
    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3f(0.99, 0.90, 0.60); //  color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=8;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+290, y+110);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3f(0.63, 0.63, 0.63); //  color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=6;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+292, y+112);
    }
    glEnd();

    }

    else
    {
    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3f(1.00, 0.79, 0.13); // White color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=8;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+290, y+110);
    }
    glEnd();
    }
    glPopMatrix();

}

void updateSceneD(int value){
    sunMoonD += 0.08f;
    if (sunMoonD > 37.0f){
        nightD = !nightD; // Toggle between day and nightD
        sunMoonD = -18.0f;
    }

    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(500/60, updateSceneD, 0); // Call updateScene again after 5 seconds
}

void starD(){

    if (nightD)
    {

    glPushMatrix();
    glTranslatef(starXD, 0.0f, 0.0f); // Translate star to its current position

    glBegin(GL_POLYGON); // 1
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(240,110);
    glVertex2f(239,107);
    glVertex2f(240,108);
    glVertex2f(241,107);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(238.5,109);
    glVertex2f(240,108);
    glVertex2f(241.6,109);
    glEnd();

    glBegin(GL_POLYGON); // 2
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(244,100);
    glVertex2f(243,97);
    glVertex2f(244,98);
    glVertex2f(245,97);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(242.5,99);
    glVertex2f(244,98);;
    glVertex2f(245.5,99);
    glEnd();

    glBegin(GL_POLYGON); // 3
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(230,112);
    glVertex2f(229,109);
    glVertex2f(230,110);
    glVertex2f(231,109);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(228.5,111);
    glVertex2f(230,110);;
    glVertex2f(231.5,111);
    glEnd();

    glBegin(GL_POLYGON); // 4
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(234,100);
    glVertex2f(233,97);
    glVertex2f(234,98);
    glVertex2f(235,97);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(232.5,99);
    glVertex2f(235.5,99);
    glVertex2f(234,98);
    glEnd();

    glBegin(GL_POLYGON); // 5
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(217,111);
    glVertex2f(216,108);
    glVertex2f(217,109);
    glVertex2f(218,108);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(215.5,110);
    glVertex2f(218.5,110);
    glVertex2f(217,109);
    glEnd();

    glBegin(GL_POLYGON); // 6
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(221,101);
    glVertex2f(220,98);
    glVertex2f(221,98.8);
    glVertex2f(222,98);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(219.5,100);
    glVertex2f(222.5,100);
    glVertex2f(221,98.8);
    glEnd();

    glBegin(GL_POLYGON); // 6
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(234,106);
    glVertex2f(233,103);
    glVertex2f(234,104);
    glVertex2f(235,103);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(232.5,105);
    glVertex2f(235.5,105);
    glVertex2f(234,104);
    glEnd();

    glBegin(GL_POLYGON); // 6
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(224,107);
    glVertex2f(223,104);
    glVertex2f(224,105);
    glVertex2f(225,104);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(222.5,106);
    glVertex2f(225.5,106);
    glVertex2f(224,105);
    glEnd();

    glBegin(GL_POLYGON); // 6
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(227,96);
    glVertex2f(226,93);
    glVertex2f(227,94);
    glVertex2f(228,93);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(225.5,95);
    glVertex2f(228.5,95);
    glVertex2f(227,94);
    glEnd();

    glBegin(GL_POLYGON); // 6
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(210,108);
    glVertex2f(209,105);
    glVertex2f(210,106);
    glVertex2f(211,105);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(208.5,107);
    glVertex2f(211.5,107);
    glVertex2f(210,106);
    glEnd();

    glBegin(GL_POLYGON); // 11
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(213,102);
    glVertex2f(212,99);
    glVertex2f(213,100);
    glVertex2f(214,99);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(211.5,101);
    glVertex2f(214.5,101);
    glVertex2f(213,100);
    glEnd();

    glPopMatrix();

    }

    else
    {

    }


}

void updateStarD(int value) {
    starXD += 0.09f; // Adjust the movement speed as desired

    // Reset position to the left side when it reaches the right side
    if (starXD > 320.0f) {
        starXD = -320.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateStarD, 0);
}

void air_balloonD() {
    // Balloon 1
    glPushMatrix();
    glTranslatef(-160.0f, balloonPositionY1, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.27, 0.47, 0.54); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.27, 0.47, 0.54); // Blue color for center
    float centerX1 = (169 + 179 + 174) / 3.0f;
    float centerY1 = (113 + 113 + 108) / 3.0f;
    float radiusX1 = (179 - 169) / 1.5f;
    float radiusY1 = (113 - 108) / 1.5f;
    glVertex2f(centerX1, centerY1); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX1 + radiusX1 * cos(angle);
        float y = centerY1 + radiusY1 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();

    // Balloon 2
    glPushMatrix();
    glTranslatef(-120.0f, balloonPositionY2, 0.0f);

    // Add code for Balloon 2
    glBegin(GL_POLYGON);
    glColor3f(0.66, 0.84, 0.29); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.66, 0.84, 0.29); // Blue color for center
    float centerX2 = (169 + 179 + 174) / 3.0f;
    float centerY2 = (113 + 113 + 108) / 3.0f;
    float radiusX2 = (179 - 169) / 1.5f;
    float radiusY2 = (113 - 108) / 1.5f;
    glVertex2f(centerX2, centerY2); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX2 + radiusX2 * cos(angle);
        float y = centerY2 + radiusY2 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();

    // Balloon 3
    glPushMatrix();
    glTranslatef(-80.0f, balloonPositionY3, 0.0f);

    // Add code for Balloon 3
    glBegin(GL_POLYGON);
    glColor3f(1.00, 0.72, 0.27); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.00, 0.72, 0.27); // Blue color for center
    float centerX3 = (169 + 179 + 174) / 3.0f;
    float centerY3 = (113 + 113 + 108) / 3.0f;
    float radiusX3 = (179 - 169) / 1.5f;
    float radiusY3 = (113 - 108) / 1.5f;
    glVertex2f(centerX3, centerY3); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX3 + radiusX3 * cos(angle);
        float y = centerY3 + radiusY3 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Balloon 4
    glPushMatrix();
    glTranslatef(-40.0f, balloonPositionY4, 0.0f);

    // Add code for Balloon 4
    glBegin(GL_POLYGON);
    glColor3f(0.89, 0.45, 0.10); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.89, 0.45, 0.10); // Blue color for center
    float centerX4 = (169 + 179 + 174) / 3.0f;
    float centerY4 = (113 + 113 + 108) / 3.0f;
    float radiusX4 = (179 - 169) / 1.5f;
    float radiusY4 = (113 - 108) / 1.5f;
    glVertex2f(centerX4, centerY4); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX4 + radiusX4 * cos(angle);
        float y = centerY4 + radiusY4 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Balloon 5
    glPushMatrix();
    glTranslatef(0.0f, balloonPositionY5, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.49, 0.09, 0.11); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.49, 0.09, 0.11); // Blue color for center
    float centerX5 = (169 + 179 + 174) / 3.0f;
    float centerY5 = (113 + 113 + 108) / 3.0f;
    float radiusX5 = (179 - 169) / 1.5f;
    float radiusY5 = (113 - 108) / 1.5f;
    glVertex2f(centerX5, centerY5); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX5 + radiusX5 * cos(angle);
        float y = centerY5 + radiusY5 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Balloon 6
    glPushMatrix();
    glTranslatef(40.0f, balloonPositionY6, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.44, 0.74, 0.52); // Red color
    glVertex2f(168, 112);
    glVertex2f(180, 112);
    glVertex2f(176, 103);
    glVertex2f(172, 103);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(176.5, 102.5);
    glVertex2f(176, 103);
    glVertex2f(171.5, 103);
    glVertex2f(171.5, 102.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.02, 0.02, 0.02); // rope
    glVertex2f(172, 102.5);
    glVertex2f(172, 100);
    glVertex2f(176, 102.5);
    glVertex2f(176, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.92, 0.71, 0.42); // box
    glVertex2f(171.5, 100);
    glVertex2f(171, 99.5);
    glVertex2f(171, 97);
    glVertex2f(171.5, 96.5);
    glVertex2f(176.5, 96.5);
    glVertex2f(177, 97);
    glVertex2f(177, 99.5);
    glVertex2f(176.5, 100);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.44, 0.74, 0.52); // Blue color for center
    float centerX6 = (169 + 179 + 174) / 3.0f;
    float centerY6 = (113 + 113 + 108) / 3.0f;
    float radiusX6 = (179 - 169) / 1.5f;
    float radiusY6 = (113 - 108) / 1.5f;
    glVertex2f(centerX6, centerY6); // Center of the ellipse
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159265358979323846f / 180.0f;
        float x = centerX6 + radiusX6 * cos(angle);
        float y = centerY6 + radiusY6 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void updateBalloonsD(int value) {
    // Move all balloons downwards
    balloonPositionY1 += 0.7f;
    balloonPositionY2 += 0.65f;
    balloonPositionY3 += 0.74f;
    balloonPositionY4 += 0.64f;
    balloonPositionY5 += 0.72f;
    balloonPositionY6 += 0.68f;

    // Reset positions when balloons reach the bottom
    if (balloonPositionY1 > 120.0f) {
        balloonPositionY1 = -70.0f;
    }
    if (balloonPositionY2 > 120.0f) {
        balloonPositionY2 = -70.0f;
    }
    if (balloonPositionY3 > 120.0f) {
        balloonPositionY3 = -70.0f;
    }
    if (balloonPositionY4 > 120.0f) {
        balloonPositionY4 = -70.0f;
    }
    if (balloonPositionY5 > 120.0f) {
        balloonPositionY5 = -70.0f;
    }
    if (balloonPositionY6 > 120.0f) {
        balloonPositionY6 = -70.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateBalloonsD, 0);
}

void skyD(){

    if (nightD)
    {
    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); // Left color (light gray)
    glVertex2f(-20, 120);
    glColor3f(0.67, 0.67, 0.67); // Right color (black)
    glVertex2f(320, 120);
    glColor3f(0.67, 0.67, 0.67); // Right color (black)
    glVertex2f(320, 60);
    glColor3f(0.00, 0.00, 0.00); // Left color (light gray)
    glVertex2f(-20, 60);
    glEnd();

    }
    else
    {
    glBegin(GL_POLYGON);
    glColor3f(0.05, 0.52, 0.71);
    glVertex2f(320,120);
    glVertex2f(-20,120);

    glBegin(GL_POLYGON);
    glColor3f(0.27, 0.67, 0.80);
    glVertex2f(-20,60);
    glVertex2f(320,60);
    glVertex2f(320,120);
    glEnd();
    }

}

//part 2
void hillsD(){
    if (nightD)
    {
    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(16,82);
    glVertex2f(-2,60);
    glVertex2f(30,60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(0,85);
    glVertex2f(-20,60);
    glVertex2f(14,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(-20,82);
    glVertex2f(-6,60);
    glVertex2f(-20,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(14,60);
    glVertex2f(34,84);
    glVertex2f(50,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(60,80);
    glVertex2f(30,60);
    glVertex2f(80,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(74,84);
    glVertex2f(50,60);
    glVertex2f(92,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(90,80);
    glVertex2f(65,60);
    glVertex2f(110,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(110,84);
    glVertex2f(92,60);
    glVertex2f(125,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(135,80);
    glVertex2f(120,60);
    glVertex2f(150,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(150,82);
    glVertex2f(140,60);
    glVertex2f(160,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(170,80);
    glVertex2f(160,60);
    glVertex2f(190,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(200,84);
    glVertex2f(180,60);
    glVertex2f(220,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(170,80);
    glVertex2f(160,60);
    glVertex2f(190,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(230,80);
    glVertex2f(210,60);
    glVertex2f(250,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(260,80);
    glVertex2f(240,60);
    glVertex2f(280,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(282,80);
    glVertex2f(270,60);
    glVertex2f(294,60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(305,80);
    glVertex2f(320,70);
    glVertex2f(320,60);
    glVertex2f(280,60);
    glEnd();
    }

    else
    {
    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(16,82);
    glVertex2f(-2,60);
    glVertex2f(30,60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(0,85);
    glVertex2f(-20,60);
    glVertex2f(14,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(-20,82);
    glVertex2f(-6,60);
    glVertex2f(-20,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(14,60);
    glVertex2f(34,84);
    glVertex2f(50,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(60,80);
    glVertex2f(30,60);
    glVertex2f(80,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(74,84);
    glVertex2f(50,60);
    glVertex2f(92,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(90,80);
    glVertex2f(65,60);
    glVertex2f(110,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(110,84);
    glVertex2f(92,60);
    glVertex2f(125,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(135,80);
    glVertex2f(120,60);
    glVertex2f(150,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(150,82);
    glVertex2f(140,60);
    glVertex2f(160,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(170,80);
    glVertex2f(160,60);
    glVertex2f(190,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(200,84);
    glVertex2f(180,60);
    glVertex2f(220,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(170,80);
    glVertex2f(160,60);
    glVertex2f(190,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(230,80);
    glVertex2f(210,60);
    glVertex2f(250,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(260,80);
    glVertex2f(240,60);
    glVertex2f(280,60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(282,80);
    glVertex2f(270,60);
    glVertex2f(294,60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(305,80);
    glVertex2f(320,70);
    glVertex2f(320,60);
    glVertex2f(280,60);
    glEnd();
    }

}

void smallhillD(){

    if (nightD)
    {
    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(142,78);
    glVertex2f(125,60);
    glVertex2f(160,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small 1
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(0,75);
    glVertex2f(-15,60);
    glVertex2f(14,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(24,76);
    glVertex2f(45,60);
    glVertex2f(0,60);
    glEnd();

     glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(50,80);
    glVertex2f(30,60);
    glVertex2f(70,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(70,75);
    glVertex2f(45,60);
    glVertex2f(90,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(85,75);
    glVertex2f(70,60);
    glVertex2f(100,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(110,75);
    glVertex2f(90,60);
    glVertex2f(130,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(100,80);
    glVertex2f(80,60);
    glVertex2f(115,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(125,75);
    glVertex2f(115,60);
    glVertex2f(135,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(160,75);
    glVertex2f(150,60);
    glVertex2f(170,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(185,80);
    glVertex2f(170,60);
    glVertex2f(200,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(215,80);
    glVertex2f(200,60);
    glVertex2f(230,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(245,80);
    glVertex2f(230,60);
    glVertex2f(260,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.09, 0.27, 0.32);
    glVertex2f(270,80);
    glVertex2f(260,60);
    glVertex2f(280,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.07, 0.19, 0.23);
    glVertex2f(295,80);
    glVertex2f(280,60);
    glVertex2f(310,60);
    glEnd();
    }

    else
    {
        glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(142,78);
    glVertex2f(125,60);
    glVertex2f(160,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small 1
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(0,75);
    glVertex2f(-15,60);
    glVertex2f(14,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(24,76);
    glVertex2f(45,60);
    glVertex2f(0,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(50,80);
    glVertex2f(30,60);
    glVertex2f(70,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(70,75);
    glVertex2f(45,60);
    glVertex2f(90,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(85,75);
    glVertex2f(70,60);
    glVertex2f(100,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(110,75);
    glVertex2f(90,60);
    glVertex2f(130,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(100,80);
    glVertex2f(80,60);
    glVertex2f(115,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(125,75);
    glVertex2f(115,60);
    glVertex2f(135,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(160,75);
    glVertex2f(150,60);
    glVertex2f(170,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(185,80);
    glVertex2f(170,60);
    glVertex2f(200,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(215,80);
    glVertex2f(200,60);
    glVertex2f(230,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(245,80);
    glVertex2f(230,60);
    glVertex2f(260,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.66, 0.69, 0.39);
    glVertex2f(270,80);
    glVertex2f(260,60);
    glVertex2f(280,60);
    glEnd();

    glBegin(GL_TRIANGLES); // hill small
    glColor3f(0.49, 0.53, 0.24);
    glVertex2f(295,80);
    glVertex2f(280,60);
    glVertex2f(310,60);
    glEnd();
    }

}

//part3
void homeD(){

    if (nightD)
    {
           //FOR FLOORS
    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18); //1 L
    glVertex2f(-6, 40);
    glVertex2f(18, 40);
    glVertex2f(18, 32);
    glVertex2f(-6, 32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.55, 0.53);
    glVertex2f(-6, 32);
    glVertex2f(18, 32);
    glVertex2f(18, 24);
    glVertex2f(-6, 24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18);
    glVertex2f(18, 24);
    glVertex2f(-6, 24);
    glVertex2f(-6, 16);
    glVertex2f(18, 16);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.55, 0.53);
    glVertex2f(-6, 16);
    glVertex2f(18, 16);
    glVertex2f(18, 8);
    glVertex2f(-6, 8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18);
    glVertex2f(18, 8);
    glVertex2f(-6, 8);
    glVertex2f(-6, 0);
    glVertex2f(18, 0);
    glEnd();

    //DOOR
    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.51, 0.51);
    glVertex2f(8, 7);
    glVertex2f(13, 7);
    glVertex2f(13, 0);
    glVertex2f(8,0);
    glEnd();

    //SHADOW
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.09, 0.09);
    glVertex2f(18, 40);
    glVertex2f(24, 38);
    glVertex2f(24, 2);
    glVertex2f(18,0);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(-2, 38);
    glVertex2f(4, 38);
    glVertex2f(4, 34);
    glVertex2f(-2,34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(-2, 30);
    glVertex2f(4, 30);
    glVertex2f(4, 26);
    glVertex2f(-2,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(-2, 22);
    glVertex2f(4, 22);
    glVertex2f(4, 18);
    glVertex2f(-2,18);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(-2, 14);
    glVertex2f(4, 14);
    glVertex2f(4, 10);
    glVertex2f(-2,10);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00);
    glVertex2f(-2, 6);
    glVertex2f(4, 6);
    glVertex2f(4, 2);
    glVertex2f(-2, 2);
    glEnd();

    }

    else
    {

     //FOR FLOORS
    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18); //1 L
    glVertex2f(-6, 40);
    glVertex2f(18, 40);
    glVertex2f(18, 32);
    glVertex2f(-6, 32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.55, 0.53);
    glVertex2f(-6, 32);
    glVertex2f(18, 32);
    glVertex2f(18, 24);
    glVertex2f(-6, 24);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18);
    glVertex2f(18, 24);
    glVertex2f(-6, 24);
    glVertex2f(-6, 16);
    glVertex2f(18, 16);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.55, 0.53);
    glVertex2f(-6, 16);
    glVertex2f(18, 16);
    glVertex2f(18, 8);
    glVertex2f(-6, 8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.60, 0.18, 0.18);
    glVertex2f(18, 8);
    glVertex2f(-6, 8);
    glVertex2f(-6, 0);
    glVertex2f(18, 0);
    glEnd();

    //DOOR
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(8, 7);
    glVertex2f(13, 7);
    glVertex2f(13, 0);
    glVertex2f(8,0);
    glEnd();

    //SHADOW
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.09, 0.09);
    glVertex2f(18, 40);
    glVertex2f(24, 38);
    glVertex2f(24, 2);
    glVertex2f(18,0);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(-2, 38);
    glVertex2f(4, 38);
    glVertex2f(4, 34);
    glVertex2f(-2,34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(-2, 30);
    glVertex2f(4, 30);
    glVertex2f(4, 26);
    glVertex2f(-2,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(-2, 22);
    glVertex2f(4, 22);
    glVertex2f(4, 18);
    glVertex2f(-2,18);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(-2, 14);
    glVertex2f(4, 14);
    glVertex2f(4, 10);
    glVertex2f(-2,10);
    glEnd();

    // W
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13);
    glVertex2f(-2, 6);
    glVertex2f(4, 6);
    glVertex2f(4, 2);
    glVertex2f(-2, 2);
    glEnd();


    }

}

void treeD(){


    for (int i = 0; i < 11; ++i) {
    glPushMatrix();
    glTranslatef(treePositionsX[i], treePositionsY[i], 0.0f);
    glScalef(treeScale, treeScale, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f); //1 L
    glVertex2f(38, 24);
    glVertex2f(34, 18);
    glVertex2f(35.5, 17);
    glVertex2f(38, 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.35f, 0.0f);  //2 L
    glVertex2f(35.5, 17);
    glVertex2f(38, 18);
    glVertex2f(38, 14);
    glVertex2f(34.5, 13);
    glVertex2f(33, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.0f);  //3 L
    glVertex2f(38, 14);
    glVertex2f(34.5, 13);
    glVertex2f(33.5, 12);
    glVertex2f(32.5, 12);
    glVertex2f(31.5, 10.5);
    glVertex2f(33, 9.5);
    glVertex2f(32, 7.5);
    glVertex2f(36.5, 9);
    glVertex2f(38, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.0f); //1 R
    glVertex2f(38, 24);
    glVertex2f(42, 18);
    glVertex2f(40.5, 17);
    glVertex2f(38, 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.35f, 0.0f);  //2 R
    glVertex2f(40.5, 17);
    glVertex2f(38, 18);
    glVertex2f(38, 14);
    glVertex2f(41.5, 13);
    glVertex2f(43, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.0f);  //3 R
    glVertex2f(38, 14);
    glVertex2f(41.5, 13);
    glVertex2f(42.5, 12);
    glVertex2f(43.5, 12);
    glVertex2f(44.5, 10.5);
    glVertex2f(43, 9.5);
    glVertex2f(44, 7.5);
    glVertex2f(39.5, 9);
    glVertex2f(38, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.14f, 0.0f, 0.0f);  //4 R
    glVertex2f(40, 0);
    glVertex2f(39.5, 9);
    glVertex2f(38, 10);
    glVertex2f(38, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.18f, 0.0f, 0.0f);  //4 L
    glVertex2f(38, 10);
    glVertex2f(38, 0);
    glVertex2f(36, 0);
    glVertex2f(36.5, 9);
    glEnd();

    glPopMatrix();

    }

}

void lamppostD(){

    if (nightD)
    {
    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(54, 11.5);
    glVertex2f(55.5, 11.5);
    glVertex2f(56.5, 10);
    glVertex2f(53, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(56.5, 10);
    glVertex2f(53, 10);
    glVertex2f(53, 1.5);
    glVertex2f(56.5, 1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(53, 1.5);
    glVertex2f(56.5, 1.5);
    glVertex2f(57.5, 0);
    glVertex2f(52, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(54, 11.5);
    glVertex2f(55.5, 11.5);
    glVertex2f(55.5, 18.5);
    glVertex2f(54, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(57, 21);
    glVertex2f(57.5, 20);
    glVertex2f(55.5, 18.5);
    glVertex2f(54, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(57, 21);
    glVertex2f(57.5, 20);
    glVertex2f(67, 20);
    glVertex2f(67.5, 20.5);
    glVertex2f(67.5, 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.96, 0.05); //LIGHT
    glVertex2f(62, 20);
    glVertex2f(66, 20);
    glVertex2f(65, 18);
    glVertex2f(63, 18);
    glEnd();

    }

    else
    {
        glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(54, 11.5);
    glVertex2f(55.5, 11.5);
    glVertex2f(56.5, 10);
    glVertex2f(53, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(56.5, 10);
    glVertex2f(53, 10);
    glVertex2f(53, 1.5);
    glVertex2f(56.5, 1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.09, 0.10, 0.11); //M
    glVertex2f(53, 1.5);
    glVertex2f(56.5, 1.5);
    glVertex2f(57.5, 0);
    glVertex2f(52, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(54, 11.5);
    glVertex2f(55.5, 11.5);
    glVertex2f(55.5, 18.5);
    glVertex2f(54, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(57, 21);
    glVertex2f(57.5, 20);
    glVertex2f(55.5, 18.5);
    glVertex2f(54, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.32, 0.32, 0.32); //M
    glVertex2f(57, 21);
    glVertex2f(57.5, 20);
    glVertex2f(67, 20);
    glVertex2f(67.5, 20.5);
    glVertex2f(67.5, 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.98, 0.98); //LIGHT
    glVertex2f(62, 20);
    glVertex2f(66, 20);
    glVertex2f(65, 18);
    glVertex2f(63, 18);
    glEnd();

    }

}

void benchD(){
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(66.5, 0.8);
    glVertex2f(67.5, 1);
    glVertex2f(68, 1.4);
    glVertex2f(68, 13);
    glVertex2f(66.5, 13); //
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(73.5, 0.8);
    glVertex2f(72.5, 1);
    glVertex2f(72, 1.4);
    glVertex2f(72, 13);
    glVertex2f(73.5, 13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f); //M
    glVertex2f(64, 4.5);
    glVertex2f(64, 0);
    glVertex2f(65, 0);
    glVertex2f(65.5, 0.5);
    glVertex2f(65.5, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f); //M
    glVertex2f(76, 4.5);
    glVertex2f(76, 0);
    glVertex2f(75, 0);
    glVertex2f(74.5, 0.5);
    glVertex2f(74.5, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //s
    glVertex2f(65, 0);
    glVertex2f(65.5, 0.5);
    glVertex2f(65.5, 4.5);
    glVertex2f(65, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //s
    glVertex2f(75, 0);
    glVertex2f(74.5, 0.5);
    glVertex2f(74.5, 4.5);
    glVertex2f(75, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //M
    glVertex2f(64, 8);
    glVertex2f(63, 5.5);
    glVertex2f(77, 5.5);
    glVertex2f(76, 8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.0f, 0.0f); //M SHADOW
    glVertex2f(63, 5.5);
    glVertex2f(63, 4.5);
    glVertex2f(77, 4.5);
    glVertex2f(77, 5.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //s
    glVertex2f(67.5, 1);
    glVertex2f(68, 1.4);
    glVertex2f(68, 4.5);
    glVertex2f(67.5, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //s
    glVertex2f(72.5, 1);
    glVertex2f(72, 1.4);
    glVertex2f(72, 4.5);
    glVertex2f(72.5, 4.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //111
    glVertex2f(64.5, 12);
    glVertex2f(64.5, 11);
    glVertex2f(75.5, 11);
    glVertex2f(75.5, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.0f, 0.0f); //111
    glVertex2f(64.5, 10);
    glVertex2f(64.5, 9);
    glVertex2f(75.5, 9);
    glVertex2f(75.5, 10);
    glEnd();

}

void umbrellaD(){

    glPushMatrix();
    glScalef(umbrellaScale, umbrellaScale, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.00, 0.00, 0.00); //middle
    glVertex2f(92,25);
    glVertex2f(92.2,24.4);
    glVertex2f(91.8,24.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); //middle
    glVertex2f(92,25);
    glVertex2f(92.2,24.4);
    glVertex2f(92.2,0);
    glVertex2f(91.8,0);
    glVertex2f(91.8,24.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.62, 0.16, 0.19); //L
    glVertex2f(92,24.4);
    glVertex2f(84,17);
    glVertex2f(78,17);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.89, 0.45, 0.10); //L
    glVertex2f(92,24.4);
    glVertex2f(84,17);
    glVertex2f(88,17);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.64, 0.65, 0.22); //L
    glVertex2f(92,24.4);
    glVertex2f(88,17);
    glVertex2f(96,17);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.27, 0.47, 0.54); //L
    glVertex2f(92,24.4);
    glVertex2f(96,17);
    glVertex2f(100,17);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.91, 0.63, 0.15); //L
    glVertex2f(92,24.4);
    glVertex2f(100,17);
    glVertex2f(106,17);
    glEnd();

    glPopMatrix();

}

void trafficlightD(){
    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); //road
    glVertex2f(110,24);
    glVertex2f(112,24);
    glVertex2f(112,0);
    glVertex2f(110, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39, 0.38, 0.36); //road
    glVertex2f(112,22);
    glVertex2f(116,22);
    glVertex2f(116,12);
    glVertex2f(112, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.03, 0.04);
    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+114, y+20);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 0.93, 0.03);
    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+114, y+17);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.03, 0.84, 0.18);
    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+114, y+14);
    }
    glEnd();
}

void hotelD(){

    if (nightD)
    {

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11); //bl
    glVertex2f(126,2);
    glVertex2f(126,0);
    glVertex2f(218,0);
    glVertex2f(218,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(130,2);
    glVertex2f(130,45);
    glVertex2f(156,56);
    glVertex2f(180,50);
    glVertex2f(180,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(216,2);
    glVertex2f(216,50);
    glVertex2f(195,50);
    glVertex2f(185,45);
    glVertex2f(185,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(180,2);
    glVertex2f(185,2);
    glVertex2f(185,28);
    glVertex2f(180,28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(216,24);
    glVertex2f(220,24);
    glVertex2f(220,20);
    glVertex2f(216,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white
    glVertex2f(158,20);
    glVertex2f(158,18);
    glVertex2f(216,18);
    glVertex2f(220,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //door
    glVertex2f(176,2);
    glVertex2f(176,14);
    glVertex2f(180,16);
    glVertex2f(196,16);
    glVertex2f(200,14);
    glVertex2f(200,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(187,14);
    glVertex2f(188,14);
    glVertex2f(188,3);
    glVertex2f(187,3);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.23, 0.40); //deep blue
    glVertex2f(130,2);
    glVertex2f(130,45);
    glVertex2f(156,56);
    glVertex2f(156,2);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,41);
    glVertex2f(132,36);
    glVertex2f(138,37);
    glVertex2f(138,42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,33);
    glVertex2f(132,28);
    glVertex2f(138,29);
    glVertex2f(138,34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,25);
    glVertex2f(132,20);
    glVertex2f(138,21);
    glVertex2f(138,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,17);
    glVertex2f(132,11);
    glVertex2f(138,12);
    glVertex2f(138,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,45);
    glVertex2f(132,43);
    glVertex2f(138,44);
    glVertex2f(138,47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window left
    glVertex2f(132,8);
    glVertex2f(132,3);
    glVertex2f(138,4);
    glVertex2f(138,9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,42);
    glVertex2f(140,37);
    glVertex2f(146,38);
    glVertex2f(146,43);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,34);
    glVertex2f(140,29);
    glVertex2f(146,30);
    glVertex2f(146,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,26);
    glVertex2f(140,21);
    glVertex2f(146,22);
    glVertex2f(146,27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,18);
    glVertex2f(140,12);
    glVertex2f(146,13);
    glVertex2f(146,19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,9);
    glVertex2f(140,4);
    glVertex2f(146,5);
    glVertex2f(146,10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window middle
    glVertex2f(140,47);
    glVertex2f(140,44);
    glVertex2f(146,45);
    glVertex2f(146,49);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,43);
    glVertex2f(148,38);
    glVertex2f(154,39);
    glVertex2f(154,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,35);
    glVertex2f(148,30);
    glVertex2f(154,31);
    glVertex2f(154,36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,27);
    glVertex2f(148,22);
    glVertex2f(154,23);
    glVertex2f(154,28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,19);
    glVertex2f(148,13);
    glVertex2f(154,14);
    glVertex2f(154,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,10);
    glVertex2f(148,5);
    glVertex2f(154,6);
    glVertex2f(154,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white window right
    glVertex2f(148,49);
    glVertex2f(148,45);
    glVertex2f(154,46);
    glVertex2f(154,51);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big window left
    glVertex2f(160,51);
    glVertex2f(160,42);
    glVertex2f(166,41);
    glVertex2f(166,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big window left
    glVertex2f(160,40);
    glVertex2f(160,30);
    glVertex2f(166,29);
    glVertex2f(166,39);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big window right
    glVertex2f(170,50);
    glVertex2f(170,41);
    glVertex2f(176,40);
    glVertex2f(176,49);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big window right
    glVertex2f(170,39);
    glVertex2f(170,29);
    glVertex2f(176,28);
    glVertex2f(176,38);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big_r window right
    glVertex2f(196,48);
    glVertex2f(196,40);
    glVertex2f(202,39);
    glVertex2f(202,47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big_r window right
    glVertex2f(196,38);
    glVertex2f(196,30);
    glVertex2f(202,29);
    glVertex2f(202,37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big_r window right
    glVertex2f(206,47);
    glVertex2f(206,39);
    glVertex2f(212,38);
    glVertex2f(212,46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //white big_r window right
    glVertex2f(206,37);
    glVertex2f(206,29);
    glVertex2f(212,28);
    glVertex2f(212,36);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00); //hotel
    glVertex2f(173,27);
    glVertex2f(173,21);
    glVertex2f(177,27);
    glVertex2f(177,21);
    glVertex2f(173,24);
    glVertex2f(177,24);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00); //hotel
    glVertex2f(180,26);
    glVertex2f(180,22);
    glVertex2f(180,22);
    glVertex2f(181,21);
    glVertex2f(181,21);
    glVertex2f(183,21);
    glVertex2f(183,21);
    glVertex2f(184,22);
    glVertex2f(184,22);
    glVertex2f(184,26);
    glVertex2f(184,26);
    glVertex2f(183,27);
    glVertex2f(183,27);
    glVertex2f(181,27);
    glVertex2f(181,27);
    glVertex2f(180,26);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00); //hotel
    glVertex2f(187,26.5);
    glVertex2f(187.5,27);
    glVertex2f(187.5,27);
    glVertex2f(189,27);
    glVertex2f(189,27);
    glVertex2f(189,21);
    glVertex2f(189,21);
    glVertex2f(189,27);
    glVertex2f(189,27);
    glVertex2f(190.5,27);
    glVertex2f(190.5,27);
    glVertex2f(191,26.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00); //hotel
    glVertex2f(194,27);
    glVertex2f(198,27);
    glVertex2f(194,27);
    glVertex2f(194,21);
    glVertex2f(194,24);
    glVertex2f(197,24);
    glVertex2f(194,21);
    glVertex2f(198,21);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.00, 1.00, 1.00); //hotel
    glVertex2f(201,27);
    glVertex2f(201,21);
    glVertex2f(201,21);
    glVertex2f(205,21);
    glEnd();


    }

    else
    {

      glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11); //bl
    glVertex2f(126,2);
    glVertex2f(126,0);
    glVertex2f(218,0);
    glVertex2f(218,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(130,2);
    glVertex2f(130,45);
    glVertex2f(156,56);
    glVertex2f(180,50);
    glVertex2f(180,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(216,2);
    glVertex2f(216,50);
    glVertex2f(195,50);
    glVertex2f(185,45);
    glVertex2f(185,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(180,2);
    glVertex2f(185,2);
    glVertex2f(185,28);
    glVertex2f(180,28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(216,24);
    glVertex2f(220,24);
    glVertex2f(220,20);
    glVertex2f(216,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white
    glVertex2f(158,20);
    glVertex2f(158,18);
    glVertex2f(216,18);
    glVertex2f(220,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //door
    glVertex2f(176,2);
    glVertex2f(176,14);
    glVertex2f(180,16);
    glVertex2f(196,16);
    glVertex2f(200,14);
    glVertex2f(200,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.24, 0.42); //blue
    glVertex2f(187,14);
    glVertex2f(188,14);
    glVertex2f(188,3);
    glVertex2f(187,3);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.08, 0.23, 0.40); //deep blue
    glVertex2f(130,2);
    glVertex2f(130,45);
    glVertex2f(156,56);
    glVertex2f(156,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,41);
    glVertex2f(132,36);
    glVertex2f(138,37);
    glVertex2f(138,42);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,33);
    glVertex2f(132,28);
    glVertex2f(138,29);
    glVertex2f(138,34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,25);
    glVertex2f(132,20);
    glVertex2f(138,21);
    glVertex2f(138,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,17);
    glVertex2f(132,11);
    glVertex2f(138,12);
    glVertex2f(138,18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,45);
    glVertex2f(132,43);
    glVertex2f(138,44);
    glVertex2f(138,47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window left
    glVertex2f(132,8);
    glVertex2f(132,3);
    glVertex2f(138,4);
    glVertex2f(138,9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,42);
    glVertex2f(140,37);
    glVertex2f(146,38);
    glVertex2f(146,43);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,34);
    glVertex2f(140,29);
    glVertex2f(146,30);
    glVertex2f(146,35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,26);
    glVertex2f(140,21);
    glVertex2f(146,22);
    glVertex2f(146,27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,18);
    glVertex2f(140,12);
    glVertex2f(146,13);
    glVertex2f(146,19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,9);
    glVertex2f(140,4);
    glVertex2f(146,5);
    glVertex2f(146,10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window middle
    glVertex2f(140,47);
    glVertex2f(140,44);
    glVertex2f(146,45);
    glVertex2f(146,49);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,43);
    glVertex2f(148,38);
    glVertex2f(154,39);
    glVertex2f(154,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,35);
    glVertex2f(148,30);
    glVertex2f(154,31);
    glVertex2f(154,36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,27);
    glVertex2f(148,22);
    glVertex2f(154,23);
    glVertex2f(154,28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,19);
    glVertex2f(148,13);
    glVertex2f(154,14);
    glVertex2f(154,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,10);
    glVertex2f(148,5);
    glVertex2f(154,6);
    glVertex2f(154,11);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white window right
    glVertex2f(148,49);
    glVertex2f(148,45);
    glVertex2f(154,46);
    glVertex2f(154,51);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big window left
    glVertex2f(160,51);
    glVertex2f(160,42);
    glVertex2f(166,41);
    glVertex2f(166,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big window left
    glVertex2f(160,40);
    glVertex2f(160,30);
    glVertex2f(166,29);
    glVertex2f(166,39);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big window right
    glVertex2f(170,50);
    glVertex2f(170,41);
    glVertex2f(176,40);
    glVertex2f(176,49);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big window right
    glVertex2f(170,39);
    glVertex2f(170,29);
    glVertex2f(176,28);
    glVertex2f(176,38);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big_r window right
    glVertex2f(196,48);
    glVertex2f(196,40);
    glVertex2f(202,39);
    glVertex2f(202,47);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big_r window right
    glVertex2f(196,38);
    glVertex2f(196,30);
    glVertex2f(202,29);
    glVertex2f(202,37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big_r window right
    glVertex2f(206,47);
    glVertex2f(206,39);
    glVertex2f(212,38);
    glVertex2f(212,46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white big_r window right
    glVertex2f(206,37);
    glVertex2f(206,29);
    glVertex2f(212,28);
    glVertex2f(212,36);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //hotel
    glVertex2f(173,27);
    glVertex2f(173,21);
    glVertex2f(177,27);
    glVertex2f(177,21);
    glVertex2f(173,24);
    glVertex2f(177,24);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //hotel
    glVertex2f(180,26);
    glVertex2f(180,22);
    glVertex2f(180,22);
    glVertex2f(181,21);
    glVertex2f(181,21);
    glVertex2f(183,21);
    glVertex2f(183,21);
    glVertex2f(184,22);
    glVertex2f(184,22);
    glVertex2f(184,26);
    glVertex2f(184,26);
    glVertex2f(183,27);
    glVertex2f(183,27);
    glVertex2f(181,27);
    glVertex2f(181,27);
    glVertex2f(180,26);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //hotel
    glVertex2f(187,26.5);
    glVertex2f(187.5,27);
    glVertex2f(187.5,27);
    glVertex2f(189,27);
    glVertex2f(189,27);
    glVertex2f(189,21);
    glVertex2f(189,21);
    glVertex2f(189,27);
    glVertex2f(189,27);
    glVertex2f(190.5,27);
    glVertex2f(190.5,27);
    glVertex2f(191,26.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //hotel
    glVertex2f(194,27);
    glVertex2f(198,27);
    glVertex2f(194,27);
    glVertex2f(194,21);
    glVertex2f(194,24);
    glVertex2f(197,24);
    glVertex2f(194,21);
    glVertex2f(198,21);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //hotel
    glVertex2f(201,27);
    glVertex2f(201,21);
    glVertex2f(201,21);
    glVertex2f(205,21);
    glEnd();


    }


}

void grassD(){

    // Grass 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(-18, 6);
    glVertex2f(-20, 0);
    glVertex2f(-16, 0);
    glEnd();

    // Grass 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(-16, 5);
    glVertex2f(-18, 0);
    glVertex2f(-14, 0);
    glEnd();

    // Grass 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(-14, 4);
    glVertex2f(-16, 0);
    glVertex2f(-12, 0);
    glEnd();

    // Grass 4
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(-12, 6);
    glVertex2f(-14, 0);
    glVertex2f(-10, 0);
    glEnd();

    // Grass 5
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(-10, 5);
    glVertex2f(-12, 0);
    glVertex2f(-8, 0);
    glEnd();

    // Grass 6
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(-8, 4);
    glVertex2f(-10, 0);
    glVertex2f(-6, 0);
    glEnd();

    // Continue adding grass blades...
    // Grass 7
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(-6, 6);
    glVertex2f(-8, 0);
    glVertex2f(-4, 0);
    glEnd();

    // Grass 8
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(-4, 5);
    glVertex2f(-6, 0);
    glVertex2f(-2, 0);
    glEnd();

    // Grass 9
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(-2, 4);
    glVertex2f(-4, 0);
    glVertex2f(0, 0);
    glEnd();

    // Grass 10
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(0, 6);
    glVertex2f(-2, 0);
    glVertex2f(2, 0);
    glEnd();

    // Grass 11
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(2, 5);
    glVertex2f(0, 0);
    glVertex2f(4, 0);
    glEnd();

    // Grass 12
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(4, 4);
    glVertex2f(2, 0);
    glVertex2f(6, 0);
    glEnd();

    // Continue adding grass blades...
    // Grass 13
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(6, 6);
    glVertex2f(4, 0);
    glVertex2f(8, 0);
    glEnd();

    // Grass 14
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(8, 5);
    glVertex2f(6, 0);
    glVertex2f(10, 0);
    glEnd();

    // Grass 15
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(10, 4);
    glVertex2f(8, 0);
    glVertex2f(12, 0);
    glEnd();

    // Grass 16
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(12, 6);
    glVertex2f(10, 0);
    glVertex2f(14, 0);
    glEnd();

    // Grass 17
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(14, 5);
    glVertex2f(12, 0);
    glVertex2f(16, 0);
    glEnd();

    // Continue adding more grass blades...
    // Grass 18
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(16, 4);
    glVertex2f(14, 0);
    glVertex2f(18, 0);
    glEnd();

    // Grass 19
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(18, 6);
    glVertex2f(16, 0);
    glVertex2f(20, 0);
    glEnd();

    // Grass 20
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(20, 5);
    glVertex2f(18, 0);
    glVertex2f(22, 0);
    glEnd();

        // Grass 21
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(22, 4);
    glVertex2f(20, 0);
    glVertex2f(24, 0);
    glEnd();

    // Grass 22
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(24, 6);
    glVertex2f(22, 0);
    glVertex2f(26, 0);
    glEnd();

    // Grass 23
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(26, 5);
    glVertex2f(24, 0);
    glVertex2f(28, 0);
    glEnd();

    // Grass 24
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(28, 4);
    glVertex2f(26, 0);
    glVertex2f(30, 0);
    glEnd();

    // Grass 25
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(30, 6);
    glVertex2f(28, 0);
    glVertex2f(32, 0);
    glEnd();

    // Grass 26
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(32, 5);
    glVertex2f(30, 0);
    glVertex2f(34, 0);
    glEnd();

    // Grass 27
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(34, 4);
    glVertex2f(32, 0);
    glVertex2f(36, 0);
    glEnd();

    // Grass 28
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(36, 6);
    glVertex2f(34, 0);
    glVertex2f(38, 0);
    glEnd();

    // Grass 29
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(38, 5);
    glVertex2f(36, 0);
    glVertex2f(40, 0);
    glEnd();

    // Grass 30
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(40, 4);
    glVertex2f(38, 0);
    glVertex2f(42, 0);
    glEnd();

    // Grass 31
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(42, 6);
    glVertex2f(40, 0);
    glVertex2f(44, 0);
    glEnd();

    // Grass 32
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(44, 5);
    glVertex2f(42, 0);
    glVertex2f(46, 0);
    glEnd();

    // Grass 33
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(46, 4);
    glVertex2f(44, 0);
    glVertex2f(48, 0);
    glEnd();

    // Grass 34
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(48, 6);
    glVertex2f(46, 0);
    glVertex2f(50, 0);
    glEnd();

    // Grass 35
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(50, 5);
    glVertex2f(48, 0);
    glVertex2f(52, 0);
    glEnd();

    // Grass 36
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(52, 4);
    glVertex2f(50, 0);
    glVertex2f(54, 0);
    glEnd();

    // Grass 37
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(54, 6);
    glVertex2f(52, 0);
    glVertex2f(56, 0);
    glEnd();

    // Grass 38
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(56, 5);
    glVertex2f(54, 0);
    glVertex2f(58, 0);
    glEnd();

    // Grass 39
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(58, 4);
    glVertex2f(56, 0);
    glVertex2f(60, 0);
    glEnd();

    // Grass 40
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(60, 6);
    glVertex2f(58, 0);
    glVertex2f(62, 0);
    glEnd();

    // Grass 41
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(62, 5);
    glVertex2f(60, 0);
    glVertex2f(64, 0);
    glEnd();

    // Grass 42
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(64, 4);
    glVertex2f(62, 0);
    glVertex2f(66, 0);
    glEnd();

    // Grass 43
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(66, 6);
    glVertex2f(64, 0);
    glVertex2f(68, 0);
    glEnd();

    // Grass 44
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(68, 5);
    glVertex2f(66, 0);
    glVertex2f(70, 0);
    glEnd();

    // Grass 45
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(70, 4);
    glVertex2f(68, 0);
    glVertex2f(72, 0);
    glEnd();

    // Grass 46
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(72, 6);
    glVertex2f(70, 0);
    glVertex2f(74, 0);
    glEnd();

    // Grass 47
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(74, 5);
    glVertex2f(72, 0);
    glVertex2f(76, 0);
    glEnd();

    // Grass 48
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(76, 4);
    glVertex2f(74, 0);
    glVertex2f(78, 0);
    glEnd();

    // Grass 49
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(78, 6);
    glVertex2f(76, 0);
    glVertex2f(80, 0);
    glEnd();

    // Grass 50
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(80, 5);
    glVertex2f(78, 0);
    glVertex2f(82, 0);
    glEnd();


    // Grass 51
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(82, 6);
    glVertex2f(80, 0);
    glVertex2f(84, 0);
    glEnd();

    // Grass 52
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(84, 5);
    glVertex2f(82, 0);
    glVertex2f(86, 0);
    glEnd();

    // Grass 53
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(86, 4);
    glVertex2f(84, 0);
    glVertex2f(88, 0);
    glEnd();

    // Grass 54
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(88, 6);
    glVertex2f(86, 0);
    glVertex2f(90, 0);
    glEnd();

    // Grass 55
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(90, 5);
    glVertex2f(88, 0);
    glVertex2f(92, 0);
    glEnd();

    // Grass 56
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(92, 4);
    glVertex2f(90, 0);
    glVertex2f(94, 0);
    glEnd();

    // Grass 57
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(94, 6);
    glVertex2f(92, 0);
    glVertex2f(96, 0);
    glEnd();

    // Grass 58
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(96, 5);
    glVertex2f(94, 0);
    glVertex2f(98, 0);
    glEnd();

    // Grass 59
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(98, 4);
    glVertex2f(96, 0);
    glVertex2f(100, 0);
    glEnd();

    // Grass 60
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(100, 6);
    glVertex2f(98, 0);
    glVertex2f(102, 0);
    glEnd();

    // Grass 61
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(102, 5);
    glVertex2f(100, 0);
    glVertex2f(104, 0);
    glEnd();

    // Grass 62
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(104, 4);
    glVertex2f(102, 0);
    glVertex2f(106, 0);
    glEnd();

    // Grass 63
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(106, 6);
    glVertex2f(104, 0);
    glVertex2f(108, 0);
    glEnd();

    // Grass 64
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(108, 5);
    glVertex2f(106, 0);
    glVertex2f(110, 0);
    glEnd();

    // Grass 65
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(110, 4);
    glVertex2f(108, 0);
    glVertex2f(112, 0);
    glEnd();

    // Grass 66
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(112, 6);
    glVertex2f(110, 0);
    glVertex2f(114, 0);
    glEnd();

    // Grass 67
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(114, 5);
    glVertex2f(112, 0);
    glVertex2f(116, 0);
    glEnd();

    // Grass 68
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(116, 4);
    glVertex2f(114, 0);
    glVertex2f(118, 0);
    glEnd();

    // Grass 69
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(118, 6);
    glVertex2f(116, 0);
    glVertex2f(120, 0);
    glEnd();

    // Grass 70
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(120, 5);
    glVertex2f(118, 0);
    glVertex2f(122, 0);
    glEnd();

    // Grass 71
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(122, 4);
    glVertex2f(120, 0);
    glVertex2f(124, 0);
    glEnd();

    // Grass 72
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(124, 6);
    glVertex2f(122, 0);
    glVertex2f(126, 0);
    glEnd();

    // Grass 73
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(126, 5);
    glVertex2f(124, 0);
    glVertex2f(128, 0);
    glEnd();

    // Grass 74
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(128, 4);
    glVertex2f(126, 0);
    glVertex2f(130, 0);
    glEnd();

    // Grass 75
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(130, 6);
    glVertex2f(128, 0);
    glVertex2f(132, 0);
    glEnd();

    // Grass 76
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(132, 5);
    glVertex2f(130, 0);
    glVertex2f(134, 0);
    glEnd();

    // Grass 77
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(134, 4);
    glVertex2f(132, 0);
    glVertex2f(136, 0);
    glEnd();

    // Grass 78
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(136, 6);
    glVertex2f(134, 0);
    glVertex2f(138, 0);
    glEnd();

    // Grass 79
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(138, 5);
    glVertex2f(136, 0);
    glVertex2f(140, 0);
    glEnd();

    // Grass 80
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(140, 4);
    glVertex2f(138, 0);
    glVertex2f(142, 0);
    glEnd();

    // Grass 81
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(142, 6);
    glVertex2f(140, 0);
    glVertex2f(144, 0);
    glEnd();

    // Grass 82
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(144, 5);
    glVertex2f(142, 0);
    glVertex2f(146, 0);
    glEnd();

    // Grass 83
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(146, 4);
    glVertex2f(144, 0);
    glVertex2f(148, 0);
    glEnd();

    // Grass 84
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(148, 6);
    glVertex2f(146, 0);
    glVertex2f(150, 0);
    glEnd();

    // Grass 85
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(150, 5);
    glVertex2f(148, 0);
    glVertex2f(152, 0);
    glEnd();

    // Grass 86
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(152, 4);
    glVertex2f(150, 0);
    glVertex2f(154, 0);
    glEnd();

    // Grass 87
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(154, 6);
    glVertex2f(152, 0);
    glVertex2f(156, 0);
    glEnd();

    // Grass 88
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint
    glVertex2f(156, 5);
    glVertex2f(154, 0);
    glVertex2f(158, 0);
    glEnd();

    // Grass 89
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint
    glVertex2f(158, 4);
    glVertex2f(156, 0);
    glVertex2f(160, 0);
    glEnd();

    // Grass 90
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint
    glVertex2f(160, 6);
    glVertex2f(158, 0);
    glVertex2f(162, 0);
    glEnd();


    // First grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(220, 6);
    glVertex2f(218, 0);
    glVertex2f(222, 0);
    glEnd();

    // Second grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(222, 5);
    glVertex2f(220, 0);
    glVertex2f(224, 0);
    glEnd();

    // Third grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(224, 4);
    glVertex2f(222, 0);
    glVertex2f(226, 0);
    glEnd();

    // Add 10 more grass triangles here
    // Example:
    // Fourth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(226, 6);
    glVertex2f(224, 0);
    glVertex2f(228, 0);
    glEnd();

    // Fifth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(228, 5);
    glVertex2f(226, 0);
    glVertex2f(230, 0);
    glEnd();

    // Sixth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(230, 4);
    glVertex2f(228, 0);
    glVertex2f(232, 0);
    glEnd();

    // Seventh grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(232, 6);
    glVertex2f(230, 0);
    glVertex2f(234, 0);
    glEnd();

    // Eighth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(234, 5);
    glVertex2f(232, 0);
    glVertex2f(236, 0);
    glEnd();

    // Ninth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(236, 4);
    glVertex2f(234, 0);
    glVertex2f(238, 0);
    glEnd();

    // Tenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(238, 6);
    glVertex2f(236, 0);
    glVertex2f(240, 0);
    glEnd();

        // Eleventh grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(240, 6);
    glVertex2f(238, 0);
    glVertex2f(242, 0);
    glEnd();

    // Twelfth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(242, 5);
    glVertex2f(240, 0);
    glVertex2f(244, 0);
    glEnd();

    // Thirteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(244, 4);
    glVertex2f(242, 0);
    glVertex2f(246, 0);
    glEnd();

    // Fourteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(246, 6);
    glVertex2f(244, 0);
    glVertex2f(248, 0);
    glEnd();

    // Fifteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(248, 5);
    glVertex2f(246, 0);
    glVertex2f(250, 0);
    glEnd();

    // Sixteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(250, 4);
    glVertex2f(248, 0);
    glVertex2f(252, 0);
    glEnd();

    // Seventeenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(252, 6);
    glVertex2f(250, 0);
    glVertex2f(254, 0);
    glEnd();

    // Eighteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(254, 5);
    glVertex2f(252, 0);
    glVertex2f(256, 0);
    glEnd();

    // Nineteenth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(256, 4);
    glVertex2f(254, 0);
    glVertex2f(258, 0);
    glEnd();

    // Twentieth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(258, 6);
    glVertex2f(256, 0);
    glVertex2f(260, 0);
    glEnd();

    // Twenty-first grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(260, 5);
    glVertex2f(258, 0);
    glVertex2f(262, 0);
    glEnd();

    // Twenty-second grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(262, 4);
    glVertex2f(260, 0);
    glVertex2f(264, 0);
    glEnd();

    // Twenty-third grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(264, 6);
    glVertex2f(262, 0);
    glVertex2f(266, 0);
    glEnd();

    // Twenty-fourth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(266, 5);
    glVertex2f(264, 0);
    glVertex2f(268, 0);
    glEnd();

    // Twenty-fifth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(268, 4);
    glVertex2f(266, 0);
    glVertex2f(270, 0);
    glEnd();

    // Twenty-sixth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(270, 6);
    glVertex2f(268, 0);
    glVertex2f(272, 0);
    glEnd();

    // Twenty-seventh grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(272, 5);
    glVertex2f(270, 0);
    glVertex2f(274, 0);
    glEnd();

    // Twenty-eighth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(274, 4);
    glVertex2f(272, 0);
    glVertex2f(276, 0);
    glEnd();

    // Twenty-ninth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(276, 6);
    glVertex2f(274, 0);
    glVertex2f(278, 0);
    glEnd();

    // Thirtieth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(278, 5);
    glVertex2f(276, 0);
    glVertex2f(280, 0);
    glEnd();

        // Thirty-first grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(280, 6);
    glVertex2f(278, 0);
    glVertex2f(282, 0);
    glEnd();

    // Thirty-second grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(282, 5);
    glVertex2f(280, 0);
    glVertex2f(284, 0);
    glEnd();

    // Thirty-third grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(284, 4);
    glVertex2f(282, 0);
    glVertex2f(286, 0);
    glEnd();

    // Thirty-fourth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(286, 6);
    glVertex2f(284, 0);
    glVertex2f(288, 0);
    glEnd();

    // Thirty-fifth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(288, 5);
    glVertex2f(286, 0);
    glVertex2f(290, 0);
    glEnd();

    // Thirty-sixth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(290, 4);
    glVertex2f(288, 0);
    glVertex2f(292, 0);
    glEnd();

    // Thirty-seventh grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(292, 6);
    glVertex2f(290, 0);
    glVertex2f(294, 0);
    glEnd();

    // Thirty-eighth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(294, 5);
    glVertex2f(292, 0);
    glVertex2f(296, 0);
    glEnd();

    // Thirty-ninth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(296, 4);
    glVertex2f(294, 0);
    glVertex2f(298, 0);
    glEnd();

    // Fortieth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(298, 6);
    glVertex2f(296, 0);
    glVertex2f(300, 0);
    glEnd();

    // Forty-first grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(300, 5);
    glVertex2f(298, 0);
    glVertex2f(302, 0);
    glEnd();

    // Forty-second grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(302, 4);
    glVertex2f(300, 0);
    glVertex2f(304, 0);
    glEnd();

    // Forty-third grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(304, 6);
    glVertex2f(302, 0);
    glVertex2f(306, 0);
    glEnd();

    // Forty-fourth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(306, 5);
    glVertex2f(304, 0);
    glVertex2f(308, 0);
    glEnd();

    // Forty-fifth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(308, 4);
    glVertex2f(306, 0);
    glVertex2f(310, 0);
    glEnd();

    // Forty-sixth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(310, 6);
    glVertex2f(308, 0);
    glVertex2f(312, 0);
    glEnd();

    // Forty-seventh grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(312, 5);
    glVertex2f(310, 0);
    glVertex2f(314, 0);
    glEnd();

    // Forty-eighth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.11, 0.49, 0.24); // Mint color
    glVertex2f(314, 4);
    glVertex2f(312, 0);
    glVertex2f(316, 0);
    glEnd();

    // Forty-ninth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.40, 0.20); // Mint color
    glVertex2f(316, 6);
    glVertex2f(314, 0);
    glVertex2f(318, 0);
    glEnd();

    // Fiftieth grass triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.13, 0.34, 0.16); // Mint color
    glVertex2f(318, 5);
    glVertex2f(316, 0);
    glVertex2f(320, 0);
    glEnd();


}

void atmD(){
    if (nightD)
    {
    glPushMatrix();
    glTranslatef(atmPositionX, 0.0f, 0.0f);
    glScalef(atmScale, atmScale, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.16, 0.37, 0.37); //mint
    glVertex2f(250,26);
    glVertex2f(266,26);
    glVertex2f(266,0);
    glVertex2f(250,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.20, 0.20, 0.20); //blak
    glVertex2f(252,23);
    glVertex2f(264,23);
    glVertex2f(264,12);
    glVertex2f(252,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); //white
    glVertex2f(254,22);
    glVertex2f(262,22);
    glVertex2f(262,14);
    glVertex2f(254,14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.20, 0.45, 0.45); //frame
    glVertex2f(252,12);
    glVertex2f(252,0);
    glVertex2f(264,0);
    glVertex2f(264,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.51, 0.51); //frame
    glVertex2f(252,12);
    glVertex2f(252,8);
    glVertex2f(264,8);
    glVertex2f(264,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.29, 0.56, 0.55); //frame
    glVertex2f(254,6);
    glVertex2f(254,0);
    glVertex2f(262,0);
    glVertex2f(262,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.14, 0.14); //frame
    glVertex2f(255,11);
    glVertex2f(261,11);
    glVertex2f(261,9);
    glVertex2f(255,9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.95, 0.95, 0.95); //atm
    glVertex2f(255,25.5);
    glVertex2f(254,23.5);
    glVertex2f(255,25.5);
    glVertex2f(256,23.5);
    glVertex2f(254.5,24.5);
    glVertex2f(255.5,24.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.95, 0.95, 0.95); //atm
    glVertex2f(257,25.5);
    glVertex2f(259,25.5);
    glVertex2f(258,25.5);
    glVertex2f(258,23.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.95, 0.95, 0.95); //atm
    glVertex2f(260,25.5);
    glVertex2f(260,23.5);
    glVertex2f(260,25.5);
    glVertex2f(261,24.5);
    glVertex2f(261,24.5);
    glVertex2f(262,25.5);
    glVertex2f(262,25.5);
    glVertex2f(262,23.5);
    glEnd();

    glPopMatrix();
    }

    else
    {
    glPushMatrix();
    glTranslatef(atmPositionX, 0.0f, 0.0f);
    glScalef(atmScale, atmScale, 1.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.16, 0.37, 0.37); //mint
    glVertex2f(250,26);
    glVertex2f(266,26);
    glVertex2f(266,0);
    glVertex2f(250,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.20, 0.20, 0.20); //blak
    glVertex2f(252,23);
    glVertex2f(264,23);
    glVertex2f(264,12);
    glVertex2f(252,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //white
    glVertex2f(254,22);
    glVertex2f(262,22);
    glVertex2f(262,14);
    glVertex2f(254,14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.20, 0.45, 0.45); //frame
    glVertex2f(252,12);
    glVertex2f(252,0);
    glVertex2f(264,0);
    glVertex2f(264,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.51, 0.51, 0.51); //frame
    glVertex2f(252,12);
    glVertex2f(252,8);
    glVertex2f(264,8);
    glVertex2f(264,12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.29, 0.56, 0.55); //frame
    glVertex2f(254,6);
    glVertex2f(254,0);
    glVertex2f(262,0);
    glVertex2f(262,6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.14, 0.14); //frame
    glVertex2f(255,11);
    glVertex2f(261,11);
    glVertex2f(261,9);
    glVertex2f(255,9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //atm
    glVertex2f(255,25.5);
    glVertex2f(254,23.5);
    glVertex2f(255,25.5);
    glVertex2f(256,23.5);
    glVertex2f(254.5,24.5);
    glVertex2f(255.5,24.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //atm
    glVertex2f(257,25.5);
    glVertex2f(259,25.5);
    glVertex2f(258,25.5);
    glVertex2f(258,23.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //atm
    glVertex2f(260,25.5);
    glVertex2f(260,23.5);
    glVertex2f(260,25.5);
    glVertex2f(261,24.5);
    glVertex2f(261,24.5);
    glVertex2f(262,25.5);
    glVertex2f(262,25.5);
    glVertex2f(262,23.5);
    glEnd();

    glPopMatrix();
    }

}

void tea_stallD(){

    if (nightD)
    {

    glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.00); //up
    glVertex2f(280,48);
    glVertex2f(280,40);
    glVertex2f(306,40);
    glVertex2f(306,48);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.63, 0.36, 0.16); //TEA
    glVertex2f(282,46);
    glVertex2f(283,47);
    glVertex2f(283,47);
    glVertex2f(285,47);
    glVertex2f(285,47);
    glVertex2f(287,47);
    glVertex2f(287,47);
    glVertex2f(288,46);
    glVertex2f(285,47);
    glVertex2f(285,41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.63, 0.36, 0.16); //TEA
    glVertex2f(290,47);
    glVertex2f(294,47);
    glVertex2f(290,44);
    glVertex2f(293,44);
    glVertex2f(290,41);
    glVertex2f(294,41);
    glVertex2f(290,47);
    glVertex2f(290,41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.63, 0.36, 0.16); //TEA
    glVertex2f(300,47);
    glVertex2f(297,41);
    glVertex2f(300,47);
    glVertex2f(303,41);
    glVertex2f(298.5,44);
    glVertex2f(301.5,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.44, 0.49, 0.55); //room
    glVertex2f(272,26);
    glVertex2f(272,0);
    glVertex2f(314,0);
    glVertex2f(314,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.96, 1.00); //door
    glVertex2f(272,20);
    glVertex2f(272,0);
    glVertex2f(284,0);
    glVertex2f(284,20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.63, 0.36, 0.16); //door
    glVertex2f(282,16);
    glVertex2f(282,4);
    //glVertex2f(284,0);
    //glVertex2f(284,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11); //room
    glVertex2f(270,2);
    glVertex2f(270,0);
    glVertex2f(316,0);
    glVertex2f(316,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.96, 1.00); //window
    glVertex2f(288,22);
    glVertex2f(288,10);
    glVertex2f(310,10);
    glVertex2f(310,22);
    glEnd();


    glBegin(GL_POLYGON); //up
    glColor3f(0.63, 0.36, 0.16); // Light blue// Top color
    // Define vertices
    glVertex2f(274, 40);
    glVertex2f(270, 26);

    glColor3f(0.92, 0.77, 0.68); // Dark brown// Bottom color
    // Define vertices
    glVertex2f(316, 26);
    glVertex2f(312, 40);
    glEnd();

    }

    else
    {

    glBegin(GL_POLYGON);
    glColor3f(0.58, 0.63, 0.66); //up
    glVertex2f(280,48);
    glVertex2f(280,40);
    glVertex2f(306,40);
    glVertex2f(306,48);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //TEA
    glVertex2f(282,46);
    glVertex2f(283,47);
    glVertex2f(283,47);
    glVertex2f(285,47);
    glVertex2f(285,47);
    glVertex2f(287,47);
    glVertex2f(287,47);
    glVertex2f(288,46);
    glVertex2f(285,47);
    glVertex2f(285,41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //TEA
    glVertex2f(290,47);
    glVertex2f(294,47);
    glVertex2f(290,44);
    glVertex2f(293,44);
    glVertex2f(290,41);
    glVertex2f(294,41);
    glVertex2f(290,47);
    glVertex2f(290,41);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.13, 0.13, 0.13); //TEA
    glVertex2f(300,47);
    glVertex2f(297,41);
    glVertex2f(300,47);
    glVertex2f(303,41);
    glVertex2f(298.5,44);
    glVertex2f(301.5,44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27, 0.31, 0.33); //room
    glVertex2f(272,26);
    glVertex2f(272,0);
    glVertex2f(314,0);
    glVertex2f(314,26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.58, 0.63, 0.66); //door
    glVertex2f(272,20);
    glVertex2f(272,0);
    glVertex2f(284,0);
    glVertex2f(284,20);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.63, 0.36, 0.16); //door
    glVertex2f(282,16);
    glVertex2f(282,4);
    //glVertex2f(284,0);
    //glVertex2f(284,20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11); //room
    glVertex2f(270,2);
    glVertex2f(270,0);
    glVertex2f(316,0);
    glVertex2f(316,2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.58, 0.63, 0.66); //window
    glVertex2f(288,22);
    glVertex2f(288,10);
    glVertex2f(310,10);
    glVertex2f(310,22);
    glEnd();

    glBegin(GL_POLYGON); //up
    glColor3f(0.45, 0.31, 0.23); // Light blue// Top color
    // Define vertices
    glVertex2f(274, 40);
    glVertex2f(270, 26);

    glColor3f(0.45, 0.31, 0.23); // Dark brown// Bottom color
    // Define vertices
    glVertex2f(316, 26);
    glVertex2f(312, 40);
    glEnd();

    }

}

void building_backD(){
    if (nightD)
    {
    // Reversed top to bottom shading
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.21, 0.15); // Bottom color
    glVertex2f(-20, 60);
    glColor3f(0.13, 0.21, 0.15); // Bottom color
    glVertex2f(-20, 0);
    glColor3f(0.17, 0.29, 0.20); // Top color
    glVertex2f(320, 0);
    glColor3f(0.17, 0.29, 0.20); // Top color
    glVertex2f(320, 60);
    glEnd();
    }

    else
    {
    // Reversed top to bottom shading
    glBegin(GL_POLYGON);
    glColor3f(0.20, 0.33, 0.07); // Bottom color
    glVertex2f(-20, 60);
    glColor3f(0.20, 0.33, 0.07); // Bottom color
    glVertex2f(-20, 0);
    glColor3f(0.23, 0.42, 0.08); // Top color
    glVertex2f(320, 0);
    glColor3f(0.23, 0.42, 0.08); // Top color
    glVertex2f(320, 60);
    glEnd();
    }


}

void roadD(){
    if (nightD)
    {
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); //road
    glVertex2f(-20,-28);
    glVertex2f(-20,-2);
    glVertex2f(320,-2);
    glVertex2f(320,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.72, 0.72); //road
    glVertex2f(-20,0);
    glVertex2f(-20,-2);
    glVertex2f(320,-2);
    glVertex2f(320,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.72, 0.72); //road
    glVertex2f(-20,-28);
    glVertex2f(-20,-30);
    glVertex2f(320,-30);
    glVertex2f(320,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(300,-14);
    glVertex2f(300,-16);
    glVertex2f(320,-16);
    glVertex2f(320,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(260,-14);
    glVertex2f(260,-16);
    glVertex2f(280,-16);
    glVertex2f(280,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(220,-14);
    glVertex2f(220,-16);
    glVertex2f(240,-16);
    glVertex2f(240,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(180,-14);
    glVertex2f(180,-16);
    glVertex2f(200,-16);
    glVertex2f(200,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(140,-14);
    glVertex2f(140,-16);
    glVertex2f(160,-16);
    glVertex2f(160,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(100,-14);
    glVertex2f(100,-16);
    glVertex2f(120,-16);
    glVertex2f(120,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(60,-14);
    glVertex2f(60,-16);
    glVertex2f(80,-16);
    glVertex2f(80,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(20,-14);
    glVertex2f(20,-16);
    glVertex2f(40,-16);
    glVertex2f(40,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(-20,-14);
    glVertex2f(-20,-16);
    glVertex2f(0,-16);
    glVertex2f(0,-14);
    glEnd();
    }

    else
    {
        glBegin(GL_POLYGON);
    glColor3f(0.33, 0.33, 0.33); //road
    glVertex2f(-20,-28);
    glVertex2f(-20,-2);
    glVertex2f(320,-2);
    glVertex2f(320,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.72, 0.72); //road
    glVertex2f(-20,0);
    glVertex2f(-20,-2);
    glVertex2f(320,-2);
    glVertex2f(320,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.72, 0.72, 0.72); //road
    glVertex2f(-20,-28);
    glVertex2f(-20,-30);
    glVertex2f(320,-30);
    glVertex2f(320,-28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(300,-14);
    glVertex2f(300,-16);
    glVertex2f(320,-16);
    glVertex2f(320,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(260,-14);
    glVertex2f(260,-16);
    glVertex2f(280,-16);
    glVertex2f(280,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(220,-14);
    glVertex2f(220,-16);
    glVertex2f(240,-16);
    glVertex2f(240,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(180,-14);
    glVertex2f(180,-16);
    glVertex2f(200,-16);
    glVertex2f(200,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(140,-14);
    glVertex2f(140,-16);
    glVertex2f(160,-16);
    glVertex2f(160,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(100,-14);
    glVertex2f(100,-16);
    glVertex2f(120,-16);
    glVertex2f(120,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(60,-14);
    glVertex2f(60,-16);
    glVertex2f(80,-16);
    glVertex2f(80,-14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(20,-14);
    glVertex2f(20,-16);
    glVertex2f(40,-16);
    glVertex2f(40,-14);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.84, 0.75, 0.05); //road d
    glVertex2f(-20,-14);
    glVertex2f(-20,-16);
    glVertex2f(0,-16);
    glVertex2f(0,-14);
    glEnd();
    }


}

void carD(){

    // Car 3
    glPushMatrix();
    glTranslatef(_carPositionX3D, 15.0f, 0.0f); // Adjusted position
    glBegin(GL_POLYGON);
    glColor3f(0.14, 0.44, 0.72); // Car body
    glVertex2f(128, -12);
    glVertex2f(124, -12);
    glVertex2f(124, -20); // Adjusted vertex
    glVertex2f(122, -22); // Adjusted vertex
    glVertex2f(122, -26); // Adjusted vertex
    glVertex2f(148, -26); // Adjusted vertex
    glVertex2f(148, -22); // Adjusted vertex
    glVertex2f(146, -20); // Adjusted vertex
    glVertex2f(143.6, -20); // Adjusted vertex
    glVertex2f(142, -16); // Adjusted vertex
    glVertex2f(132, -16); // Adjusted vertex
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.56, 0.57); // glass
    glVertex2f(132, -17); // Adjusted vertex
    glVertex2f(134, -17); // Adjusted vertex
    glVertex2f(134, -22); // Adjusted vertex
    glVertex2f(129, -22); // Adjusted vertex
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.56, 0.57); // glass
    glVertex2f(135, -17); // Adjusted vertex
    glVertex2f(139, -17); // Adjusted vertex
    glVertex2f(139, -22); // Adjusted vertex
    glVertex2f(135, -22); // Adjusted vertex
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.56, 0.56, 0.57); // glass
    glVertex2f(140, -17); // Adjusted vertex
    glVertex2f(142, -17); // Adjusted vertex
    glVertex2f(143.1, -22); // Adjusted vertex
    glVertex2f(140, -22); // Adjusted vertex
    glEnd();

    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.04, 0.04, 0.04);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 128, y - 26); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_POLYGON); // Left wheel rim
    glColor3f(0.43, 0.41, 0.37);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 128, y - 26); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.04, 0.04, 0.04);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 142, y - 26); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel rim
    glColor3f(0.43, 0.41, 0.37);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 142, y - 26); // Adjusted vertex
    }
    glEnd();
    glPopMatrix();

    // Car 1
    glPushMatrix();
    glTranslatef(_carPositionX1D, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.81, 0.29, 0.22); //Car body
    glVertex2f(128, -12);
    glVertex2f(124,-12);
    glVertex2f(122,-14);
    glVertex2f(122,-18);
    glVertex2f(148, -18);
    glVertex2f(148,-14);
    glVertex2f(146, -12);
    glVertex2f(143.6,-12);
    glVertex2f(142, -8);
    glVertex2f(132,-8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.99, 1.00); //Car glass
    glVertex2f(132,-9);
    glVertex2f(134,-9);
    glVertex2f(134,-12);
    glVertex2f(129,-12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.99, 1.00); //Car glass
    glVertex2f(135,-9);
    glVertex2f(139,-9);
    glVertex2f(139,-12);
    glVertex2f(135,-12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.83, 0.99, 1.00); //Car glass
    glVertex2f(140,-9);
    glVertex2f(142,-9);
    glVertex2f(143.1,-12);
    glVertex2f(140,-12);
    glEnd();

    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3f(0.04, 0.04, 0.04); // White color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+128, y-18);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.43, 0.41, 0.37);
    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=-1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+128, y-18);
    }
    glEnd();


    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3f(0.04, 0.04, 0.04); // White color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+142, y-18);
    }
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.43, 0.41, 0.37);
    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=-1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+142, y-18);
    }
    glEnd();
    glPopMatrix();

    // Car 2
    glPushMatrix();
    glTranslatef(_carPositionX2D, -5.0f, 0.0f); // Adjusted position
    glBegin(GL_POLYGON);
    glColor3f(0.49, 0.09, 0.11); // Car body
    glVertex2f(128, -12);
    glVertex2f(124,-12);
    glVertex2f(122,-14);
    glVertex2f(122,-18);
    glVertex2f(148, -18);
    glVertex2f(148,-14);
    glVertex2f(146, -12);
    glVertex2f(143.6,-12);
    glVertex2f(142, -8);
    glVertex2f(132,-8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.50, 0.50); // Car glass
    glVertex2f(132,-9);
    glVertex2f(134,-9);
    glVertex2f(134,-12);
    glVertex2f(129,-12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.50, 0.50); // Car glass
    glVertex2f(135,-9);
    glVertex2f(139,-9);
    glVertex2f(139,-12);
    glVertex2f(135,-12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.50, 0.50); // Car glass
    glVertex2f(140,-9);
    glVertex2f(142,-9);
    glVertex2f(143.1,-12);
    glVertex2f(140,-12);
    glEnd();

    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.04, 0.04, 0.04);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+128, y-18);
    }
    glEnd();

    glBegin(GL_POLYGON); // Left wheel rim
    glColor3f(0.43, 0.41, 0.37);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+128, y-18);
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.04, 0.04, 0.04);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+142, y-18);
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel rim
    glColor3f(0.43, 0.41, 0.37);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-1;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+142, y-18);
    }
    glEnd();
    glPopMatrix();


}

void updatecarD(int value){
    if (carMovingD) {
        // Update the car's horizontal positions
        _carPositionX1D -= 1.5f;
        _carPositionX2D -= 2.0f; // Adjusted speed for car 2
        _carPositionX3D += 2.5f; // Adjusted speed for car 3

        // Reset positions to the initial positions when they reach the end of the screen
        if (_carPositionX1D <= -320.0f) {
            _carPositionX1D = 320.0f;
        }
        if (_carPositionX2D <= -320.0f) {
            _carPositionX2D = 320.0f;
        }
        if (_carPositionX3D >= 320.0f) {
            _carPositionX3D = -320.0f;
        }

        // Update the wheel rotation angle for car 1
        _angle1D += 2.0f;
        if (_angle1D > 360.0f) {
            _angle1D -= 360.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, updatecarD, 0);
}

//part 5
void railD(){

    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); // line
    glVertex2f(-20, -36);
    glVertex2f(-20, -37);
    glVertex2f(320, -37);
    glVertex2f(320, -36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); // line
    glVertex2f(-20, -29);
    glVertex2f(-20, -30);
    glVertex2f(320, -30);
    glVertex2f(320, -29);
    glEnd();

    for (int i = 0; i < 48; ++i) {
        float startX = -16.0f + i * 7.0f;

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f); // Slipper
        glVertex2f(startX, -30);
        glVertex2f(startX, -36);
        glVertex2f(startX + 2.0f, -36);
        glVertex2f(startX + 2.0f, -30);
        glEnd();
    }

}

void trainD (){

    for (int i = 0; i < 6; ++i) {
        glPushMatrix();
        glTranslatef(trainPositionX[i], 0.0f, 0.0f); // Translate train based on trainPositionX

    // train 1
    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.29, 0.29, 0.33);
    for(int j=0; j<200; ++j) {
        float A=(j*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+25, y-35);
    }
    glEnd();

    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.29, 0.29, 0.33);
    for(int j=0; j<200; ++j) {
        float A=(j*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+30, y-35);
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.29, 0.29, 0.33);
    for (int j = 0; j < 200; ++j) {
        float A = (j * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 41, y - 35); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.29, 0.29, 0.33);
    for (int j = 0; j < 200; ++j) {
        float A = (j * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 46, y - 35); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.00, 0.00, 0.00); // train Connect
    glVertex2f(52, -27);
    glVertex2f(54, -27);
    glVertex2f(52, -27.2);
    glVertex2f(54, -27.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.00, 0.00, 0.00); // train Connect
    glVertex2f(52, -31.8);
    glVertex2f(54, -31.8);
    glVertex2f(52, -32);
    glVertex2f(54, -32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.41, 0.40); // train body
    glVertex2f(22, -24);
    glVertex2f(20, -26);
    glVertex2f(20, -33);
    glVertex2f(22, -35);
    glVertex2f(50, -35);
    glVertex2f(52, -33);
    glVertex2f(52, -26);
    glVertex2f(50, -24);
    glEnd();



    // train engine
    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.29, 0.29, 0.33);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+64, y-35);
    }
    glEnd();

    glBegin(GL_POLYGON); // Left wheel
    glColor3f(0.29, 0.29, 0.33);
    for(int i=0; i<200; i++) {
        float A=(i*2*pi)/200;
        float r=-2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+59, y-35);
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.29, 0.29, 0.33);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 77, y - 35); // Adjusted vertex
    }
    glEnd();

    glBegin(GL_POLYGON); // Right wheel
    glColor3f(0.29, 0.29, 0.33);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = -2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 72, y - 35); // Adjusted vertex
    }
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.41, 0.40); // train body
    glVertex2f(56, -24);
    glVertex2f(54, -26);
    glVertex2f(54, -33);
    glVertex2f(56, -35);
    glVertex2f(81, -35);
    glVertex2f(84, -33);
    glVertex2f(84, -31);
    glVertex2f(78, -24);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // train window
    glVertex2f(24, -26);
    glVertex2f(24, -30);
    glVertex2f(28, -30);
    glVertex2f(28, -26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // train window
    glVertex2f(44, -26);
    glVertex2f(44, -30);
    glVertex2f(48, -30);
    glVertex2f(48, -26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train window middle
    glVertex2f(24, -27);
    glVertex2f(28, -27);
    glVertex2f(28, -27.5);
    glVertex2f(24, -27.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train window middle
    glVertex2f(44, -27);
    glVertex2f(48, -27);
    glVertex2f(48, -27.5);
    glVertex2f(44, -27.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train window middle
    glVertex2f(44, -28.5);
    glVertex2f(48, -28.5);
    glVertex2f(48, -29);
    glVertex2f(44, -29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train window middle
    glVertex2f(24, -28.5);
    glVertex2f(28, -28.5);
    glVertex2f(28, -29);
    glVertex2f(24, -29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // train door
    glVertex2f(31, -24);
    glVertex2f(31, -35);
    glVertex2f(41, -35);
    glVertex2f(41, -24);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.95, 0.95, 0.95); // train door
    glVertex2f(36, -25);
    glVertex2f(36, -34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train door window
    glVertex2f(32, -26);
    glVertex2f(34, -26);
    glVertex2f(34, -31);
    glVertex2f(32, -31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train door window
    glVertex2f(38, -26);
    glVertex2f(40, -26);
    glVertex2f(40, -31);
    glVertex2f(38, -31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // engine window
    glVertex2f(74, -26);
    glVertex2f(78, -26);
    glVertex2f(81, -30);
    glVertex2f(74, -30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // engine window
    glVertex2f(64, -26);
    glVertex2f(69, -26);
    glVertex2f(69, -30);
    glVertex2f(64, -30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // en window middle
    glVertex2f(64, -27);
    glVertex2f(69, -27);
    glVertex2f(69, -27.5);
    glVertex2f(64, -27.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // en window middle
    glVertex2f(64, -28.5);
    glVertex2f(69, -28.5);
    glVertex2f(69, -29);
    glVertex2f(64, -29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // en window middle
    glVertex2f(74, -27);
    glVertex2f(78.7551, -27.0068);
    glVertex2f(79.1263, -27.5017);
    glVertex2f(74, -27.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // en window middle
    glVertex2f(74, -28.5);
    glVertex2f(79.8689, -28.4919);
    glVertex2f(80.25, -29);
    glVertex2f(74, -29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.13, 0.13); // train door
    glVertex2f(57, -24);
    glVertex2f(57, -35);
    glVertex2f(63, -35);
    glVertex2f(63, -24);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.95, 0.95, 0.95); // train door
    glVertex2f(62, -25);
    glVertex2f(62, -33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.95, 0.95, 0.95); // train door window
    glVertex2f(58, -26);
    glVertex2f(60, -26);
    glVertex2f(60, -31);
    glVertex2f(58, -31);
    glEnd();



    glPopMatrix();

}

}

void updatetrainD(int value) {
    if (trainMovingForwardD) {
        // Update the train horizontal positions
        for (int i = 0; i < 6; ++i) {
            trainPositionX[i] += 1.5f;
            // Reset positions to the initial positions when they reach the end of the screen
            if (trainPositionX[i] >= 320.0f) {
                trainPositionX[i] = -320.0f;
            }
        }
    } else if (trainMovingBackwardD) {
        // Update the train horizontal positions
        for (int i = 0; i < 6; ++i) {
            trainPositionX[i] -= 1.5f;
            // Reset positions to the initial positions when they reach the end of the screen
            if (trainPositionX[i] <= -320.0f) {
                trainPositionX[i] = 320.0f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, updatetrainD, 0);
}

void river_backD(){

    if (nightD)
    {
    glBegin(GL_POLYGON);
    // Define top and bottom colors
    glColor3f(0.22, 0.14, 0.12); // Top color
    glVertex2f(-20, -75);
    glVertex2f(320, -75);
    glColor3f(0.24, 0.17, 0.16); // Bottom color
    glVertex2f(320, -30);
    glVertex2f(-20, -30);
    glEnd();
    }

    else
    {
    glBegin(GL_POLYGON);
    // Define top and bottom colors
    glColor3f(0.55, 0.50, 0.44); // Top color
    glVertex2f(-20, -75);
    glVertex2f(320, -75);
    glColor3f(0.50, 0.41, 0.36); // Bottom color
    glVertex2f(320, -30);
    glVertex2f(-20, -30);
    glEnd();
    }

}

//part 6
void riverD(){
    if (nightD)
    {
    glBegin(GL_POLYGON);
    // Define top and bottom colors
    glColor3f(0.13, 0.24, 0.29); // Top color
    glVertex2f(-20, -75);
    glVertex2f(-20, -45);
    for (float x = -20; x <= 320; x += 5) {
        float y = waveHeightD * sin((x + waveOffsetD) * 0.1f);
        // Interpolate color from top to bottom
        float t = (y + 45) / 30.0f; // Normalize y coordinate to range [0, 1]
        glColor3f(0.22, 0.35, 0.40); // Bottom color
        glVertex2f(x, -45 + y);
    }
    glVertex2f(320, -45);
    glVertex2f(320, -75);
    glEnd();
    }

    else
    {
    glBegin(GL_POLYGON);
    // Define top and bottom colors
    glColor3f(0.39, 0.72, 0.87); // Top color
    glVertex2f(-20, -75);
    glVertex2f(-20, -45);
    for (float x = -20; x <= 320; x += 5) {
        float y = waveHeightD * sin((x + waveOffsetD) * 0.1f);
        // Interpolate color from top to bottom
        float t = (y + 45) / 30.0f; // Normalize y coordinate to range [0, 1]
        glColor3f(0.24, 0.64, 0.81); // Bottom color
        glVertex2f(x, -45 + y);
    }
    glVertex2f(320, -45);
    glVertex2f(320, -75);
    glEnd();
    }

}

void updateWaveD(int value){
    waveOffsetD += waveSpeedD;
    glutPostRedisplay();
    glutTimerFunc(20, updateWaveD, 0);
}

void gunboatD(){
    glPushMatrix();
    glTranslatef(boat_runD, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.13, 0.13); //b
    glVertex2f(2,-66);
    glVertex2f(10,-70);
    glVertex2f(50,-70);
    glVertex2f(56,-64);
    glVertex2f(40,-64);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11); //b
    glVertex2f(2,-66);
    glVertex2f(40,-64);
    glVertex2f(38,-62);
    glVertex2f(0,-65);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.39, 0.39, 0.40); //b
    glVertex2f(32.5,-62.5);
    glVertex2f(29,-59);
    glVertex2f(26,-59);
    glVertex2f(0,-62);
    glVertex2f(0,-65);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.22, 0.22, 0.22); //b
    glVertex2f(26,-59);
    glVertex2f(22,-54);
    glVertex2f(10,-56);
    glVertex2f(5,-60);
    glVertex2f(0,-61);
    glVertex2f(0,-62);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.00); //b
    glVertex2f(31.5,-61.5);
    glVertex2f(30.5,-60.5);
    glVertex2f(43,-57);
    glVertex2f(44,-58);
    glEnd();
    glPopMatrix();

}

void updategunboatD(int value){
    if (moveForwardD) {
        boat_runD += 1.1f; // Adjust speed as desired
    } else if (moveBackwardD) {
        boat_runD -= 1.1f; // Adjust speed as desired
    }

    // Reset position to the left side when it reaches the right side
    if (boat_runD > 320.0f) {
        boat_runD = -20.0f;
    } else if (boat_runD < -20.0f) {
        boat_runD = 320.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updategunboatD, 0);
}

void DisplayDeep() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 320, -75, 120); // Example values for Deep's part
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glClearColor(0.0f, 0.0f, 0.0f, .0f); // Set background color to white and opaque
    //glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();         // Clear the color buffer (background)
    glLineWidth(2.0);
    skyD();
    air_balloonD ();
    birdD();
    sun_moonD();
    cloudD();
    starD();
    hillsD();
    smallhillD();
    building_backD();
    treeD();
    grassD();
    homeD();
    lamppostD();
    benchD();
    umbrellaD();
    trafficlightD();
    hotelD();
    atmD();
    tea_stallD();
    roadD();
    carD();
    river_backD();
    riverD();
    railD();
    trainD();
    gunboatD();

    glFlush();  // Render now
    glutSwapBuffers();
}

///Depp's code end

///Mustakim's code start

void sun()
{
     glPushMatrix();
	glTranslatef(position_sun,0.0, 0.0);
    float pi=2*3.1416l;
     int tri=40;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255, 153);
     x=400;y=900;r=40;
     glVertex2f(x,y);
     for (i=0;i<=tri;i++)
        {
            glVertex2f(
                       x+(r*cos(i*pi/tri)),
                       y+(r*sin(i*pi/tri))
                       );
     }
     glEnd();


     glBegin(GL_TRIANGLE_FAN);
     glColor3ub(255,255, 0);
     x=400;y=900;r=30;
     glVertex2f(x,y);
     for (i=0;i<=tri;i++)
        {
            glVertex2f(
                       x+(r*cos(i*pi/tri)),
                       y+(r*sin(i*pi/tri))
                       );
     }
     glPopMatrix();

     glEnd();
}
//Part-4

void DisplayMustakim() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0); // Example values for Mustakim's part
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    	glClear(GL_COLOR_BUFFER_BIT);
//Part_4.1(hospital)
    glBegin(GL_QUADS);
	glColor3ub(60, 128, 0.0);
	glVertex2i(0,640);
	glVertex2i(1000,640);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();
	glPushMatrix();
    glTranslatef(0, 50, 0);

	glColor3ub(188,0,28);   //BODY
    glBegin(GL_QUADS);
    glVertex2i(575, 350);
    glVertex2i(575, 425);
	glVertex2i(825, 425);
	glVertex2i(825, 350);
	glEnd();

	glColor3ub(100, 805, 200);   //ROOF
    glBegin(GL_QUADS);
    glVertex2i(550, 425);
    glVertex2i(600, 460);
	glVertex2i(800, 460);
	glVertex2i(850, 425);
	glEnd();

	glColor3ub(139, 137, 143);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(565, 340);
    glVertex2i(565, 350);
	glVertex2i(835, 350);
	glVertex2i(835, 340);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);   //DOOR
    glBegin(GL_QUADS);
    glVertex2i(690, 350);
    glVertex2i(690, 400);
	glVertex2i(710, 400);
	glVertex2i(710, 350);
	glEnd();
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

	glColor3f(1.0, 1.0, 1.0);  //Left Windows
    glBegin(GL_QUADS);
    glVertex2i(595, 375);
    glVertex2i(595, 400);
	glVertex2i(615, 400);
	glVertex2i(615, 375);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(635, 375);
    glVertex2i(635, 400);
	glVertex2i(655, 400);
	glVertex2i(655, 375);
	glEnd();
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else
	glColor3f(1.0, 1.0, 1.0);  //Right Windows
    glBegin(GL_QUADS);
    glVertex2i(805, 375);
    glVertex2i(805, 400);
	glVertex2i(785, 400);
	glVertex2i(785, 375);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(765, 400);
	glVertex2i(745, 400);
	glVertex2i(745, 375);
	glVertex2i(765, 375);
	glEnd();

    glPopMatrix();

/// barricade

   glPushMatrix();
    glScalef(0.1, 0.09, 0.1);
    glTranslatef(5000, 2700, 10);
    glBegin(GL_QUADS);
    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glVertex2i(-300, -50);
    glVertex2i(-300, 50);
    glVertex2i(300, 50);
    glVertex2i(300, -50);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 100);
    glVertex2i(-300, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 250);
    glVertex2i(-300, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-200, 400);
    glVertex2i(-150, 400);
    glVertex2i(-150, -100);
    glVertex2i(-200, -100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(200, 400);
    glVertex2i(150, 400);
    glVertex2i(150, -100);
    glVertex2i(200, -100);
    glEnd();

    glPopMatrix();
/// barricade

   glPushMatrix();
    glScalef(0.1, 0.09, 0.1);
    glTranslatef(8000, 2700, 10);
    glBegin(GL_QUADS);
    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glVertex2i(-300, -50);
    glVertex2i(-300, 50);
    glVertex2i(300, 50);
    glVertex2i(300, -50);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 100);
    glVertex2i(-300, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 250);
    glVertex2i(-300, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-200, 400);
    glVertex2i(-150, 400);
    glVertex2i(-150, -100);
    glVertex2i(-200, -100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(200, 400);
    glVertex2i(150, 400);
    glVertex2i(150, -100);
    glVertex2i(200, -100);
    glEnd();

    glPopMatrix();

    /// barricade

   glPushMatrix();
    glScalef(0.1, 0.09, 0.1);
    glTranslatef(2000, 2700, 10);
    glBegin(GL_QUADS);
    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glVertex2i(-300, -50);
    glVertex2i(-300, 50);
    glVertex2i(300, 50);
    glVertex2i(300, -50);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 100);
    glVertex2i(-300, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-300, 250);
    glVertex2i(-300, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 250);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-200, 400);
    glVertex2i(-150, 400);
    glVertex2i(-150, -100);
    glVertex2i(-200, -100);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(200, 400);
    glVertex2i(150, 400);
    glVertex2i(150, -100);
    glVertex2i(200, -100);
    glEnd();

    glPopMatrix();
//Part_4.2(Circle Tree)

/////circle tree 1

    glPushMatrix();
    glTranslatef(200, 450, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
/////circle tree 2
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(250, 50, 0);
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
   glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
   glPopMatrix();
///circle tree 3
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
   glTranslatef(350, 50, 0);
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    //glColor3f(1.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
    glPopMatrix();
///near tree circle tree 4

    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(250, 35, 0);


    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();



    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);



    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
///circle tree 4

glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(350, 47, 0);


glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);

glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
 glPopMatrix();
///circle tree 5
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(756, 80, 0);
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.8, 0.5);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glColor3f(0.4, 0, 0.5);
   glBegin(GL_QUADS);
    glVertex2i(198, 395);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 395);
	glEnd();
 glPopMatrix();
///circle tree 7
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(650, 40, 0);
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
glPopMatrix();
///circle tree 6 near tree

glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(50, 34, 0);
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);
glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPopMatrix();
glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
	glVertex2i(203, 425);
	glVertex2i(203, 380);
	glEnd();
 glPopMatrix();

//Part 4.3 (Hills)
glColor3ub(49,175,141);
glBegin(GL_QUADS);
glVertex2i(0,630);          //   back 1
glVertex2i(0,740);
glVertex2i(50,760);
glVertex2i(50,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(50,630);          //   back 2
glVertex2i(50,760);
glVertex2i(120,750);
glVertex2i(120,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(100,630);          //   back 3
glVertex2i(120,750);
glVertex2i(180,800);
glVertex2i(180,630);
glEnd();


glBegin(GL_QUADS);
glVertex2i(180,630);       //  back 4
glVertex2i(180,800);
glVertex2i(240,810);
glVertex2i(240,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(240,630);
glVertex2i(240,810);
glVertex2i(290,770);  ////   back 5
glVertex2i(290,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(290,630);
glVertex2i(290,770);
glVertex2i(390,790);       /////  back   6
glVertex2i(390,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(400,630);
glVertex2i(470,790);         ///////// back 5
glVertex2i(500,790);
glVertex2i(500,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(500,630);
glVertex2i(500,790);         //////////// back 6
glVertex2i(570,700);
glVertex2i(570,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(570,630);
glVertex2i(570,700);
glVertex2i(620,790);         ////////// back 7
glVertex2i(620,630);
glEnd();


glBegin(GL_QUADS);
glVertex2i(620,630);
glVertex2i(620,790);             ///////// back  8
glVertex2i(700,750);
glVertex2i(700,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(700,630);
glVertex2i(700,750);                  ////////  back 9
glVertex2i(800,790);
glVertex2i(800,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(800,630);
glVertex2i(800,790);          //////////back 10
glVertex2i(890,680);
glVertex2i(890,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(890,630);
glVertex2i(890,680);       //// back 11
glVertex2i(950,770);
glVertex2i(950,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(950,630);
glVertex2i(950,770);       //////////// back 12
glVertex2i(1100,790);
glVertex2i(1100,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1100,630);
glVertex2i(1100,790);            //////// back     13
glVertex2i(1200,700);
glVertex2i(1200,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1100,630);
glVertex2i(1200,700);            //////// back     14
glVertex2i(1300,790);
glVertex2i(1300,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1300,630);
glVertex2i(1300,790);             //////// back     15
glVertex2i(1400,740);
glVertex2i(1400,630);
glEnd();
glColor3ub(52,203,147);
glBegin(GL_QUADS);
glVertex2i(0,630);          //   1
glVertex2i(20,670);
glVertex2i(80,700);
glVertex2i(80,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(80,630);
glVertex2i(80,700);       //   2
glVertex2i(120,700);
glVertex2i(120,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(120,630);
glVertex2i(120,700);      //     3
glVertex2i(200,750);
glVertex2i(200,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(200,630);
glVertex2i(200,750);     //     4
glVertex2i(270,690);
glVertex2i(270,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(270,630);
glVertex2i(270,690);           //   5
glVertex2i(400,820);
glVertex2i(400,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(400,630);            //      6
glVertex2i(400,820);
glVertex2i(520,740);
glVertex2i(520,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(520,630);
glVertex2i(520,740);            //          7
glVertex2i(570,790);
glVertex2i(570,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(570,630);
glVertex2i(570,790);           //        8
glVertex2i(620,740);
glVertex2i(620,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(620,630);
glVertex2i(620,740);           //        9
glVertex2i(650,760);
glVertex2i(650,630);
glEnd();


glBegin(GL_QUADS);
glVertex2i(650,630);
glVertex2i(650,760);           //        10
glVertex2i(750,690);
glVertex2i(750,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(750,630);
glVertex2i(750,690);           //        11
glVertex2i(900,740);
glVertex2i(900,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(900,630);
glVertex2i(900,740);           //        12
glVertex2i(1020,720);
glVertex2i(1020,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(900,630);
glVertex2i(900,740);           //        13
glVertex2i(1020,720);
glVertex2i(1020,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1020,630);
glVertex2i(1020,720);                //        14
glVertex2i(1100,740);
glVertex2i(1100,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1100,630);
glVertex2i(1100,740);              //     15
glVertex2i(1200,790);
glVertex2i(1200,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1200,630);
glVertex2i(1200,790);
glVertex2i(1300,700);           //   16
glVertex2i(1300,630);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1300,630);
glVertex2i(1300,700);              //  17
glVertex2i(1500,800);
glVertex2i(1500,630);
glEnd();


glColor3ub(1311,240,197);
glBegin(GL_QUADS);
glVertex2i(20,745);
glVertex2i(50,755);///// left 1
glVertex2i(30,735);
glVertex2i(10,725);
glEnd();


glBegin(GL_QUADS);
glVertex2i(70,750);
glVertex2i(100,740);
glVertex2i(110,730);////// left 2
glVertex2i(60,720);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(180,800);
glVertex2i(240,810); ////////// left 3
glVertex2i(280,770);
glVertex2i(140,760);
glEnd();

glBegin(GL_QUADS);
glVertex2i(240,750);
glVertex2i(230,740);
glVertex2i(290,730);
glVertex2i(270,720);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(470,790);
glVertex2i(480,790); ////////// left 3-4
glVertex2i(480,770);
glVertex2i(467,775);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(300,770);       //////left 4
glVertex2i(365,785);
glVertex2i(320,740);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(500,785);
glVertex2i(520,755);
glVertex2i(510,745);////// left 5
glVertex2i(490,760);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(620,790);
glVertex2i(640,780); ////////// left 5-6
glVertex2i(615,775);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(680,740);
glVertex2i(670,760); ////// left 6
glVertex2i(700,745);
glVertex2i(690,740);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(712,755);
glVertex2i(800,790); ////// left 7
glVertex2i(780,760);
glVertex2i(770,750);
glVertex2i(770,740);
glVertex2i(750,720);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(950,770);
glVertex2i(1100,790); ////// left 8
glVertex2i(1050,740);
glVertex2i(1000,750);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(1300,790);
glVertex2i(1355,750); ////// left 9
glVertex2i(1270,760);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(40,680);
glVertex2i(80,700);
glVertex2i(120,700); ////// upper 1
glVertex2i(110,680);
glVertex2i(70,660);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(157,720);
glVertex2i(200,750);
glVertex2i(220,730); ////// upper 2
glEnd();

glBegin(GL_QUADS);
glVertex2i(400,820);
glVertex2i(400,810);
glVertex2i(390,790); ////// upper 3
glVertex2i(370,790);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(370,790);
glVertex2i(390,790);
glVertex2i(400,780);
glVertex2i(420,760);
glVertex2i(350,760);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(350,760);
glVertex2i(420,760);
glVertex2i(400,740);
glVertex2i(400,730);
glVertex2i(430,710);
glVertex2i(290,700);
glEnd();


glBegin(GL_TRIANGLES);
glVertex2i(570,790);
glVertex2i(590,760);
glVertex2i(520,740);/////upper  4
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(610,730);
glVertex2i(650,760);         //////////upper 5
glVertex2i(675,740);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(900,740);
glVertex2i(800,700);  ///////// upper 6
glVertex2i(860,710);
glVertex2i(870,670);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1000,720);
glVertex2i(1050,725);
glVertex2i(1025,700);
glVertex2i(1000,700);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(1200,790);
glVertex2i(1100,740);
glVertex2i(1235,750);
glVertex2i(1200,730);
glVertex2i(1150,720);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1460,780);
glVertex2i(1370,730);
glVertex2i(1350,710);
glVertex2i(1450,760);
glEnd();
glColor3f(0.4,0.9,0.5);
glBegin(GL_QUADS);
glVertex2i(450,780);
glVertex2i(530,730);
glVertex2i(550,690);
glVertex2i(460,750);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(400,630);
glVertex2i(450,670);
glVertex2i(510,630);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(400,660);
glVertex2i(450,700);
glVertex2i(550,650);
glEnd();
glBegin(GL_QUAD_STRIP);
glVertex2i(140,630);
glVertex2i(120,680);
glVertex2i(170,690);
glVertex2i(170,630);
glEnd();
glBegin(GL_QUAD_STRIP);
glVertex2i(170,630);
glVertex2i(170,690);
glVertex2i(220,670);
glVertex2i(230,630);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(745,690);
glVertex2i(700,630);
glVertex2i(800,630);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(750,630);
glVertex2i(680,690);
glVertex2i(680,630);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(590,630);
glVertex2i(680,660);
glVertex2i(680,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(1000,630);
glVertex2i(950,660);
glVertex2i(1050,690);
glVertex2i(1050,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(1050,630);
glVertex2i(1050,690);
glVertex2i(1070,660);
glVertex2i(1070,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(1070,630);
glVertex2i(1070,660);
glVertex2i(1150,700);
glVertex2i(1150,630);
glEnd();
glBegin(GL_QUADS);
glVertex2i(1150,630);
glVertex2i(1100,660);
glVertex2i(1225,690);
glVertex2i(1225,630);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(1500,750);
glVertex2i(1350,670);
glVertex2i(1500,670);
glEnd();

glBegin(GL_QUADS);
glVertex2i(1350,630);
glVertex2i(1450,670);
glVertex2i(1500,670);
glVertex2i(1500,630);
glEnd();
//Part 4.4

// House 1
glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(400, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House

glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(150, 50, 50); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix


// House 2
glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(200, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25);

// House
glColor3ub(120, 120, 120); // House color
glBegin(GL_QUADS);
glVertex2i(700, 250); // Bottom-left corner
glVertex2i(800, 250); // Bottom-right corner
glVertex2i(800, 350); // Top-right corner
glVertex2i(700, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(100, 70, 70); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(700, 350); // Bottom-left corner
glVertex2i(800, 350); // Bottom-right corner
glVertex2i(750, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(720, 280); // Bottom-left corner
glVertex2i(750, 280); // Bottom-right corner
glVertex2i(750, 310); // Top-right corner
glVertex2i(720, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(770, 250); // Bottom-left corner
glVertex2i(790, 250); // Bottom-right corner
glVertex2i(790, 330); // Top-right corner
glVertex2i(770, 330); // Top-left corner
glEnd();

glPopMatrix();
//3
glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(250, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House
glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(150, 50, 50); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix

//3
glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(250, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House
glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(150, 50, 50); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix
//4
glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(180, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House
glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(100, 70, 70); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix
//road
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,330);
	glVertex2i(1000,330);
	glVertex2i(1000,280);
	glVertex2i(0,280);
	glEnd();

	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(690,390);
	glVertex2i(710,390);
	glVertex2i(710,320);
	glVertex2i(690,320);
	glEnd();
//rail line
if (nightS)
    glColor3ub(250 , 0, 0); // Day color
else

    glColor3ub(150, 150, 144);
	glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(0,205);
    glVertex2i(1000,205);
    glVertex2i(1000,180);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,202);
    glVertex2i(1000,202);
    glVertex2i(1000,205);
    glVertex2i(0,205);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(1000,180);
    glVertex2i(1000,184);
    glVertex2i(0,184);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    float j;
    for(j=0;j<=1000;j+=20) //rail line
   {
        glVertex2i(10+j,180);
        glVertex2i(15+j,205);

    }
    glEnd();

    glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(00, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House

glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(150, 50, 50); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix
//6
  glPushMatrix(); // Push the current matrix onto the stack
glTranslatef(-70, 300, 0); // Translate the house
glScalef(0.60, 0.90, 0.25); // Scale the house

// House

glColor3ub(100, 100, 100); // House color
glBegin(GL_QUADS);
glVertex2i(500, 250); // Bottom-left corner
glVertex2i(600, 250); // Bottom-right corner
glVertex2i(600, 350); // Top-right corner
glVertex2i(500, 350); // Top-left corner
glEnd();

// Roof
glColor3ub(150, 50, 50); // Roof color
glBegin(GL_TRIANGLES);
glVertex2i(500, 350); // Bottom-left corner
glVertex2i(600, 350); // Bottom-right corner
glVertex2i(550, 400); // Top-middle corner
glEnd();

// Window
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

glColor3ub(255, 255, 255); // Window color
glBegin(GL_QUADS);
glVertex2i(520, 280); // Bottom-left corner
glVertex2i(550, 280); // Bottom-right corner
glVertex2i(550, 310); // Top-right corner
glVertex2i(520, 310); // Top-left corner
glEnd();

// Door
glColor3ub(100, 70, 70); // Door color
glBegin(GL_QUADS);
glVertex2i(570, 250); // Bottom-left corner
glVertex2i(590, 250); // Bottom-right corner
glVertex2i(590, 330); // Top-right corner
glVertex2i(570, 330); // Top-left corner
glEnd();

glPopMatrix(); // Restore the original matrix


// Road Line in the center
if (nightS)
    glColor3f(0.1 , 1, 1); // Day color
else

    glColor3ub(255, 255, 255);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    float roadLineHeight = (330 + 280) / 2;
    for (int j = 0; j <= 1000; j += 40)
    {
        glVertex2i(10 + j, roadLineHeight);
        glVertex2i(30 + j, roadLineHeight);
    }
    glEnd();
    glLineWidth(1.0);

//Part 4.5(Tree)
    //TREE 1

    glPushMatrix();
    glScalef(0.4, 0.9, 0.5);
    glTranslatef(500, 350, 0);

   glColor3f(0.6, 0.3, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //TREE 2
    glPushMatrix();
    glScalef(0.50, 0.90, 0.25);
    glTranslatef(400, 350, 0);

    glColor3f(0.6, 0.3, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();
	    glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();

    //tree 3
    glPushMatrix();
    glScalef(0.50, 0.90, 0.5);
    glTranslatef(1100, 350, 0);

    glColor3f(0.6, 0.3, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

   glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 4 //// train tree
    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(250, 200, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
if (nightS)
    glColor3ub(255 , 255, 0); // Day color
else
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 5// train tree small
    glPushMatrix();
    glTranslatef(750, 150, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
if (nightS)
    glColor3ub(255 , 255, 0); // Day color
else
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 6
    glPushMatrix();
    glTranslatef(400, 100, 0);
    glScalef(0.5, 0.5, 0.5);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
if (nightS)
    glColor3ub(255 , 255, 0); // Day color
else
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 7
    glPushMatrix();
    glTranslatef(-50, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 8
    glPushMatrix();
    glTranslatef(180, 90, 0);
    glScalef(0.25, 0.55, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
if (nightS)
    glColor3ub(255 , 255, 0); // Day color
else
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    //tree 9
    glPushMatrix();
    glTranslatef(480, 110, 0);
    glScalef(0.5, 0.5, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();
if (nightS)
    glColor3ub(255 , 255, 0); // Day color
else
	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
//Part 4.5(River)
//river
    glPushMatrix();
    glTranslatef(_run, 0.0, 0.0);
    if (nightS)
    glColor3f( 0.1, 0.1, 1); // Day color
else
    glColor3f(0.5f, 0.5f, 1.0f);

    //glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2i(-1000, 120);
    glVertex2i(1000, 120);
	glVertex2i(1000, 0);
	glVertex2i(-1000, 0);
	glEnd();

    glPopMatrix();
    //Left Moving Boat
    glPushMatrix();
	glTranslatef(-_run, 0.0, 0.0);
    //boat 2
    glPushMatrix();
    glTranslatef(200, 35, 0);
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex2i(130, 40);
    glVertex2i(110, 60);
	glVertex2i(190, 60);
	glVertex2i(170, 40);
	glEnd();
    if (nightS){
     // Day color
	glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(150, 80);
    glVertex2i(170, 80);
	glVertex2i(170, 60);
	glVertex2i(150, 60);
	glEnd();}
else{
	glColor3f(0.329, 0.517, 0.588);
    glBegin(GL_QUADS);
    glVertex2i(150, 80);
    glVertex2i(170, 80);
	glVertex2i(170, 60);
	glVertex2i(150, 60);
	glEnd();}

    glPopMatrix();
    glPopMatrix();

glTranslatef(_run, 0.0, 0.0);
glBegin(GL_QUADS);   //boat lower part
glColor3ub (56,56,52);
glVertex2i(350,10);
glVertex2i(410,60);
glVertex2i(40,35);
glVertex2i(50,10);
glEnd();
glBegin(GL_QUADS);   //lower upper part
glColor3ub(132,132,130);
glVertex2i(60,35);
glVertex2i(257,47);
glVertex2i(250,70);
glVertex2i(65,55);
glEnd();

if (nightS){
     // Day color
glBegin(GL_QUADS);    //middle upper part
glColor3ub(255,255,0);
glVertex2i(250,47);
glVertex2i(275,50);
glVertex2i(270,62);
glVertex2i(250,60);
glEnd();}
else{
glBegin(GL_QUADS);    //middle upper part
glColor3ub(92,92,88);
glVertex2i(250,47);
glVertex2i(275,50);
glVertex2i(270,62);
glVertex2i(250,60);
glEnd();}

if (nightS){
     // Day color
    glBegin(GL_QUADS);   //upper part
glColor3ub(255 , 255, 0);
glVertex2i(90,55);
glVertex2i(200,60);
glVertex2i(180,90);
glVertex2i(95,80);
glEnd();}
else{
glBegin(GL_QUADS);   //upper part
glColor3ub(69,69,68);
glVertex2i(90,55);
glVertex2i(200,60);
glVertex2i(180,90);
glVertex2i(95,80);
glEnd();}

glPopMatrix();
    ///Right Moving Boat
    glPushMatrix();
	glTranslatef(_run2, 0.0, 0.0);

    ///boat 1
    glPushMatrix();

    glPopMatrix();

    ///boat 2
    glPushMatrix();
    glTranslatef(500, 15, 0);


    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 40);
    glVertex2i(110, 60);
	glVertex2i(190, 60);
	glVertex2i(170, 40);
	glEnd();

	glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(130, 80);
    glVertex2i(150, 80);
	glVertex2i(150, 60);
	glVertex2i(130, 60);
	glEnd();

    glPopMatrix();

      ///boat 3

    glPushMatrix();
    glTranslatef(300, 0, 0);


    glColor3f(1, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(130, 40);
    glVertex2i(110, 60);
	glVertex2i(190, 60);
	glVertex2i(170, 40);
	glEnd();

	glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(130, 80);
    glVertex2i(150, 80);
	glVertex2i(150, 60);
	glVertex2i(130, 60);
	glEnd();

    glPopMatrix();


    glPopMatrix();

    ///Left Moving Boat
    glPushMatrix();
	glTranslatef(-_run, 0.0, 0.0);

      ///boat 3

    glPushMatrix();
    glTranslatef(700, -30, 0);


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 40);
    glVertex2i(100, 65);
	glVertex2i(220, 65);
	glVertex2i(190, 40);
	glEnd();

    if (nightS){
     // Day color
	glColor3f(1, 1, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(190, 88);
    glVertex2i(150, 88);
	glVertex2i(150, 65);
	glVertex2i(190, 65);
	glEnd();}
else{
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(190, 88);
    glVertex2i(150, 88);
	glVertex2i(150, 65);
	glVertex2i(190, 65);
	glEnd();}

    glPopMatrix();


    glPopMatrix();


//Part 4.6


//Part-4.7
    //small home
    glPushMatrix();
    glTranslatef(200, 70, 0.0);

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2i(85,310);
    glVertex2i(85,350);
    glVertex2i(130,350);
    glVertex2i(130,310);
    glEnd();
if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else
    glColor3ub(200, 200, 255);
    glBegin(GL_POLYGON);
    glVertex2i(100,310);
    glVertex2i(100,338);
    glVertex2i(115,338);
    glVertex2i(115,310);
    glEnd();

    glColor3ub(0, 128, 255);
    glBegin(GL_TRIANGLES);
    glVertex2i(80,350);
    glVertex2i(107,380);
    glVertex2i(135,350);
    glEnd();

    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(80,310);
    glVertex2i(80,300);
    glVertex2i(135,300);
    glVertex2i(135,310);
    glEnd();
    glPopMatrix();


    //small home2
    glPushMatrix();
    glTranslatef(290, 70, 0.0);

    glColor3ub(182, 163, 240);
    glBegin(GL_POLYGON);
    glVertex2i(85,310);
    glVertex2i(85,350);
    glVertex2i(130,350);
    glVertex2i(130,310);
    glEnd();
    if (nightS)
    glColor3ub(0 , 0, 0); // Day color
else

    glColor3ub(240, 242, 242);
    glBegin(GL_POLYGON);
    glVertex2i(100,310);
    glVertex2i(100,338);
    glVertex2i(115,338);
    glVertex2i(115,310);
    glEnd();

    glColor3ub(55, 161, 163);
    glBegin(GL_TRIANGLES);
    glVertex2i(80,350);
    glVertex2i(107,380);
    glVertex2i(135,350);
    glEnd();

    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(80,310);
    glVertex2i(80,300);
    glVertex2i(135,300);
    glVertex2i(135,310);
    glEnd();
    glPopMatrix();

//Part 4.8
///Making of Rail Body

    glPushMatrix();
    glTranslatef(_ang_tri, 0.0, 0.0);

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();
                if (nightS)
    glColor3f(.0, .0, 0.0); // Day color
else

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();

                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(.0, .0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();

                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(.0, .0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
                    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
                    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(75, 0, 0);

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();
                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(.0, .0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();
                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(.0, .0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();

                if (nightS)
    glColor3f(1 ,1 , 1); // Day color
else
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
                    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
                    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-75, 0, 0);
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();
                if (nightS)
    glColor3f(0 , 0, 0); // Day color
else
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();
                if (nightS)
    glColor3f(0 , 0, 0); // Day color
else
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();
                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(0.0 ,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();

                if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
	glColor3f(.0, .0, .0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
                    if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
                if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(150, 0, 0);
   glColor3f(0.502, 0.0, 0.502);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();
            if (nightS)
    glColor3f(0 , 0, 0); // Day color
else
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();
            if (nightS)
    glColor3f( 0, 0, 0); // Day color
else
	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();
            if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
    glColor3f(.0, .0, .0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();

            if (nightS)
    glColor3f(1 , 1, 1); // Day color
else
	glColor3f(.0, .0, .0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
            if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
        if (nightS)
    glColor3f(1 , 1, 0); // Day color
else
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();
    if (nightS)
    glColor3f(1 , 0, 0); // Day color
else
    glColor3f(0.7, 0.3, 1.0);
	glBegin(GL_QUADS);
    glVertex2i(322, 245);
    glVertex2i(330, 245);
	glVertex2i(330, 232);
	glVertex2i(322, 232);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(310, 253);
    glVertex2i(300, 253);
	glVertex2i(300, 258);
	glVertex2i(310, 258);
	glEnd();

	glPushMatrix();
    glTranslatef(303, 267, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(293, 270, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(283, 272, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

///End of Making of Rail Body

//Part 4.9

    glPushMatrix();
    glTranslatef(0, 40, 0);

    glColor3ub(156, 143, 6);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(465, 340);
    glVertex2i(465, 350);
	glVertex2i(490, 350);
	glVertex2i(490, 340);
	glEnd();
    glColor3ub(104, 138, 143);    //STAND
    glBegin(GL_QUADS);
    glVertex2i(470, 350);
    glVertex2i(470, 425);
	glVertex2i(485, 425);
	glVertex2i(485, 350);
	glEnd();

 if (nightS) {
    glPushMatrix();
    glTranslatef(1000, 40, 0);
    // nightStime rendering
    // Example: Flag taken down
    glEnd();
    glPopMatrix();
} else {
    // Daytime rendering
    glColor3ub(9, 107, 4);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(485, 390);
    glVertex2i(485, 425);
    glVertex2i(550, 425);
    glVertex2i(550, 390);
    glEnd();
}

    //Circle
     if (nightS) {
    glPushMatrix();
    glTranslatef(1000, 40, 0);
    // nightStime rendering
    // Example: Flag taken down
    glEnd();
    glPopMatrix();
} else {
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(516, 407, 0);


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();}
   glPopMatrix();

   glPopMatrix();

    sun();
    glPopMatrix();

//Part4.10
///Cloud

    glPushMatrix();
    glTranslatef(-_run3, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(200, 800, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180, 750, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(250, 800, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    //



//cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180, 750, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPushMatrix();
    glTranslatef(250, 800, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

//3

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(200, 700, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180, 750, 0);
    glBegin(GL_POLYGON);
     glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(250, 800, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
     glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

//4
 glPushMatrix();
    glTranslatef(_run2, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(180, 750, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();
    glPushMatrix();
    glTranslatef(250, 800, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
/// air balloon

glPushMatrix();
glScalef(0.5, 0.5, 0.5);
glTranslatef(_run4, 0.5, 1.0);
glTranslatef(300, 1600, 0);

// Draw balloon body
glColor3ub(255, 0, 0); // Red color
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i += 10) {
    float angle = i * 3.14159 / 180.0;
    float x = 150 + 50 * cos(angle);
    float y = 250 + 100 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

// Draw balloon basket
glColor3ub(139, 69, 19); // Brown color
glBegin(GL_QUADS);
glVertex2i(125, 100);
glVertex2i(175, 100);
glVertex2i(175, 200);
glVertex2i(125, 200);
glEnd();

// Draw ropes
glColor3ub(0, 0, 0); // Black color for ropes
glBegin(GL_LINES);
glVertex2i(150, 250); // Rope 1 starting point (top of the balloon)
glVertex2i(125, 200); // Rope 1 ending point (basket)
glVertex2i(150, 250); // Rope 2 starting point (top of the balloon)
glVertex2i(175, 200); // Rope 2 ending point (basket)
glEnd();

glPopMatrix();



//Part 4.12
//text school
    glColor3f(1.0, 1.0, 1.0);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();
    glPushMatrix();
    glTranslatef(680, 478, 0);
    Sprint(1.0,0,text);
    glPopMatrix();
// end of text
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
    glFlush();
	glutSwapBuffers();
}
//Part 5
void moon()
{

  glPushMatrix();
	glTranslatef(position_sun,0.0, 0.0);
    float pi=2*3.1416l;
     int tri=40;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255, 255);
     x=400;y=900;r=40;
     glVertex2f(x,y);
     for (i=0;i<=tri;i++)
     for (i=0;i<=tri;i++)
        {
            glVertex2f(
                       x+(r*cos(i*pi/tri)),
                       y+(r*sin(i*pi/tri))
                       );
     }
     glEnd();
glPopMatrix();
}
//Part 6
void update(int value) {

	_run += 0.09f;
	if (_run > 1000)
    {
        _run -= 1700;
    }
    _run4 += 1.25f;
	if (_run4 > 1000)
    {
        _run4 += 170;
    }


    _run1 += 3.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1300;
    }

    _run2 += 2.0f;	if (_run2 > 1000)
    {
        _run2 += 300;
    }

     _run3 += 3.0f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}

void railForward(int value){

if(frd){

    _ang_tri += 2.5f;

    if (_ang_tri > 1000) {
		_ang_tri -= 1400;
	}

	glutPostRedisplay();
	glutTimerFunc(25, railForward, 0);
}
}

void railBackward(int value){
if(bck){

    _ang_tri -= 2.2f;

     if (_ang_tri < -350) {
		_ang_tri = 1100;
	}
	glutPostRedisplay();
	glutTimerFunc(100, railBackward, 0);
}
}

void Rain(int value){

if(raindayS){
     glClearColor(0.7,0.7,0.7,0.0);
    _rainS += 5.0f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+10,y+10);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}

void NightS(int value){

if(nightS){

    glClearColor(0.0,0.0,0.0,0.0);
	//glutPostRedisplay();
    glutTimerFunc(5, NightS, 10);
    glFlush();
    glPushMatrix();
   moon();
    glPopMatrix();
}
}

 void update_sun(int value) {

for (i=0;i<5;i++)
    {
     position_sun -= speed_sun;

     }
    glutPostRedisplay();
	glutTimerFunc(100, update_sun, 0);
}


void update_moon(int value) {

for (i=0;i<5;i++)
    {
     position_moon += speed_moon;

     }

    glutPostRedisplay();
	glutTimerFunc(100, update_moon, 0);

}
///Mustakim's code end

///Masum's code start
void triangle(int R, int G, int B, float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(R, G, B);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void triangleCombine(int R1, int G1, int B1, int R2, int G2, int B2, float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(R1, G1, B1);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glBegin(GL_TRIANGLES);
    glColor3ub(R2, G2, B2);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void rectangle(int R, int G, int B, float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);            // Draw a filled rectangle

    glColor3ub(R,G,B); // Set color

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

void rectangleCombine(int R1, int G1, int B1, int R2, int G2, int B2, float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);            // Draw a filled rectangle

    glColor3ub(R1,G1,B1); // Set 1st color

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glBegin(GL_POLYGON);            // Draw a filled rectangle

    glColor3ub(R2,G2,B2); // Set 2nd color

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

void polygon(int R, int G, int B, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_POLYGON); //right side view 1st building
    glColor3ub(R, G, B);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glEnd();
}

void polygonCombine(int R1, int G1, int B1, int R2, int G2, int B2, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_POLYGON); //right side view 1st building
    glColor3ub(R1, B1, G1);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glBegin(GL_POLYGON);
    glColor3ub(R2, B2, G2);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);

    glEnd();
}

void parallelX(int R, int G, int B, float x1, float x2, float x3, float x4, float y1, float y2)
{
    glBegin(GL_POLYGON);   // top white parallel

    glColor3ub(R,G,B); // white color

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x3, y2);
    glVertex2f(x4, y2);
    glEnd();
}

void circle(int R, int G, int B, float rad, float X, float Y)
{
    glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
    glColor3ub(R,G,B); // White color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=rad;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+X, y+Y);
    }
    glEnd();
}

void circleCombile(int R1, int G1, int B1, int R2, int G2, int B2, float rad, float X, float Y)
{
    glBegin(GL_POLYGON);
    glColor3ub(R1,G1,B1); // 1st color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=rad;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+X, y+Y);
    }

    glBegin(GL_POLYGON);
    glColor3ub(R2,G2,B2); // 2nd color

    for(int i=0; i<200; i++)
    {
        float A=(i*2*pi)/200;
        float r=rad;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+X, y+Y);
    }

    glEnd();
}

void sky()
{
    if(night_M){
    glBegin(GL_POLYGON);

    glColor3ub(15, 25, 35);
    glVertex2f(-2500.0,1700.0);
    glColor3ub(80, 80, 80);
    glVertex2f(2500.0,1700.0);
    glColor3ub(85, 87, 89);
    glVertex2f(2500.0,750.0);
    glColor3ub(0, 0, 0);
    glVertex2f(-2500.0,750.0);
    glEnd();

    } else if(night_M==false && rain_M==true){
    glBegin(GL_POLYGON);
    glColor3ub(188, 191, 191);
    glVertex2f(-2500.0,1700.0);
    glVertex2f(2500.0,1700.0);

    glBegin(GL_POLYGON);
    glColor3ub(107, 115, 114);
    glVertex2f(2500.0,750.0);
    glVertex2f(-2500.0,750.0);
    glVertex2f(-2500.0,1700.0);
    glEnd();
    } else {
    glBegin(GL_POLYGON);
    glColor3ub(214, 225, 225);
    glVertex2f(-2500.0,1700.0);
    glVertex2f(2500.0,1700.0);

    glBegin(GL_POLYGON);
    glColor3ub(160, 197, 199);
    glVertex2f(2500.0,750.0);
    glVertex2f(-2500.0,750.0);
    glVertex2f(-2500.0,1700.0);
    glEnd();
    }
}

void stars()
{
    if(night_M==true && rain_M == false){
        circle(202, 198, 189, 3, -2450, 1300);
        circle(202, 198, 189, 4, -1450, 1300);
        circle(202, 198, 189, 5, -750, 1300);
        circle(202, 198, 189, 2, -50, 1300);
        circle(202, 198, 189, 3, 850, 1300);
        circle(202, 198, 189, 2, 1700, 1300);
        circle(202, 198, 189, 4, 2400, 1300);
        circle(202, 198, 189, 4, 1000, 1400);
        circle(202, 198, 189, 2, -1000, 1400);
        circle(202, 198, 189, 4, 100, 1450);
        circle(202, 198, 189, 3, -1300, 1450);
        circle(202, 198, 189, 2, 400, 1400);
        circle(202, 198, 189, 3, -1150, 1350);
        circle(202, 198, 189, 2, 750, 1450);
        circle(202, 198, 189, 2, -450, 1350);

        circle(202, 198, 189, 4, -300, 1500);
        circle(202, 198, 189, 3, -1800, 1450);
        circle(202, 198, 189, 2, -900, 1400);
        circle(202, 198, 189, 3, -1650, 1350);
        circle(202, 198, 189, 2, -1750, 1600);
        circle(202, 198, 189, 2, -1590, 1550);

        circle(202, 198, 189, 4, -2300, 1500);
        circle(202, 198, 189, 3, -2100, 1450);
        circle(202, 198, 189, 2, -1900, 1400);
        circle(202, 198, 189, 3, -2250, 1350);
        circle(202, 198, 189, 2, 2350, 1600);
        circle(202, 198, 189, 3, 2190, 1350);
        circle(202, 198, 189, 3, 1700, 1400);
    }
}

void cloud()
{
    glPushMatrix();
    glTranslatef(move_cloud_M, 0.0, 0.0);

    if(rain_M){
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1600, 1450);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1650, 1550);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1750, 1450);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1800, 1600);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1850, 1500);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1950, 1450);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -1940, 1580);
        circleCombile(195, 195, 195, 145, 145, 145, 100, -2050, 1500);
    } else{
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1600, 1450);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1650, 1550);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1750, 1450);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1800, 1600);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1850, 1500);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1950, 1450);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -1940, 1580);
        circleCombile(255, 255, 255, 215, 215, 215, 100, -2050, 1500);
    }

    //megh
    circleCombile(195, 195, 195, 145, 145, 145, 40, -560, 1320);
    circleCombile(195, 195, 195, 145, 145, 145, 40, -580, 1280);
    circleCombile(195, 195, 195, 145, 145, 145, 40, -620, 1360);
    circleCombile(195, 195, 195, 145, 145, 145, 60, -640, 1300);
    circleCombile(195, 195, 195, 145, 145, 145, 50, -700, 1350);
    circleCombile(195, 195, 195, 145, 145, 145, 40, -720, 1280);
    circleCombile(195, 195, 195, 145, 145, 145, 40, -760, 1340);
    circleCombile(195, 195, 195, 145, 145, 145, 50, -800, 1300);

    glPopMatrix();
}

void rainy_cloud()
{
    glPushMatrix();
    glTranslatef(move_cloud_M, 0.0, 0.0);

    if(rain_M){
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1600, 1400);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1650, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 150, 1400, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1400, 1400);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1500, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 80, 1400, 1600);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1350, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1200, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1100, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 100, 1200, 1400);

    circleCombile(195, 195, 195, 145, 145, 145, 50, 2050, 1600);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2100, 1600);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2150, 1600);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2250, 1600);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2000, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2100, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2200, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2300, 1550);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2050, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2200, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2250, 1500);
    circleCombile(195, 195, 195, 145, 145, 145, 50, 2150, 1500);

    int random1 = rand() % 10 + 1;
    int random2 = rand() % 10 + 1;
    int random3 = rand() % 10 + 1;
    int random4 = rand() % 10 + 1;

    if(random1==1) //Lighting when rain start 1
    {
        triangle(221, 222, 169, 2040, 1340, 2080, 1380, 2080, 1400);
        triangle(221, 222, 169, 2140, 1440, 2100, 1400, 2100, 1380);
        rectangle(221, 222, 169, 2080, 1380, 2100, 1400);
    }
    if(random2==2) //Lighting when rain start 2
    {
        triangle(221, 222, 169, 1150, 1100, 1200, 1180, 1200, 1200);
        triangle(221, 222, 169, 1280, 1280, 1220, 1200, 1220, 1180);
        rectangle(221, 222, 169, 1200, 1180, 1220, 1200);
    }
    if(random3==3) //Lighting when rain start 3
    {
        triangle(221, 222, 169, -820, 1140, -780, 1180, -780, 1200);
        triangle(221, 222, 169, -700, 1240, -760, 1200, -760, 1180);
        rectangle(221, 222, 169, -780, 1180, -760, 1200);
    }
    if(random4==4) //Lighting when rain start 3
    {
        triangle(221, 222, 169, -1900, 1100, -1840, 1220, -1840, 1240);
        triangle(221, 222, 169, -1760, 1340, -1820, 1220, -1820, 1240);
        rectangle(221, 222, 169, -1840, 1220, -1820, 1240);
    }
    }

    glPopMatrix();
}

void Rain_M(int value)
{
    if (rain_M)
    {
        move_rain_M += 0.1;

        /*glBegin(GL_POINTS);
        for (int i = 1; i <= 1000; i++)
        {
            int x = rand(), y = rand();
            x %= 2550; // Use window width for x-coordinate limit
            y %= 1750; // Use window height for y-coordinate limit
            x -= 2550;  // Adjust x-coordinate to start from -5
            y -= 1550;  // Adjust y-coordinate to start from -5
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 0.2, y + 0.2);
            glEnd();
        }*/

        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0); // Set rain color to white
        glLineWidth(2.0f);
        for (int i = 0; i < 1000; i++)
        {
            float x = static_cast<float>(rand() % 5000) - 2500.0f; // Adjust range to fit within window width
            float y = static_cast<float>(rand() % 3200) - 1500.0f; // Adjust range to fit within window height
            glVertex2f(x, y);
            glVertex2f(x, y - 20.0f); // Simulate a falling raindrop
        }

        glEnd();


        glutPostRedisplay();
        glutTimerFunc(2, Rain_M, 0);
        glFlush();
    }
}

void land()
{
    if(night_M){
    rectangleCombine(89, 102, 61, 65, 77, 36, -2500.0,-1100.0,2500.0,750.0);
    }else{
    rectangleCombine(89, 102, 61, 123, 147, 65, -2500.0,-1100.0,2500.0,750.0);
    }
}

void hills()
{
    if(night_M){
    polygon(45,70,42, 820, 750, 950, 1050, 2000, 1000, 2500, 750);
    triangle(34,61,24,-782.098,896.14,-477.37,750.0,-277.37,1050.9);
    triangle(46,80,31,-477.37,750.0,22.63,750.0,-277.37,1050.9);
    triangle(53,70,43,-277.37,1050.9,22.63,750.0,340.1,988.99);
    triangle(34,61,24,155.57,1007.61,847.48,1112.42,1200.0,900.0);
    triangle(46,80,24,22.63,750.0,822.63,750.0,422.63,1050.9);
    triangle(53,70,43,422.63,1050.9,722.63,950.9,822.63,750.0);
    triangle(42,65,38,722.63,950.9,822.63,750.0,1022.63,750.0);
    triangle(46,65,28,722.63,950.9,1200.0,900.0,1022.63,750.0);
    triangle(48,65,38,1022.63,750.0,1922.63,750.0,1392.92,1081.1);
    triangle(38,65,26,1600.0,750.0,2500.0,750.0,2500.0,1100.0);
    triangle(34,57,28,1659.25,915.05,2000.0,1000.0,2500.0,750.0);
    triangle(45,70,37,1659.25,915.05,1922.63,750.9,2500.0,750.0);
    triangle(50,70,42,2228.94,977.6,1922.63,750.9,2500.0,750.0);

    polygon(48,57,40,-2500.0, 1000.0,-2200.0, 900.0,-1977.37, 750.0,-2500.0, 750.0);
    polygon(55,70,43,-2300.49, 933.49,-1900.0, 1050.0,-1477.37, 950.89,-1977.37, 750.0);
    polygon(65,80,55,-1977.37, 750.0,-1477.37, 950.89,-1000.0, 1000.0,-477.37, 750.0);
    polygon(70,80,62,-1595.76, 978.65,-1300.0, 1100.0,-400.60, 1013.11,-782.09, 896.14);

    triangle(34,61,24,-1300.0,1100.0,-1477.37,950.89,-1595.76,978.65);
    triangle(27,48,15,-1300.0,1100.0,-1477.37,950.89,-1000.0,1000.0);
    } else{
    polygon(45,120,42, 820, 750, 950, 1050, 2000, 1000, 2500, 750);
    triangle(34,91,24,-782.098,896.14,-477.37,750.0,-277.37,1050.9);
    triangle(46,127,31,-477.37,750.0,22.63,750.0,-277.37,1050.9);
    triangle(53,108,43,-277.37,1050.9,22.63,750.0,340.1,988.99);
    triangle(34,91,24,155.57,1007.61,847.48,1112.42,1200.0,900.0);
    triangle(46,127,24,22.63,750.0,822.63,750.0,422.63,1050.9);
    triangle(53,108,43,422.63,1050.9,722.63,950.9,822.63,750.0);
    triangle(42,100,38,722.63,950.9,822.63,750.0,1022.63,750.0);
    triangle(46,105,28,722.63,950.9,1200.0,900.0,1022.63,750.0);
    triangle(48,105,38,1022.63,750.0,1922.63,750.0,1392.92,1081.1);
    triangle(38,105,26,1600.0,750.0,2500.0,750.0,2500.0,1100.0);
    triangle(34,97,28,1659.25,915.05,2000.0,1000.0,2500.0,750.0);
    triangle(45,107,37,1659.25,915.05,1922.63,750.9,2500.0,750.0);
    triangle(50,110,42,2228.94,977.6,1922.63,750.9,2500.0,750.0);

    polygon(48,97,40,-2500.0, 1000.0,-2200.0, 900.0,-1977.37, 750.0,-2500.0, 750.0);
    polygon(55,112,43,-2300.49, 933.49,-1900.0, 1050.0,-1477.37, 950.89,-1977.37, 750.0);
    polygon(65,120,55,-1977.37, 750.0,-1477.37, 950.89,-1000.0, 1000.0,-477.37, 750.0);
    polygon(70,125,62,-1595.76, 978.65,-1300.0, 1100.0,-400.60, 1013.11,-782.09, 896.14);

    triangle(34,91,24,-1300.0,1100.0,-1477.37,950.89,-1595.76,978.65);
    triangle(27,78,15,-1300.0,1100.0,-1477.37,950.89,-1000.0,1000.0);
    }

}

void river(float water_level)
{
    //glPushMatrix();
    //glTranslatef(0.0, move_river, 0.0);
    //glScalef(1.0, move_river, 1.0);
    glBegin(GL_POLYGON);

    if(night_M){
    glColor3ub(51, 95, 100);
    } else{
    glColor3ub(56, 119, 127);
    }

    glVertex2f(-2500.0, -1500.0);
    glVertex2f(2500.0, -1500.0);
    glVertex2f(2500.0, -1100.0 + water_level);
    glVertex2f(-2500.0, -1100.0 + water_level);

    glEnd();
    //glPopMatrix();
}

void riverBank()
{
    rectangle(131, 125, 5, -2500.0, -1100.0, 2500.0, -1060.0);
}

void sun_moon()
{
    if(rain_M)
    {
        //sun or covered by cloudy sky
    } else{
        glPushMatrix();
        glTranslatef(0.0f, -move_sun_moon, 0.0f);
        glBegin(GL_POLYGON);// Draw a 1st circle filled with white color
        if(night_M){
        glColor3ub(177, 180, 150);
        } else{
        glColor3ub(213, 204, 9);
        }

        for(int i=0; i<200; i++)
        {
            float A=(i*2*pi)/200;
            float r=150.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1400.0, y+1500.0);
        }
        glEnd();
        glPopMatrix();
    }
}

void road()
{
    rectangle(75, 75, 69, -2500.0, -800.0, 2500.0, -450.0);
}

void fighter_jet1()
{
    glPushMatrix();
    glTranslatef(move_fighter_jet, 0.0, 0.0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(20.0, 1120.0);
    glVertex2f(140.0, 1130.0);
    glVertex2f(300.0, 1155.0);
    glVertex2f(320.0, 1160.0);
    glVertex2f(360.0, 1160.0);
    glVertex2f(380.0, 1140.0);
    glVertex2f(440.0, 1120.0);

    glEnd();

    //wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(60.0, 1123.0);
    glVertex2f(60.0, 1080.0);
    glVertex2f(290.0, 1140.0);
    glEnd();

    //wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(140.0, 1130.0);
    glVertex2f(128.0, 1148.0);
    glVertex2f(229.75, 1144.0);
    glEnd();

    //tail wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(40.0, 1160.0);
    glVertex2f(70.0, 1160.0);
    glVertex2f(140.0, 1130.0);
    glVertex2f(60.0, 1123.0);
    glVertex2f(40.0, 1160.0);
    glEnd();

    //tail wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(100.0, 1147.0);
    glVertex2f(100.0, 1160.0);
    glVertex2f(120.0, 1160.0);
    glVertex2f(140.0, 1130.0);
    glVertex2f(100.0, 1147.0);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3ub(202, 209, 213);

    glVertex2f(300.0, 1155.0);
    glVertex2f(320.0, 1160.0);
    glVertex2f(360.0, 1160.0);
    glVertex2f(380.0, 1140.0);
    glVertex2f(300.0, 1155.0);

    glEnd();

    glPopMatrix();
}

void fighter_jet2()
{
    glPushMatrix();
    glTranslatef(move_fighter_jet, 0.0, 0.0);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(20.0, 1325.0);
    glVertex2f(40.0, 1328.0);
    glVertex2f(60.0, 1330.0);
    glVertex2f(120.210185276416, 1335.5347065763956);
    glVertex2f(140.0, 1340.0);
    glVertex2f(170.0, 1338.0);
    glVertex2f(180.10, 1335.306);
    glVertex2f(200.0, 1330.0);
    glVertex2f(149.903268400867, 1325.4692546698027);
    glEnd();

    //tail wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(30.0, 1340.0);
    glVertex2f(40.0, 1340.0);
    glVertex2f(60.0, 1330.0);
    glVertex2f(40.0, 1328.0);
    glEnd();

    //wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(48.0, 1340.0);
    glVertex2f(55.0, 1340.0);
    glVertex2f(69.92, 1330.81);
    glVertex2f(60.0, 1330.0);
    glVertex2f(50.05, 1334.97);
    glEnd();

    //wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(49.2864482982858, 1326.804561302181);
    glVertex2f(120.0, 1330.0);
    glVertex2f(50.0, 1305.0);
    glEnd();

    //tail wing
    glBegin(GL_POLYGON);
    glColor3ub(84, 88, 85);

    glVertex2f(63.36, 1334.85);
    glVertex2f(120.21, 1335.535);
    glVertex2f(69.92, 1330.81);
    glEnd();

    //window
    glBegin(GL_POLYGON);
    glColor3ub(202, 209, 213);

    glVertex2f(120.21, 1335.535);
    glVertex2f(140.0, 1340.0);
    glVertex2f(170.0, 1338.0);
    glVertex2f(180.10, 1335.306);
    glEnd();

    glPopMatrix();
}

void elevated_road()
{
    //pillars
    rectangle(155, 158, 160, -2350, -700, -2300, -600);
    triangle(155, 158, 160, -2300, -600, -2250, -600, -2300, -700);

    rectangle(155, 158, 160, -1500, -700, -1450, -600);
    triangle(155, 158, 160, -1450, -600, -1400, -600, -1450, -700);

    rectangle(155, 158, 160, -650, -700, -600, -600);
    triangle(155, 158, 160, -600, -600, -550, -612, -600, -700);

    rectangle(155, 158, 160, 200, -700, 250, -600);
    triangle(155, 158, 160, 250, -600, 300, -600, 250, -700);

    rectangle(155, 158, 160, 1050, -700, 1100, -600);
    triangle(155, 158, 160, 1100, -600, 1150, -600, 1100, -700);

    rectangle(155, 158, 160, 1900, -700, 1950, -600);
    triangle(155, 158, 160, 1950, -600, 2000, -600, 1950, -700);

    //girders
    rectangle(46, 48, 48, -2500, -580, -600, -500);
    triangle(46, 48, 48, -600, -500, -600, -580, -550, -500);
    rectangle(155, 158, 160, -2500, -600, -600, -580);

    polygon(46, 48, 48, -550, -500, -150, -600, -200, -680, -600, -580);
    polygon(46, 48, 48, -150, -600, -150, -620, -200, -700, -200, -680);
    polygon(155, 158, 160, -600, -580, -600, -600, -200, -700, -200, -680);

    glBegin(GL_POLYGON);
    glColor3ub(46, 48, 48);

    glVertex2f(-60, -600);
    glVertex2f(200, -500);
    glVertex2f(450, -500);
    glVertex2f(400, -580);
    glVertex2f(200, -580);
    glVertex2f(-110, -685);
    glEnd();

    polygon(46, 48, 48, 450, -500, 450, -520, 400, -600, 400, -580);
    polygon(155, 158, 160, 400, -580, 400, -600, 200, -600, 200, -580);
    polygon(155, 158, 160, 200, -580, 200, -600, -100, -700, -110, -685);

    glBegin(GL_POLYGON);
    glColor3ub(46, 48, 48);

    glVertex2f(800, -600);
    glVertex2f(1050, -500);
    glVertex2f(1050, -580);
    glVertex2f(770, -680);
    glVertex2f(440, -680);
    glVertex2f(480, -600);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155, 158, 160);

    glVertex2f(770, -680);
    glVertex2f(1050, -580);
    glVertex2f(1050, -600);
    glVertex2f(770, -700);
    glVertex2f(440, -700);
    glVertex2f(440, -680);
    glEnd();

    rectangle(46, 48, 48, 1050, -580, 2500, -500);
    rectangle(155, 158, 160, 1050, -600, 2500, -580);
}

void frigate()
{
    glPushMatrix();
    glTranslatef(move_frigate, 0.0, 0.0);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(150, 150, 160);

    glVertex2f(200, -1300);
    glVertex2f(2400, -1320);
    glVertex2f(2380, -1400);
    glVertex2f(400, -1400);
    glVertex2f(200, -1300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(155, 158, 160);

    glVertex2f(1101.53, -1308.2);
    glVertex2f(1200, -1200);
    glVertex2f(1800, -1200);
    glVertex2f(1800, -1250);
    glVertex2f(1900, -1250);
    glVertex2f(1920, -1315.64);
    glEnd();

    polygon(57, 57, 57, 1230, -1230, 1240, -1210, 1190.5, -1210.45, 1172.59, -1230);//front glass

    //main gun
    polygon(48, 48, 48, 420, -1270, 520, -1270, 520, -1275, 420, -1275);
    polygon(114, 114, 114, 500, -1302.73, 520, -1260, 560, -1260, 560, -1303.27);

    //torpedo launcher
    polygon(132, 134, 140, 665, -1230, 754, -1270, 744, -1296, 654, -1256);
    polygon(114, 114, 114, 680.63, -1304.37, 731.11, -1304.83, 730, -1290, 695, -1275);

    //Vertical launcher (SAM, Anti Ship, & Land Attack Missiles)
    polygon(114, 114, 114, 840, -1290, 1040, -1290, 1040, -1307.64, 840.11, -1305.87);

    //sensors
    polygon(155, 158, 160, 1610, -1200, 1700, -1200, 1660, -1100, 1620, -1100);
    polygon(155, 158, 160, 1540, -1200, 1540, -1140, 1500, -1140, 1460, -1200);

    //radars
    polygon(148, 149, 150, 1290, -1030, 1440, -1030, 1440, -1050, 1290, -1050);
    polygon(127, 128, 129, 1360, -1060, 1360, -1050, 1370, -1050, 1370, -1060);
    polygon(155, 158, 160, 1280, -1200, 1350, -1060, 1380, -1060, 1380, -1200);

    //Anti Missile Gun System (Phalanx CIWS)
    polygon(135, 136, 137, 1220, -1200, 1220, -1185, 1240, -1190, 1240, -1200);//front AMG system

    glBegin(GL_POLYGON);
    glColor3ub(155, 158, 160);

    glVertex2f(1216, -1184);
    glVertex2f(1220, -1175);
    glVertex2f(1230, -1170);
    glVertex2f(1246, -1182);
    glVertex2f(1248, -1192);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(14,14,14);
    glLineWidth(1.0);

    glVertex2f(1205, -1160);
    glVertex2f(1220, -1175);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 136, 137);

    glVertex2f(1220, -1175);
    glVertex2f(1230, -1170);
    glVertex2f(1220, -1169.28);
    glEnd();

    polygon(155, 158, 160, 1234, -1173, 1244, -1160, 1256, -1166, 1246, -1182);

    polygon(135, 136, 137, 1770, -1200, 1770, -1190, 1790, -1185, 1790, -1200); //rear AMG system

    glBegin(GL_POLYGON);
    glColor3ub(155, 158, 160);

    glVertex2f(1766, -1191);
    glVertex2f(1768, -1182);
    glVertex2f(1782, -1170);
    glVertex2f(1790, -1174);
    glVertex2f(1794, -1184);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(14,14,14);
    glLineWidth(1.0);

    glVertex2f(1800, -1156);
    glVertex2f(1786, -1172);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 136, 137);

    glVertex2f(1790, -1174);
    glVertex2f(1782, -1170);
    glVertex2f(1788.87, -1168.72);
    glEnd();

    polygon(155, 158, 160, 1768, -1182, 1758, -1168, 1770, -1160, 1779, -1172.56);

    //ASW (Anti-Submarine Warfare Helicopter)
    glBegin(GL_POLYGON);
    glColor3ub(127, 128, 129);

    glVertex2f(2139.97, -1317.84);
    glVertex2f(2080, -1310);
    glVertex2f(2080, -1295);
    glVertex2f(2100, -1285);
    glVertex2f(2115, -1270);
    glVertex2f(2130, -1267.86);
    glVertex2f(2150, -1265);
    glVertex2f(2240, -1265);
    glVertex2f(2370, -1275);
    glVertex2f(2383.60, -1276);
    glVertex2f(2380, -1285);
    glVertex2f(2250, -1290);
    glVertex2f(2219.88, -1318.36);
    glEnd();

    polygon(127, 128, 129, 2370, -1275, 2380, -1260, 2390, -1260, 2383.60, -1276); //tail wing

    polygon(109, 110, 111, 2150, -1265, 2170, -1260, 2220, -1260, 2240, -1265); //engine

    polygon(109, 110, 111, 2180, -1255, 2190, -1255, 2190, -1260, 2180, -1260); //rotor hook
    polygon(109, 110, 111, 2184, -1250, 2186, -1250, 2186, -1255, 2184, -1255);

    glBegin(GL_LINES); //rotor blade
    glColor3ub(14,14,14);
    glLineWidth(1.0);

    glVertex2f(2040, -1250);
    glVertex2f(2330, -1250);
    glEnd();

    glBegin(GL_LINES); //tail rotor blade
    glColor3ub(14,14,14);
    glLineWidth(1.0);

    glVertex2f(2360, -1250);
    glVertex2f(2400, -1290);

    glVertex2f(2360, -1290);
    glVertex2f(2400, -1250);
    glEnd();

    polygon(14, 14, 14, 2100, -1285, 2115, -1270, 2130, -1267.86, 2130, -1285); //front glass

    polygon(14, 14, 14, 2160, -1290, 2160, -1280, 2170, -1280, 2170, -1290); //windows
    polygon(14, 14, 14, 2180, -1280, 2190, -1280, 2190, -1290, 2180, -1290);
    polygon(14, 14, 14, 2210, -1280, 2210, -1290, 2200, -1290, 2200, -1280);

    glPopMatrix();
}

void hospital()
{
    if(night_M)
    {
        rectangleCombine(210, 241, 237, 94, 133, 130, -2200, -200, -800, 200);
        rectangleCombine(210, 241, 237, 94, 133, 130, -2200, 200, -1800, 400);
        rectangleCombine(210, 241, 237, 94, 133, 130, -1200, 200, -800, 400);
    } else {
        rectangleCombine(216, 235, 232, 139, 175, 170, -2200, -200, -800, 200);
        rectangleCombine(139, 175, 170, 216, 235, 232, -2200, 200, -1800, 400);
        rectangleCombine(216, 235, 232, 139, 175, 170, -1200, 200, -800, 400);
    }
    triangle(150, 150, 150, -1800, 400, -1800, 200, -1754, 360);
    polygon(150, 150, 150, -800, 400, -700, 300, -700, -100, -800, -200); //right side view
    polygon(222, 222, 222, -800, 400, -700, 300, -700, -100, -800, -200);

    glBegin(GL_POLYGON); //half circle
    glColor3ub(210, 210, 210);

    for(int i=0; i<101; i++)
    {
        float A=(i*2*pi)/200;
        float r=300;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-1500, y+200);
    }

    glBegin(GL_POLYGON);
    glColor3ub(145, 145, 145);

    for(int i=0; i<101; i++)
    {
        float A=(i*2*pi)/200;
        float r=300;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x-1500, y+200);
    }
    glEnd();

    glBegin(GL_LINES); //frames
    glColor3ub(0,0,0);
    glLineWidth(1.0);

    glVertex2f(-2200, -200);
    glVertex2f(-2200, 400);

    glVertex2f(-2100, -200);
    glVertex2f(-2100, 400);

    glVertex2f(-2000, -200);
    glVertex2f(-2000, 400);

    glVertex2f(-1900, -200);
    glVertex2f(-1900, 400);

    glVertex2f(-1800, -200);
    glVertex2f(-1800, 400);

    glVertex2f(-1200, -200);
    glVertex2f(-1200, 400);

    glVertex2f(-1100, -200);
    glVertex2f(-1100, 400);

    glVertex2f(-1000, -200);
    glVertex2f(-1000, 400);

    glVertex2f(-900, -200);
    glVertex2f(-900, 400);

    glVertex2f(-800, -200);
    glVertex2f(-800, 400);

    glVertex2f(-2200, 400);
    glVertex2f(-1800, 400);

    glVertex2f(-1200, 400);
    glVertex2f(-800, 400);

    glVertex2f(-2200, 300);
    glVertex2f(-1800, 300);

    glVertex2f(-1200, 300);
    glVertex2f(-800, 300);

    glVertex2f(-2200, 200);
    glVertex2f(-800, 200);

    glVertex2f(-2200, 100);
    glVertex2f(-800, 100);

    glVertex2f(-2200, 0);
    glVertex2f(-800, 0);

    glVertex2f(-2200, -100);
    glVertex2f(-800, -100);

    glVertex2f(-2200, -200);
    glVertex2f(-800, -200);
    glEnd();

    rectangle(145, 145, 145, -1620, -200, -1580, 200); //middle columns
    rectangle(145, 145, 145, -1420, -200, -1380, 200);
    rectangle(145, 145, 145, -1800, 90, -1200, 110);
    rectangle(145, 145, 145, -1800, -10, -1200, 10);
    rectangle(145, 145, 145, -1800, -110, -1200, -90);
    rectangle(205, 205, 205, -1800, 195, -1200, 260);
    if(night_M)
    {
        rectangle(190, 199, 82, -1580, -200, -1420, -110);
    } else{
        rectangle(59, 59, 59, -1580, -200, -1420, -110);
    }

    staticText("AL-SHIFA HOSPITAL", -1750, 210, 0.4, 1, 1, 0, 0); //name text
}

void twinTower()
{
    rectangle(137, 137, 137, 400, 0, 700, 820); //structure of 1st building

    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 40, 680, 80); //glasses of 1st building
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 100, 680, 140);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 160, 680, 200);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 220, 680, 260);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 280, 680, 320);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 340, 680, 380);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 400, 680, 440);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 460, 680, 500);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 520, 680, 560);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 580, 680, 620);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 640, 680, 680);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 700, 680, 740);
    rectangleCombine(190, 195, 200, 62, 64, 66, 420, 760, 680, 800);

    polygonCombine(150, 150, 150, 222, 222, 222, 700, 0, 750, 50, 750, 770, 700, 820); //right side view 1st building



    polygon(136, 134, 135, -100, 700, 180, 660, 100, 0, -200, 0); //Structure of 2nd building
    polygonCombine(136, 134, 135, 210, 210, 210, 100, 0, 150, 50, 200, 610, 180, 660); //right side view 2nd building

    polygonCombine(190, 195, 200, 62, 64, 66, -80, 680, 160, 640, 155, 600, -85, 640); //glasses of 2nd building
    polygonCombine(190, 195, 200, 62, 64, 66, -88, 620, 153, 580, 147, 540, -94, 580);
    polygonCombine(190, 195, 200, 62, 64, 66, -97, 560, 145, 520, 140, 480, -103, 520);
    polygonCombine(190, 195, 200, 62, 64, 66, -106, 500, 138, 460, 132, 420, -111, 460);
    polygonCombine(190, 195, 200, 62, 64, 66, -114, 440, 130, 400, 125, 360, -120, 400);
    polygonCombine(190, 195, 200, 62, 64, 66, -123, 380, 122, 340, 117, 300, -128, 340);
    polygonCombine(190, 195, 200, 62, 64, 66, -131, 320, 115, 280, 110, 240, -137, 280);
    polygonCombine(190, 195, 200, 62, 64, 66, -140, 260, 107, 220, 112, 180, -146, 220);
    polygonCombine(190, 195, 200, 62, 64, 66, -148, 200, 100, 160, 95, 120, -155, 160);
    polygonCombine(190, 195, 200, 62, 64, 66, -157, 140, 92, 100, 87, 60, -163, 100);
    polygonCombine(190, 195, 200, 62, 64, 66, -168, 80, 83, 40, 80, 0, -171, 40);

    // connecting bridge
    glBegin(GL_POLYGON); //right side
    glColor3ub(130, 130, 130);

    glVertex2f(400, 585);
    glVertex2f(400, 540);
    glVertex2f(320, 460);
    glVertex2f(310, 470);
    glVertex2f(325, 480);
    glVertex2f(312, 500);

    glBegin(GL_POLYGON);
    glColor3ub(200, 200, 200);

    glVertex2f(400, 585);
    glVertex2f(400, 540);
    glVertex2f(320, 460);
    glVertex2f(310, 470);
    glVertex2f(325, 480);
    glVertex2f(312, 500);
    glEnd();
    polygonCombine(130, 130, 130, 200, 200, 200, 300, 440, 298, 442, 318, 462, 320, 460);

    glBegin(GL_POLYGON); //left side
    glColor3ub(130, 130, 130);

    glVertex2f(170, 500);
    glVertex2f(165, 470);
    glVertex2f(240, 440);
    glVertex2f(260, 440);
    glVertex2f(253, 453);
    glVertex2f(280, 460);

    glBegin(GL_POLYGON);
    glColor3ub(200, 200, 200);

    glVertex2f(170, 500);
    glVertex2f(165, 470);
    glVertex2f(240, 440);
    glVertex2f(260, 440);
    glVertex2f(253, 453);
    glVertex2f(280, 460);
    glEnd();
    rectangleCombine(130, 130, 130, 200, 200, 200, 278, 434, 280, 460);
    rectangleCombine(130, 130, 130, 200, 200, 200, 240, 424, 242, 440);
    polygonCombine(120, 120, 120, 190, 190, 190, 190, 50, 200, 60, 220, 40, 210, 30);
    polygonCombine(120, 120, 120, 190, 190, 190, 210, 30, 230, 50, 270, 0, 240, 0);
    triangleCombine(120, 120, 120, 190, 190, 190, 150, 50, 180, 60, 160, 40);
    polygonCombine(120, 120, 120, 190, 190, 190, 160, 40, 180, 60, 240, 0, 200, 0);
    triangleCombine(120, 120, 120, 190, 190, 190, 100, 0, 150, 50, 200, 0);

}

void singleTower()
{
    if(night_M){
        rectangleCombine(216, 235, 232, 92, 113, 111, 1800, -360, 2200, 360);
        rectangleCombine(216, 235, 232, 92, 113, 111, 1960, 360, 2200, 400);
        polygonCombine(216, 235, 232, 92, 113, 111, 1960, 400, 2120, 400, 2100, 440, 1960, 440);
        polygonCombine(216, 235, 232, 92, 113, 111, 1800, 600, 1800, 360, 1960, 360, 1960, 560);
        polygonCombine(216, 235, 232, 92, 113, 111, 1960, 520, 1960, 440, 2040, 440, 2060, 520);
        polygonCombine(216, 235, 232, 92, 113, 111, 1960, 560, 1960, 520, 2060, 520, 2020, 580);
    } else{
        rectangleCombine(139, 175, 170, 216, 235, 232, 1800, -360, 2200, 360);
        rectangleCombine(139, 175, 170, 216, 235, 232, 1960, 360, 2200, 400);
        polygonCombine(139, 175, 170, 216, 235, 232, 1960, 400, 2120, 400, 2100, 440, 1960, 440);
        polygonCombine(139, 175, 170, 216, 235, 232, 1800, 600, 1800, 360, 1960, 360, 1960, 560);
        polygonCombine(139, 175, 170, 216, 235, 232, 1960, 520, 1960, 440, 2040, 440, 2060, 520);
        polygonCombine(139, 175, 170, 216, 235, 232, 1960, 560, 1960, 520, 2060, 520, 2020, 580);
    }

    polygonCombine(82, 82, 82, 200, 200, 200, 2200, 400, 2200, -360, 2250, -300, 2250, 350);
    rectangle(30, 30, 30, 1800, -280, 1880, -200);
    rectangle(30, 30, 30, 1800, 280, 1880, 360);
    rectangle(30, 30, 30, 1800, 40, 1880, 120);
    rectangle(30, 30, 30, 1880, -200, 1960, -120);
    rectangle(30, 30, 30, 1880, -40, 1960, 40);
    rectangle(30, 30, 30, 1880, 120, 1960, 200);
    rectangle(30, 30, 30, 1960, -200, 2040, -120);
    rectangle(30, 30, 30, 1960, -120, 2040, -40);
    rectangle(30, 30, 30, 1960, 280, 2040, 360);
    rectangle(30, 30, 30, 2040, -280, 2120, -200);
    rectangle(30, 30, 30, 2040, -40, 2120, 40);
    rectangle(30, 30, 30, 2040, 40, 2120, 120);
    rectangle(30, 30, 30, 2120, -200, 2200, -120);
    rectangle(30, 30, 30, 2120, 200, 2200, 280);



    glBegin(GL_LINES); //glasses frames
    glColor3ub(0,0,0);
    glLineWidth(1.0);

    glVertex2f(1800, -360);
    glVertex2f(1800, 600);

    glVertex2f(1880, -360);
    glVertex2f(1880, 600);

    glVertex2f(1960, -360);
    glVertex2f(1960, 600);

    glVertex2f(2040, -360);
    glVertex2f(2040, 600);

    glVertex2f(2120, -360);
    glVertex2f(2120, 510);

    glVertex2f(2200, -360);
    glVertex2f(2200, 470);

    glVertex2f(1800, 520);
    glVertex2f(2100, 520);

    glVertex2f(1800, 440);
    glVertex2f(2150, 440);

    glVertex2f(1800, 360);
    glVertex2f(2200, 360);

    glVertex2f(1800, 280);
    glVertex2f(2200, 280);

    glVertex2f(1800, 200);
    glVertex2f(2200, 200);

    glVertex2f(1800, 120);
    glVertex2f(2200, 120);

    glVertex2f(1800, 40);
    glVertex2f(2200, 40);

    glVertex2f(1800, -40);
    glVertex2f(2200, -40);

    glVertex2f(1800, -120);
    glVertex2f(2200, -120);

    glVertex2f(1800, -200);
    glVertex2f(2200, -200);

    glVertex2f(1800, -280);
    glVertex2f(2200, -280);
    glEnd();

    triangleCombine(130, 130, 130, 200, 200, 200, 2330, -270, 2350, -240, 2390, -280);
    triangleCombine(130, 130, 130, 200, 200, 200, 2270, -310, 2270, -230, 2390, -280);
    triangleCombine(130, 130, 130, 200, 200, 200, 2220, -320, 2260, -260, 2320, -340);
    triangleCombine(130, 130, 130, 200, 200, 200, 2360, -300, 2400, -240, 2500, -340);
    triangleCombine(130, 130, 130, 200, 200, 200, 2250, -350, 2300, -250, 2450, -350);
}

void collapsed()
{
    //collapsed standing buidling
    polygonCombine(80, 80, 80, 160, 160, 160, 960, -100, 1325.4, -8.5, 1400, 350, 1100, 400);
    polygonCombine(150, 150, 150, 90, 90, 90, 1400, 350, 1325.4, -8.5, 1376, -25.35, 1440, 300);

    //windows
    polygon(64, 64, 64, 1120, 380, 1380, 340, 1370, 300, 1110, 340);
    polygon(64, 64, 64, 1105, 330, 1365, 285, 1355, 245, 1095, 290);
    polygon(64, 64, 64, 1090, 270, 1350, 230, 1340, 185, 1080, 230);
    polygon(64, 64, 64, 1075, 210, 1335, 165, 1325, 120, 1060, 160);
    polygon(64, 64, 64, 1055, 140, 1320, 95, 1305, 40, 1040, 90);
    polygon(64, 64, 64, 1030, 70, 1300, 20, 1290, -25, 1020, 20);
    polygon(64, 64, 64, 1015, 0, 1204, -27, 1050, -71, 1000, -60);

    //frames
    polygon(90, 90, 90, 1180, 386.6, 1190, 385, 1065, -67, 1050, -72);
    polygon(75, 76, 77, 1190, 385, 1195, 384, 1075, -65, 1065, -67);

    polygon(90, 90, 90, 1300, 366.6, 1308, 365, 1222, -22, 1204, -27);
    polygon(75, 76, 77, 1308, 365, 1314, 364, 1231, -20, 1222, -22);

    //collapsed building and wreckages
    polygonCombine(160, 160, 160, 80, 80, 80, 1600, -100, 1600, -300, 1100, -300, 1300, 0);

    glBegin(GL_POLYGON);
    glColor3ub(130, 130, 130);

    glVertex2f(1600, -150);
    glVertex2f(1600, -300);
    glVertex2f(1760, -300);
    glVertex2f(1700, -260);
    glVertex2f(1680, -220);
    glVertex2f(1620, -200);

    glBegin(GL_POLYGON);
    glColor3ub(70, 70, 70);

    glVertex2f(1600, -150);
    glVertex2f(1600, -300);
    glVertex2f(1760, -300);
    glVertex2f(1700, -260);
    glVertex2f(1680, -220);
    glVertex2f(1620, -200);
    glEnd();

    polygon(64, 66, 68, 1536, -268, 1548, -273, 1544, -218, 1556, -217);
    triangle(74, 76, 78, 1400, -350, 1600, -250, 1500, -250);
    polygon(64, 66, 68, 1434, -248, 1450, -250, 1532, -187, 1529, -175);
    polygon(64, 66, 68, 1435, -127, 1518, -116, 1508, -104, 1430, -117);
    polygon(64, 66, 68, 1370, -40, 1380, -50, 1320, -110, 1310, -100);
    polygon(64, 66, 68, 1270, -147, 1370, -153, 1365, -169, 1265, -162);
    parallelX(64, 66, 68, 1400, 1410, 1430, 1420, -200, -160);
    parallelX(64, 66, 68, 1175, 1185, 1190, 1200, -255, -190);
    polygon(74, 76, 78, 1300, -350, 1400, -300, 1410, -200, 1250, -200);
    polygon(74, 76, 78, 1100, -300, 1250, -350, 1250, -300, 1200, -250);

    triangle(100, 100, 100, 1300, 0, 1100, -300, 220, -310);

    glBegin(GL_POLYGON);
    glColor3ub(80, 85, 90);

    glVertex2f(220, -310);
    glVertex2f(260, -260);
    glVertex2f(320, -260);
    glVertex2f(400, -220);
    glVertex2f(480, -235);
    glVertex2f(500, -200);
    glVertex2f(575, -225);
    glVertex2f(615, -250);
    glVertex2f(692, -214);
    glVertex2f(728, -238);
    glVertex2f(750, -304);
    glVertex2f(760, -380);
    glVertex2f(680, -320);
    glVertex2f(600, -360);
    glVertex2f(560, -320);
    glVertex2f(450, -350);
    glEnd();

    polygon(64, 66, 68, 750, -300, 850, -300, 975, -125, 890, -150);
    polygon(64, 66, 68, 880, -300, 950, -300, 1090, -100, 1010, -120);
    polygon(64, 66, 68, 980, -300, 1055, -300, 1205, -75, 1125, -95);
    polygon(64, 66, 68, 700, -245, 769, -244, 840, -160, 760, -180);

    glBegin(GL_POLYGON);
    glColor3ub(80, 85, 90);

    glVertex2f(908, -265);
    glVertex2f(1006, -220);
    glVertex2f(1100, -200);
    glVertex2f(1200, -250);
    glVertex2f(1100, -300);
    glVertex2f(900, -350);
    glVertex2f(760, -380);
    glVertex2f(728, -238);
    glVertex2f(769, -244);
    glEnd();

}

void leftmostCollapsed()
{
    //left most collapsed building
    polygonCombine(177, 177, 177, 149, 149, 149, -500, -300, 150, -300, 0, -150, -200, -100);

    glBegin(GL_POLYGON);
    glColor3ub(149, 149, 149);

    glVertex2f(-120, -310);
    glVertex2f(0, -350);
    glVertex2f(150, -300);
    glVertex2f(-500, -300);
    glVertex2f(-260, -330);

    glEnd();
    polygon(149, 149, 149, -120, -310, 0, -350, 220, -310, 260, -260);

    triangle(118, 118, 118, -420, -290, -390, -260, -260, -290);//right
    triangle(118, 118, 118, -370, -260, -340, -230, -220, -280);
    triangle(118, 118, 118, -330, -220, -300, -200, -200, -240);
    triangle(118, 118, 118, -280, -190, -250, -170, -160, -210);
    triangle(118, 118, 118, -230, -160, -210, -140, -150, -170);
    triangle(118, 118, 118, -195, -130, -180, -120, -135, -145);

    triangle(118, 118, 118, -100, -280, -10, -240, 30, -280);//left
    triangle(118, 118, 118, -95, -240, -20, -210, 15, -240);
    triangle(118, 118, 118, -90, -210, -25, -180, 10, -200);
    triangle(118, 118, 118, -80, -180, -30, -165, 0, -180);
    triangle(118, 118, 118, -70, -160, -30, -150, -10, -160);

}

void railline()
{
    rectangle(151, 145, 145, -2500, -1000, 2500, -950);

    glBegin(GL_LINES); //rail line frames
    glColor3ub(0,0,0);
    glLineWidth(1.0);

    glVertex2f(-2500, -1000);
    glVertex2f(2500, -1000);

    glVertex2f(-2500, -950);
    glVertex2f(2500, -950);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    for(float j=0; j<=5000;j+=50) //rail line
   {
        glVertex2f(-2450+j,-950);
        glVertex2f(-2500+j,-1000);

    }
    glEnd();
}

void train()
{
    glPushMatrix();
    glTranslatef(move_train_M, 0.0, 0.0);

    polygon(0, 0, 0, -740, -960, -740, -970, -240, -970, -240, -960); //front engine
    polygon(0, 0, 0, -240, -960, -240, -970, -228, -950, -228, -942);
    polygon(0, 0, 0, -234, -952, -234, -958, -226, -958, -226, -952);
    if(night_M) {
        glBegin(GL_POLYGON);
        glColor3ub(146, 104, 15);

        glVertex2f(-240, -960);
        glVertex2f(-260, -900);
        glVertex2f(-300, -890);
        glVertex2f(-320, -840);
        glVertex2f(-740, -840);
        glVertex2f(-740, -960);

        glEnd();

        polygon(167, 124, 32, -260, -900, -250, -890, -228, -942, -240, -960);
        polygon(167, 124, 32, -290, -880, -300, -890, -260, -900, -250, -890);
        polygon(0, 0, 0, -310, -830, -320, -840, -300, -890, -290, -880);
        polygon(167, 124, 32, -725, -830, -740, -840, -320, -840, -310, -830);
    } else {
        glBegin(GL_POLYGON);
        glColor3ub(205, 158, 8);

        glVertex2f(-240, -960);
        glVertex2f(-260, -900);
        glVertex2f(-300, -890);
        glVertex2f(-320, -840);
        glVertex2f(-740, -840);
        glVertex2f(-740, -960);

        glEnd();

        polygon(189, 155, 48, -260, -900, -250, -890, -228, -942, -240, -960);
        polygon(189, 155, 48, -290, -880, -300, -890, -260, -900, -250, -890);
        polygon(0, 0, 0, -310, -830, -320, -840, -300, -890, -290, -880);
        polygon(189, 155, 48, -725, -830, -740, -840, -320, -840, -310, -830);
    }


    polygon(0, 0, 0, -325, -820, -325, -830, -320, -830, -320, -820); //exhaust pipe
    //smokes
    circle(210, 210, 210, 1, -328, -816);//small
    circle(210, 200, 210, 1, -329, -817);
    circle(210, 210, 210, 1, -329, -815);
    circle(210, 210, 210, 1, -330, -816);
    circle(210, 210, 210, 1, -331, -817);
    circle(210, 210, 210, 1, -331, -815);
    circle(210, 210, 210, 1, -332, -816);

    circle(210, 210, 210, 2, -344, -812);//medium
    circle(210, 210, 210, 2, -346, -814);
    circle(210, 210, 210, 2, -346, -810);
    circle(210, 210, 210, 2, -348, -812);
    circle(210, 210, 210, 2, -350, -814);
    circle(210, 210, 210, 2, -350, -810);
    circle(210, 210, 210, 2, -352, -812);

    circle(210, 210, 210, 5, -370, -810);//large
    circle(210, 210, 210, 5, -375, -815);
    circle(210, 210, 210, 5, -375, -805);
    circle(210, 210, 210, 5, -380, -810);
    circle(210, 210, 210, 5, -385, -805);
    circle(210, 210, 210, 5, -385, -815);
    circle(210, 210, 210, 5, -390, -810);

    polygon(0, 0, 0, -754, -956, -754, -960, -740, -960, -740, -956);
    if(night_M){
        polygon(178, 169, 72, -400, -860, -400, -890, -360, -890, -360, -860); //gate
    } else {
        polygon(141, 139, 131, -400, -860, -400, -890, -360, -890, -360, -860); //gate
    }

    polygon(111, 112, 113, -740, -880, -740, -890, -520, -890, -520, -880); //design
    polygon(11, 12, 13, -740, -910, -740, -920, -440, -920, -440, -910);
    polygon(144, 7, 7, -255, -915, -254, -918, -243, -906, -244, -904);
    polygon(144, 7, 7, -251, -926, -250, -929, -239, -916, -240, -914);
    polygon(144, 7, 7, -248, -936, -246, -939, -235, -924, -236, -922);

    circle(32, 32, 29, 15, -295, -985);
    circle(32, 32, 29, 15, -335, -985);
    circle(32, 32, 29, 15, -480, -985);
    circle(32, 32, 29, 15, -520, -985);
    circle(32, 32, 29, 15, -655, -985);
    circle(32, 32, 29, 15, -695, -985);

    polygon(0, 0, 0, -760, -960, -760, -970, -1260, -970, -1260, -960); //1st coach
    polygon(0, 0, 0, -745, -940, -745, -950, -760, -970, -760, -960);
    polygon(142, 142, 142, -1260, -960, -1250, -940, -745, -940, -760, -960);
    polygon(0, 0, 0, -1276, -954, -1276, -958, -1259, -954, -1257, -958);
    if(night_M){
        polygon(91, 27, 20, -1240, -960, -1240, -840, -780, -840, -780, -960); //container
        polygon(122, 34, 23, -1230, -830, -1240, -840, -780, -840, -765, -830);
        polygon(122, 34, 23, -780, -840, -765, -830, -765, -940, -780, -960);
    } else {
        polygon(140, 5, 5, -1240, -960, -1240, -840, -780, -840, -780, -960); //container
        polygon(155, 7, 7, -1230, -830, -1240, -840, -780, -840, -765, -830);
        polygon(155, 7, 7, -780, -840, -765, -830, -765, -940, -780, -960);
    }

    circle(32, 32, 29, 15, -845, -985);
    circle(32, 32, 29, 15, -890, -985);
    circle(32, 32, 29, 15, -1125, -985);
    circle(32, 32, 29, 15, -1165, -985);

    polygon(0, 0, 0, -1280, -970, -1280, -960, -1780, -960, -1760, -970); //2nd coach
    polygon(0, 0, 0, -1280, -960, -1270, -940, -1760, -940, -1780, -960);
    polygon(142, 142, 142, -1280, -960, -1270, -940, -1760, -940, -1780, -960);
    polygon(0, 0, 0, -1792, -954, -1792, -960, -1780, -960, -1774, -954);

    glBegin(GL_POLYGON); // leopard 2 tank
    glColor3ub(167, 155, 5);

    glVertex2f(-1760, -890);
    glVertex2f(-1460, -900);
    glVertex2f(-1360, -910);
    glVertex2f(-1360, -940);
    glVertex2f(-1740, -940);
    glVertex2f(-1760, -920);

    glEnd();

    polygon(34, 36, 38, -1740, -940, -1720, -960, -1380, -960, -1360, -940);
    polygon(150, 140, 1, -1520, -880, -1520, -890, -1290, -890, -1290, -880);
    polygon(157, 145, 5, -1670, -875, -1669.7, -893, -1500, -898.6, -1500, -875);

    circle(32, 32, 29, 15, -1355, -985);
    circle(32, 32, 29, 15, -1400, -985);
    circle(32, 32, 29, 15, -1640, -985);
    circle(32, 32, 29, 15, -1680, -985);

    polygon(0, 0, 0, -1800, -960, -1800, -970, -2300, -970, -2300, -960); //3rd coach
    polygon(0, 0, 0, -1800, -960, -1800, -970, -1780, -950, -1780, -940);
    polygon(142, 142, 142, -1800, -960, -1780, -940, -2285, -940, -2300, -960);
    polygon(0, 0, 0, -2310, -952, -2310, -958, -2298.5, -958, -2294, -952);

    glBegin(GL_POLYGON); // M1A2 tank
    glColor3ub(167, 155, 5);

    glVertex2f(-2280, -940);
    glVertex2f(-2280, -900);
    glVertex2f(-2200, -890);
    glVertex2f(-1990, -900);
    glVertex2f(-1920, -915);
    glVertex2f(-1920, -940);

    glEnd();

    polygon(34, 36, 38, -2280, -940, -2240, -960, -1950, -960, -1920, -940);
    polygon(150, 140, 1, -2060, -880, -2060, -890, -1820, -890, -1820, -880);
    polygon(157, 145, 5, -2200, -870, -2030, -870, -2020.2, -898.6, -2200, -890);

    circle(32, 32, 29, 15, -1885, -985);
    circle(32, 32, 29, 15, -1930, -985);
    circle(32, 32, 29, 15, -2170, -985);
    circle(32, 32, 29, 15, -2215, -985);

    polygon(0, 0, 0, -2320, -960, -2320, -970, -2820, -970, -2820, -960); //rear engine
    polygon(0, 0, 0, -2320, -960, -2320, -970, -2300, -950, -2300, -940);

    if(night_M){
        glBegin(GL_POLYGON);
        glColor3ub(146, 104, 15);

        glVertex2f(-2820, -960);
        glVertex2f(-2800, -900);
        glVertex2f(-2760, -890);
        glVertex2f(-2740, -840);
        glVertex2f(-2320, -840);
        glVertex2f(-2320, -960);
        glEnd();

        polygon(167, 124, 32, -2710, -830, -2740, -840, -2320, -840, -2300, -830);
        polygon(167, 124, 32, -2300, -830, -2320, -840, -2320, -960, -2300, -940);
        polygon(167, 124, 32, -2710, -830, -2740, -840, -2320, -840, -2300, -830);

        polygon(178, 169, 72, -2700, -860, -2700, -900, -2660, -900, -2660, -860); //gate
    } else {
        glBegin(GL_POLYGON);
        glColor3ub(205, 158, 8);

        glVertex2f(-2820, -960);
        glVertex2f(-2800, -900);
        glVertex2f(-2760, -890);
        glVertex2f(-2740, -840);
        glVertex2f(-2320, -840);
        glVertex2f(-2320, -960);
        glEnd();

        polygon(189, 155, 48, -2710, -830, -2740, -840, -2320, -840, -2300, -830);
        polygon(189, 155, 48, -2300, -830, -2320, -840, -2320, -960, -2300, -940);
        polygon(189, 155, 48, -2710, -830, -2740, -840, -2320, -840, -2300, -830);

        polygon(141, 139, 131, -2700, -860, -2700, -900, -2660, -900, -2660, -860); //gate
    }

    polygon(111, 112, 113, -2540, -890, -2540, -900, -2320, -900, -2320, -890); //design
    polygon(11, 12, 13, -2610, -920, -2610, -930, -2320, -930, -2320, -920);

    circle(32, 32, 29, 15, -2375, -985);
    circle(32, 32, 29, 15, -2415, -985);
    circle(32, 32, 29, 15, -2555, -985);
    circle(32, 32, 29, 15, -2595, -985);
    circle(32, 32, 29, 15, -2725, -985);
    circle(32, 32, 29, 15, -2765, -985);

	glPopMatrix();
}

void tree_1()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, 2300, 520, 2320, 580);
        polygon(1, 41, 3, 2260, 580, 2360, 580, 2340, 620, 2280, 620);
        polygon(14, 74, 19, 2270, 620, 2350, 620, 2330, 660, 2290, 660);
        triangleCombine(1, 76, 5, 7, 93, 9, 2280, 660, 2340, 660, 2310, 710);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, 2300, 520, 2320, 580);
        polygon(6, 81, 11, 2260, 580, 2360, 580, 2340, 620, 2280, 620);
        polygon(34, 124, 39, 2270, 620, 2350, 620, 2330, 660, 2290, 660);
        triangleCombine(3, 106, 10, 14, 143, 23, 2280, 660, 2340, 660, 2310, 710);
    }
}

void tree_2()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, 1620, 520, 1640, 580);
        parallelX(124, 72, 1, 1620, 1630, 1620, 1610, 580, 600);
        parallelX(124, 72, 1, 1630, 1640, 1640, 1650, 580, 600);
        circle(1, 41, 3, 40, 1600, 620);
        circle(1, 41, 3, 40, 1660, 620);
        circle(7, 93, 9, 30, 1590, 650);
        circle(7, 93, 9, 30, 1670, 650);
        circle(14, 74, 19, 50, 1630, 660);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, 1620, 520, 1640, 580);
        parallelX(144, 92, 1, 1620, 1630, 1620, 1610, 580, 600);
        parallelX(144, 92, 1, 1630, 1640, 1640, 1650, 580, 600);
        circle(6, 81, 11, 40, 1600, 620);
        circle(6, 81, 11, 40, 1660, 620);
        circle(14, 143, 23, 30, 1590, 650);
        circle(14, 143, 23, 30, 1670, 650);
        circle(34, 124, 39, 50, 1630, 660);
    }
}

void tree_3()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, 960, 520, 1000, 620);
        parallelX(124, 72, 1, 960, 980, 960, 940, 620, 660);
        parallelX(124, 72, 1, 980, 1000, 1020, 1000, 620, 660);
        circle(1, 41, 3, 60, 920, 700);
        circle(1, 41, 3, 60, 1040, 700);
        circle(7, 93, 9, 60, 920, 740);
        circle(7, 93, 9, 60, 1040, 740);
        circle(14, 74, 19, 80, 980, 740);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, 960, 520, 1000, 620);
        parallelX(144, 92, 1, 960, 980, 960, 940, 620, 660);
        parallelX(144, 92, 1, 980, 1000, 1020, 1000, 620, 660);
        circle(6, 81, 11, 60, 920, 700);
        circle(6, 81, 11, 60, 1040, 700);
        circle(14, 143, 23, 60, 920, 740);
        circle(14, 143, 23, 60, 1040, 740);
        circle(34, 124, 39, 80, 980, 740);
    }
}

void tree_4()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, -1200, 600, -1180, 640);
        polygon(1, 41, 3, -1220, 640, -1160, 640, -1170, 660, -1210, 660);
        polygon(14, 74, 19, -1215, 660, -1165, 660, -1175, 680, -1205, 680);
        triangleCombine(1, 76, 5, 7, 93, 9, -1210, 680, -1170, 680, -1190, 710);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, -1200, 600, -1180, 640);
        polygon(6, 81, 11, -1220, 640, -1160, 640, -1170, 660, -1210, 660);
        polygon(34, 124, 39, -1215, 660, -1165, 660, -1175, 680, -1205, 680);
        triangleCombine(3, 106, 10, 14, 143, 23, -1210, 680, -1170, 680, -1190, 710);
    }
}

void tree_5()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, -1900, 540, -1880, 600);
        parallelX(124, 72, 1, -1900, -1890, -1900, -1910, 600, 620);
        parallelX(124, 72, 1, -1890, -1880, -1870, -1880, 600, 620);
        circle(1, 41, 3, 30, -1920, 640);
        circle(1, 41, 3, 30, -1860, 640);
        circle(7, 93, 9, 20, -1920, 670);
        circle(7, 93, 9, 20, -1860, 670);
        circle(14, 74, 19, 30, -1890, 670);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, -1900, 540, -1880, 600);
        parallelX(144, 92, 1, -1900, -1890, -1900, -1910, 600, 620);
        parallelX(144, 92, 1, -1890, -1880, -1870, -1880, 600, 620);
        circle(6, 81, 11, 30, -1920, 640);
        circle(6, 81, 11, 30, -1860, 640);
        circle(14, 143, 23, 20, -1920, 670);
        circle(14, 143, 23, 20, -1860, 670);
        circle(34, 124, 39, 30, -1890, 670);
    }
}

void tree_6()
{
    if(night_M){
        rectangleCombine(73, 6, 6, 124, 72, 1, -2320, 600, -2300, 640);
        polygon(1, 41, 3, -2340, 640, -2280, 640, -2290, 660, -2330, 660);
        polygon(14, 74, 19, -2285, 660, -2335, 660, -2325, 680, -2295, 680);
        triangleCombine(1, 76, 5, 7, 93, 9, -2290, 680, -2330, 680, -2310, 710);
    } else{
        rectangleCombine(93, 6, 6, 144, 92, 1, -2320, 600, -2300, 640);
        polygon(6, 81, 11, -2340, 640, -2280, 640, -2290, 660, -2330, 660);
        polygon(34, 124, 39, -2285, 660, -2335, 660, -2325, 680, -2295, 680);
        triangleCombine(3, 106, 10, 14, 143, 23, -2290, 680, -2330, 680, -2310, 710);
    }
}

void TrainForwardMove(int value) {
    if(train_F){
        move_train_M += 2.5f;
	if (move_train_M > 6500){ //5000+
		move_train_M = -2500;

	}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(10, TrainForwardMove, 0);
    }
}

void TrainBackwardMove(int value){
    if(train_B){
            move_train_M -= 2.5f;

         if (move_train_M < -3000) {
            move_train_M = 6500; //5000+
        }
        glutPostRedisplay();
        glutTimerFunc(10, TrainBackwardMove, 0);
    }
}

void updateFrigate(int value) {

	move_frigate -= 0.5f;
	if (move_frigate < -5000){
		move_frigate = 2550;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(10, updateFrigate, 0);
}

void updateFighterJet(int value) {

	move_fighter_jet += 5.0f;
	if (move_fighter_jet > 20000){
		move_fighter_jet = -2800;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(5, updateFighterJet, 0);
}

void updateSunMoon(int value) {
    move_sun_moon += 0.05f;
    if (move_sun_moon > 600.0f){
        night_M = !night_M; // Toggle between day and night_M
        move_sun_moon = -370.0f;
    }

    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(5, updateSunMoon, 0); // Call updateScene again after 5 seconds
}

void updateCloud(int value) {

	move_cloud_M -= 2.0f;
	if (move_cloud_M < -5000){
		move_cloud_M = 4500;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(15, updateCloud, 0);
}

void updateRiver(int value) {
    if(rain_M)
    {
        if (water_level < 1851){
            water_level += move_river;

        }
        if(water_level > 100){
                train_F=false;
                train_B=false;
            }
    }
    else
    {
        if(water_level > 0)
        {
            water_level -= move_river;
        }
        if(water_level > 100){
                train_F=false;
                train_B=false;
            }
    }
    glutPostRedisplay(); // Trigger a redraw
    glutTimerFunc(10, updateRiver, 0); // Call update function after 10 milliseconds
}

void DisplayMasum() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2500, 2500, -1500, 1700); // Example values for Mustakim's part
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    stars();
    sun_moon();
    land();
    hills();
    riverBank();
    road();
    railline();
    river(water_level);
    train();
    fighter_jet1();
    fighter_jet2();
    cloud();
    rainy_cloud();
    elevated_road();
    frigate();
    hospital();
    twinTower();
    singleTower();
    collapsed();
    leftmostCollapsed();
    tree_1();
    tree_2();
    tree_3();
    tree_4();
    tree_5();
    tree_6();

    glFlush();
	glutSwapBuffers();
}

///Masum's code end

///Redwan's code start

/// Defining Color for Objects
struct ColorR
{
    int r;
    int g;
    int b;

    ColorR(int red, int green, int blue) : r(red), g(green), b(blue) {}
};

/// Generating Gradient ColorRs
ColorR interpolateColorR(ColorR ColorR1, ColorR ColorR2, float t) {
    int r = static_cast<int>((1 - t) * ColorR1.r + t * ColorR2.r);
    int g = static_cast<int>((1 - t) * ColorR1.g + t * ColorR2.g);
    int b = static_cast<int>((1 - t) * ColorR1.b + t * ColorR2.b);
    return ColorR(r, g, b);
}

/// Shapes Structure
void quadR(float x1, float x2, float y1, float y2, ColorR ColorR, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(ColorR.r, ColorR.g, ColorR.b);
    glBegin(GL_QUADS);
    glVertex2f(s * x1 + Tx, s * y1 + Ty);
    glVertex2f(s * x2 + Tx, s * y1 + Ty);
    glVertex2f(s * x2 + Tx, s * y2 + Ty);
    glVertex2f(s * x1 + Tx, s * y2 + Ty);
    glEnd();
}

void circleR(float x, float y, float radius, float height, ColorR ColorR)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(ColorR.r, ColorR.g, ColorR.b);
    glVertex2f(x, y); // center of circleR
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}

void quadR(vector<pair<float, float>> coord, ColorR ColorR = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(ColorR.r, ColorR.g, ColorR.b);
    glBegin(GL_QUADS);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

void triangleR(vector<pair<float, float>> coord, ColorR ColorR = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(ColorR.r, ColorR.g, ColorR.b);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

void polygonR(vector<pair<float, float>> coord, ColorR ColorR = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(ColorR.r, ColorR.g, ColorR.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

/// Sky Function
void SkyR(){
    ColorR skyColorR = {25, 19, 65};
    if(nightR){
        skyColorR = {25, 19, 65};
    } else if(dayR) {
        skyColorR = {245, 204, 160};
    }
    polygonR({{0, 0}, {1920, 0}, {1920, 1080}, {0, 1080}}, skyColorR);
}

/// Star Function
void Star_R(float x, float y, ColorR Star_Rs = {136, 139, 134}){
    polygonR({{x + 0, y + 0}, {x + 5, y + 0}, {x + 5, y + 5}, {x + 0, y + 5}}, Star_Rs);
}

void SunR(float x, float y){
    circleR(x, y, 94, 94, {255, 173, 132});
    circleR(x, y, 93, 93, {255, 227, 130});
    circleR(x, y, 92, 92, {255, 196, 126});
    circleR(x, y, 91, 91, {255, 247, 138});
}

void Star_Rs(){
    float arr[45][2] = {
        {150, 1000}, {250, 920}, {360, 970}, {400, 920}, {540, 950},
        {560, 980}, {710, 1000}, {720, 1030}, {810, 930}, {810, 940},
        {820, 950}, {850, 1040}, {880, 920}, {920, 1020}, {970, 910},
        {1000, 920}, {1000, 950}, {1100, 1030}, {1170, 920}, {1200, 910},
        {1200, 930}, {1200, 1040}, {1280, 1050}, {1290, 1040}, {1310, 910},
        {1370, 980}, {1400, 940}, {1400, 940}, {1450, 1030}, {1460, 950},
        {1490, 930}, {1500, 1050}, {1640, 970}, {1660, 970}, {1780, 960},
        {1790, 960}, {1810, 950}, {1880, 970}, {1930, 1050}, {1960, 970},
        {1970, 1010}, {1980, 940}, {1980, 950}, {1990, 970}
    };

    /// Calls of Star_R function with coordinates
    for (int i = 0; i < 45; ++i) {
        Star_R(arr[i][0], arr[i][1]);
    }
}

/// Cloud Function
void Clouds_R(float Tx, float Ty, float s, ColorR ColorR){
    /// Left Portion
    circleR(Tx + s * 2, Ty + s * 30, 60, 60, ColorR);
    circleR(Tx + s * 13, Ty + s * 22, 93, 93, ColorR);
    circleR(Tx + s * 24, Ty + s * 24, 83, 90, ColorR);
    circleR(Tx + s * 40, Ty + s * 32, 120, 120, ColorR);
    circleR(Tx + s * 54, Ty + s * 36, 77, 70, ColorR);
    circleR(Tx + s * 60, Ty + s * 30, 77, 70, ColorR);
    circleR(Tx + s * 66, Ty + s * 40, 77, 84, ColorR);
    circleR(Tx + s * 74, Ty + s * 40, 100, 100, ColorR);
    circleR(Tx + s * 85, Ty + s * 37, 77, 84, ColorR);
    circleR(Tx + s * 85, Ty + s * 32, 77, 84, ColorR);
    circleR(Tx + s * 95, Ty + s * 40, 107, 100, ColorR);
    circleR(Tx + s * 108, Ty + s * 34, 67, 60, ColorR);
    circleR(Tx + s * 122, Ty + s * 31, 100, 100, ColorR);
    circleR(Tx + s * 132, Ty + s * 25, 100, 100, ColorR);
    circleR(Tx + s * 144, Ty + s * 16, 60, 60, ColorR);

    /// quadRs for filling the empty portion
    quadR({{0, -10}, {220, -10}, {220, 25}, {0, 25}}, ColorR, Tx, Ty, s);
    quadR({{25, 10}, {220, 10}, {220, 32}, {25, 32}}, ColorR, Tx, Ty, s);

    /// Right Portion
    circleR(Tx + s * 102, Ty + s * 30, 60, 60, ColorR);
    circleR(Tx + s * 113, Ty + s * 16, 93, 93, ColorR);
    circleR(Tx + s * 124, Ty + s * 24, 83, 90, ColorR);
    circleR(Tx + s * 140, Ty + s * 32, 120, 120, ColorR);
    circleR(Tx + s * 154, Ty + s * 36, 77, 70, ColorR);
    circleR(Tx + s * 160, Ty + s * 30, 77, 70, ColorR);
    circleR(Tx + s * 166, Ty + s * 40, 77, 84, ColorR);
    circleR(Tx + s * 174, Ty + s * 40, 100, 100, ColorR);
    circleR(Tx + s * 185, Ty + s * 37, 77, 84, ColorR);
    circleR(Tx + s * 185, Ty + s * 32, 77, 84, ColorR);
    circleR(Tx + s * 195, Ty + s * 40, 107, 100, ColorR);
    circleR(Tx + s * 208, Ty + s * 34, 100, 100, ColorR);
    circleR(Tx + s * 222, Ty + s * 31, 100, 100, ColorR);
    circleR(Tx + s * 232, Ty + s * 25, 100, 100, ColorR);
    circleR(Tx + s * 244, Ty + s * 16, 60, 60, ColorR);

}

/// Timer Function for updating Cloud Positions
void updateCloud_R(int value) {
    cloudTime1 += 0.01;
    cloudTime2 -= 0.01;
    glutPostRedisplay();
    glutTimerFunc(16, updateCloud_R, 10);
}

void cloud1() {
    ColorR cloud = {114, 80, 203};
    if(nightR){
        cloud = {114, 80, 203};
    } else if(dayR){
        cloud = {228, 123, 50};
    }
    Clouds_R(0, 100 + 20 * sin(cloudTime1), 10, cloud);
}

void cloud2(){
    ColorR cloud = {53, 41, 107};
    if(nightR){
        cloud = {53, 41, 107};
    } else if(dayR){
        cloud = {153, 77, 28};
    }
    Clouds_R(-100, 285 + 20 * sin(cloudTime2), 10, cloud);
}

void cloud3(){
    ColorR cloud = {36, 27, 82};
    if(nightR){
        cloud = {36, 27, 82};
    } else if(dayR){
        cloud = {107, 36, 12};
    }
    Clouds_R(-250, 480 + 20 * sin(cloudTime1), 10, cloud);
}

/// Plane Function
void plane_R(float x, float y, ColorR window = {112, 146, 243}, ColorR body = {0, 0, 0}){
        polygonR({{x + 0, y + 0}, {x + 100, y + 0}, {x + 100, y + 15}, {x + 0, y + 15}}, body);
        polygonR({{x - 15, y + 0}, {x + 0, y + 0}, {x + 0, y + 15}, {x - 15, y + 15}}, {191, 205, 252});
        polygonR({{x - 10, y + 15}, {x + 0, y + 15}, {x + 0, y + 20}, {x - 10, y + 20}}, {191, 205, 252});

        /// Windows
        polygonR({{x + 8, y + 5}, {x + 13, y + 5}, {x + 13, y + 10}, {x + 8, y + 10}}, window);
        polygonR({{x + 21, y + 5}, {x + 26, y + 5}, {x + 26, y + 10}, {x + 21, y + 10}}, window);
        polygonR({{x + 34, y + 5}, {x + 39, y + 5}, {x + 39, y + 10}, {x + 34, y + 10}}, window);
        polygonR({{x + 47, y + 5}, {x + 52, y + 5}, {x + 52, y + 10}, {x + 47, y + 10}}, window);
        polygonR({{x + 60, y + 5}, {x + 65, y + 5}, {x + 65, y + 10}, {x + 60, y + 10}}, window);
        polygonR({{x + 73, y + 5}, {x + 78, y + 5}, {x + 78, y + 10}, {x + 73, y + 10}}, window);

        polygonR({{x - 15, y + 0}, {x + 0, y + 0}, {x + 0, y + 5}, {x - 15, y + 5}}, body);
        polygonR({{x + 20, y + 15}, {x + 50, y + 15}, {x + 50, y + 20}, {x + 20, y + 20}}, body);
        polygonR({{x + 30, y + 20}, {x + 70, y + 20}, {x + 70, y + 25}, {x + 30, y + 25}}, body);
        polygonR({{x + 20, y + 0}, {x + 40, y + 0}, {x + 40, y - 5}, {x + 20, y - 5}}, body);
        polygonR({{x + 25, y - 5}, {x + 50, y - 5}, {x + 50, y - 10}, {x + 25, y - 10}}, body);
        polygonR({{x + 30, y - 10}, {x + 60, y - 10}, {x + 60, y - 15}, {x + 30, y - 15}}, body);

        polygonR({{x + 100, y + 3}, {x + 140, y + 3}, {x + 140, y + 7}, {x + 100, y + 7}}, {191, 205, 252});
        polygonR({{x + 100, y + 7}, {x + 160, y + 7}, {x + 160, y + 12}, {x + 100, y + 12}}, window);
}

/// Timer Function for updating plane_R Positions
void updateplane_R(int value) {
    if(plane_RPosition > 0){
        plane_RPosition -= 50;
    }
    else{
        plane_RPosition = 40000;
    }

    glutPostRedisplay();
    glutTimerFunc(1, updateplane_R, 0);
}

void moveplane_R(){
    glPushMatrix();
    glScalef(0.5, 0.5,0.0);
    plane_R(plane_RPosition, 1500);
    glPopMatrix();
}

/// First Carrier Function
void carrier(float x, float y, ColorR window = {227, 81, 144}, ColorR body = {0, 0, 0}){
        polygonR({{x + 0, y + 0}, {x + 100, y + 0}, {x + 100, y + 30}, {x + 0, y + 30}}, body);
        polygonR({{x + 85, y + 15}, {x + 100, y + 15}, {x + 100, y + 30}, {x + 85, y + 30}}, window);
        polygonR({{x + 50, y + 23}, {x + 80, y + 23}, {x + 80, y + 30}, {x + 50, y + 30}}, window);
        polygonR({{x + 10, y + 23}, {x + 40, y + 23}, {x + 40, y + 30}, {x + 10, y + 30}}, window);

        /// Windows
        polygonR({{x + 10, y + 5}, {x + 20, y + 5}, {x + 20, y + 15}, {x + 10, y + 15}}, window);
        polygonR({{x + 30, y + 5}, {x + 40, y + 5}, {x + 40, y + 15}, {x + 30, y + 15}}, window);
        polygonR({{x + 50, y + 5}, {x + 60, y + 5}, {x + 60, y + 15}, {x + 50, y + 15}}, window);
        polygonR({{x + 70, y + 5}, {x + 80, y + 5}, {x + 80, y + 15}, {x + 70, y + 15}}, window);
}

/// Timer Function for updating First Carrier Positions
void updateCarrier(int value) {
    if(carrierPosition < 3780){
        carrierPosition += 20;
    }
    else{
        carrierPosition = -8000;
    }

    glutPostRedisplay();
    glutTimerFunc(1, updateCarrier, 0);
}

void moveCarrier(){
    glPushMatrix();
    glScalef(0.5, 0.5,0.0);
    carrier(carrierPosition, 1000);
    glPopMatrix();
}

/// Second Carrier Function
void carrierTwo(float x, float y, ColorR window = {46, 190, 186}, ColorR body = {0, 0, 0}){
        polygonR({{x + 0, y + 0}, {x + 100, y + 0}, {x + 100, y + 30}, {x + 0, y + 30}}, body);
        polygonR({{x + 0, y + 15}, {x + 10, y + 15}, {x + 10, y + 25}, {x + 0, y + 25}}, window);
        polygonR({{x + 20, y + 20}, {x + 30, y + 20}, {x + 30, y + 25}, {x + 20, y + 25}}, window);
        polygonR({{x + 40, y + 20}, {x + 50, y + 20}, {x + 50, y + 25}, {x + 40, y + 25}}, window);
        polygonR({{x + 60, y + 20}, {x + 70, y + 20}, {x + 70, y + 25}, {x + 60, y + 25}}, window);
        polygonR({{x + 20, y + 10}, {x + 80, y + 10}, {x + 80, y + 15}, {x + 20, y + 15}}, {21, 107, 104});
}

/// Timer Function for updating Second Carrier Positions
void updateCarrierTwo(int value) {
    if(carrierTwoPosition > 0){
        carrierTwoPosition -= 10;
    }
    else{
        carrierTwoPosition = 5000;
    }

    glutPostRedisplay();
    glutTimerFunc(1, updateCarrierTwo, 0);
}

void moveCarrierTwo(){
    glPushMatrix();
    glScalef(0.5, 0.5,0.0);
    carrierTwo(carrierTwoPosition, 550);
    glPopMatrix();
}

/// Building One
void Building_One(float x, float y, int m = 1, ColorR Pillar = {135, 82, 214}, ColorR PillarShadow = {33, 72, 136}, ColorR DarkPillar = {26, 46, 74}, ColorR DarkPillarShadow = {6, 23, 52}, ColorR windowDark = {28, 0, 149}, ColorR windowLightTop = {34, 203, 197}, ColorR windowLightBottom = {41, 94, 135}){
    if(nightR){
        windowDark = {28, 0, 149};
        windowLightTop = {34, 203, 197};
        windowLightBottom = {41, 94, 135};
        Pillar = {135, 82, 214};
        PillarShadow = {33, 72, 136};
        DarkPillar = {26, 46, 74};
        DarkPillarShadow = {6, 23, 52};
    } else if(dayR){
        windowDark = {227, 100, 20};
        windowLightTop = {251, 139, 36};
        windowLightBottom = {145, 15, 64};
        Pillar = {245, 204, 160};
        PillarShadow = {153, 77, 28};
        DarkPillar = {228, 143, 69};
        DarkPillarShadow = {107, 36, 12};
    }
    /// Bottom Portion
    /// Left Portion
    polygonR({{x + 0, y + 0}, {x + 15, y + 0}, {x + 15, y + 245}, {x + 0, y + 245}}, PillarShadow);

    /// Pillar One
    polygonR({{x + 15, y + 0}, {x + 25, y + 0}, {x + 25, y + 245}, {x + 15, y + 245}}, Pillar);
    polygonR({{x + 25, y + 0}, {x + 40, y + 0}, {x + 40, y + 245}, {x + 25, y + 245}}, PillarShadow);

    /// Pillar Two
    polygonR({{x + 40, y + 0}, {x + 50, y + 0}, {x + 50, y + 245}, {x + 40, y + 245}}, Pillar);
    polygonR({{x + 50, y + 0}, {x + 65, y + 0}, {x + 65, y + 245}, {x + 50, y + 245}}, PillarShadow);

    /// Pillar Three
    polygonR({{x + 65, y + 0}, {x + 75, y + 0}, {x + 75, y + 245}, {x + 65, y + 245}}, Pillar);

    /// Pillar Four
    polygonR({{x + 105, y + 0}, {x + 115, y + 0}, {x + 115, y + 245}, {x + 105, y + 245}}, DarkPillar);
    polygonR({{x + 115, y + 0}, {x + 135, y + 0}, {x + 135, y + 245}, {x + 115, y + 245}}, DarkPillarShadow);

    /// Right Portion
    polygonR({{x + 75, y + 0}, {x + 85, y + 0}, {x + 85, y + 245}, {x + 75, y + 245}}, DarkPillar);

    /// Pillar One
    polygonR({{x + 85, y + 0}, {x + 105, y + 0}, {x + 105, y + 245}, {x + 85, y + 245}}, DarkPillarShadow);

    /// Window Column One
    polygonR({{x + 5, y + 0}, {x + 15, y + 0}, {x + 15, y + 10}, {x + 5, y + 10}}, windowLightBottom);

    polygonR({{x + 5, y + 20}, {x + 15, y + 20}, {x + 15, y + 30}, {x + 5, y + 30}}, windowLightTop);
    polygonR({{x + 5, y + 30}, {x + 15, y + 30}, {x + 15, y + 40}, {x + 5, y + 40}}, windowLightBottom);

    polygonR({{x + 5, y + 50}, {x + 15, y + 50}, {x + 15, y + 60}, {x + 5, y + 60}}, windowLightTop);
    polygonR({{x + 5, y + 60}, {x + 15, y + 60}, {x + 15, y + 70}, {x + 5, y + 70}}, windowLightBottom);

    for (int i = 0; i< 6; i++){
        int startY = 80 + i * 30;
        polygonR({{x + 5, y + startY}, {x + 15, y + startY}, {x + 15, y + (startY + 20)}, {x + 5, y + (startY + 20)}}, windowDark);
    }

    /// Window Column Two
    polygonR({{x + 30, y + 0}, {x + 40, y + 0}, {x + 40, y + 10}, {x + 30, y + 10}}, windowDark);

    polygonR({{x + 30, y + 20}, {x + 40, y + 20}, {x + 40, y + 30}, {x + 30, y + 30}}, windowLightTop);
    polygonR({{x + 30, y + 30}, {x + 40, y + 30}, {x + 40, y + 40}, {x + 30, y + 40}}, windowLightBottom);

    polygonR({{x + 30, y + 50}, {x + 40, y + 50}, {x + 40, y + 60}, {x + 30, y + 60}}, windowLightTop);
    polygonR({{x + 30, y + 60}, {x + 40, y + 60}, {x + 40, y + 70}, {x + 30, y + 70}}, windowLightBottom);

    polygonR({{x + 30, y + 80}, {x + 40, y + 80}, {x + 40, y + 90}, {x + 30, y + 90}}, windowLightTop);
    polygonR({{x + 30, y + 90}, {x + 40, y + 90}, {x + 40, y + 100}, {x + 30, y + 100}}, windowLightBottom);

    polygonR({{x + 30, y + 110}, {x + 40, y + 110}, {x + 40, y + 130}, {x + 30, y + 130}}, windowDark);

    polygonR({{x + 30, y + 140}, {x + 40, y + 140}, {x + 40, y + 160}, {x + 30, y + 160}}, windowDark);

    polygonR({{x + 30, y + 170}, {x + 40, y + 170}, {x + 40, y + 180}, {x + 30, y + 180}}, windowLightTop);
    polygonR({{x + 30, y + 180}, {x + 40, y + 180}, {x + 40, y + 190}, {x + 30, y + 190}}, windowLightBottom);

    polygonR({{x + 30, y + 200}, {x + 40, y + 200}, {x + 40, y + 210}, {x + 30, y + 210}}, windowLightTop);
    polygonR({{x + 30, y + 210}, {x + 40, y + 210}, {x + 40, y + 220}, {x + 30, y + 220}}, windowLightBottom);

    polygonR({{x + 30, y + 230}, {x + 40, y + 230}, {x + 40, y + 240}, {x + 30, y + 240}}, windowLightTop);
    polygonR({{x + 30, y + 240}, {x + 40, y + 240}, {x + 40, y + 250}, {x + 30, y + 250}}, windowLightBottom);

    /// Window Column Three
    polygonR({{x + 55, y + 0}, {x + 65, y + 0}, {x + 65, y + 10}, {x + 55, y + 10}}, windowDark);

    polygonR({{x + 55, y + 20}, {x + 65, y + 20}, {x + 65, y + 30}, {x + 55, y + 30}}, windowLightTop);
    polygonR({{x + 55, y + 30}, {x + 65, y + 30}, {x + 65, y + 40}, {x + 55, y + 40}}, windowLightBottom);

    polygonR({{x + 55, y + 50}, {x + 65, y + 50}, {x + 65, y + 70}, {x + 55, y + 70}}, windowDark);

    polygonR({{x + 55, y + 80}, {x + 65, y + 80}, {x + 65, y + 90}, {x + 55, y + 90}}, windowLightTop);
    polygonR({{x + 55, y + 90}, {x + 65, y + 90}, {x + 65, y + 100}, {x + 55, y + 100}}, windowLightBottom);

    polygonR({{x + 55, y + 110}, {x + 65, y + 110}, {x + 65, y + 120}, {x + 55, y + 120}}, windowLightTop);
    polygonR({{x + 55, y + 120}, {x + 65, y + 120}, {x + 65, y + 130}, {x + 55, y + 130}}, windowLightBottom);

    polygonR({{x + 55, y + 140}, {x + 65, y + 140}, {x + 65, y + 160}, {x + 55, y + 160}}, windowDark);

    polygonR({{x + 55, y + 170}, {x + 65, y + 170}, {x + 65, y + 180}, {x + 55, y + 180}}, windowLightTop);
    polygonR({{x + 55, y + 180}, {x + 65, y + 180}, {x + 65, y + 190}, {x + 55, y + 190}}, windowLightBottom);

    polygonR({{x + 55, y + 200}, {x + 65, y + 200}, {x + 65, y + 220}, {x + 55, y + 220}}, windowDark);

    polygonR({{x + 55, y + 230}, {x + 65, y + 230}, {x + 65, y + 240}, {x + 55, y + 240}}, windowLightTop);
    polygonR({{x + 55, y + 240}, {x + 65, y + 240}, {x + 65, y + 250}, {x + 55, y + 250}}, windowLightBottom);

    /// Window Column Four
    polygonR({{x + 85, y + 0}, {x + 98, y + 0}, {x + 98, y + 10}, {x + 85, y + 10}}, windowDark);

    polygonR({{x + 85, y + 20}, {x + 98, y + 20}, {x + 98, y + 40}, {x + 85, y + 40}}, windowDark);

    polygonR({{x + 85, y + 50}, {x + 98, y + 50}, {x + 98, y + 70}, {x + 85, y + 70}}, windowDark);

    polygonR({{x + 85, y + 80}, {x + 98, y + 80}, {x + 98, y + 90}, {x + 85, y + 90}}, windowLightTop);
    polygonR({{x + 85, y + 90}, {x + 98, y + 90}, {x + 98, y + 100}, {x + 85, y + 100}}, windowLightBottom);

    polygonR({{x + 85, y + 110}, {x + 98, y + 110}, {x + 98, y + 130}, {x + 85, y + 130}}, windowDark);

    polygonR({{x + 85, y + 140}, {x + 98, y + 140}, {x + 98, y + 160}, {x + 85, y + 160}}, windowDark);

    polygonR({{x + 85, y + 170}, {x + 98, y + 170}, {x + 98, y + 190}, {x + 85, y + 190}}, windowDark);

    polygonR({{x + 85, y + 200}, {x + 98, y + 200}, {x + 98, y + 210}, {x + 85, y + 210}}, windowLightTop);
    polygonR({{x + 85, y + 210}, {x + 98, y + 210}, {x + 98, y + 220}, {x + 85, y + 220}}, windowLightBottom);

    polygonR({{x + 85, y + 230}, {x + 98, y + 230}, {x + 98, y + 245}, {x + 85, y + 245}}, windowDark);


   /// Window Column Five
    polygonR({{x + 115, y + 0}, {x + 130, y + 0}, {x + 130, y + 10}, {x + 115, y + 10}}, windowDark);

    polygonR({{x + 115, y + 20}, {x + 130, y + 20}, {x + 130, y + 40}, {x + 115, y + 40}}, windowDark);

    polygonR({{x + 115, y + 50}, {x + 130, y + 50}, {x + 130, y + 60}, {x + 115, y + 60}}, windowLightTop);
    polygonR({{x + 115, y + 60}, {x + 130, y + 60}, {x + 130, y + 70}, {x + 115, y + 70}}, windowLightBottom);

    polygonR({{x + 115, y + 80}, {x + 130, y + 80}, {x + 130, y + 90}, {x + 115, y + 90}}, windowLightTop);
    polygonR({{x + 115, y + 90}, {x + 130, y + 90}, {x + 130, y + 100}, {x + 115, y + 100}}, windowLightBottom);

    polygonR({{x + 115, y + 110}, {x + 130, y + 110}, {x + 130, y + 120}, {x + 115, y + 120}}, windowLightTop);
    polygonR({{x + 115, y + 120}, {x + 130, y + 120}, {x + 130, y + 130}, {x + 115, y + 130}}, windowLightBottom);

    polygonR({{x + 115, y + 140}, {x + 130, y + 140}, {x + 130, y + 160}, {x + 115, y + 160}}, windowDark);

    polygonR({{x + 115, y + 170}, {x + 130, y + 170}, {x + 130, y + 180}, {x + 115, y + 180}}, windowLightTop);
    polygonR({{x + 115, y + 180}, {x + 130, y + 180}, {x + 130, y + 190}, {x + 115, y + 190}}, windowLightBottom);

    polygonR({{x + 115, y + 200}, {x + 130, y + 200}, {x + 130, y + 220}, {x + 115, y + 220}}, windowDark);

    polygonR({{x + 115, y + 230}, {x + 130, y + 230}, {x + 130, y + 237}, {x + 115, y + 237}}, windowLightTop);
    polygonR({{x + 115, y + 237}, {x + 130, y + 237}, {x + 130, y + 245}, {x + 115, y + 245}}, windowLightBottom);

    polygonR({{x + 135, y + 0}, {x + 145, y + 0}, {x + 145, y + 245}, {x + 135, y + 245}}, DarkPillar);

    /// Terrace
    polygonR({{x + 0, y + 245}, {x + 75, y + 245}, {x + 75, y + 250}, {x + 0, y + 250}}, Pillar);
    polygonR({{x + 75, y + 245}, {x + 145, y + 245}, {x + 145, y + 250}, {x + 75, y + 250}}, DarkPillar);
}

void updateLights(int value) {

    if(on && i < 10){
        on = false;
        i += 0.5;
    }
    else{
        on = true;
        i = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(2000, updateLights, 0);
}

void updateLights2(int value) {

    if(on && j < 1){
        two = false;
        j += 1;
    }
    else{
        two = true;
        j = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(500, updateLights2, 0);
}

void updateLights3(int value) {

    if(on && k < 1){
        three = false;
        k += 1;
    }
    else{
        three = true;
        k = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000, updateLights3, 0);
}

void LightOnOff(){
    if(nightR){
        if(on) {
            polygonR({{30, 80}, {40, 80}, {40, 100}, {30, 100}}, {28, 0, 149});
            polygonR({{85, 255 + 200}, {98, 255 + 200}, {98, 255 + 220}, {85, 255 + 220}}, {28, 0, 149});
            polygonR({{420 + 5, 340}, {420 + 65, 340}, {420 + 65, 360}, {420 +  5, 360}}, {43, 71, 136});
            polygonR({{420 + 5, 360}, {420 + 65, 360}, {420 + 65, 370}, {420 + 5, 370}}, {61, 56, 130});
            polygonR({{930 + 100, 255 + 185}, {930 + 110, 255 + 185}, {930 + 110, 255 + 200}, {930 + 100, 255 + 200}}, {34, 203, 197});
            polygonR({{930 + 120, 255 + 185}, {930 + 130, 255 + 185}, {930 + 130, 255 + 200}, {930 + 120, 255 + 200}}, {34, 203, 197});
            polygonR({{930 + 120, 255 + 155}, {930 + 130, 255 + 155}, {930 + 130, 255 + 170}, {930 + 120, 255 + 170}}, {34, 203, 197});
        }
        if(two){
            polygonR({{30, 255 + 80}, {40, 255 + 80}, {40, 255 + 100}, {30, 255 + 100}}, {28, 0, 149});
            polygonR({{320 + 10, 40}, {320 + 15, 40}, {320 + 15, 46}, {320 + 10, 46}}, {34, 203, 197});
            polygonR({{320 + 25, 40}, {320 + 30, 40}, {320 + 30, 46}, {320 + 25, 46}}, {34, 203, 197});
            polygonR({{320 + 50, 40}, {320 + 55, 40}, {320 + 55, 46}, {320 + 50, 46}}, {34, 203, 197});
            polygonR({{1720 + 87, 290}, {1720 + 98, 290}, {1720 + 98, 310}, {1720 + 87, 310}}, {28, 0, 149});
        }
        if(three){
            polygonR({{1850 + 10, 40}, {1850 + 15, 40}, {1850 + 15, 46}, {1850 + 10, 46}}, {34, 203, 197});
            polygonR({{1850 + 25, 40}, {1850 + 30, 40}, {1850 + 30, 46}, {1850 + 25, 46}}, {34, 203, 197});
            polygonR({{520 + 10, 70}, {520 + 20, 70}, {520 + 20, 85}, {520 + 10, 85}}, {34, 203, 197});
            polygonR({{520 + 10, 40}, {520 + 20, 40}, {520 + 20, 55}, {520 + 10, 55}}, {34, 203, 197});
            polygonR({{1720 + 117, 320}, {1720 + 127, 320}, {1720 + 127, 340}, {1720 + 117, 340}}, {28, 0, 149});
        }
    }
}

/// Signboard's Ghost
void Ghost(float x, float y, ColorR Body = {218, 78, 209}){
    polygonR({{x + 0, y + 0}, {x + 3, y + 0}, {x + 3, y + 15}, {x + 0, y + 15}}, Body);
    polygonR({{x + 3, y + 15}, {x + 6, y + 15}, {x + 6, y + 20}, {x + 3, y + 20}}, Body);
    polygonR({{x + 6, y + 20}, {x + 15, y + 20}, {x + 15, y + 23}, {x + 6, y + 23}}, Body);
    polygonR({{x + 15, y + 15}, {x + 18, y + 15}, {x + 18, y + 20}, {x + 15, y + 20}}, Body);
    polygonR({{x + 18, y + 0}, {x + 21, y + 0}, {x + 21, y + 15}, {x + 18, y + 15}}, Body);

    // Eyes
    polygonR({{x + 6, y + 9}, {x + 9, y + 9}, {x + 9, y + 12}, {x + 6, y + 12}}, Body);
    polygonR({{x + 12, y + 9}, {x + 15, y + 9}, {x + 15, y + 12}, {x + 12, y + 12}}, Body);

    // Legs
    polygonR({{x + 3, y + 0}, {x + 6, y + 0}, {x + 6, y + 3}, {x + 3, y + 3}}, Body);
    polygonR({{x + 6, y + 3}, {x + 9, y + 3}, {x + 9, y + 6}, {x + 6, y + 6}}, Body);
    polygonR({{x + 9, y + 0}, {x + 12, y + 0}, {x + 12, y + 3}, {x + 9, y + 3}}, Body);
    polygonR({{x + 12, y + 3}, {x + 15, y + 3}, {x + 15, y + 6}, {x + 12, y + 6}}, Body);
    polygonR({{x + 15, y + 0}, {x + 18, y + 0}, {x + 18, y + 3}, {x + 15, y + 3}}, Body);
}

/// Timer Function for making the Ghost Translate on Y-axis
void moveGhost(){
    glPushMatrix();
    if(nightR) if(signBoard) Ghost(-5 + 32, 510 + 60 + GhostPosition);
    glPopMatrix();
}

void updateGhost(int value) {
    if(GhostPosition < 2){
        GhostPosition += 1;
    }
    else{
        GhostPosition = 1;
    }

    glutPostRedisplay();
    glutTimerFunc(200, updateGhost, 0);
}

/// Signboard's Donute
void SignBoard_Donute(float x, float y, ColorR Donute = {218, 78, 209}){
    polygonR({{x + 2, y + 0}, {x + 7, y + 0}, {x + 7, y + 2}, {x + 2, y + 2}}, Donute);
    polygonR({{x + 0, y + 2}, {x + 2, y + 2}, {x + 2, y + 9}, {x + 0, y + 9}}, Donute);
    polygonR({{x + 7, y + 2}, {x + 9, y + 2}, {x + 7, y + 9}, {x + 9, y + 9}}, Donute);
    polygonR({{x + 2, y + 9}, {x + 7, y + 9}, {x + 7, y + 11}, {x + 2, y + 11}}, Donute);
}

/// Timer Function for making the Donutes Translate on Y-axis
void updateDonute(int value) {
    if(DonutePosition > -10){
        DonutePosition -= 2;
    }
    else{
        DonutePosition = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(50, updateDonute, 0);
}

/// Building One's Signboard
void Building_One_SignBoard(float x, float y, ColorR shadow = {19, 23, 69}, ColorR light = {244, 29, 27}){
    /// Polls
    polygonR({{x + 5, y + 0}, {x + 10, y + 0}, {x + 10, y + 35}, {x + 5, y + 35}}, shadow);
    polygonR({{x + 85, y + 0}, {x + 90, y + 0}, {x + 90, y + 35}, {x + 85, y + 35}}, shadow);

    /// Layer One
    if(nightR) if(signBoard) polygonR({{x - 10, y + 35}, {x + 105, y + 35}, {x + 105, y + 90}, {x - 10, y + 90}}, {77, 104, 159});

    /// Layer Two
    polygonR({{x - 5, y + 40}, {x + 100, y + 40}, {x + 100, y + 85}, {x - 5, y + 85}}, {103, 152, 191});

    /// Layer Three
    if(nightR) if(signBoard) polygonR({{x - 2, y + 43}, {x + 97, y + 43}, {x + 97, y + 82}, {x - 2, y + 82}}, {79, 211, 217});

    /// Layer Four
    polygonR({{x, y + 45}, {x + 95, y + 45}, {x + 95, y + 80}, {x, y + 80}}, {103, 152, 191});

    /// Layer Five
    polygonR({{x + 2, y + 47}, {x + 93, y + 47}, {x + 93, y + 78}, {x + 2, y + 78}}, {19, 23, 69});
}

/// Initializing Signboard
void SignBoard(float x, float y){
    Building_One_SignBoard(x + 25, y + 10);
    if(signBoard){
        if(nightR){
            SignBoard_Donute(x + 60 + DonutePosition, y + 65, {218, 78, 209});
            SignBoard_Donute(x + 75 + DonutePosition, y + 67, {250, 254, 124});
            SignBoard_Donute(x + 90 + DonutePosition, y + 65, {218, 78, 209});
            SignBoard_Donute(x + 105 + DonutePosition, y + 67, {250, 254, 124});
        }
    }
}

/// Building One Network Tower
void NetworkTower(float x, float y, ColorR shadow = {19, 23, 69}, ColorR light = {244, 29, 27}){

    polygonR({{x + 25, y}, {x + 30, y}, {x + 30, y + 15}, {x + 25, y + 15}}, shadow);
    if(nightR) polygonR({{x + 24, y + 15}, {x + 31, y + 15}, {x + 31, y + 20}, {x + 24, y + 20}}, light);

    polygonR({{x + 30, y}, {x + 50, y}, {x + 50, y + 10}, {x + 30, y + 10}}, shadow);

    polygonR({{x + 50, y}, {x + 55, y}, {x + 55, y + 20}, {x + 50, y + 20}}, shadow);

    polygonR({{x + 65, y}, {x + 70, y}, {x + 70, y + 10}, {x + 65, y + 10}}, shadow);
}

/// Building One's Terrace
void Building_One_Terrace(float x, float y){
    polygonR({{x + 20, y}, {x + 75, y}, {x + 75, y + 5}, {x + 20, y + 5}}, {122, 165, 198});
    polygonR({{x + 20, y + 5}, {x + 75, y + 5}, {x + 75, y + 10}, {x + 20, y + 10}}, {155, 204, 239});

    polygonR({{x + 75, y}, {x + 130, y}, {x + 130, y + 5}, {x + 75, y + 5}}, {78, 105, 131});
    polygonR({{x + 75, y + 5}, {x + 130, y + 5}, {x + 130, y + 10}, {x + 75, y + 10}}, {90, 125, 149});

    NetworkTower(x + 20, y + 10);
}

/// Building Two
void Building_Two(float x, float y, int m = 1){
    if(nightR){
        /// Base
        polygonR({{x + 0, y + 0}, {x + 70, y + 0}, {x + 70, y + 10}, {x + 0, y + 10}}, {49, 33, 196});
        polygonR({{x + 70, y + 0}, {x + 140, y + 0}, {x + 140, y + 10}, {x + 70, y + 10}}, {29, 1, 50});

        /// First Floor
        polygonR({{x + 0, y + 10}, {x + 70, y + 10}, {x + 70, y + 20}, {x + 0, y + 20}}, {22, 37, 128});
        polygonR({{x + 0, y + 20}, {x + 70, y + 20}, {x + 70, y + 30}, {x + 0, y + 30}}, {33, 25, 108});

        polygonR({{x + 70, y + 10}, {x + 140, y + 10}, {x + 140, y + 20}, {x + 70, y + 20}}, {49, 0, 49});
        polygonR({{x + 70, y + 20}, {x + 140, y + 20}, {x + 140, y + 30}, {x + 70, y + 30}}, {41, 0, 54});

        /// Second Floor
        polygonR({{x + 0, y + 30}, {x + 70, y + 30}, {x + 70, y + 40}, {x + 0, y + 40}}, {48, 38, 193});
        polygonR({{x + 70, y + 30}, {x + 140, y + 30}, {x + 140, y + 40}, {x + 70, y + 40}}, {36, 0, 51});

        polygonR({{x + 0, y + 40}, {x + 70, y + 40}, {x + 70, y + 50}, {x + 0, y + 50}}, {22, 37, 128});
        polygonR({{x + 0, y + 50}, {x + 70, y + 50}, {x + 70, y + 60}, {x + 0, y + 60}}, {33, 25, 108});

        polygonR({{x + 70, y + 40}, {x + 140, y + 40}, {x + 140, y + 50}, {x + 70, y + 50}}, {49, 0, 49});
        polygonR({{x + 70, y + 50}, {x + 140, y + 50}, {x + 140, y + 60}, {x + 70, y + 60}}, {41, 0, 54});

        /// Third Floor
        polygonR({{x + 0, y + 60}, {x + 70, y + 60}, {x + 70, y + 70}, {x + 0, y + 70}}, {48, 38, 193});
        polygonR({{x + 70, y + 60}, {x + 140, y + 60}, {x + 140, y + 70}, {x + 70, y + 70}}, {27, 2, 50});

        polygonR({{x + 0, y + 70}, {x + 70, y + 70}, {x + 70, y + 80}, {x + 0, y + 80}}, {22, 37, 128});
        polygonR({{x + 0, y + 80}, {x + 70, y + 80}, {x + 70, y + 90}, {x + 0, y + 90}}, {33, 25, 108});

        polygonR({{x + 70, y + 70}, {x + 140, y + 70}, {x + 140, y + 80}, {x + 70, y + 80}}, {49, 0, 49});
        polygonR({{x + 70, y + 80}, {x + 140, y + 80}, {x + 140, y + 90}, {x + 70, y + 90}}, {41, 0, 54});

        /// Middle Portion
        polygonR({{x + 0, y + 90}, {x + 70, y + 90}, {x + 70, y + 100}, {x + 0, y + 100}}, {77, 50, 202});
        polygonR({{x + 70, y + 90}, {x + 140, y + 90}, {x + 140, y + 100}, {x + 70, y + 100}}, {43, 17, 78});

        polygonR({{x + 0, y + 100}, {x + 140, y + 100}, {x + 140, y + 110}, {x + 0, y + 110}}, {27, 2, 50});

        polygonR({{x + 0, y + 110}, {x + 70, y + 110}, {x + 70, y + 125}, {x + 0, y + 125}}, {77, 50, 202});
        polygonR({{x + 70, y + 110}, {x + 140, y + 110}, {x + 140, y + 125}, {x + 70, y + 125}}, {43, 17, 78});

        /// Fourth Floor
        polygonR({{x + 0, y + 125}, {x + 70, y + 125}, {x + 70, y + 135}, {x + 0, y + 135}}, {29, 53, 142});
        polygonR({{x + 0, y + 135}, {x + 70, y + 135}, {x + 70, y + 145}, {x + 0, y + 145}}, {40, 24, 106});

        polygonR({{x + 70, y + 125}, {x + 140, y + 125}, {x + 140, y + 145}, {x + 70, y + 145}}, {33, 11, 58});

        /// Fifth Floor
        polygonR({{x + 0, y + 145}, {x + 70, y + 145}, {x + 70, y + 155}, {x + 0, y + 155}}, {36, 50, 127});
        polygonR({{x + 70, y + 145}, {x + 140, y + 145}, {x + 140, y + 155}, {x + 70, y + 155}}, {40, 24, 106});

        polygonR({{x + 0, y + 155}, {x + 70, y + 155}, {x + 70, y + 165}, {x + 0, y + 165}}, {29, 53, 142});
        polygonR({{x + 0, y + 165}, {x + 70, y + 165}, {x + 70, y + 175}, {x + 0, y + 175}}, {40, 24, 106});

        polygonR({{x + 70, y + 155}, {x + 140, y + 155}, {x + 140, y + 175}, {x + 70, y + 175}}, {33, 11, 58});

        /// Sixth Floor
        polygonR({{x + 0, y + 175}, {x + 70, y + 175}, {x + 70, y + 185}, {x + 0, y + 185}}, {36, 50, 127});
        polygonR({{x + 70, y + 175}, {x + 140, y + 175}, {x + 140, y + 185}, {x + 70, y + 185}}, {40, 24, 106});

        polygonR({{x + 0, y + 185}, {x + 70, y + 185}, {x + 70, y + 195}, {x + 0, y + 195}}, {29, 53, 142});
        polygonR({{x + 0, y + 195}, {x + 70, y + 195}, {x + 70, y + 205}, {x + 0, y + 205}}, {40, 24, 106});

        polygonR({{x + 70, y + 185}, {x + 140, y + 185}, {x + 140, y + 205}, {x + 70, y + 205}}, {33, 11, 58});

        /// First Floor's Windows
        polygonR({{x + 10, y + 10}, {x + 20, y + 10}, {x + 20, y + 25}, {x + 10, y + 25}}, {5, 67, 157});
        polygonR({{x + 30, y + 10}, {x + 40, y + 10}, {x + 40, y + 25}, {x + 30, y + 25}}, {34, 203, 197});
        polygonR({{x + 50, y + 10}, {x + 60, y + 10}, {x + 60, y + 25}, {x + 50, y + 25}}, {5, 67, 157});

        polygonR({{x + 80, y + 10}, {x + 90, y + 10}, {x + 90, y + 25}, {x + 80, y + 25}}, {29, 18, 90});
        polygonR({{x + 100, y + 10}, {x + 110, y + 10}, {x + 110, y + 25}, {x + 100, y + 25}}, {29, 18, 90});
        polygonR({{x + 120, y + 10}, {x + 130, y + 10}, {x + 130, y + 25}, {x + 120, y + 25}}, {29, 18, 90});

        /// Second Floor's Windows
        polygonR({{x + 10, y + 40}, {x + 20, y + 40}, {x + 20, y + 55}, {x + 10, y + 55}}, {5, 67, 157});
        polygonR({{x + 30, y + 40}, {x + 40, y + 40}, {x + 40, y + 55}, {x + 30, y + 55}}, {34, 203, 197});
        polygonR({{x + 50, y + 40}, {x + 60, y + 40}, {x + 60, y + 55}, {x + 50, y + 55}}, {39, 80, 92});

        polygonR({{x + 80, y + 40}, {x + 90, y + 40}, {x + 90, y + 55}, {x + 80, y + 55}}, {39, 80, 92});
        polygonR({{x + 100, y + 40}, {x + 110, y + 40}, {x + 110, y + 55}, {x + 100, y + 55}}, {39, 80, 92});
        polygonR({{x + 120, y + 40}, {x + 130, y + 40}, {x + 130, y + 55}, {x + 120, y + 55}}, {5, 67, 157});

        /// Third Floor's Windows
        polygonR({{x + 10, y + 70}, {x + 20, y + 70}, {x + 20, y + 85}, {x + 10, y + 85}}, {5, 67, 157});
        polygonR({{x + 30, y + 70}, {x + 40, y + 70}, {x + 40, y + 85}, {x + 30, y + 85}}, {34, 203, 197});
        polygonR({{x + 50, y + 70}, {x + 60, y + 70}, {x + 60, y + 85}, {x + 50, y + 85}}, {5, 67, 157});

        polygonR({{x + 80, y + 70}, {x + 90, y + 70}, {x + 90, y + 85}, {x + 80, y + 85}}, {34, 203, 197});
        polygonR({{x + 100, y + 70}, {x + 110, y + 70}, {x + 110, y + 85}, {x + 100, y + 85}}, {25, 67, 157});
        polygonR({{x + 120, y + 70}, {x + 130, y + 70}, {x + 130, y + 85}, {x + 120, y + 85}}, {5, 67, 157});

        /// Fourth Floor's Windows
        polygonR({{x + 10, y + 125}, {x + 20, y + 125}, {x + 20, y + 140}, {x + 10, y + 140}}, {5, 67, 157});
        polygonR({{x + 30, y + 125}, {x + 40, y + 125}, {x + 40, y + 140}, {x + 30, y + 140}}, {34, 203, 197});
        polygonR({{x + 50, y + 125}, {x + 60, y + 125}, {x + 60, y + 140}, {x + 50, y + 140}}, {5, 67, 157});

        polygonR({{x + 80, y + 125}, {x + 90, y + 125}, {x + 90, y + 140}, {x + 80, y + 140}}, {5, 67, 157});
        polygonR({{x + 100, y + 125}, {x + 110, y + 125}, {x + 110, y + 140}, {x + 100, y + 140}}, {5, 67, 157});
        polygonR({{x + 120, y + 125}, {x + 130, y + 125}, {x + 130, y + 140}, {x + 120, y + 140}}, {5, 67, 157});

        /// Fifth Floor's Windows
        polygonR({{x + 10, y + 155}, {x + 20, y + 155}, {x + 20, y + 170}, {x + 10, y + 170}}, {34, 203, 197});
        polygonR({{x + 30, y + 155}, {x + 40, y + 155}, {x + 40, y + 170}, {x + 30, y + 170}}, {34, 203, 197});
        polygonR({{x + 50, y + 155}, {x + 60, y + 155}, {x + 60, y + 170}, {x + 50, y + 170}}, {51, 111, 188});

        polygonR({{x + 80, y + 155}, {x + 90, y + 155}, {x + 90, y + 170}, {x + 80, y + 170}}, {5, 67, 157});
        polygonR({{x + 100, y + 155}, {x + 110, y + 155}, {x + 110, y + 170}, {x + 100, y + 170}}, {5, 67, 157});
        polygonR({{x + 120, y + 155}, {x + 130, y + 155}, {x + 130, y + 170}, {x + 120, y + 170}}, {5, 67, 157});

        /// Sixth Floor's Windows
        polygonR({{x + 10, y + 185}, {x + 20, y + 185}, {x + 20, y + 200}, {x + 10, y + 200}}, {34, 203, 197});
        polygonR({{x + 30, y + 185}, {x + 40, y + 185}, {x + 40, y + 200}, {x + 30, y + 200}}, {34, 203, 197});
        polygonR({{x + 50, y + 185}, {x + 60, y + 185}, {x + 60, y + 200}, {x + 50, y + 200}}, {51, 111, 188});

        polygonR({{x + 80, y + 185}, {x + 90, y + 185}, {x + 90, y + 200}, {x + 80, y + 200}}, {51, 111, 188});
        polygonR({{x + 100, y + 185}, {x + 110, y + 185}, {x + 110, y + 200}, {x + 100, y + 200}}, {51, 111, 188});
        polygonR({{x + 120, y + 185}, {x + 130, y + 185}, {x + 130, y + 200}, {x + 120, y + 200}}, {51, 111, 188});

        /// Terrace
        polygonR({{x + 0, y + 205}, {x + 70, y + 205}, {x + 70, y + 220}, {x + 0, y + 220}}, {123, 82, 198});
        polygonR({{x + 70, y + 205}, {x + 140, y + 205}, {x + 140, y + 220}, {x + 70, y + 220}}, {16, 40, 59});
    }
    else if(dayR){
        ColorR WhiteOne = {245, 204, 160};
        ColorR WhiteTwo = {153, 77, 28};
        ColorR GrayOne = {228, 143, 69};
        ColorR GrayTwo = {107, 36, 12};
        ColorR GrayThree = {107, 36, 12};
        ColorR WindowTypeOne = {251, 139, 36};
        ColorR WindowTypeTwo = {227, 100, 20};
        /// Base
        polygonR({{x + 0, y + 0}, {x + 70, y + 0}, {x + 70, y + 10}, {x + 0, y + 10}}, WhiteOne);
        polygonR({{x + 70, y + 0}, {x + 140, y + 0}, {x + 140, y + 10}, {x + 70, y + 10}}, GrayOne);

        /// First Floor
        polygonR({{x + 0, y + 10}, {x + 70, y + 10}, {x + 70, y + 20}, {x + 0, y + 20}}, WhiteTwo);
        polygonR({{x + 0, y + 20}, {x + 70, y + 20}, {x + 70, y + 30}, {x + 0, y + 30}}, GrayTwo);

        polygonR({{x + 70, y + 10}, {x + 140, y + 10}, {x + 140, y + 30}, {x + 70, y + 30}}, GrayThree);

        /// Second Floor
        polygonR({{x + 0, y + 30}, {x + 70, y + 30}, {x + 70, y + 40}, {x + 0, y + 40}}, WhiteOne);
        polygonR({{x + 70, y + 30}, {x + 140, y + 30}, {x + 140, y + 40}, {x + 70, y + 40}}, GrayOne);

        polygonR({{x + 0, y + 40}, {x + 70, y + 40}, {x + 70, y + 50}, {x + 0, y + 50}}, WhiteTwo);
        polygonR({{x + 0, y + 50}, {x + 70, y + 50}, {x + 70, y + 60}, {x + 0, y + 60}}, GrayTwo);

        polygonR({{x + 70, y + 40}, {x + 140, y + 40}, {x + 140, y + 60}, {x + 70, y + 60}}, GrayThree);

        /// Third Floor
        polygonR({{x + 0, y + 60}, {x + 70, y + 60}, {x + 70, y + 70}, {x + 0, y + 70}}, WhiteOne);
        polygonR({{x + 70, y + 60}, {x + 140, y + 60}, {x + 140, y + 70}, {x + 70, y + 70}}, GrayOne);

        polygonR({{x + 0, y + 70}, {x + 70, y + 70}, {x + 70, y + 80}, {x + 0, y + 80}}, WhiteTwo);
        polygonR({{x + 0, y + 80}, {x + 70, y + 80}, {x + 70, y + 90}, {x + 0, y + 90}}, GrayTwo);

        polygonR({{x + 70, y + 70}, {x + 140, y + 70}, {x + 140, y + 90}, {x + 70, y + 90}}, GrayThree);

        /// Middle Portion
        polygonR({{x + 0, y + 90}, {x + 70, y + 90}, {x + 70, y + 100}, {x + 0, y + 100}}, WhiteOne);
        polygonR({{x + 70, y + 90}, {x + 140, y + 90}, {x + 140, y + 100}, {x + 70, y + 100}}, GrayOne);

        polygonR({{x + 0, y + 100}, {x + 140, y + 100}, {x + 140, y + 110}, {x + 0, y + 110}}, {27, 2, 50});

        polygonR({{x + 0, y + 110}, {x + 70, y + 110}, {x + 70, y + 125}, {x + 0, y + 125}}, WhiteOne);
        polygonR({{x + 70, y + 110}, {x + 140, y + 110}, {x + 140, y + 125}, {x + 70, y + 125}}, GrayOne);

        /// Fourth Floor
        polygonR({{x + 0, y + 125}, {x + 70, y + 125}, {x + 70, y + 135}, {x + 0, y + 135}}, WhiteTwo);
        polygonR({{x + 0, y + 135}, {x + 70, y + 135}, {x + 70, y + 145}, {x + 0, y + 145}}, GrayTwo);

        polygonR({{x + 70, y + 125}, {x + 140, y + 125}, {x + 140, y + 145}, {x + 70, y + 145}}, GrayThree);

        /// Fifth Floor
        polygonR({{x + 0, y + 145}, {x + 70, y + 145}, {x + 70, y + 155}, {x + 0, y + 155}}, WhiteOne);
        polygonR({{x + 70, y + 145}, {x + 140, y + 145}, {x + 140, y + 155}, {x + 70, y + 155}}, GrayOne);

        polygonR({{x + 0, y + 155}, {x + 70, y + 155}, {x + 70, y + 165}, {x + 0, y + 165}}, WhiteTwo);
        polygonR({{x + 0, y + 165}, {x + 70, y + 165}, {x + 70, y + 175}, {x + 0, y + 175}}, GrayTwo);

        polygonR({{x + 70, y + 155}, {x + 140, y + 155}, {x + 140, y + 175}, {x + 70, y + 175}}, GrayThree);

        /// Sixth Floor
        polygonR({{x + 0, y + 175}, {x + 70, y + 175}, {x + 70, y + 185}, {x + 0, y + 185}}, WhiteOne);
        polygonR({{x + 70, y + 175}, {x + 140, y + 175}, {x + 140, y + 185}, {x + 70, y + 185}}, GrayOne);

        polygonR({{x + 0, y + 185}, {x + 70, y + 185}, {x + 70, y + 195}, {x + 0, y + 195}}, WhiteTwo);
        polygonR({{x + 0, y + 195}, {x + 70, y + 195}, {x + 70, y + 205}, {x + 0, y + 205}}, GrayTwo);

        polygonR({{x + 70, y + 185}, {x + 140, y + 185}, {x + 140, y + 205}, {x + 70, y + 205}}, GrayThree);

        /// First Floor's Windows
        polygonR({{x + 10, y + 10}, {x + 20, y + 10}, {x + 20, y + 25}, {x + 10, y + 25}}, WindowTypeTwo);
        polygonR({{x + 30, y + 10}, {x + 40, y + 10}, {x + 40, y + 25}, {x + 30, y + 25}}, WindowTypeOne);
        polygonR({{x + 50, y + 10}, {x + 60, y + 10}, {x + 60, y + 25}, {x + 50, y + 25}}, WindowTypeTwo);

        polygonR({{x + 80, y + 10}, {x + 90, y + 10}, {x + 90, y + 25}, {x + 80, y + 25}}, WindowTypeTwo);
        polygonR({{x + 100, y + 10}, {x + 110, y + 10}, {x + 110, y + 25}, {x + 100, y + 25}}, WindowTypeTwo);
        polygonR({{x + 120, y + 10}, {x + 130, y + 10}, {x + 130, y + 25}, {x + 120, y + 25}}, WindowTypeTwo);

        /// Second Floor's Windows
        polygonR({{x + 10, y + 40}, {x + 20, y + 40}, {x + 20, y + 55}, {x + 10, y + 55}}, WindowTypeTwo);
        polygonR({{x + 30, y + 40}, {x + 40, y + 40}, {x + 40, y + 55}, {x + 30, y + 55}}, WindowTypeOne);
        polygonR({{x + 50, y + 40}, {x + 60, y + 40}, {x + 60, y + 55}, {x + 50, y + 55}}, WindowTypeTwo);

        polygonR({{x + 80, y + 40}, {x + 90, y + 40}, {x + 90, y + 55}, {x + 80, y + 55}}, WindowTypeTwo);
        polygonR({{x + 100, y + 40}, {x + 110, y + 40}, {x + 110, y + 55}, {x + 100, y + 55}}, WindowTypeTwo);
        polygonR({{x + 120, y + 40}, {x + 130, y + 40}, {x + 130, y + 55}, {x + 120, y + 55}}, WindowTypeTwo);

        /// Third Floor's Windows
        polygonR({{x + 10, y + 70}, {x + 20, y + 70}, {x + 20, y + 85}, {x + 10, y + 85}}, WindowTypeTwo);
        polygonR({{x + 30, y + 70}, {x + 40, y + 70}, {x + 40, y + 85}, {x + 30, y + 85}}, WindowTypeOne);
        polygonR({{x + 50, y + 70}, {x + 60, y + 70}, {x + 60, y + 85}, {x + 50, y + 85}}, WindowTypeTwo);

        polygonR({{x + 80, y + 70}, {x + 90, y + 70}, {x + 90, y + 85}, {x + 80, y + 85}}, WindowTypeTwo);
        polygonR({{x + 100, y + 70}, {x + 110, y + 70}, {x + 110, y + 85}, {x + 100, y + 85}}, WindowTypeTwo);
        polygonR({{x + 120, y + 70}, {x + 130, y + 70}, {x + 130, y + 85}, {x + 120, y + 85}}, WindowTypeTwo);

        /// Fourth Floor's Windows
        polygonR({{x + 10, y + 125}, {x + 20, y + 125}, {x + 20, y + 140}, {x + 10, y + 140}}, WindowTypeTwo);
        polygonR({{x + 30, y + 125}, {x + 40, y + 125}, {x + 40, y + 140}, {x + 30, y + 140}}, WindowTypeOne);
        polygonR({{x + 50, y + 125}, {x + 60, y + 125}, {x + 60, y + 140}, {x + 50, y + 140}}, WindowTypeTwo);

        polygonR({{x + 80, y + 125}, {x + 90, y + 125}, {x + 90, y + 140}, {x + 80, y + 140}}, WindowTypeTwo);
        polygonR({{x + 100, y + 125}, {x + 110, y + 125}, {x + 110, y + 140}, {x + 100, y + 140}}, WindowTypeTwo);
        polygonR({{x + 120, y + 125}, {x + 130, y + 125}, {x + 130, y + 140}, {x + 120, y + 140}}, WindowTypeTwo);

        /// Fifth Floor's Windows
        polygonR({{x + 10, y + 155}, {x + 20, y + 155}, {x + 20, y + 170}, {x + 10, y + 170}}, WindowTypeOne);
        polygonR({{x + 30, y + 155}, {x + 40, y + 155}, {x + 40, y + 170}, {x + 30, y + 170}}, WindowTypeOne);
        polygonR({{x + 50, y + 155}, {x + 60, y + 155}, {x + 60, y + 170}, {x + 50, y + 170}}, WindowTypeTwo);

        polygonR({{x + 80, y + 155}, {x + 90, y + 155}, {x + 90, y + 170}, {x + 80, y + 170}}, WindowTypeTwo);
        polygonR({{x + 100, y + 155}, {x + 110, y + 155}, {x + 110, y + 170}, {x + 100, y + 170}}, WindowTypeTwo);
        polygonR({{x + 120, y + 155}, {x + 130, y + 155}, {x + 130, y + 170}, {x + 120, y + 170}}, WindowTypeTwo);

        /// Sixth Floor's Windows
        polygonR({{x + 10, y + 185}, {x + 20, y + 185}, {x + 20, y + 200}, {x + 10, y + 200}}, WindowTypeOne);
        polygonR({{x + 30, y + 185}, {x + 40, y + 185}, {x + 40, y + 200}, {x + 30, y + 200}}, WindowTypeOne);
        polygonR({{x + 50, y + 185}, {x + 60, y + 185}, {x + 60, y + 200}, {x + 50, y + 200}}, WindowTypeTwo);

        polygonR({{x + 80, y + 185}, {x + 90, y + 185}, {x + 90, y + 200}, {x + 80, y + 200}}, WindowTypeTwo);
        polygonR({{x + 100, y + 185}, {x + 110, y + 185}, {x + 110, y + 200}, {x + 100, y + 200}}, WindowTypeTwo);
        polygonR({{x + 120, y + 185}, {x + 130, y + 185}, {x + 130, y + 200}, {x + 120, y + 200}}, WindowTypeTwo);

        /// Terrace
        polygonR({{x + 0, y + 205}, {x + 70, y + 205}, {x + 70, y + 220}, {x + 0, y + 220}}, WhiteOne);
        polygonR({{x + 70, y + 205}, {x + 140, y + 205}, {x + 140, y + 220}, {x + 70, y + 220}}, GrayOne);
    }
}

/// Other Building's Network Tower
void NetworkTowerTwo(float x, float y, ColorR shadow = {19, 23, 69}, ColorR light = {244, 29, 27}){

    polygonR({{x + 25, y}, {x + 100, y}, {x + 100, y + 10}, {x + 25, y + 10}}, shadow);
    polygonR({{x + 45, y}, {x + 80, y}, {x + 80, y + 25}, {x + 45, y + 25}}, shadow);
    polygonR({{x + 95, y}, {x + 100, y}, {x + 100, y + 25}, {x + 95, y + 25}}, shadow);
    polygonR({{x + 75, y}, {x + 80, y}, {x + 80, y + 40}, {x + 75, y + 40}}, shadow);

    if(nightR) polygonR({{x + 74, y + 40}, {x + 81, y + 40}, {x + 81, y + 47}, {x + 74, y + 47}}, light);
}

void Tomb(float x, float y, int m = 1, ColorR buildingWall = {132, 82, 211}, ColorR buildingWall2 = {33, 43, 80}, ColorR shadow = {56, 99, 164}, ColorR shadow2 = {16, 41, 83} , ColorR LeftWindow = {40, 82, 149}, ColorR RightWIndow = {9, 36, 78}){
    if(nightR){
        buildingWall = {132, 82, 211};
        buildingWall2 = {33, 43, 80};
        shadow = {56, 99, 164};
        shadow2 = {16, 41, 83};
        LeftWindow = {40, 82, 149};
        RightWIndow = {9, 36, 78};
    }
    else if(dayR){
        buildingWall = {245, 204, 160};
        buildingWall2 = {228, 143, 69};
        shadow = {153, 77, 28};
        shadow2 = {107, 36, 12};
        LeftWindow = {251, 139, 36};
        RightWIndow = {227, 100, 20};
    }
    polygonR({{x + m * 0, y + 0}, {x + m * 40, y + 0}, {x + m * 40, y + 8}, {x + m * 0, y + 8}}, buildingWall);
    polygonR({{x + m * 40, y + 0}, {x + m * 80, y + 0}, {x + m * 80, y + 8}, {x + m * 40, y + 8}}, buildingWall2);

    polygonR({{x + m * 5, y + 8}, {x + m * 40, y + 8}, {x + m * 40, y + 16}, {x + m * 5, y + 16}}, shadow);
    polygonR({{x + m * 40, y + 8}, {x + m * 75, y + 8}, {x + m * 75, y + 16}, {x + m * 40, y + 16}}, shadow2);

    /// First Floor Left Window
    polygonR({{x + m * 10, y + 8}, {x + m * 15, y + 8}, {x + m * 15, y + 14}, {x + m * 10, y + 14}}, LeftWindow);
    polygonR({{x + m * 25, y + 8}, {x + m * 30, y + 8}, {x + m * 30, y + 14}, {x + m * 25, y + 14}}, LeftWindow);

    /// First Floor Right Window
    polygonR({{x + m * 50, y + 8}, {x + m * 55, y + 8}, {x + m * 55, y + 14}, {x + m * 50, y + 14}}, RightWIndow);
    polygonR({{x + m * 65, y + 8}, {x + m * 70, y + 8}, {x + m * 70, y + 14}, {x + m * 65, y + 14}}, RightWIndow);

    polygonR({{x + m * 0, y + 16}, {x + m * 40, y + 16}, {x + m * 40, y + 24}, {x + m * 0, y + 24}}, buildingWall);
    polygonR({{x + m * 40, y + 16}, {x + m * 80, y + 16}, {x + m * 80, y + 24}, {x + m * 40, y + 24}}, buildingWall2);

    polygonR({{x + m * 5, y + 24}, {x + m * 40, y + 24}, {x + m * 40, y + 32}, {x + m * 5, y + 32}}, shadow);
    polygonR({{x + m * 40, y + 24}, {x + m * 75, y + 24}, {x + m * 75, y + 32}, {x + m * 40, y + 32}}, shadow2);

    /// Second Floor Left Window
    polygonR({{x + m * 10, y + 24}, {x + m * 15, y + 24}, {x + m * 15, y + 30}, {x + m * 10, y + 30}}, LeftWindow);
    polygonR({{x + m * 25, y + 24}, {x + m * 30, y + 24}, {x + m * 30, y + 30}, {x + m * 25, y + 30}}, LeftWindow);

    /// Third Floor Right Window
    polygonR({{x + m * 50, y + 24}, {x + m * 55, y + 24}, {x + m * 55, y + 30}, {x + m * 50, y + 30}}, RightWIndow);
    polygonR({{x + m * 65, y + 24}, {x + m * 70, y + 24}, {x + m * 70, y + 30}, {x + m * 65, y + 30}}, RightWIndow);

    polygonR({{x + m * 0, y + 32}, {x + m * 40, y + 32}, {x + m * 40, y + 40}, {x + m * 0, y + 40}}, buildingWall);
    polygonR({{x + m * 40, y + 32}, {x + m * 80, y + 32}, {x + m * 80, y + 40}, {x + m * 40, y + 40}}, buildingWall2);

    polygonR({{x + m * 5, y + 40}, {x + m * 40, y + 40}, {x + m * 40, y + 48}, {x + m * 5, y + 48}}, shadow);
    polygonR({{x + m * 40, y + 40}, {x + m * 75, y + 40}, {x + m * 75, y + 48}, {x + m * 40, y + 48}}, shadow2);

    /// Third Floor Left Window
    polygonR({{x + m * 10, y + 40}, {x + m * 15, y + 40}, {x + m * 15, y + 46}, {x + m * 10, y + 46}}, LeftWindow);
    polygonR({{x + m * 25, y + 40}, {x + m * 30, y + 40}, {x + m * 30, y + 46}, {x + m * 25, y + 46}}, LeftWindow);

    /// Third Floor Right Window
    polygonR({{x + m * 50, y + 40}, {x + m * 55, y + 40}, {x + m * 55, y + 46}, {x + m * 50, y + 46}}, RightWIndow);
    polygonR({{x + m * 65, y + 40}, {x + m * 70, y + 40}, {x + m * 70, y + 46}, {x + m * 65, y + 46}}, RightWIndow);

    polygonR({{x + m * 0, y + 48}, {x + m * 40, y + 48}, {x + m * 40, y + 56}, {x + m * 0, y + 56}}, buildingWall);
    polygonR({{x + m * 40, y + 48}, {x + m * 80, y + 48}, {x + m * 80, y + 56}, {x + m * 40, y + 56}}, buildingWall2);

    polygonR({{x + m * 5, y + 56}, {x + m * 40, y + 56}, {x + m * 40, y + 64}, {x + m * 5, y + 64}}, shadow);
    polygonR({{x + m * 40, y + 56}, {x + m * 75, y + 56}, {x + m * 75, y + 64}, {x + m * 40, y + 64}}, shadow2);

    /// Fourth Floor Left Window
    polygonR({{x + m * 10, y + 56}, {x + m * 15, y + 56}, {x + m * 15, y + 62}, {x + m * 10, y + 62}}, LeftWindow);
    polygonR({{x + m * 25, y + 56}, {x + m * 30, y + 56}, {x + m * 30, y + 62}, {x + m * 25, y + 62}}, LeftWindow);

    /// Fourth Floor Right Window
    polygonR({{x + m * 50, y + 56}, {x + m * 55, y + 56}, {x + m * 55, y + 62}, {x + m * 50, y + 62}}, RightWIndow);
    polygonR({{x + m * 65, y + 56}, {x + m * 70, y + 56}, {x + m * 70, y + 62}, {x + m * 65, y + 62}}, RightWIndow);

    polygonR({{x + m * 0, y + 64}, {x + m * 40, y + 64}, {x + m * 40, y + 72}, {x + m * 0, y + 72}}, buildingWall);
    polygonR({{x + m * 40, y + 64}, {x + m * 80, y + 64}, {x + m * 80, y + 72}, {x + m * 40, y + 72}}, buildingWall2);

    polygonR({{x + m * 5, y + 72}, {x + m * 40, y + 72}, {x + m * 40, y + 80}, {x + m * 5, y + 80}}, shadow);
    polygonR({{x + m * 40, y + 72}, {x + m * 75, y + 72}, {x + m * 75, y + 80}, {x + m * 40, y + 80}}, shadow2);

    /// Top Layer
    polygonR({{x + m * 10, y + 80}, {x + m * 40, y + 80}, {x + m * 40, y + 85}, {x + m * 10, y + 85}}, {155, 204, 239});
    polygonR({{x + m * 40, y + 80}, {x + m * 75, y + 80}, {x + m * 75, y + 85}, {x + m * 40, y + 85}}, {122, 165, 198});
}

void Third_Building(float x, float y, int m = 1, ColorR windowLightTop = {34, 203, 197}, ColorR windowLightBottom = {41, 94, 135}, ColorR windowDark = {28, 0, 149}, ColorR left = {135, 82, 214}, ColorR right = {26, 46, 74}, ColorR rightShadow = {6, 23, 52}, ColorR leftShadow = {33, 72, 136}){

    Building_One(200, 0);
    Building_One(1720, 0);

    if(nightR){
        windowLightTop = {34, 203, 197};
        windowLightBottom = {41, 94, 135};
        windowDark = {28, 0, 149};
        left = {135, 82, 214};
        right = {26, 46, 74};
        rightShadow = {6, 23, 52};
        leftShadow = {33, 72, 136};
    } else if(dayR){
        windowDark = {227, 100, 20};
        windowLightTop = {251, 139, 36};
        windowLightBottom = {145, 15, 64};
        left = {245, 204, 160};
        right = {228, 143, 69};
        rightShadow = {107, 36, 12};
        leftShadow = {153, 77, 28};
    }

    /// Terrace Layer
    polygonR({{x + m * 10, y + 250}, {x + m * 75, y + 250}, {x + m * 75, y + 255}, {x + m * 10, y + 255}}, {122, 165, 198});
    polygonR({{x + m * 10, y + 255}, {x + m * 75, y + 255}, {x + m * 75, y + 260}, {x + m * 10, y + 260}}, {155, 204, 239});

    polygonR({{x + m * 75, y + 250}, {x + m * 140, y + 250}, {x + m * 140, y + 255}, {x + m * 75, y + 255}}, {78, 105, 131});
    polygonR({{x + m * 75, y + 255}, {x + m * 140, y + 255}, {x + m * 140, y + 260}, {x + m * 75, y + 260}}, {90, 125, 149});

    polygonR({{x + m * 15, y + 260}, {x + m * 80, y + 260}, {x + m * 80, y + 265}, {x + m * 15, y + 265}}, {122, 165, 198});
    polygonR({{x + m * 15, y + 265}, {x + m * 80, y + 265}, {x + m * 80, y + 270}, {x + m * 15, y + 270}}, {155, 204, 239});

    polygonR({{x + m * 80, y + 260}, {x + m * 135, y + 260}, {x + m * 135, y + 265}, {x + m * 80, y + 265}}, {78, 105, 131});
    polygonR({{x + m * 80, y + 265}, {x + m * 135, y + 265}, {x + m * 135, y + 270}, {x + m * 80, y + 270}}, {90, 125, 149});

    polygonR({{x + m * 20, y + 270}, {x + m * 130, y + 270}, {x + m * 130, y + 275}, {x + m * 20, y + 275}}, {0, 0, 0});

    /// Top Portion
    /// Left Section
    polygonR({{x + m * 15, y + 275}, {x + m * 75, y + 275}, {x + m * 75, y + 400}, {x + m * 15, y + 400}}, left);


    polygonR({{x + m * 50, y + 280}, {x + m * 65, y + 280}, {x + m * 65, y + 395}, {x + m * 50, y + 395}}, leftShadow);
    polygonR({{x + m * 15, y + 280}, {x + m * 40, y + 280}, {x + m * 40, y + 395}, {x + m * 15, y + 395}}, leftShadow);

    /// Window Column One
    polygonR({{x + m * 20, y + 290}, {x + m * 40, y + 290}, {x + m * 40, y + 300}, {x + m * 20, y + 300}}, windowLightBottom);
    polygonR({{x + m * 20, y + 300}, {x + m * 40, y + 300}, {x + m * 40, y + 310}, {x + m * 20, y + 310}}, windowLightTop);

    polygonR({{x + m * 20, y + 320}, {x + m * 40, y + 320}, {x + m * 40, y + 330}, {x + m * 20, y + 330}}, windowLightBottom);
    polygonR({{x + m * 20, y + 330}, {x + m * 40, y + 330}, {x + m * 40, y + 340}, {x + m * 20, y + 340}}, windowLightTop);

    polygonR({{x + m * 20, y + 350}, {x + m * 40, y + 350}, {x + m * 40, y + 360}, {x + m * 20, y + 360}}, windowLightBottom);
    polygonR({{x + m * 20, y + 360}, {x + m * 40, y + 360}, {x + m * 40, y + 370}, {x + m * 20, y + 370}}, windowLightTop);

    polygonR({{x + m * 20, y + 380}, {x + m * 40, y + 380}, {x + m * 40, y + 390}, {x + m * 20, y + 390}}, windowLightTop);



    /// Window Column Two
    polygonR({{x + m * 55, y + 290}, {x + m * 65, y + 290}, {x + m * 65, y + 300}, {x + m * 55, y + 300}}, windowLightBottom);
    polygonR({{x + m * 55, y + 300}, {x + m * 65, y + 300}, {x + m * 65, y + 310}, {x + m * 55, y + 310}}, windowLightTop);

    polygonR({{x + m * 55, y + 320}, {x + m * 65, y + 320}, {x + m * 65, y + 340}, {x + m * 55, y + 340}}, windowDark);

    polygonR({{x + m * 55, y + 350}, {x + m * 65, y + 350}, {x + m * 65, y + 370}, {x + m * 55, y + 370}}, windowDark);

    polygonR({{x + m * 55, y + 380}, {x + m * 65, y + 380}, {x + m * 65, y + 390}, {x + m * 55, y + 390}}, windowDark);

    /// Right Section
    /// Pillar One
    polygonR({{x + m * 75, y + 275}, {x + m * 135, y + 275}, {x + m * 135, y + 400}, {x + m * 75, y + 400}}, right);

    /// Shadowed Portion One
    polygonR({{x + m * 85, y + 280}, {x + m * 105, y + 280}, {x + m * 105, y + 395}, {x + m * 85, y + 395}}, rightShadow);

    /// Window Column Three
    polygonR({{x + m * 87, y + 290}, {x + m * 98, y + 290}, {x + m * 98, y + 300}, {x + m * 87, y + 300}}, windowLightBottom);
    polygonR({{x + m * 87, y + 300}, {x + m * 98, y + 300}, {x + m * 98, y + 310}, {x + m * 87, y + 310}}, windowLightTop);

    polygonR({{x + m * 87, y + 320}, {x + m * 98, y + 320}, {x + m * 98, y + 330}, {x + m * 87, y + 330}}, windowLightBottom);
    polygonR({{x + m * 87, y + 330}, {x + m * 98, y + 330}, {x + m * 98, y + 340}, {x + m * 87, y + 340}}, windowLightTop);

    polygonR({{x + m * 87, y + 350}, {x + m * 98, y + 350}, {x + m * 98, y + 370}, {x + m * 87, y + 370}}, windowDark);

    polygonR({{x + m * 87, y + 380}, {x + m * 98, y + 380}, {x + m * 98, y + 390}, {x + m * 87, y + 390}}, windowLightBottom);

    /// Shadowed Portion Two
    polygonR({{x + m * 115, y + 280}, {x + m * 135, y + 280}, {x + m * 135, y + 395}, {x + m * 115, y + 395}}, rightShadow);

    /// Window Column Four
    polygonR({{x + m * 117, y + 290}, {x + m * 127, y + 290}, {x + m * 127, y + 310}, {x + m * 117, y + 310}}, windowDark);

    polygonR({{x + m * 117, y + 320}, {x + m * 127, y + 320}, {x + m * 127, y + 330}, {x + m * 117, y + 330}}, windowLightBottom);
    polygonR({{x + m * 117, y + 330}, {x + m * 127, y + 330}, {x + m * 127, y + 340}, {x + m * 117, y + 340}}, windowLightTop);

    polygonR({{x + m * 117, y + 350}, {x + m * 127, y + 350}, {x + m * 127, y + 370}, {x + m * 117, y + 370}}, windowDark);

    polygonR({{x + m * 117, y + 380}, {x + m * 127, y + 380}, {x + m * 127, y + 390}, {x + m * 117, y + 390}}, windowDark);

    /// Top Portion's Terrace Layer
    polygonR({{x + m * 20, y + 400}, {x + m * 75, y + 400}, {x + m * 75, y + 405}, {x + m * 20, y + 405}}, {122, 165, 198});
    polygonR({{x + m * 20, y + 405}, {x + m * 75, y + 405}, {x + m * 75, y + 410}, {x + m * 20, y + 410}}, {155, 204, 239});

    polygonR({{x + m * 75, y + 400}, {x + m * 130, y + 400}, {x + m * 130, y + 405}, {x + m * 75, y + 405}}, {78, 105, 131});
    polygonR({{x + m * 75, y + 405}, {x + m * 130, y + 405}, {x + m * 130, y + 410}, {x + m * 75, y + 410}}, {90, 125, 149});

    polygonR({{x + m * 25, y + 410}, {x + m * 80, y + 410}, {x + m * 80, y + 415}, {x + m * 25, y + 415}}, {122, 165, 198});
    polygonR({{x + m * 25, y + 415}, {x + m * 80, y + 415}, {x + m * 80, y + 420}, {x + m * 25, y + 420}}, {155, 204, 239});

    polygonR({{x + m * 80, y + 410}, {x + m * 125, y + 410}, {x + m * 125, y + 415}, {x + m * 80, y + 415}}, {78, 105, 131});
    polygonR({{x + m * 80, y + 415}, {x + m * 125, y + 415}, {x + m * 125, y + 420}, {x + m * 80, y + 420}}, {90, 125, 149});

    Tomb(1755, 420);
    Tomb(235, 420);
}

void NetworkTowerThree(float x, float y, ColorR shadow = {19, 23, 69}, ColorR light = {244, 29, 27}){
    polygonR({{x + 25, y}, {x + 30, y}, {x + 30, y + 15}, {x + 25, y + 15}}, shadow);

    polygonR({{x + 35, y}, {x + 50, y}, {x + 50, y + 10}, {x + 35, y + 10}}, shadow);

    polygonR({{x + 50, y}, {x + 55, y}, {x + 55, y + 25}, {x + 50, y + 25}}, shadow);

    if(nightR) polygonR({{x + 49, y + 25}, {x + 56, y + 25}, {x + 56, y + 30}, {x + 49, y + 30}}, light);

    polygonR({{x + 65, y}, {x + 70, y}, {x + 70, y + 40}, {x + 65, y + 40}}, shadow);

    if(nightR) polygonR({{x + 64, y + 40}, {x + 71, y + 40}, {x + 71, y + 45}, {x + 64, y + 45}}, light);
}

void Fifth_Building(float x, float y, int m = 1, ColorR buildingWall = {130, 86, 199}, ColorR buildingWall2 = {32, 35, 76}){
    if(nightR){
        buildingWall = {130, 86, 199};
        buildingWall2 = {32, 35, 76};
    }
    else if(dayR){
        buildingWall = {228, 143, 69};
        buildingWall2 = {153, 77, 28};
    }
    polygonR({{x + m * 0, y + 0}, {x + m * 70, y + 0}, {x + m * 70, y + 495}, {x + m * 0, y + 495}}, buildingWall);
    polygonR({{x + m * 70, y + 0}, {x + m * 130, y + 0}, {x + m * 130, y + 495}, {x + m * 70, y + 495}}, buildingWall2);

    if(nightR){
    /// Bottom Window
    polygonR({{x + m * 5, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 10}, {x + m * 5, y + 10}}, {46, 21, 87});

    /// Second Window
    polygonR({{x + m * 5, y + 20}, {x + m * 65, y + 20}, {x + m * 65, y + 40}, {x + m * 5, y + 40}}, {38, 46, 127});
    polygonR({{x + m * 5, y + 40}, {x + m * 65, y + 40}, {x + m * 65, y + 50}, {x + m * 5, y + 50}}, {47, 25, 89});

    /// Third Window
    polygonR({{x + m * 5, y + 60}, {x + m * 65, y + 60}, {x + m * 65, y + 80}, {x + m * 5, y + 80}}, {41, 221, 132});
    polygonR({{x + m * 5, y + 80}, {x + m * 65, y + 80}, {x + m * 65, y + 90}, {x + m * 5, y + 90}}, {32, 130, 81});

    /// Forth Window
    polygonR({{x + m * 5, y + 100}, {x + m * 65, y + 100}, {x + m * 65, y + 120}, {x + m * 5, y + 120}}, {43, 71, 136});
    polygonR({{x + m * 5, y + 120}, {x + m * 65, y + 120}, {x + m * 65, y + 130}, {x + m * 5, y + 130}}, {61, 56, 130});

    /// Fifth Window
    polygonR({{x + m * 5, y + 140}, {x + m * 65, y + 140}, {x + m * 65, y + 160}, {x + m * 5, y + 160}}, {43, 221, 207});
    polygonR({{x + m * 5, y + 160}, {x + m * 65, y + 160}, {x + m * 65, y + 170}, {x + m * 5, y + 170}}, {34, 165, 146});

    /// Sixth Window
    polygonR({{x + m * 5, y + 180}, {x + m * 65, y + 180}, {x + m * 65, y + 200}, {x + m * 5, y + 200}}, {45, 87, 135});
    polygonR({{x + m * 5, y + 200}, {x + m * 65, y + 200}, {x + m * 65, y + 210}, {x + m * 5, y + 210}}, {32, 62, 97});

    /// Seventh Window
    polygonR({{x + m * 5, y + 220}, {x + m * 65, y + 220}, {x + m * 65, y + 240}, {x + m * 5, y + 240}}, {102, 255, 147});
    polygonR({{x + m * 5, y + 240}, {x + m * 65, y + 240}, {x + m * 65, y + 250}, {x + m * 5, y + 250}}, {67, 164, 97});

    /// Eight Window
    polygonR({{x + m * 5, y + 260}, {x + m * 65, y + 260}, {x + m * 65, y + 290}, {x + m * 5, y + 290}}, {51, 87, 145});

    /// Ninth Window
    polygonR({{x + m * 5, y + 300}, {x + m * 65, y + 300}, {x + m * 65, y + 320}, {x + m * 5, y + 320}}, {38, 46, 127});
    polygonR({{x + m * 5, y + 320}, {x + m * 65, y + 320}, {x + m * 65, y + 330}, {x + m * 5, y + 330}}, {47, 25, 89});

    /// Tenth Window
    polygonR({{x + m * 5, y + 340}, {x + m * 65, y + 340}, {x + m * 65, y + 360}, {x + m * 5, y + 360}}, {43, 221, 207});
    polygonR({{x + m * 5, y + 360}, {x + m * 65, y + 360}, {x + m * 65, y + 370}, {x + m * 5, y + 370}}, {34, 165, 146});

    /// Eleventh Window
    polygonR({{x + m * 5, y + 380}, {x + m * 65, y + 380}, {x + m * 65, y + 400}, {x + m * 5, y + 400}}, {41, 221, 132});
    polygonR({{x + m * 5, y + 400}, {x + m * 65, y + 400}, {x + m * 65, y + 410}, {x + m * 5, y + 410}}, {32, 130, 81});

    /// Twelfth Window
    polygonR({{x + m * 5, y + 420}, {x + m * 65, y + 420}, {x + m * 65, y + 440}, {x + m * 5, y + 440}}, {43, 71, 136});
    polygonR({{x + m * 5, y + 440}, {x + m * 65, y + 440}, {x + m * 65, y + 450}, {x + m * 5, y + 450}}, {61, 56, 130});

    /// Thirteenth Window
    polygonR({{x + m * 5, y + 460}, {x + m * 65, y + 460}, {x + m * 65, y + 480}, {x + m * 5, y + 480}}, {102, 255, 147});
    polygonR({{x + m * 5, y + 480}, {x + m * 65, y + 480}, {x + m * 65, y + 490}, {x + m * 5, y + 490}}, {67, 164, 97});

    } else if(dayR){

        ColorR windowBottom = {153, 77, 28};
        ColorR windowTop = {107, 36, 12};

        /// Bottom Window
        polygonR({{x + m * 5, y + 0}, {x + m * 65, y + 0}, {x + m * 65, y + 10}, {x + m * 5, y + 10}}, windowTop);

        /// Second Window
        polygonR({{x + m * 5, y + 20}, {x + m * 65, y + 20}, {x + m * 65, y + 40}, {x + m * 5, y + 40}}, windowBottom);
        polygonR({{x + m * 5, y + 40}, {x + m * 65, y + 40}, {x + m * 65, y + 50}, {x + m * 5, y + 50}}, windowTop);

        /// Third Window
        polygonR({{x + m * 5, y + 60}, {x + m * 65, y + 60}, {x + m * 65, y + 80}, {x + m * 5, y + 80}}, windowBottom);
        polygonR({{x + m * 5, y + 80}, {x + m * 65, y + 80}, {x + m * 65, y + 90}, {x + m * 5, y + 90}}, windowTop);

        /// Forth Window
        polygonR({{x + m * 5, y + 100}, {x + m * 65, y + 100}, {x + m * 65, y + 120}, {x + m * 5, y + 120}}, windowBottom);
        polygonR({{x + m * 5, y + 120}, {x + m * 65, y + 120}, {x + m * 65, y + 130}, {x + m * 5, y + 130}}, windowTop);

        /// Fifth Window
        polygonR({{x + m * 5, y + 140}, {x + m * 65, y + 140}, {x + m * 65, y + 160}, {x + m * 5, y + 160}}, windowBottom);
        polygonR({{x + m * 5, y + 160}, {x + m * 65, y + 160}, {x + m * 65, y + 170}, {x + m * 5, y + 170}}, windowTop);

        /// Sixth Window
        polygonR({{x + m * 5, y + 180}, {x + m * 65, y + 180}, {x + m * 65, y + 200}, {x + m * 5, y + 200}}, windowBottom);
        polygonR({{x + m * 5, y + 200}, {x + m * 65, y + 200}, {x + m * 65, y + 210}, {x + m * 5, y + 210}}, windowTop);

        /// Seventh Window
        polygonR({{x + m * 5, y + 220}, {x + m * 65, y + 220}, {x + m * 65, y + 240}, {x + m * 5, y + 240}}, windowBottom);
        polygonR({{x + m * 5, y + 240}, {x + m * 65, y + 240}, {x + m * 65, y + 250}, {x + m * 5, y + 250}}, windowTop);

        /// Eight Window
        polygonR({{x + m * 5, y + 260}, {x + m * 65, y + 260}, {x + m * 65, y + 290}, {x + m * 5, y + 290}}, windowTop);

         // Ninth Window
        polygonR({{x + m * 5, y + 300}, {x + m * 65, y + 300}, {x + m * 65, y + 320}, {x + m * 5, y + 320}}, windowBottom);
        polygonR({{x + m * 5, y + 320}, {x + m * 65, y + 320}, {x + m * 65, y + 330}, {x + m * 5, y + 330}}, windowTop);

        /// Tenth Window
        polygonR({{x + m * 5, y + 340}, {x + m * 65, y + 340}, {x + m * 65, y + 360}, {x + m * 5, y + 360}}, windowBottom);
        polygonR({{x + m * 5, y + 360}, {x + m * 65, y + 360}, {x + m * 65, y + 370}, {x + m * 5, y + 370}}, windowTop);

        /// Eleventh Window
        polygonR({{x + m * 5, y + 380}, {x + m * 65, y + 380}, {x + m * 65, y + 400}, {x + m * 5, y + 400}}, windowBottom);
        polygonR({{x + m * 5, y + 400}, {x + m * 65, y + 400}, {x + m * 65, y + 410}, {x + m * 5, y + 410}}, windowTop);

        /// Twelfth Window
        polygonR({{x + m * 5, y + 420}, {x + m * 65, y + 420}, {x + m * 65, y + 440}, {x + m * 5, y + 440}}, windowBottom);
        polygonR({{x + m * 5, y + 440}, {x + m * 65, y + 440}, {x + m * 65, y + 450}, {x + m * 5, y + 450}}, windowTop);

        /// Thirteenth Window
        polygonR({{x + m * 5, y + 460}, {x + m * 65, y + 460}, {x + m * 65, y + 480}, {x + m * 5, y + 480}}, windowBottom);
        polygonR({{x + m * 5, y + 480}, {x + m * 65, y + 480}, {x + m * 65, y + 490}, {x + m * 5, y + 490}}, windowTop);
    }
}

void SignBoard_Two(float x, float y, ColorR shadow = {19, 23, 69}){
    /// Pole's back shadow
    polygonR({{x + 20, y + 60}, {x + 100, y + 60}, {x + 100, y + 70}, {x + 20, y + 70}}, {35, 48, 98});

    /// Poles
    polygonR({{x + 10, y + 60}, {x + 20, y + 60}, {x + 20, y + 70}, {x + 10, y + 70}}, shadow);
    polygonR({{x + 40, y + 60}, {x + 50, y + 60}, {x + 50, y + 70}, {x + 40, y + 70}}, shadow);
    polygonR({{x + 70, y + 60}, {x + 80, y + 60}, {x + 80, y + 70}, {x + 70, y + 70}}, shadow);
    polygonR({{x + 100, y + 60}, {x + 110, y + 60}, {x + 110, y + 70}, {x + 100, y + 70}}, shadow);

    /// Board
    polygonR({{x + 0, y + 70}, {x + 120, y + 70}, {x + 120, y + 110}, {x + 0, y + 110}}, {63, 73, 249});

    /// Board Objects
    polygonR({{x + 15, y + 105}, {x + 20, y + 105}, {x + 20, y + 110}, {x + 15, y + 110}}, {125, 187, 255});
    polygonR({{x + 25, y + 105}, {x + 80, y + 105}, {x + 80, y + 110}, {x + 25, y + 110}}, {125, 187, 255});

    polygonR({{x + 20, y + 80}, {x + 55, y + 80}, {x + 55, y + 105}, {x + 20, y + 105}}, shadow);
    polygonR({{x + 55, y + 80}, {x + 75, y + 80}, {x + 75, y + 90}, {x + 55, y + 90}}, shadow);
    polygonR({{x + 75, y + 85}, {x + 95, y + 85}, {x + 95, y + 90}, {x + 75, y + 90}}, shadow);
    polygonR({{x + 80, y + 85}, {x + 95, y + 85}, {x + 95, y + 100}, {x + 80, y + 100}}, shadow);
    polygonR({{x + 90, y + 80}, {x + 100, y + 80}, {x + 100, y + 100}, {x + 90, y + 100}}, shadow);
    polygonR({{x + 20, y + 90}, {x + 35, y + 90}, {x + 35, y + 105}, {x + 20, y + 105}}, {239, 46, 65});
}

void Eight_Building(float x, float y, int m = 1, ColorR buildingWall = {24, 31, 61}, ColorR buildingWall2  = {42, 33, 186}, ColorR buildingWall3 = {35, 4, 46}, ColorR buildingWall4 = {27, 46, 75},
                    ColorR windowLightBottom = {34, 203, 197}, ColorR windowLightTop = {19, 122, 117}, ColorR SecondwindowLightBottom = {7, 79, 178}, ColorR SecondwindowLightTop = {18, 43, 135},
                    ColorR windowDarkBottom = {31, 19, 92}, ColorR windowDarkTop = {41, 0, 70}, ColorR SecondwindowDarkBottom = {23, 125, 122}, ColorR SecondwindowDarkTop = {39, 80, 92}
                    ){
    if(nightR){
        buildingWall = {24, 31, 61};
        buildingWall2  = {42, 33, 186};
        windowLightBottom = {34, 203, 197};
        windowLightTop = {19, 122, 117};
        SecondwindowLightBottom = {7, 79, 178};
        SecondwindowLightTop = {18, 43, 135};
        windowDarkBottom = {31, 19, 92};
        windowDarkTop = {41, 0, 70};
        SecondwindowDarkBottom = {23, 125, 122};
        SecondwindowDarkTop = {39, 80, 92};
    }else if(dayR){
        buildingWall2 = {153, 77, 28};
        buildingWall  = {228, 143, 69};
        windowLightBottom = {251, 139, 36};
        windowLightTop = {145, 15, 64};
        SecondwindowLightBottom = {153, 77, 28};
        SecondwindowLightTop = {107, 36, 12};
        windowDarkBottom = {107, 36, 12};
        windowDarkTop = {53, 27, 28};
        SecondwindowDarkBottom = {226, 139, 59};
        SecondwindowDarkTop = {125, 12, 55};
    }
    for (int i = 0; i < 200; ++i) {
        ColorR interpolatedColorR = interpolateColorR(buildingWall, buildingWall2, static_cast<float>(i) / 200.0f);
        polygonR({{x + m * i, y + 0}, {x + m * (i + 1), y + 0}, {x + m * (i + 1), y + 250}, {x + m * i, y + 250}}, interpolatedColorR);
    }

    polygonR({{x + m * 0, y + 70}, {x + m * 200, y + 70}, {x + m * 200, y + 75}, {x + m * 0, y + 75}}, {0, 0, 0});
    polygonR({{x + m * 0, y + 150}, {x + m * 200, y + 150}, {x + m * 200, y + 155}, {x + m * 0, y + 155}}, {0, 0, 0});

    polygonR({{x + m * 40, y + 250}, {x + m * 160, y + 250}, {x + m * 160, y + 255}, {x + m * 40, y + 255}}, {0, 0, 0});

    /// Windows Layer One
    polygonR({{x + m * 0, y + 10}, {x + m * 40, y + 10}, {x + m * 40, y + 20}, {x + m * 0, y + 20}}, windowLightBottom);
    polygonR({{x + m * 0, y + 20}, {x + m * 40, y + 20}, {x + m * 40, y + 30}, {x + m * 0, y + 30}}, windowLightTop);

    polygonR({{x + m * 50, y + 10}, {x + m * 100, y + 10}, {x + m * 100, y + 20}, {x + m * 50, y + 20}}, SecondwindowLightBottom);
    polygonR({{x + m * 50, y + 20}, {x + m * 100, y + 20}, {x + m * 100, y + 30}, {x + m * 50, y + 30}}, SecondwindowLightTop);


    polygonR({{x + m * 100, y + 10}, {x + m * 140, y + 10}, {x + m * 140, y + 20}, {x + m * 100, y + 20}}, windowDarkBottom);
    polygonR({{x + m * 100, y + 20}, {x + m * 140, y + 20}, {x + m * 140, y + 30}, {x + m * 100, y + 30}}, windowDarkTop);

    polygonR({{x + m * 150, y + 10}, {x + m * 175, y + 10}, {x + m * 175, y + 20}, {x + m * 150, y + 20}}, windowDarkBottom);
    polygonR({{x + m * 150, y + 20}, {x + m * 175, y + 20}, {x + m * 175, y + 30}, {x + m * 150, y + 30}}, windowDarkTop);

    polygonR({{x + m * 180, y + 10}, {x + m * 200, y + 10}, {x + m * 200, y + 20}, {x + m * 180, y + 20}}, SecondwindowDarkBottom);
    polygonR({{x + m * 180, y + 20}, {x + m * 200, y + 20}, {x + m * 200, y + 30}, {x + m * 180, y + 30}}, SecondwindowDarkTop);

    /// Windows Layer Two
    polygonR({{x + m * 0, y + 40}, {x + m * 20, y + 40}, {x + m * 20, y + 50}, {x + m * 0, y + 50}}, SecondwindowLightBottom);
    polygonR({{x + m * 0, y + 50}, {x + m * 20, y + 50}, {x + m * 20, y + 60}, {x + m * 0, y + 60}}, SecondwindowLightTop);

    polygonR({{x + m * 30, y + 40}, {x + m * 50, y + 40}, {x + m * 50, y + 50}, {x + m * 30, y + 50}}, windowLightBottom);
    polygonR({{x + m * 30, y + 50}, {x + m * 50, y + 50}, {x + m * 50, y + 60}, {x + m * 30, y + 60}}, windowLightTop);

    polygonR({{x + m * 60, y + 40}, {x + m * 100, y + 40}, {x + m * 100, y + 50}, {x + m * 60, y + 50}}, windowLightBottom);
    polygonR({{x + m * 60, y + 50}, {x + m * 100, y + 50}, {x + m * 100, y + 60}, {x + m * 60, y + 60}}, windowLightTop);

    polygonR({{x + m * 100, y + 40}, {x + m * 130, y + 40}, {x + m * 130, y + 50}, {x + m * 100, y + 50}}, SecondwindowDarkBottom);
    polygonR({{x + m * 100, y + 50}, {x + m * 130, y + 50}, {x + m * 130, y + 60}, {x + m * 100, y + 60}}, SecondwindowDarkTop);

    polygonR({{x + m * 140, y + 40}, {x + m * 160, y + 40}, {x + m * 160, y + 50}, {x + m * 140, y + 50}}, windowDarkBottom);
    polygonR({{x + m * 140, y + 50}, {x + m * 160, y + 50}, {x + m * 160, y + 60}, {x + m * 140, y + 60}}, windowDarkTop);

    polygonR({{x + m * 170, y + 40}, {x + m * 200, y + 40}, {x + m * 200, y + 50}, {x + m * 170, y + 50}}, SecondwindowDarkBottom);
    polygonR({{x + m * 170, y + 50}, {x + m * 200, y + 50}, {x + m * 200, y + 60}, {x + m * 170, y + 60}}, SecondwindowDarkTop);

    /// Window Layer Three
    polygonR({{x + m * 0, y + 80}, {x + m * 20, y + 80}, {x + m * 20, y + 90}, {x + m * 0, y + 90}}, SecondwindowLightBottom);
    polygonR({{x + m * 0, y + 90}, {x + m * 20, y + 90}, {x + m * 20, y + 100}, {x + m * 0, y + 100}}, windowLightTop);

    polygonR({{x + m * 30, y + 80}, {x + m * 50, y + 80}, {x + m * 50, y + 90}, {x + m * 30, y + 90}}, SecondwindowLightBottom);
    polygonR({{x + m * 30, y + 90}, {x + m * 50, y + 90}, {x + m * 50, y + 100}, {x + m * 30, y + 100}}, windowLightTop);

    polygonR({{x + m * 60, y + 80}, {x + m * 80, y + 80}, {x + m * 80, y + 90}, {x + m * 60, y + 90}}, SecondwindowLightBottom);
    polygonR({{x + m * 60, y + 90}, {x + m * 80, y + 90}, {x + m * 80, y + 100}, {x + m * 60, y + 100}}, windowLightTop);

    polygonR({{x + m * 90, y + 80}, {x + m * 100, y + 80}, {x + m * 100, y + 90}, {x + m * 90, y + 90}}, SecondwindowLightBottom);
    polygonR({{x + m * 90, y + 90}, {x + m * 100, y + 90}, {x + m * 100, y + 100}, {x + m * 90, y + 100}}, windowLightTop);

    polygonR({{x + m * 100, y + 80}, {x + m * 110, y + 80}, {x + m * 110, y + 90}, {x + m * 100, y + 90}}, windowDarkBottom);
    polygonR({{x + m * 100, y + 90}, {x + m * 110, y + 90}, {x + m * 110, y + 100}, {x + m * 100, y + 100}}, windowDarkTop);

    polygonR({{x + m * 120, y + 80}, {x + m * 140, y + 80}, {x + m * 140, y + 90}, {x + m * 120, y + 90}}, windowDarkBottom);
    polygonR({{x + m * 120, y + 90}, {x + m * 140, y + 90}, {x + m * 140, y + 100}, {x + m * 120, y + 100}}, windowDarkTop);

    polygonR({{x + m * 150, y + 80}, {x + m * 170, y + 80}, {x + m * 170, y + 90}, {x + m * 150, y + 90}}, windowDarkBottom);
    polygonR({{x + m * 150, y + 90}, {x + m * 170, y + 90}, {x + m * 170, y + 100}, {x + m * 150, y + 100}}, windowDarkTop);

    polygonR({{x + m * 180, y + 80}, {x + m * 200, y + 80}, {x + m * 200, y + 90}, {x + m * 180, y + 90}}, windowDarkBottom);
    polygonR({{x + m * 180, y + 90}, {x + m * 200, y + 90}, {x + m * 200, y + 100}, {x + m * 180, y + 100}}, windowDarkTop);

    /// Window Layer Four
    polygonR({{x + m * 0, y + 115}, {x + m * 40, y + 115}, {x + m * 40, y + 125}, {x + m * 0, y + 125}}, windowLightBottom);
    polygonR({{x + m * 0, y + 125}, {x + m * 40, y + 125}, {x + m * 40, y + 135}, {x + m * 0, y + 135}}, windowLightTop);

    polygonR({{x + m * 50, y + 115}, {x + m * 100, y + 115}, {x + m * 100, y + 125}, {x + m * 50, y + 125}}, SecondwindowLightBottom);
    polygonR({{x + m * 50, y + 125}, {x + m * 100, y + 125}, {x + m * 100, y + 135}, {x + m * 50, y + 135}}, windowLightTop);

    polygonR({{x + m * 100, y + 115}, {x + m * 150, y + 115}, {x + m * 150, y + 125}, {x + m * 100, y + 125}}, windowDarkBottom);
    polygonR({{x + m * 100, y + 125}, {x + m * 150, y + 125}, {x + m * 150, y + 135}, {x + m * 100, y + 135}}, windowDarkTop);

    polygonR({{x + m * 160, y + 115}, {x + m * 180, y + 115}, {x + m * 180, y + 125}, {x + m * 160, y + 125}}, SecondwindowDarkBottom);
    polygonR({{x + m * 160, y + 125}, {x + m * 180, y + 125}, {x + m * 180, y + 135}, {x + m * 160, y + 135}}, SecondwindowDarkTop);

    polygonR({{x + m * 190, y + 115}, {x + m * 200, y + 115}, {x + m * 200, y + 125}, {x + m * 190, y + 125}}, windowDarkBottom);
    polygonR({{x + m * 190, y + 125}, {x + m * 200, y + 125}, {x + m * 200, y + 135}, {x + m * 190, y + 135}}, windowDarkTop);

    /// Window Layer Five
    polygonR({{x + m * 0, y + 160}, {x + m * 20, y + 160}, {x + m * 20, y + 170}, {x + m * 0, y + 170}}, SecondwindowLightBottom);
    polygonR({{x + m * 0, y + 170}, {x + m * 20, y + 170}, {x + m * 20, y + 180}, {x + m * 0, y + 180}}, windowLightTop);

    polygonR({{x + m * 30, y + 160}, {x + m * 50, y + 160}, {x + m * 50, y + 170}, {x + m * 30, y + 170}}, windowLightBottom);
    polygonR({{x + m * 30, y + 170}, {x + m * 50, y + 170}, {x + m * 50, y + 180}, {x + m * 30, y + 180}}, windowLightTop);

    polygonR({{x + m * 60, y + 160}, {x + m * 80, y + 160}, {x + m * 80, y + 170}, {x + m * 60, y + 170}}, SecondwindowLightBottom);
    polygonR({{x + m * 60, y + 170}, {x + m * 80, y + 170}, {x + m * 80, y + 180}, {x + m * 60, y + 180}}, windowLightTop);

    polygonR({{x + m * 90, y + 160}, {x + m * 100, y + 160}, {x + m * 100, y + 170}, {x + m * 90, y + 170}}, SecondwindowLightBottom);
    polygonR({{x + m * 90, y + 170}, {x + m * 100, y + 170}, {x + m * 100, y + 180}, {x + m * 90, y + 180}}, windowLightTop);

    polygonR({{x + m * 100, y + 160}, {x + m * 110, y + 160}, {x + m * 110, y + 170}, {x + m * 100, y + 170}}, windowDarkBottom);
    polygonR({{x + m * 100, y + 170}, {x + m * 110, y + 170}, {x + m * 110, y + 180}, {x + m * 100, y + 180}}, windowDarkTop);

    polygonR({{x + m * 120, y + 160}, {x + m * 140, y + 160}, {x + m * 140, y + 170}, {x + m * 120, y + 170}}, windowDarkBottom);
    polygonR({{x + m * 120, y + 170}, {x + m * 140, y + 170}, {x + m * 140, y + 180}, {x + m * 120, y + 180}}, windowDarkTop);

    polygonR({{x + m * 150, y + 160}, {x + m * 170, y + 160}, {x + m * 170, y + 170}, {x + m * 150, y + 170}}, windowDarkBottom);
    polygonR({{x + m * 150, y + 170}, {x + m * 170, y + 170}, {x + m * 170, y + 180}, {x + m * 150, y + 180}}, windowDarkTop);

    polygonR({{x + m * 180, y + 160}, {x + m * 200, y + 160}, {x + m * 200, y + 170}, {x + m * 180, y + 170}}, SecondwindowDarkBottom);
    polygonR({{x + m * 180, y + 170}, {x + m * 200, y + 170}, {x + m * 200, y + 180}, {x + m * 180, y + 180}}, SecondwindowDarkTop);

    /// Window Layer Six
    polygonR({{x + m * 0, y + 195}, {x + m * 50, y + 195}, {x + m * 50, y + 205}, {x + m * 0, y + 205}}, windowLightBottom);
    polygonR({{x + m * 0, y + 205}, {x + m * 50, y + 205}, {x + m * 50, y + 215}, {x + m * 0, y + 215}}, windowLightTop);

    polygonR({{x + m * 60, y + 195}, {x + m * 100, y + 195}, {x + m * 100, y + 205}, {x + m * 60, y + 205}}, windowLightBottom);
    polygonR({{x + m * 60, y + 205}, {x + m * 100, y + 205}, {x + m * 100, y + 215}, {x + m * 60, y + 215}}, windowLightTop);

    polygonR({{x + m * 100, y + 195}, {x + m * 140, y + 195}, {x + m * 140, y + 205}, {x + m * 100, y + 205}}, SecondwindowDarkBottom);
    polygonR({{x + m * 100, y + 205}, {x + m * 140, y + 205}, {x + m * 140, y + 215}, {x + m * 100, y + 215}}, SecondwindowDarkTop);

    polygonR({{x + m * 150, y + 195}, {x + m * 200, y + 195}, {x + m * 200, y + 205}, {x + m * 150, y + 205}}, windowDarkBottom);
    polygonR({{x + m * 150, y + 205}, {x + m * 200, y + 205}, {x + m * 200, y + 215}, {x + m * 150, y + 215}}, windowDarkTop);

    /// Window Layer Seven
    polygonR({{x + m * 0, y + 225}, {x + m * 30, y + 225}, {x + m * 30, y + 232}, {x + m * 0, y + 232}}, windowLightBottom);
    polygonR({{x + m * 0, y + 232}, {x + m * 30, y + 232}, {x + m * 30, y + 240}, {x + m * 0, y + 240}}, windowLightTop);

    polygonR({{x + m * 40, y + 225}, {x + m * 70, y + 225}, {x + m * 70, y + 232}, {x + m * 40, y + 232}}, SecondwindowLightBottom);
    polygonR({{x + m * 40, y + 232}, {x + m * 70, y + 232}, {x + m * 70, y + 240}, {x + m * 40, y + 240}}, windowLightTop);

    polygonR({{x + m * 80, y + 225}, {x + m * 100, y + 225}, {x + m * 100, y + 232}, {x + m * 80, y + 232}}, windowLightBottom);
    polygonR({{x + m * 80, y + 232}, {x + m * 100, y + 232}, {x + m * 100, y + 240}, {x + m * 80, y + 240}}, windowLightTop);

    polygonR({{x + m * 100, y + 225}, {x + m * 120, y + 225}, {x + m * 120, y + 232}, {x + m * 100, y + 232}}, SecondwindowDarkBottom);
    polygonR({{x + m * 100, y + 232}, {x + m * 120, y + 232}, {x + m * 120, y + 240}, {x + m * 100, y + 240}}, SecondwindowDarkTop);

    polygonR({{x + m * 130, y + 225}, {x + m * 160, y + 225}, {x + m * 160, y + 232}, {x + m * 130, y + 232}}, SecondwindowDarkBottom);
    polygonR({{x + m * 130, y + 232}, {x + m * 160, y + 232}, {x + m * 160, y + 240}, {x + m * 130, y + 240}}, SecondwindowDarkTop);

    polygonR({{x + m * 170, y + 225}, {x + m * 200, y + 225}, {x + m * 200, y + 232}, {x + m * 170, y + 232}}, SecondwindowDarkBottom);
    polygonR({{x + m * 170, y + 232}, {x + m * 200, y + 232}, {x + m * 200, y + 240}, {x + m * 170, y + 240}}, SecondwindowDarkTop);
}

void Shadow_Building_One(float x, float y, int m = 1, ColorR shadow = {19, 23, 69}){
    polygonR({{x + m * 0, y + 0}, {x + m * 60, y + 0}, {x + m * 60, y + 40}, {x + m * 0, y + 40}}, shadow);
    polygonR({{x + m * 0, y + 40}, {x + m * 45, y + 40}, {x + m * 45, y + 60}, {x + m * 0, y + 60}}, shadow);
    polygonR({{x + m * 0, y + 60}, {x + m * 30, y + 60}, {x + m * 30, y + 80}, {x + m * 0, y + 80}}, shadow);
    polygonR({{x + m * 15, y + 80}, {x + m * 25, y + 80}, {x + m * 25, y + 95}, {x + m * 15, y + 95}}, shadow);

    polygonR({{x + m * 70, y - 85}, {x + m * 80, y - 85}, {x + m * 80, y + 165}, {x + m * 70, y + 165}}, shadow);
}

void Shadow_Building_Three(float x, float y, ColorR shadow = {19, 23, 69}){
    polygonR({{x + 0, y + 0}, {x + 50, y + 0}, {x + 50, y + 130}, {x + 0, y + 130}}, shadow);
    polygonR({{x + 10, y + 60}, {x + 50, y + 60}, {x + 50, y + 245}, {x + 10, y + 245}}, shadow);

    polygonR({{x + 20, y + 245}, {x + 40, y + 245}, {x + 40, y + 250}, {x + 20, y + 250}}, shadow);
    polygonR({{x + 10, y + 250}, {x + 50, y + 250}, {x + 50, y + 255}, {x + 10, y + 255}}, shadow);

    polygonR({{x + 20, y + 255}, {x + 40, y + 255}, {x + 40, y + 260}, {x + 20, y + 260}}, shadow);
    polygonR({{x + 10, y + 260}, {x + 50, y + 260}, {x + 50, y + 265}, {x + 10, y + 265}}, shadow);

    polygonR({{x + 20, y + 265}, {x + 40, y + 265}, {x + 40, y + 270}, {x + 20, y + 270}}, shadow);
    polygonR({{x + 10, y + 270}, {x + 50, y + 270}, {x + 50, y + 275}, {x + 10, y + 275}}, shadow);

    polygonR({{x + 20, y + 275}, {x + 40, y + 275}, {x + 40, y + 280}, {x + 20, y + 280}}, shadow);
    polygonR({{x + 10, y + 280}, {x + 50, y + 280}, {x + 50, y + 285}, {x + 10, y + 285}}, shadow);

    polygonR({{x + 20, y + 285}, {x + 40, y + 285}, {x + 40, y + 290}, {x + 20, y + 290}}, shadow);
    polygonR({{x + 10, y + 290}, {x + 50, y + 290}, {x + 50, y + 295}, {x + 10, y + 295}}, shadow);

    polygonR({{x + 20, y + 295}, {x + 40, y + 295}, {x + 40, y + 300}, {x + 20, y + 300}}, shadow);
    polygonR({{x + 10, y + 300}, {x + 50, y + 300}, {x + 50, y + 310}, {x + 10, y + 310}}, shadow);
}

void Building_Tower(float x, float y, ColorR shadow = {19, 23, 69}, ColorR light = {130, 86, 199}, ColorR red = {244, 29, 27}, ColorR black = {19, 23, 69}, ColorR pole = {53, 41, 107}){
    if(nightR){
        light = {130, 86, 199};
        shadow = {19, 23, 69};
        pole = {53, 41, 107};
    } else if (dayR){
        light = {228, 143, 69};
        shadow = {153, 77, 28};
        pole = {107, 36, 12};
    }
    polygonR({{x + -5, y}, {x + 70, y}, {x + 70, y + 15}, {x + -5, y + 15}}, light);
    polygonR({{x + 70, y}, {x + 145, y}, {x + 145, y + 15}, {x + 70, y + 15}}, shadow);

    polygonR({{x + -5, y + 15}, {x + 65, y + 15}, {x + 65, y + 30}, {x + -5, y + 30}}, light);
    polygonR({{x + 65, y + 15}, {x + 140, y + 15}, {x + 140, y + 30}, {x + 65, y + 30}}, shadow);

    polygonR({{x + -5, y + 30}, {x + 65, y + 30}, {x + 65, y + 45}, {x + -5, y + 45}}, light);
    polygonR({{x + 60, y + 30}, {x + 135, y + 30}, {x + 135, y + 45}, {x + 60, y + 45}}, shadow);

    polygonR({{x + -5, y + 45}, {x + 60, y + 45}, {x + 60, y + 60}, {x + -5, y + 60}}, light);
    polygonR({{x + 55, y + 45}, {x + 130, y + 45}, {x + 130, y + 60}, {x + 55, y + 60}}, shadow);

    polygonR({{x + -5, y + 60}, {x + 55, y + 60}, {x + 55, y + 75}, {x + -5, y + 75}}, light);
    polygonR({{x + 50, y + 60}, {x + 125, y + 60}, {x + 125, y + 75}, {x + 50, y + 75}}, shadow);

    polygonR({{x + 90, y + 15}, {x + 110, y + 15}, {x + 110, y + 90}, {x + 90, y + 90}}, pole);
    polygonR({{x + 85, y + 90}, {x + 110, y + 90}, {x + 100, y + 105}, {x + 75, y + 105}}, {40, 55, 76});
    polygonR({{x + 85, y + 15}, {x + 90, y + 15}, {x + 90, y + 95}, {x + 85, y + 95}}, light);
    polygonR({{x + 80, y + 30}, {x + 85, y + 30}, {x + 85, y + 105}, {x + 80, y + 105}}, light);
    polygonR({{x + 75, y + 45}, {x + 80, y + 45}, {x + 80, y + 110}, {x + 75, y + 110}}, light);

    polygonR({{x + 15, y + 75}, {x + 40, y + 75}, {x + 40, y + 125}, {x + 15, y + 125}}, light);
    polygonR({{x + 40, y + 75}, {x + 65, y + 75}, {x + 65, y + 110}, {x + 40, y + 110}}, shadow);

    polygonR({{x + 27, y + 120}, {x + 40, y + 120}, {x + 40, y + 125}, {x + 27, y + 125}}, black);
    polygonR({{x + 35, y + 125}, {x + 40, y + 125}, {x + 40, y + 135}, {x + 35, y + 135}}, black);
    if(nightR) polygonR({{x + 34, y + 135}, {x + 41, y + 135}, {x + 41, y + 140}, {x + 34, y + 140}}, red);

    polygonR({{x + 40, y + 90}, {x + 80, y + 90}, {x + 80, y + 110}, {x + 40, y + 110}}, light);
    polygonR({{x + 50, y + 105}, {x + 75, y + 105}, {x + 75, y + 110}, {x + 50, y + 110}}, black);
    polygonR({{x + 65, y + 80}, {x + 80, y + 80}, {x + 80, y + 90}, {x + 65, y + 90}}, light);
    polygonR({{x + 85, y + 95}, {x + 90, y + 95}, {x + 90, y + 100}, {x + 85, y + 100}}, black);

    polygonR({{x + 95, y + 95}, {x + 100, y + 95}, {x + 100, y + 120}, {x + 95, y + 120}}, black);
    if(nightR) polygonR({{x + 94, y + 120}, {x + 101, y + 120}, {x + 101, y + 125}, {x + 94, y + 125}}, red);
}

void setGLColorRWithAlpha(const ColorR& ColorR, int alpha) {
    glColor4ub(ColorR.r, ColorR.g, ColorR.b, alpha);
}

void Laser(float x, float y, ColorR shadow = {97, 252, 254}, int alpha = 100){

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    setGLColorRWithAlpha(shadow, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x + 0, y + 0);
    glVertex2f(x + 5, y + 0);
    glVertex2f(x + 5, y + 600);
    glVertex2f(x + 0, y + 600);
    glEnd();

    setGLColorRWithAlpha({48, 122, 255}, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x + 5, y + 0);
    glVertex2f(x + 45, y + 0);
    glVertex2f(x + 45, y + 600);
    glVertex2f(x + 5, y + 600);
    glEnd();

    setGLColorRWithAlpha(shadow, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x + 45, y + 0);
    glVertex2f(x + 50, y + 0);
    glVertex2f(x + 50, y + 600);
    glVertex2f(x + 45, y + 600);
    glEnd();

    glDisable(GL_BLEND);
    glPopMatrix();
}

void LaserObjects(float x, float y, ColorR body = {97, 252, 254}){
    polygonR({{x + 20, y + 10 + objectPositionYR}, {x + 25, y + 10 + objectPositionYR}, {x + 25, y + 15 + objectPositionYR}, {x + 20, y + 15 + objectPositionYR}}, body);
    polygonR({{x + 30, y + 20 - objectPositionYR}, {x + 35, y + 20 - objectPositionYR}, {x + 35, y + 25 - objectPositionYR}, {x + 30, y + 25 - objectPositionYR}}, body);
    polygonR({{x + 25, y + 40 + objectPositionYR}, {x + 30, y + 40 + objectPositionYR}, {x + 30, y + 45 + objectPositionYR}, {x + 25, y + 45 + objectPositionYR}}, body);
    polygonR({{x + 20, y + 50 - objectPositionYR}, {x + 25, y + 50 - objectPositionYR}, {x + 25, y + 55 - objectPositionYR}, {x + 20, y + 55 - objectPositionYR}}, body);
}

void updateLaserObjects(int value) {
    if(objectPositionXR < 2000){
        objectPositionXR += 20;
    }
    else{
        objectPositionXR = 0;
    }

    if(objectPositionYR < 10){
        objectPositionYR += 1;
    }
    else{
        objectPositionYR = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(50, updateLaserObjects, 0);
}

/// SignBoard Building Two
void SignBoard2(float x, float y, ColorR body = {211, 0, 253}, ColorR light = {111, 81, 143}){
    /// Poles
    polygonR({{x + 0, y + 0}, {x + 30, y + 0}, {x + 30, y + 5}, {x + 0, y + 5}}, {22, 28, 40});
    polygonR({{x + 0, y + 5}, {x + 30, y + 5}, {x + 30, y + 35}, {x + 0, y + 35}}, {53, 59, 107});
    polygonR({{x + 0, y + 35}, {x + 30, y + 35}, {x + 30, y + 40}, {x + 0, y + 40}}, {22, 28, 40});

    /// Body
    polygonR({{x - 10 , y - 10}, {x + 15, y - 10}, {x + 15, y + 50}, {x - 10, y + 50}}, body);
    polygonR({{x - 5 , y + 50}, {x + 10, y + 50}, {x + 10, y + 55}, {x - 5, y + 55}}, body);
    polygonR({{x - 5 , y - 15}, {x + 10, y - 15}, {x + 10, y - 10}, {x - 5, y - 10}}, body);

    /// Light
    polygonR({{x - 15 , y - 10}, {x - 10, y - 10}, {x - 10, y + 50}, {x - 15, y + 50}}, light);
    polygonR({{x + 15 , y - 10}, {x + 20, y - 10}, {x + 20, y + 50}, {x + 15, y + 50}}, light);
    polygonR({{x - 10 , y + 50}, {x - 5, y + 50}, {x - 5, y + 55}, {x - 10, y + 55}}, light);
    polygonR({{x + 10 , y + 50}, {x + 15, y + 50}, {x + 15, y + 55}, {x + 10, y + 55}}, light);
    polygonR({{x - 5 , y + 55}, {x + 10, y + 55}, {x + 10, y + 60}, {x - 5, y + 60}}, light);
    polygonR({{x - 5 , y - 20}, {x + 10, y - 20}, {x + 10, y - 15}, {x - 5, y - 15}}, light);
    polygonR({{x - 10 , y - 15}, {x - 5, y - 15}, {x - 5, y - 10}, {x - 10, y - 10}}, light);
    polygonR({{x + 10 , y - 15}, {x + 15, y - 15}, {x + 15, y - 10}, {x + 10, y - 10}}, light);

    /// Objects
    polygonR({{x - 5 , y + 0}, {x + 10, y + 0}, {x + 10, y + 5}, {x - 5, y + 5}}, light);
    polygonR({{x - 5 , y + 35}, {x + 10, y + 35}, {x + 10, y + 40}, {x - 5, y + 40}}, light);
    polygonR({{x - 5 , y + 15}, {x + 10, y + 15}, {x + 10, y + 20}, {x - 5, y + 20}}, light);
    polygonR({{x + 0 , y + 20}, {x + 10, y + 20}, {x + 10, y + 25}, {x + 0, y + 25}}, light);
}

/// SignBoard Building Thirteen
void SignBoard13(float x, float y, ColorR light = {110, 115, 153}){
    /// Poles
    polygonR({{x + 0, y + 0}, {x + 30, y + 0}, {x + 30, y + 5}, {x + 0, y + 5}}, {22, 28, 40});
    polygonR({{x + 0, y + 5}, {x + 30, y + 5}, {x + 30, y + 35}, {x + 0, y + 35}}, {53, 59, 107});
    polygonR({{x + 0, y + 35}, {x + 30, y + 35}, {x + 30, y + 40}, {x + 0, y + 40}}, {22, 28, 40});

    /// Body
    polygonR({{x - 10 , y - 10}, {x + 15, y - 10}, {x + 15, y + 50}, {x - 10, y + 50}}, {0, 252, 161});

    /// Light
    polygonR({{x - 15 , y - 5}, {x - 10, y - 5}, {x - 10, y + 50}, {x - 15, y + 50}}, light);
    polygonR({{x + 15 , y - 5}, {x + 20, y - 5}, {x + 20, y + 50}, {x + 15, y + 50}}, light);
    polygonR({{x - 10 , y + 50}, {x + 15, y + 50}, {x + 15, y + 55}, {x - 10, y + 55}}, light);
    polygonR({{x - 10 , y - 10}, {x + 15, y - 10}, {x + 15, y - 5}, {x - 10, y - 5}}, light);

    /// Lower Object
    polygonR({{x - 10 , y - 10}, {x + 15, y - 10}, {x + 15, y + 10}, {x + 10, y + 10}, {x + 10, y + 5}, {x - 10, y + 5}}, {46, 0, 251});
    polygonR({{x - 10 , y + 30}, {x + 15, y + 30}, {x + 15, y + 40}, {x + 10, y + 40}, {x + 10, y + 25}, {x - 10, y + 25}}, {114, 195, 204});
}

void RainR(float x, float y, ColorR shadow = {197, 255, 248}, int alpha = 50){

    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    setGLColorRWithAlpha(shadow, alpha);
    int numLines = 10; // Number of lines
    int xIncrement = 20; // Distance between lines along the x-axis
        int numpolygonRs = 10; // Number of polygonRs per line
    int yIncrement = 180; // Distance between polygonRs along the y-axis

    for (int line = 0; line < numLines; ++line) {
        for (int i = 0; i < numpolygonRs; ++i) {
            glBegin(GL_POLYGON);

            int startX = line * (numpolygonRs * xIncrement); // Adjust this for proper spacing
            int startY = i * yIncrement;

            glVertex2f(x + startX, y + startY);
            glVertex2f(x + 2 + startX, y + startY);
            glVertex2f(x + 2 + startX, y + 70 + startY);
            glVertex2f(x + startX, y + 70 + startY);

            glEnd();
        }
    }
    glDisable(GL_BLEND);
    glPopMatrix();
}

/// Timer Function for updating First Carrier Positions
void updaterainR(int value) {
    if(rainPositionR > - 80){
        rainPositionR -= 2;
    }
    else{
        rainPositionR = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1, updaterainR, 0);
}

void moverainR(){
    glPushMatrix();
    RainR(10, rainPositionR + 10);
    RainR(100, rainPositionR + 40);
    glPopMatrix();
}

/// Initializing all Clouds_R
void drawClouds_R(){
    cloud3();
    cloud2();
    cloud1();
}

/// Initializing Buildings
void Building(){
    /// Building One
    Building_One(0, 0);
    polygonR({{0, 250}, {0, 255}, {140,255}, {140, 250}}, {0, 0, 0});
    Building_One(0, 255);
    Building_One_Terrace(-5, 510);
    SignBoard(-5, 510);

    /// Building Two
    Building_Two(100, 0);
    NetworkTowerTwo(100, 220);

    /// Shadow Building One
    Shadow_Building_One(335, 85);

    /// Building Three
    Third_Building(200, 0);
    NetworkTowerThree(230, 505);

    /// Building Five
    Fifth_Building(420, 0);
    SignBoard_Two(420, 435);

    /// Building Six
    Building_Two(520, 0);
    NetworkTowerTwo(535, 220);

    /// Shadow Building Three
    Shadow_Building_Three(660, 0);

    /// Building Seven
    Building_One(700, 0);

    /// Shadow Building Four
    polygonR({{840, 0}, {840, 120}, {860, 120}, {860, 0}}, {19, 23, 69});
    polygonR({{860, 0}, {860, 180}, {900, 180}, {900, 0}}, {19, 23, 69});

    /// Building Eight
    Eight_Building(900, 0);
    Building_Two(930, 255);
    NetworkTowerTwo(935, 475);

    /// Shadow Building Five
    polygonR({{1080, 0}, {1080, 280}, {1200,280}, {1200, 0}}, {19, 23, 69});

    /// Building Ten
    glPushMatrix();
    glScalef(1.2,1.4,0.0);
    Building_Two(950, 0);
    Building_Tower(950, 220);
    glPopMatrix();

    /// Building Twelve
    Building_One(1380, 0);
    polygonR({{1420, 250}, {1500, 250}, {1500, 260}, {1420, 260}}, {19, 23, 69});
    polygonR({{1400, 260}, {1500, 260}, {1500, 290}, {1400, 290}}, {19, 23, 69});

    /// Building Eleven
    Building_Two(1280, 0);
    NetworkTowerTwo(1295, 220);

    /// Building Thirteen
    Building_One(1500, 0);
    polygonR({{1505, 250}, {1505, 255}, {1640,255}, {1640, 250}}, {0, 0, 0});
    Building_One_Terrace(1500, 510);
    Building_One(1500, 255);

    /// Shadow Building One
    Shadow_Building_One(1845, 85);

    /// Fourteenth Building
    Building_Two(1600, 0);
    NetworkTowerTwo(1615, 220);
    if(nightR) {
        if(laser){
            Laser(1775, 505);
            LaserObjects(1775, 515 + objectPositionXR);
        }
    }

    /// Building Fifteen
    Third_Building(1720, 0);
    NetworkTowerThree(1750, 505);

    /// Building Four
    Tomb(320, 0);

    /// Building Nine
    Tomb(1070, 0);

    /// Building Sixteen
    Tomb(1850, 0);
}

void DisplayRedwan()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1920, 0, 1080); // Example values for Mustakim's part
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

   /// Sky
    SkyR();

    /// Stars
    if(nightR){
        Star_Rs();
    }

    /// SunR for evening
    if(dayR){SunR(1000, 900);}

    /// Clouds_R
    drawClouds_R();
    // Building
    Building();

    /// plane_R and Carrier
    moveplane_R();
    moveCarrier();
    moveCarrierTwo();

    /// Signboards
    moveGhost();

    /// Buildings Window Light Toggle
    LightOnOff();

    /// Signboard for Building Two and Thirteen
    SignBoard2(185, 335);
    SignBoard13(1705, 315);

    /// Rain
    if(nightR){
        if(rainR) moverainR();
    }

    glFlush();
    glutSwapBuffers();
}

void updates(){
    glutTimerFunc(100, updateCloud_R, 0);
    glutTimerFunc(100, updateplane_R, 0);
    glutTimerFunc(100, updateCarrier, 0);
    glutTimerFunc(100, updateCarrierTwo, 0);
    glutTimerFunc(100, updateGhost, 0);
    glutTimerFunc(100, updateDonute, 0);
    glutTimerFunc(100, updateLights, 0);
    glutTimerFunc(100, updateLights2, 0);
    glutTimerFunc(100, updateLights3, 0);
    glutTimerFunc(50, updateLaserObjects, 0);
    glutTimerFunc(1, updaterainR, 0);
}

///Redwan's code start

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            std::cout << "Displaying Mustakim's part" << std::endl;
            // Set the display function to DisplayMustakim
            PlayMusic("E:/AIUB/7th Sem/CG/Project/Beautiful_Memory.WAV"); ///change the path according your file path
            glutDisplayFunc(DisplayMustakim);
            currentProjection=1;
            break;
        case '2':
            std::cout << "Displaying Deep's part" << std::endl;
            // Set the display function to DisplayDeep
            PlayMusic("E:/AIUB/7th Sem/CG/Project/Wistful_Heart.WAV"); ///change the path according your file path
            glutDisplayFunc(DisplayDeep);
            currentProjection=2;
            break;
        case '3':
            std::cout << "Displaying Masum's part" << std::endl;
            // Set the display function to DisplayMasum
            PlayMusic("E:/AIUB/7th Sem/CG/Project/BG_M.WAV"); ///change the path according your file path
            glutDisplayFunc(DisplayMasum);
            currentProjection=3;
            break;
        case '4':
            std::cout << "Displaying Masum's part" << std::endl;
            // Set the display function to DisplayRedwan
            PlayMusic("E:/AIUB/7th Sem/CG/Project/Quantam.WAV"); ///change the path according your file path
            glutDisplayFunc(DisplayRedwan);
            currentProjection=4;
            break;
        case 'r':
            // Start the rain animation
            if(currentProjection==1)
            {
                raindayS = true;
                Rain(_rainS);
            } else if(currentProjection==2) {
                raindayD = true;
                RainD(_rainD);
            } else if(currentProjection==3) {
                rain_M = true;
                Rain_M(move_rain_M);
                glutTimerFunc(2, Rain_M, 0);
            } else if(currentProjection==4) {
                rainR = true;
                rainSoundR = true;
            }
            break;

        case 'e': // Stop the rain animation
            if(currentProjection==1)
            {
                raindayS = false;
            } else if(currentProjection==2) {
                raindayD = false;
            } else if(currentProjection==3) {
                rain_M = false;
            }else if(currentProjection==4) {
                rainR = false;
                rainSoundR = false;
            }

            break;

        case 'w': // to forward the train
            if(currentProjection==1) {
                frd = true;
                bck = false;
                railForward(_ang_tri);
            } else if(currentProjection==2) {
                trainMovingForwardD = true;
                trainMovingBackwardD = false;
            } else if(currentProjection==3) {
                train_B = false;
                train_F = true;
                glutTimerFunc(10, TrainForwardMove, 0);
            }

            break;

        case 's': // to backward the train
            if(currentProjection==1) {
                frd = false;
                bck = true;
                railBackward(_ang_tri);
            } else if(currentProjection==2) {
                trainMovingBackwardD = true;
                trainMovingForwardD = false;
            } else if(currentProjection==3) {
                train_B = true;
                train_F = false;
                glutTimerFunc(10, TrainBackwardMove, 0);
            }

            break;

        case 'b': // to stop the train
            if(currentProjection==1) {
                frd = false;
                bck = false;
                railBackward(_ang_tri);
            } else if(currentProjection==2) {
                trainMovingForwardD = false;
                trainMovingBackwardD = false;
            } else if(currentProjection==3) {
                train_F = false;
                train_B = false;
            }

            break;
        case 'd': /// for day
            if(currentProjection==1) {
                nightS = false;
                glClearColor(0.0,0.5,0.8,1.0);
            } else if(currentProjection==2) {
                nightD = false;
                glutPostRedisplay();
            } else if(currentProjection==3) {
                night_M = false;
            } else if(currentProjection==4) {
                dayR = true;
                nightR = false;
            }
            break;

        case 'n': /// for night
             if(currentProjection==1) {
                nightS = true;
                NightS(_nt);
            } else if(currentProjection==2) {
                nightD = true;
                glutPostRedisplay();
            } else if(currentProjection==3) {
                night_M = true;
            } else if(currentProjection==4) {
                dayR = false;
                nightR = true;
            }
            break;

        case 'f':
            if(currentProjection==2){
                carMovingD = true; /// Start the car moving
            } else if (currentProjection==4){
                signBoard = true; /// for turning on signboard at nightR
            }
            break;
        case 'g':
            if(currentProjection==2){
                carMovingD = false; /// Stop the car moving
            } else if (currentProjection==4){
                signBoard = false; /// for turning on signboard at night
            }
            break;
        case 'l':
            if(currentProjection==2){
                moveForwardD = true; /// boat forward moving
                moveBackwardD = false;
            } else if (currentProjection==4){
                laser = true; /// for turning on laser at night
            }
            break;
        case 'k':
            if(currentProjection==2){
                moveBackwardD = true;
                moveForwardD = false; /// boat backward moving
            } else if (currentProjection==4){
                laser = false; /// for turning off laser at night
            break;
        case '+':
            if(currentProjection==2){
                umbrellaScale += 0.1f; /// Zoom in umbrella
            }

            break;
        case '-':
            if(currentProjection==2){
                umbrellaScale -= 0.1f; /// Zoom out umbrella
                if (umbrellaScale < 0.1f) umbrellaScale = 0.1f; // Clamp the scale to prevent it from becoming negative
            }

            break;

        case 'o':
            if(currentProjection==2){
               atmPositionX += 10.0f; /// Move right atm
            }

            break;
        case 'p':
            if(currentProjection==2){
                atmPositionX -= 10.0f; /// Move left atm
            }

            break;


        case 27: // ESC key
            exit(0);
    }

    // Request redisplay to update the display function
    glutPostRedisplay();
}
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;

    // Request redisplay to update the projection
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
    glutInitWindowSize(windowWidth, windowHeight);  // Set window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2); // Center window
    glutCreateWindow("Year Transition"); // Create window

    PlayMusic("E:/AIUB/7th Sem/CG/Project/Beautiful_Memory.WAV");
    glutDisplayFunc(DisplayMustakim);            // Register initial display callback function
    glutReshapeFunc(reshape);                       // Register reshape callback function
    glutKeyboardFunc(handleKeypress);               // Register keyboard callback function

    //Deep's main part
    glutTimerFunc(0, updatecarD, 0); // Start the timer for car animation
    glutTimerFunc(20, updategunboatD, 0);
    glutTimerFunc(0, updateSceneD, 0);
    glutTimerFunc(0, updateWaveD, 0); // Start the timer for wave animation
    glutTimerFunc(0, updateCloudD, 0);
    glutTimerFunc(0, updateStarD, 0);
    glutTimerFunc(0, updateBirdD, 0); // Start the timer for birdD animation
    glutTimerFunc(20, updateBalloonsD, 0); // Start the timer for balloon animation
    glutTimerFunc(0, updatetrainD, 0);

    //Mustakim's main part
    glutTimerFunc(100, update_sun,0);
    glutTimerFunc(100, update_moon,0);
	glutTimerFunc(25, update, 0);

    //Masum's main part
	glutTimerFunc(10, updateFrigate, 0);
	glutTimerFunc(5, updateFighterJet, 0);
	glutTimerFunc(15, updateCloud, 0);
	glutTimerFunc(5, updateSunMoon, 0);
	glutTimerFunc(10, updateRiver, 0);

    //Redwan's main part
    updates();
    glutFullScreen();
    glutMainLoop();                                 // Enter the event-processing loop
    return 0;
}
