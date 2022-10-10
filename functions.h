#ifndef TECPTOG3_FUNCTIONS_H
#define TECPTOG3_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

#include "Exeptions.h"
#include "base-struct.h"

std::basic_ifstream<char> openFile(const std::string& fileName);
void inputFromFile(const char* file,std::vector<Polygon> &data);
double areaEvenOdd(std::vector<Polygon> &data, const size_t flag);
double areaMean(std::vector<Polygon> &data);
double areaNumOfVertexes(std::vector<Polygon> &data, const size_t num);
double findMinAreaOrVertexes(std::vector<Polygon> &data, const size_t flag);
double findMaxAreaOrVertexes(std::vector<Polygon> &data, const size_t flag);
size_t countEvenOddNumOfVertexes(std::vector<Polygon> &data, const size_t flag, const size_t num);
size_t doRect(std::vector<Polygon> &data);
size_t doRightShapes(std::vector<Polygon> &data);
#endif //TECPTOG3_FUNCTIONS_H
