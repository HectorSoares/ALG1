#include "FileHandler.h"
#include "Data.h"
#include "Person.h"
#include "HealthCenter.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

FileHandler::FileHandler() {

}

void FileHandler::Print() {
    printf("Test\n");
}

vector<Store> FileHandler::getHealthCenters(string filePath) {
    string line, delimiter = " ", world, distance;
    int  pos=0, healthCenterCount;
    int  healthCenterCapacity, healthCenterX, healthCenterY ;
    vector<Store> healthCenters;
    
    ifstream File(filePath);
    if (!File.eof() && File.fail()){
        cout << "error reading " << filePath << endl;
    } else {
        getline (File, line);
        healthCenterCount = stoi(line);       

        for(int i = 0; healthCenterCount > i; i++){
            getline (File, line);
            pos = line.find(delimiter);
            healthCenterCapacity = stoi(line.substr(0, pos));
            line = (line.substr(pos+1, line.length()-1));
            pos = line.find(delimiter);
            healthCenterX = stoi(line.substr(0, pos));
            line = (line.substr(pos+1, line.length()-1));
            pos = line.find(delimiter);
            healthCenterY = stoi(line.substr(0, pos));
            healthCenters.push_back(Store(i, healthCenterX, healthCenterY, healthCenterCapacity));
        }
    }
    File.close();
    return healthCenters;
}

vector<Person> FileHandler::getPeople(string filePath, vector<Store> healthCenters) {
    string line, delimiter = " ", world, distance;
    int  pos=0, healthCenterCount, peopleCount;
    int  personAge, personX, personY ;
    vector<Person> people;
    
    ifstream File(filePath);
    if (!File.eof() && File.fail()){
        cout << "error reading " << filePath << endl;
    } else {
        getline (File, line);
        healthCenterCount = stoi(line);       

        for(int i = 0; healthCenterCount > i; i++){
            getline (File, line);          
        }
        getline (File, line);
        peopleCount = stoi(line);

        for(int i = 0; peopleCount > i; i++){
            getline (File, line); 
            pos = line.find(delimiter);
            personAge = stoi(line.substr(0, pos));
            line = (line.substr(pos+1, line.length()-1));
            pos = line.find(delimiter);
            personX = stoi(line.substr(0, pos));
            line = (line.substr(pos+1, line.length()-1));
            pos = line.find(delimiter);
            personY = stoi(line.substr(0, pos));
            people.push_back(Person(i, personX, personY, personAge, healthCenters));
        }
    }
    File.close();
    return people;
}