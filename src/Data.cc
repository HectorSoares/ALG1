#include "Data.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Data::Data() {

}

void Data::set(string worldName, int distance) {
    this->worldName = worldName;
    this->distance = distance;
}

string Data::getWorld(){
    return this->worldName;
}

int Data::getDistance(){
    return this->distance;
}

void Data::Print(){
    cout << "test";
}
