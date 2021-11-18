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
    vector<Store> stores;
    vector<Person> people;
    FileHandler* file = new FileHandler();
    stores = file->getStores(filePath);
    people = file->getPeople(filePath, stores);
    bool boolAdd = false;
    cout << endl;

    sort(people.begin(), people.end(), [](Person &a, Person &b){return ( a.getAge() > b.getAge() ) || (a.getAge() == b.getAge() && a.getId() < b.getId());});
  
    for(Person person:people){
        boolAdd = false;
        for(tuple<double,int> distance:person.getDistances()){
            if(stores[get<1>(distance)].getCapacity() > 0 && !boolAdd){
                stores[get<1>(distance)].SetPerson(person.getId());
                boolAdd=true;
            }
        }
        if(!boolAdd) break;
        
    }

    for(Store store: stores){
        store.PrintResult();
    }
    return 0;
}

