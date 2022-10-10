#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "Exeptions.h"
#include "base-struct.h"
#include "functions.h"

void makeChoice(std::vector<size_t> &choice){

    std::cout << "Select task:" << std::endl;
    std::cout << "1 - [AREA <EVEN|ODD>]" << std::endl;
    std::cout << "2 - [AREA <MEAN>]" << std::endl;
    std::cout << "3 - [AREA <num-of-vertexes>]" << std::endl;
    std::cout << "4 - [MAX <AREA|VERTEXES>]" << std::endl;
    std::cout << "5 - [MIN <AREA|VERTEXES>]" << std::endl;
    std::cout << "6 - [COUNT <EVEN|ODD|num-of-Vertexes>]" << std::endl;
    std::cout << "7 - RECTS" << std::endl;
    std::cout << "8 - RIGHTSHAPES" << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "Enter command: " << std::endl;
    std::cin >> choice[0];
    if (!std::cin) {
        throw ErrorWrongCommand();
    }

    if(choice[0] == 1){
        std::cout << "0 - Even" << std::endl;
        std::cout << "1 - Odd" << std::endl;

        std::cin >> choice[1];
        if (!std::cin) {
            throw ErrorWrongCommand();
        }
    }
    else if(choice[0] == 3){
        std::cout << "Enter number" << std::endl;

        std::cin >> choice[1];
        if (!std::cin) {
            throw ErrorWrongCommand();
        }
    }
    else if((choice[0] == 4 || (choice[0] == 5))){
        std::cout << "0 - AREA" << std::endl;
        std::cout << "1 - VERTEXES" << std::endl;

        std::cin >> choice[1];
        if (!std::cin) {
            throw ErrorWrongCommand();
        }
    }
    else if(choice[0] == 6){
        std::cout << "0 - Even" << std::endl;
        std::cout << "1 - Odd" << std::endl;
        std::cout << "2 - Num of vertexes" << std::endl;

        std::cin >> choice[1];
        if (!std::cin) {
            throw ErrorWrongCommand();
        }

        if(choice[1] == 2){
            std::cout << "Enter number" << std::endl;
        }

        std::cin >> choice[2];
        if (!std::cin) {
            throw ErrorWrongCommand();
        }
    }
}

int main( int argc, char *argv[] )
{
    try {
        std::vector<Polygon> data;
        std::vector<size_t> choice = { 0, 0, 0};
        inputFromFile(argv[1], data);
    while(1) {
        makeChoice(choice);
        switch (choice[0]) {
            case 1:
                std::cout << areaEvenOdd(data, choice[1]) << std::endl;
                break;
            case 2:
                std::cout << areaMean(data) << std::endl;
                break;
            case 3:
                std::cout << areaNumOfVertexes(data, choice[1]) << std::endl;
                break;
            case 4:
                std::cout << findMaxAreaOrVertexes(data, choice[1]) << std::endl;
                break;
            case 5:
                std::cout << findMinAreaOrVertexes(data, choice[1]) << std::endl;
                break;
            case 6:
                std::cout << countEvenOddNumOfVertexes(data, choice[1], choice[2]) << std::endl;
                break;
            case 7:
                std::cout << doRect(data) << std::endl;
                break;
            case 8:
                std::cout << doRightShapes(data) << std::endl;
                break;
        }
    }
    }
    catch (std::exception &exception) {
        std::cerr << std::endl << exception.what() << std::endl;
        return -1;
    }
    return 0;
}
