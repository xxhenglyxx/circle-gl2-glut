
#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLUT/glut.h>
#include <string>

class Display {

    public:

        Display (

            int argc,
            char ** argv,
            const char * title,
            const unsigned int display_mode,
            const int WIDTH, const int HEIGHT,
            const int POSX, const int POSY

        );

        ~Display ();

        void loop ();

        void loop (

            const float colors [ 4 ],
            const GLenum mode

        );

        void render ( void ( * callback ) ( void ) );

        void customInit ();

    private:

        int WIDTH = 800, HEIGHT = 600, POSX = 0, POSY = 0;
        unsigned int display_mode = GLUT_SINGLE;

        void setWidth ( const int WIDTH );
        void setHeight ( const int HEIGHT );
        void setPosX ( const int POSX );
        void setPosY ( const int POSY );
        void setProjView (

            const float left,
            const float right,
            const float top,
            const float bottom

        );

        void init ();

};

#endif