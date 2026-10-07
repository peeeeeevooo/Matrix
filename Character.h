#pragma once

enum class CharacterColor
{
    Green,
    Red,
    Blue,
    Cyan,
    Yellow,
    Magenta,
    White
};

class Character
{
public:
    Character(char symbol, CharacterColor color);

    char getSymbol() const;
    CharacterColor getColor() const;

private:
    char symbol;
    CharacterColor color;
};