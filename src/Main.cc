#include "FileHandler.h"
#include "Data.h"
#include "Person.h"
#include <ctime>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {
    string filePath = argv[1];
    vector<Store> healthCenters;
    vector<Person> people;
    FileHandler* file = new FileHandler();
    healthCenters = file->getHealthCenters(filePath);
    people = file->getPeople(filePath, healthCenters);
    bool boolAdd = false;

    sort(people.begin(), people.end(), [](Person &a, Person &b){return ( a.getAge() > b.getAge() ) || (a.getAge() == b.getAge() && a.getId() < b.getId());});
  
    for(Person person:people){
        boolAdd = false;
        for(tuple<double,int> distance:person.getDistances()){
            if(healthCenters[get<1>(distance)].getCapacity() > 0 && !boolAdd){
                healthCenters[get<1>(distance)].SetPerson(person.getId());
                boolAdd=true;
            }
        }
        if(!boolAdd) break;
        
    }

    for(Store healthCenter: healthCenters){
        healthCenter.PrintResult();
    }
    return 0;
}

