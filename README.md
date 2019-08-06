# CppConsoleGameLibrary
Fast &amp; Easy to use C++ Library to make console games.

## Why should i use this library ?
Because it's open source, easy to use and to add to your project but especially ... because *ITS FAST*.

### Functionalities
- Fill a cell using X & Y coordinates and an Ascii Char with some Attributes.
- Fill the entire buffer.
- Draw the buffer into the console in one call !
- Check for key pressing state.
- Setting console title.
- Setting window & buffer size.
- Show or Hide cursor.
- Move cursor using X & Y positions.

### How to use it
1) Start donwloading the *'.hpp'* file.
2) Add it into your project simply including it at the beginning of your file.
```
#include "Base4ConsoleGames.hpp"
```
3) Create a class and inherit the *'Game'* Class.
```
class ExampleGame: public Game
{
  ...
}
```
4) In the main loop call the DrawBuffer Function.
```
{
  ...
  void mainLoop()
  {
    // Clear all with [FillBuffer]
    // Draw Something on the buffer [FillCell]
    // Game Logic
    DrawBuffer();
  }
}
```
