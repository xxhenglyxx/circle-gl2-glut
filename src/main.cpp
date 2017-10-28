
#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>

#define PI 3.14

#include <display/Display.h>

void drawCircle ( ) {

    int index = 0;
    
    glClear( GL_COLOR_BUFFER_BIT );
    
    glColor3d ( 1.0, .8, .6 );
    
    glBegin ( GL_TRIANGLE_FAN );

        for ( index = 0; index < 360; index++ ) {
        
            glVertex2f( .4 * cos ( ( float ) index ), .4 * sin ( ( float ) index ) );

        }

        glColor3d ( .0, .3, .6 );

    glEnd();
    
    glFlush ();

}


int main ( int argc, char ** argv ) {

    Display mainDisplay ( argc, argv, "Circle GL2", GLUT_SINGLE, 680, 680, 100, 100 );

    glutDisplayFunc ( drawCircle );

    mainDisplay.loop ();

    return 0;

}