
#include <iostream>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>

#define PI 3.14

#include <display/Display.h>

void drawCircle ( const double radius, const double POSX, const double POSY ) {

    int index = 0;
    
    glBegin ( GL_TRIANGLE_FAN );

        glColor3d ( 1.0, .0, .0 );

        for ( index = 0; index < 360; index++ ) {
        
            glVertex2f( radius * cos ( ( float ) index ) + POSX , radius * sin ( ( float ) index ) + POSY );

        }

    glEnd();

}

void drawTriangle (

    const double c1x,
    const double c1y,
    const double c2x,
    const double c2y,
    const double c3x,
    const double c3y

) {

    glColor3d ( .0, .0, 1.0 );

    glBegin ( GL_TRIANGLES );

        glVertex2f ( c1x, c1y );
        glVertex2f ( c2x, c2y );
        glVertex2f ( c3x, c3y );

    glEnd ();

}

void render() {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    drawCircle ( 30, -20, 20 );

    drawTriangle ( 100, 50, 50, 100, 100, 100 );

    glFlush (); // render

}

int main ( int argc, char ** argv ) {

    Display mainDisplay ( argc, argv, "Circle GL2", GLUT_SINGLE, 680, 680, 100, 100 );

    mainDisplay.render ( render );

    mainDisplay.loop ();

    return 0;

}