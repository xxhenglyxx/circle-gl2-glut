
#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>

#define PI 3.14

#include <display/Display.h>

void drawCircle ( ) {

    int index = 0;
    
    glBegin ( GL_TRIANGLE_FAN );

        glColor3d ( 1.0, .0, .0 );

        for ( index = 0; index < 360; index++ ) {
        
            glVertex2f( .68 * cos ( ( float ) index ), .68 * sin ( ( float ) index ) );

        }

    glEnd();

    glFlush ();

}

void drawTriangle () {

    glColor3d ( .0, .0, 1.0 );

    glBegin ( GL_TRIANGLES );

        glVertex2f ( 0, 0 );
        glVertex2f ( -.8, 1 );
        glVertex2f ( .8, 1 );

    glEnd ();

    glFlush ();

}

void render() {

    glClearColor( .0f, .0f, .0f, .5f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, 4.0, 0.0, 4.0, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // Draw shape one
    glPushMatrix();
        glTranslatef( 1.6, 1.8, .0 );
        drawCircle ();
    glPopMatrix();

    // Draw shape two
    glPushMatrix();
        glTranslatef( 2.5, 2.5, .0 );
        drawTriangle ();
    glPopMatrix();

    glutSwapBuffers();

}

int main ( int argc, char ** argv ) {

    Display mainDisplay ( argc, argv, "Circle GL2", GLUT_SINGLE, 680, 680, 100, 100 );

    mainDisplay.render ( render );

    mainDisplay.loop ();

    return 0;

}