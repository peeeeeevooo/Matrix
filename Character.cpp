#include "Character.h"
#include <iostream>

Character::Character(char symbol, CharacterColor color)
    : symbol(symbol), color(color)
{
}

char Character::getSymbol() const
{
    return symbol;
}

CharacterColor Character::getColor() const
{
    return color;
}