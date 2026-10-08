#pragma once

#include <memory>

#include "Line.h"

class ApplicationManager
{
public:
    ApplicationManager(int speed,int length,char epilepsyMode);

    void run();

private:
    void createLine();

    void renderNewCharacter();

    void clearRemovedCharacter();

    bool isLineFinished() const;

    int speed;

    int length;

    char epilepsyMode;

    std::unique_ptr<Line> line;
};