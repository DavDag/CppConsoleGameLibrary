#pragma once
#ifndef BASE4CONSOLEGAMES_HPP
#define BASE4CONSOLEGAMES_HPP

#include <stdio.h>
#include <algorithm>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 ** Default SCREEN_WIDTH is 80.
 ** Default SCREEN_HEIGHT is 25.
 **/
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 80
#endif // SCREEN_WIDTH

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 25
#endif // SCREEN_HEIGHT

#define F_BLACK			0x00
#define	F_BLUE			0x01
#define	F_GREEN 		0x02
#define F_AQUA			0x03
#define	F_RED			0x04
#define F_PURPLE		0x05
#define F_YELLOW		0x06
#define F_WHITE			0x07
#define	F_GREY			0x08
#define	F_LIGHTBLUE		0x09
#define	F_LIGHTGREEN	0x0A
#define	F_LIGHTAQUA		0x0B
#define	F_LIGHTRED		0x0C
#define	F_LIGHTPURPLE	0x0D
#define	F_LIGHTYELLOW	0x0E
#define	F_BRIGTHWHITE	0x0F

#define B_BLACK			0x00
#define	B_BLUE			0x10
#define	B_GREEN 		0x20
#define B_AQUA			0x30
#define	B_RED			0x40
#define B_PURPLE		0x50
#define B_YELLOW		0x60
#define B_WHITE			0x70
#define	B_GREY			0x80
#define	B_LIGHTBLUE		0x90
#define	B_LIGHTGREEN	0xA0
#define	B_LIGHTAQUA		0xB0
#define	B_LIGHTRED		0xC0
#define	B_LIGHTPURPLE	0xD0
#define	B_LIGHTYELLOW	0xE0
#define	B_BRIGTHWHITE	0xF0

#define KEY_BACKSPACE	0x08
#define KEY_ENTER		0x0D
#define KEY_ARROW_LEFT	0x25
#define KEY_ARROW_UP	0x26
#define KEY_ARROW_RIGHT	0x27
#define KEY_ARROW_DOWN	0x28
#define KEY_0			0x30
#define KEY_1			0x31
#define KEY_2			0x32
#define KEY_3			0x33
#define KEY_4			0x34
#define KEY_5			0x35
#define KEY_6			0x36
#define KEY_7			0x37
#define KEY_8			0x38
#define KEY_9			0x39
#define KEY_A			0x41
#define KEY_B			0x42
#define KEY_C			0x43
#define KEY_D			0x44
#define KEY_E			0x45
#define KEY_F			0x46
#define KEY_G			0x47
#define KEY_H			0x48
#define KEY_I			0x49
#define KEY_J			0x4A
#define KEY_K			0x4B
#define KEY_L			0x4C
#define KEY_M			0x4D
#define KEY_N			0x4E
#define KEY_O			0x4F
#define KEY_P			0x50
#define KEY_Q			0x51
#define KEY_R			0x52
#define KEY_S			0x53
#define KEY_T			0x54
#define KEY_U			0x55
#define KEY_V			0x56
#define KEY_W			0x57
#define KEY_X			0x58
#define KEY_Y			0x59
#define KEY_Z			0x5A
#define KEY_NUMPAD0		0x60
#define KEY_NUMPAD1		0x61
#define KEY_NUMPAD2		0x62
#define KEY_NUMPAD3		0x63
#define KEY_NUMPAD4		0x64
#define KEY_NUMPAD5		0x65
#define KEY_NUMPAD6		0x66
#define KEY_NUMPAD7		0x67
#define KEY_NUMPAD8		0x68
#define KEY_NUMPAD9		0x69

class Game
{
	protected:
		/**
		 ** 	Game constructor.
		 **		
		 ** 	Names are self-explanatory.
		 ** 	It's important to setup correctly the buffer,
		 ** 	initializing it with something.
		 **/
		Game()
		{
			consoleOutput	= (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
			bufferSize		= {SCREEN_WIDTH,SCREEN_HEIGHT};
			bufferCoord		= {0, 0};
			region			= {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};
			
			ReadConsoleOutputA(consoleOutput, (CHAR_INFO *) buffer, bufferSize, bufferCoord, &region);
		}

		/**
		 **	FillCell(SHORT x, SHORT y, CHAR c, WORD attr):
		 **	
		 **		Fill the selected cell (buffer[y][x]) with
		 ** 	an ASCII CHAR c and some ATTRIBUTES attr.
		 **/
		void FillCell(SHORT x, SHORT y, CHAR c, WORD attr)
		{
			buffer[y][x].Attributes		= attr;
			buffer[y][x].Char.AsciiChar	= c;
		}

		/**
		 **	DrawBuffer():
		 **	
		 **		Draw the buffer into the screen.
		 **	
		 ** 	Call it after have drawned something.
		 **/
		void DrawBuffer()
		{
			WriteConsoleOutputA(consoleOutput, (CHAR_INFO*) buffer, bufferSize, bufferCoord, &region);
		}

		/**
		 ** DrawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows):
		 **
		 **		Draw a region of the buffer into the screen.
		 **		The region is defined by the topleft corner
		 **		[x, y] coordinates and the number of rows
		 **		and columns.
		 **
		 ** 	Call it after have drawned something.
		 **/
		void DrawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows)
		{
			SMALL_RECT region = {x, y, x + columns - 1, y + rows - 1};
			WriteConsoleOutputA(consoleOutput, (CHAR_INFO*)buffer, bufferSize, {x, y}, &region);
		}
		
		/**
		 **	FillBuffer(CHAR c, WORD attr):
		 **	
		 **		Fill the entire buffer with an ASCII CHAR c
		 **		and some ATTRIBUTES attr.
		 **
		 **		ex. Use FillBuffer(' ', F_BLACK | B_BLACK)
		 **		to display black screen;
		 **/
		void FillBuffer(CHAR c, WORD attr)
		{
			CHAR_INFO ci;
			ci.Attributes		= attr;
			ci.Char.AsciiChar	= c;
			
			for(unsigned short y = 0; y < SCREEN_HEIGHT; ++y)
				for(unsigned short x = 0; x < SCREEN_WIDTH; ++x)
					buffer[y][x] = ci;
		}

		/**
		 ** isKeyDown(int key):
		 **
		 **		Check is key is down.
		 **/
		bool isKeyDown(int key)
		{
			return (GetAsyncKeyState(key) & 0x8000);
		}

		/**
		 ** SetTitle(const char* title):
		 **	
		 **		Set console title.
		 **/
		void SetTitle(const char* title)
		{
			SetConsoleTitle(title);
		}

		/**
		 **	SetWindowSize(SHORT width, SHORT height, bool adjustBuffer):
		 **	
		 **		Set window size and if adjustBuffer flag is
		 **		setted to true, the buffer is resized too.
		 ** 
		 **/
		void SetWindowSize(SHORT width, SHORT height, bool adjustBuffer)
		{
			SMALL_RECT rect = {0, 0, width, height};
			if (adjustBuffer) SetConsoleScreenBufferSize(consoleOutput, {width, height});
			SetConsoleWindowInfo(consoleOutput, TRUE, &rect);
		}
		
		/**
		 **	ShowConsoleCursor(BOOL visible):
		 **	
		 ** 	Set cursor visibility.
		 **/
		void ShowConsoleCursor(BOOL visible)
		{
			CONSOLE_CURSOR_INFO cursorInfo;
			GetConsoleCursorInfo(consoleOutput, &cursorInfo);
			cursorInfo.bVisible = visible;
			SetConsoleCursorInfo(consoleOutput, &cursorInfo);
		}
		
		/**
		 ** Gotoxy(SHORT x, SHORT y):
		 ** 
		 ** 	Set cursor position at [x, y].
		 **/
		void Gotoxy(SHORT x, SHORT y)
		{
			SetConsoleCursorPosition(consoleOutput, {x, y});
		}
		
	private:
		HANDLE consoleOutput;
		COORD bufferSize, bufferCoord;
		SMALL_RECT region;
		CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
};

#endif // BASE4CONSOLEGAMES_HPP
