// https://en.wikipedia.org/wiki/ANSI_escape_code

#include <ansi.hpp>

namespace ansi
 {
  namespace face
   {
    const char * italic="\e[3m";
    const char * no_italic="\e[23m";

    const char * blink="\e[5m"; // may or may not be supported
    const char * fast_blink="\e[6m"; // may or may not be supported
    const char * no_blink="\e[25m";

    const char * crossed="\e[9m";
    const char * no_crossed="\e[29m";

    const char * underlined="\e[4m";
    const char * no_underlined="\e[24m";
   } // namespace face

  namespace color
   {
    const char * reset="\e[0m";

    namespace foreground
     {
      const char * reset="\e[39m";

      const char * bright="\e[1m"; // "bold" in ITU-T T.416 (1993 E)
      const char * faint="\e[2m";
      const char * normal="\e[22m";

      const char * black="\e[30m";
      const char * red="\e[31m";
      const char * green="\e[32m";
      const char * yellow="\e[33m";
      const char * blue="\e[34m";
      const char * magenta="\e[35m";
      const char * cyan="\e[36m";
      const char * white="\e[37m"; // normal may appear gray

    } // namespace foreground

    namespace background
     {
      const char * reset="\e[49m";

      // bright faint normal not supported for background?

      const char * black="\e[40m";
      const char * red="\e[41m";
      const char * green="\e[42m";
      const char * yellow="\e[43m";
      const char * blue="\e[44m";
      const char * magenta="\e[45m";
      const char * cyan="\e[46m";
      const char * white="\e[47m"; // normal may appear gray

     } // namespace background
    
   } // namespace color
  
  namespace cursor
   {
    const char * save="\e[s"; // NOT a stack! SHAME!
    const char * restore="\e[u";
    //const char * tell="\e[6n"; // good luck with that

    const char * up="\e[A";
    const char * down="\e[B";
    const char * right="\e[C";
    const char * left="\e[D";

   } // namespace cursor

  namespace screen
   {
    const char * clear="\e[2J";
   } // namespace screen

 } // namespace ansi

