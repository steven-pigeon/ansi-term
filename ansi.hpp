#ifndef __MODULE_ANSI_CONSOLE_CODES__
#define __MODULE_ANSI_CONSOLE_CODES__

#include <iostream>

// https://en.wikipedia.org/wiki/ANSI_escape_code

namespace ansi
 {
  namespace face
   {
    extern const char * italic;
    extern const char * no_italic;

    extern const char * blink; // may or may not be supported
    extern const char * fast_blink; // may or may not be supported
    extern const char * no_blink;

    extern const char * crossed;
    extern const char * no_crossed;

    extern const char * underlined;
    extern const char * no_underlined;
   } // namespace face

  namespace color
   {
    extern const char * reset;

    namespace foreground
     {
      extern const char * reset;

      extern const char * bright; // "bold" in ITU-T T.416 (1993 E)
      extern const char * faint;
      extern const char * normal;

      extern const char * black;
      extern const char * red;
      extern const char * green;
      extern const char * yellow;
      extern const char * blue;
      extern const char * magenta;
      extern const char * cyan;
      extern const char * white; // normal may appear gray

      // should be one type, but this allows
      // automatic selection of foreground or
      // background codes
      //
      struct _rgb { int r,g,b; };
      inline _rgb rgb(int r,int g,int b) { return {r,g,b}; }

      inline std::ostream & operator<<(std::ostream & out, _rgb r)
       {
        out << "\e[38;2;" << r.r << ";" << r.g << ";" << r.b << "m";
        return out;
       }

    } // namespace foreground

    namespace background
     {
      extern const char * reset;

      // bright faint normal not supported for background?

      extern const char * black;
      extern const char * red;
      extern const char * green;
      extern const char * yellow;
      extern const char * blue;
      extern const char * magenta;
      extern const char * cyan;
      extern const char * white; // normal may appear gray

      struct _rgb { int r,g,b; };
      inline _rgb rgb(int r,int g,int b) { return {r,g,b}; }
    
      inline std::ostream & operator<<(std::ostream & out, _rgb r)
       {
        out << "\e[48;2;" << r.r << ";" << r.g << ";" << r.b << "m";
        return out;
       }
     } // namespace background
   } // namespace color

  namespace cursor
   {
    extern const char * save; // NOT a stack! SHAME!
    extern const char * restore;
    //extern const char * tell; // good luck with that

    extern const char * up;
    extern const char * down;
    extern const char * right;
    extern const char * left;

    struct _gotoxy { int x,y; };
    inline _gotoxy gotoxy(int x, int y) { return {x,y}; }

    inline std::ostream & operator<<(std::ostream & out, _gotoxy g)
     {
      out << "\e[" << g.y << ";" << g.x << "H";
      return out;
     }
   } // namespace cursor

  namespace screen
   {
    extern const char * clear;
   } // namespace screen

} // namespace ansi


// ansi::color::foreground::X11::...
// ansi::color::background::X11::...
#include <x11-foreground.hpp>
#include <x11-background.hpp>

// other color sets would go here
// ansi::color::foreground::c64::...
// ansi::color::background::c64::...

#endif
  // __MODULE_ANSI_CONSOLE_CODES__
 
