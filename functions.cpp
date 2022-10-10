#include "functions.h"

std::basic_ifstream<char> openFile(const std::string& fileName) {
    std::ifstream fileIn(fileName, std::ifstream::in);

    if (!fileIn.is_open()) {
        throw ErrorFileNotOpen();
    }
    return fileIn;
}

void inputFromFile(const char* file,std::vector<Polygon> &data) {
    std::basic_ifstream<char> fileIn = openFile(file);
    while (!fileIn.eof()) {
        Polygon buffer;
        fileIn >> buffer;

        if (fileIn.fail()) {
            fileIn.ignore('\n');
            fileIn.clear();
        }
        else {
            data.emplace_back(buffer);
        }
    }
    fileIn.close();
}

double areaEvenOdd(std::vector<Polygon> &data, const size_t flag){
    auto functor = [flag](double sum, Polygon &data){
        if(data.points.size() % 2 == flag){
            sum += data.getArea();
        }
        return sum;
    };

    std::cout << std::endl << "Area:" << std::endl;

    return std::accumulate(data.begin(), data.end(), 0.0, functor);
}

double areaMean(std::vector<Polygon> &data){
    auto functor = [](double sum, Polygon &data){
        sum += data.getArea();
        return sum;
    };

    std::cout << std::endl << "Area mean:" << std::endl;

    if(data.empty()){
        return 0.0;
    }

    return std::accumulate(data.begin(), data.end(), 0.0, functor) / double(data.size());

}

double areaNumOfVertexes(std::vector<Polygon> &data, const size_t num){
    auto functor = [num](double sum, Polygon &data){
        if(data.points.size() == num) {
            sum += data.getArea();
        }
        return sum;
    };
    std::cout << std::endl << "Area " << num << std::endl;

    if(data.empty()){
        return 0.0;
    }

    return std::accumulate(data.begin(), data.end(), 0.0, functor);

}

double findMinAreaOrVertexes(std::vector<Polygon> &data, const size_t flag){

    if(data.empty()){
        throw ErrorEmpty();
    }

    switch(flag) {
        case 0:
            std::sort(data.begin(), data.end(), [](const Polygon &data1, const Polygon &data2) {
                return data1.getArea() <= data2.getArea();
            });

            std::cout << std::endl << "Min area " << std::endl;

            return data[0].getArea();

        case 1:
            std::sort(data.begin(), data.end(), [](const Polygon &data1, const Polygon &data2) {
                return data1.points.size() < data2.points.size();
            });

            std::cout << std::endl << "Min vertexes " << std::endl;

            return data[0].points.size();

        default :
            throw WrongIntegerInput();
    }

}

double findMaxAreaOrVertexes(std::vector<Polygon> &data, const size_t flag){

    if(data.empty()){
        throw ErrorEmpty();
    }

    switch(flag) {
        case 0:
            std::sort(data.begin(), data.end(), [](const Polygon &data1, const Polygon &data2) {
                return data1.getArea() > data2.getArea();
            });

            std::cout << std::endl << "Max area " << std::endl;

            return data[0].getArea();

        case 1:
            std::sort(data.begin(), data.end(), [](const Polygon &data1, const Polygon &data2) {
                return data1.points.size() > data2.points.size();
            });

            std::cout << std::endl << "Max vertexes " << std::endl;

            return data[0].points.size();

        default :
            throw WrongIntegerInput();
    }
}

size_t countEvenOddNumOfVertexes(std::vector<Polygon> &data, const size_t flag, const size_t num){

    auto functor = [flag](size_t sum, Polygon &data){
        if(data.points.size()% 2 == flag) {
            sum++;
        }
        return sum;
    };

    switch(flag) {
        case 0:
            std::cout << std::endl << "Count even" << std::endl;
            return std::accumulate(data.begin(), data.end(), 0, functor);

        case 1:
            std::cout << std::endl << "Count odd" << std::endl;
            return std::accumulate(data.begin(), data.end(), 0, functor);

        case 2:
            std::cout << std::endl << "Count " << num << std::endl;
            return std::accumulate(data.begin(), data.end(), 0, [num](size_t sum, Polygon &data){
                if(data.points.size() == num) {
                    sum++;
                }
                return sum;
            });

        default :
            throw WrongIntegerInput();
    }
}


size_t doRect(std::vector<Polygon> &data){
    auto functor = [](size_t sum, Polygon &data) {
        if (data.findRects()) {
            sum++;
        }
        return sum;
    };

    std::cout << std::endl << "Rects" << std::endl;

    return std::accumulate(data.begin(), data.end(), 0, functor);
}

size_t doRightShapes(std::vector<Polygon> &data){
    auto functor = [](size_t sum, Polygon &data) {
        if (data.findRightShapes()) {
            sum++;
        }
        return sum;
    };

    std::cout << std::endl << "Rightshapes" << std::endl;

    return std::accumulate(data.begin(), data.end(), 0, functor);
}