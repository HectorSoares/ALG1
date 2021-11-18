#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "HealthCenter.h"
#include "Data.h"
#include "Person.h"

using namespace std;

class FileHandler 
{
    public:
        FileHandler();
        void Print();
        vector<Store> getHealthCenters(string filePath);
        vector<Person> getPeople(string filePath, vector<Store> healthCenters);
};

#endif