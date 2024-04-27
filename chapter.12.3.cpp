
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

// The NOGDI below is needed to prevent Windows from including wingdi.h which has a duplicate
// declaration of 'Polygon' and throws ambiguous error.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define NOGDI
#endif

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "vec3.h"
//------------------------------------------------------------------------------

class Pixel {
    int positionx;
    int positiony;
    vec3 color;

    public:

    Pixel(int Positionx,int Positiony,vec3 Color) {
        positionx = Positionx;
        positiony = Positiony;
        color = Color;
    }

    int getpositionx() {return positionx;}
    int getpositiony() {return positiony;}
    vec3 getcolor() {return color;}

};

class ImageData {
    vector<vector<Pixel>> Image;
    int width;
    int height;

    public:

    ImageData(vector<vector<Pixel>> image,int Width,int Height) {
        Image = image;
        width = Width;
        height = Height;
    }

    vector<vector<Pixel>> getImage() {return Image;}
    int getwidth() {return width;}
    int getheight() {return height;}

    
};

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

    Polygon poly;                // make a shape (a polygon)

    poly.add(Point(300,200));    // add a point
    poly.add(Point(350,100));    // add another point
    poly.add(Point(400,200));    // add a third point 

    poly.set_color(Color::red);  // adjust properties of poly

    Text t(Point(150,50), "Hello World of HY150! ");
    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);

    win.attach(t);
    
    win.attach (poly);           // connect poly to the window

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
