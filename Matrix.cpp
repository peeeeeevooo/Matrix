#include <iostream>
#include <sstream>
#include <string>

#include "ApplicationManager.h"

bool parseInteger(const std::string& input, int& value)
{
    std::stringstream stream(input);

    std::string extra;

    if (!(stream >> value)){
        return false;
    }

    if (stream >> extra){
        return false;
    }

    return true;
}

bool parseEpilepsyMode(const std::string& input,char& mode)
{
    if (input.length() != 1){
        return false;
    }

    char value = input[0];

    if (value == 'Y' || value == 'y' || value == 'N' || value == 'n'){
        mode = value;
        return true;
    }

    return false;
}

int main(int argc, char* argv[])
{
    int speed;
    int length;
    char epilepsyMode;

    if (argc == 2 && ( std::string(argv[1]) == "--help" || std::string(argv[1]) == "/?")){
        std::cout << "Matrix - Laboratory Work #1\n\n";

        std::cout << "Usage:\n";

        std::cout << "  Matrix.exe [speed] [length] [Y/N]\n\n";

        std::cout << "Parameters:\n";

        std::cout << "  speed  - 1..30 characters per second\n";

        std::cout << "  length - 1..30 characters\n";

        std::cout << "  Y/N    - epilepsy mode\n\n";

        std::cout << "Example:\n";

        std::cout << "  Matrix.exe 23 8 Y\n";

        return 0;
    }


    if (argc == 4){
        std::string speedInput = argv[1];

        std::string lengthInput = argv[2];

        std::string modeInput = argv[3];

        if (!parseInteger(speedInput,speed) || speed < 1 || speed > 30){
            std::cout<< "Error: speed must be "
            "from 1 to 30.\n";

            return 1;
        }


        if (!parseInteger(lengthInput, length) || length < 1 || length > 30){
            std::cout<< "Error: length must be "
            "from 1 to 30.\n";

            return 1;
        }

        if (!parseEpilepsyMode(modeInput, epilepsyMode)){
            std::cout<< "Error: epilepsy mode "
            "must be Y or N.\n";

            return 1;
        }
    }


    else if (argc == 1){
        std::string input;

        while (true)
        {
            std::cout<< "Enter line speed "
            "(1-30): ";

            std::getline(std::cin, input);

            if (parseInteger(input, speed) && speed >= 1 && speed <= 30){
                break;
            }

            std::cout<< "Invalid speed. "
            "Please enter a number "
            "from 1 to 30.\n";
        }

        while (true)
        {
            std::cout<< "Enter line length "
            "(1-30): ";

            std::getline(std::cin, input);

            if (parseInteger(input, length) && length >= 1 && length <= 30){
                break;
            }

            std::cout<< "Invalid length. "
            "Please enter a number "
            "from 1 to 30.\n";
        }


        while (true)
        {
            std::cout << "Epilepsy mode " 
            "(Y/N): ";

            std::getline(std::cin, input);

            if (parseEpilepsyMode(input, epilepsyMode)){
                break;
            }

            std::cout<< "Invalid mode. "
            "Please enter Y or N.\n";
        }
    }


    else{
        std::cout<< "Error: invalid number "
        "of parameters.\n\n";

        std::cout<< "Use:\n";

        std::cout<< "  Matrix.exe --help\n";

        std::cout<< "or\n";

        std::cout<< "  Matrix.exe /?\n";

        return 1;
    }


    ApplicationManager applicationManager(speed,length,epilepsyMode);

    applicationManager.run();

    return 0;
}