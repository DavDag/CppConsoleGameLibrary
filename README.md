# CppConsoleGameLibrary
Fast &amp; Easy to use C++ Library to make console games.

## Why should i use this library ?
Because it's open source, easy to use and to add to your project but especially ... because *ITS FAST*.

### Functionalities
- It manage Cursor, Window, buffer and keyboard.
- You can simply call two basic functions to get a fast cpp console game.
- Some ```#define``` to help you with colors and keys.

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

## Version
- 1.0 Uploaded on GitHub !
- 1.1 Added function to update only a region of the buffer.

