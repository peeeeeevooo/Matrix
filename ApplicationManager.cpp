#include "ApplicationManager.h"

#include "Console.h"

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

ApplicationManager::ApplicationManager(int speed,int length,char epilepsyMode): speed(speed),length(length),epilepsyMode(epilepsyMode),line(nullptr)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void ApplicationManager::run()
{
    Console::clearScreen();

    while (true)
    {
        createLine();

        while (!isLineFinished())
        {
            line->move();

            renderNewCharacter();

            clearRemovedCharacter();

            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / speed));
        }

        line.reset();
    }
}

void ApplicationManager::createLine()
{
    int consoleWidth =
        Console::getWidth();

    int consoleHeight =
        Console::getHeight();

    int x = -length;

    int y = 0;

    if (consoleHeight > 2)
    {
        y = std::rand() % (consoleHeight - 1);
    }

    line = std::make_unique<Line>(length,x,y,epilepsyMode,consoleHeight);
}

void ApplicationManager::renderNewCharacter()
{
    int x = line->getNewCharacterX();

    int y = line->getNewCharacterY();

    int width = Console::getWidth();

    int height = Console::getHeight();

    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        Console::setCursorPosition(x, y);

        Console::writeCharacter(line->getNewCharacter());
    }
}

void ApplicationManager::clearRemovedCharacter()
{
    if (!line->hasRemovedCharacter())
    {
        return;
    }

    int x = line->getRemovedCharacterX();

    int y = line->getRemovedCharacterY();

    int width = Console::getWidth();

    int height = Console::getHeight();

    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        Console::clearCharacter(x, y);
    }
}

bool ApplicationManager::isLineFinished() const
{
    return line->getX() - length >= Console::getWidth();
}