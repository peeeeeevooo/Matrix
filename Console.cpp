#include "Console.h"

#include <windows.h>
#include <iostream>

void Console::setCursorPosition(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD position;

    position.X = static_cast<SHORT>(x);

    position.Y = static_cast<SHORT>(y);

    SetConsoleCursorPosition(consoleHandle,position);
}

void Console::setColor(CharacterColor color)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (color)
    {
    case CharacterColor::Green:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_GREEN);
        break;

    case CharacterColor::Red:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_RED);
        break;

    case CharacterColor::Blue:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_BLUE);
        break;

    case CharacterColor::Cyan:
 
        SetConsoleTextAttribute(consoleHandle,FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;

    case CharacterColor::Yellow:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_RED | FOREGROUND_GREEN);
        break;

    case CharacterColor::Magenta:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_RED | FOREGROUND_BLUE);
        break;

    case CharacterColor::White:

        SetConsoleTextAttribute(consoleHandle,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        break;
    }
}

void Console::writeCharacter(const Character& character)
{
    setColor(character.getColor());

    std::cout << character.getSymbol();

    std::cout.flush();
}

void Console::clearCharacter(int x, int y)
{
    setCursorPosition(x, y);

    std::cout << ' ';

    std::cout.flush();
}

int Console::getWidth()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

    return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

int Console::getHeight()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

    return consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
}

void Console::clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;
    COORD homeCoords = { 0, 0 };

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, homeCoords, &written);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, homeCoords, &written);
    SetConsoleCursorPosition(hConsole, homeCoords);
}