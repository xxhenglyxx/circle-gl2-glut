
#include "Display.h"

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <string>
#include <iostream>

Display::Display (

    int argc,
    char ** argv,
    const char * title,
    const unsigned int display_mode,
    const int WIDTH, const int HEIGHT,
    const int POSX, const int POSY

) {

    glutInit ( &argc, argv );

    glutInitDisplayMode ( display_mode ? display_mode : this -> display_mode );

    glutInitWindowSize ( WIDTH ? WIDTH : this -> WIDTH, HEIGHT ? HEIGHT : this -> HEIGHT );

    glutInitWindowPosition ( POSX ? POSX : this -> POSX, POSY ? POSY : this -> POSY );

    glutCreateWindow ( title ? title : "Baby GL" );

    this -> init ();

}

Display::~Display () {

    std::cout << "Destructing..." << std::endl;

}

void Display::init () {

    glClearColor( .0f, .0f, .0f, .5f );

    this -> setProjView ( -150, 150, -150, 150 );

}

void Display::loop () {

    glutMainLoop ();

}

void Display::render ( void ( * callback ) ( void ) ) {

    glutDisplayFunc ( callback );

}

void Display::setProjView (

    const float left,
    const float right,
    const float top,
    const float bottom

) {

    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluOrtho2D ( left, right, top, bottom );

}