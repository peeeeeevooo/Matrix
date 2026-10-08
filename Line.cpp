#include "Line.h"

#include <cstdlib>

Line::Line(int length,int x,int y,char epilepsyMode,int consoleHeight): length(length),x(x),y(y),epilepsyMode(epilepsyMode),consoleHeight(consoleHeight),characterRemoved(false),removedCharacterX(0),removedCharacterY(0)
{
}

void Line::move()
{
    ++x;

    characterRemoved = false;

    characters.push_front(createCharacter());

    if (static_cast<int>(characters.size()) > length)
    {
        removedCharacterX = x - length;
        removedCharacterY = getCharacterY(removedCharacterX);

        characters.pop_back();

        characterRemoved = true;
    }
}

int Line::getX() const
{
    return x;
}

int Line::getY() const
{
    return y;
}

const Character& Line::getNewCharacter() const
{
    return characters.front();
}

int Line::getNewCharacterX() const
{
    return x;
}

int Line::getNewCharacterY() const
{
    return getCharacterY(x);
}

bool Line::hasRemovedCharacter() const
{
    return characterRemoved;
}

int Line::getRemovedCharacterX() const
{
    return removedCharacterX;
}

int Line::getRemovedCharacterY() const
{
    return removedCharacterY;
}

Character Line::createCharacter() const
{
    char symbol = static_cast<char>('A' + std::rand() % 26);

    CharacterColor color = CharacterColor::Green;

    if (epilepsyMode == 'Y' || epilepsyMode == 'y')
    {
        int colorIndex = std::rand() % 7;

        color = static_cast<CharacterColor>(colorIndex);
    }

    return Character(symbol, color);
}

int Line::getCharacterY(int x) const
{
    int offset = x % 2;

    int result = y + offset;

    if (result >= consoleHeight)
    {
        result = consoleHeight - 1;
    }

    if (result < 0)
    {
        result = 0;
    }

    return result;
}