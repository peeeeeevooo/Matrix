#pragma once

#include <deque>
#include "Character.h"

class Line
{
public:
    Line(
        int length,
        int x,
        int y,
        char epilepsyMode,
        int consoleHeight
    );

    void move();

    int getX() const;
    int getY() const;

    const Character& getNewCharacter() const;

    int getNewCharacterX() const;
    int getNewCharacterY() const;

    bool hasRemovedCharacter() const;

    int getRemovedCharacterX() const;
    int getRemovedCharacterY() const;

private:
    Character createCharacter() const;

    int getCharacterY(int x) const;

    int length;
    int x;
    int y;

    char epilepsyMode;

    int consoleHeight;

    std::deque<Character> characters;

    bool characterRemoved;

    int removedCharacterX;
    int removedCharacterY;
};