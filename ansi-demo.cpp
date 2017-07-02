#include <iostream>

#include <ansi.hpp>

int main()
 {
  std::cout
   << ansi::screen::clear
   << ansi::color::reset
   << ansi::color::foreground::black << "slkfskd" << std::endl
   << ansi::color::foreground::red << "slkfskd" << std::endl
   << ansi::color::foreground::green << "slkfskd" << std::endl
   << ansi::color::foreground::yellow << "slkfskd" << std::endl
   << ansi::color::foreground::blue << "slkfskd" << std::endl
   << ansi::color::foreground::magenta << "slkfskd" << std::endl
   << ansi::color::foreground::cyan << "slkfskd" << std::endl
   << ansi::color::foreground::white << "slkfskd" << std::endl
   << ansi::color::foreground::normal << " akakaak"
   << ansi::color::background::white
   << ansi::color::foreground::bright
   << ansi::color::foreground::red << " fsdfasdf"
   << std::endl;

  std::cout << ansi::color::reset << std::endl;

  std::cout
   << ansi::cursor::save
   << std::endl
   << "sd;lfsdlf" << std::endl
   << ansi::cursor::restore
   << "X"
   << std::endl;

  std::cout
   << ansi::cursor::save
   << ansi::cursor::gotoxy(3,3)
   << ansi::color::background::green << "askjdas"
   << ansi::color::background::reset
   << ansi::cursor::gotoxy(5,5)
   << ansi::color::background::blue << "bleh!"
   << "xxxx"
   << ansi::cursor::restore
   << "yyyy"
   << ansi::color::reset
   << std::endl;

  std::cout
   << ansi::face::italic << "italic" << std::endl
   << ansi::face::underlined << "italic underlined" << std::endl
   << ansi::face::no_italic << "underline only" << std::endl
   << ansi::face::blink << "blink underline" << std::endl
   << ansi::face::no_underlined << "blink only" << std::endl
   << ansi::face::crossed << "blink crossed" << std::endl
   << ansi::face::no_blink << "crossed only" << std::endl
   << ansi::face::no_crossed << "normal?" << std::endl;

  std::cout << std::endl;

  for (int r=0;r<256;r+=32)
   {
    for (int g=0;g<256;g+=32)
     for (int b=0;b<256;b+=32)
      std::cout
       << ansi::color::foreground::rgb(r,g,b)
       << "\u25ae"; // small centered block
    std::cout << std::endl;
   }

  std::cout << ansi::color::reset;

  for (int r=0;r<256;r+=32)
   {
    for (int g=0;g<256;g+=32)
     for (int b=0;b<256;b+=32)
      std::cout << ansi::color::background::rgb(r,g,b) << ' ';
    std::cout << ansi::color::background::reset << std::endl;
   }

  return 0;
 }
