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

    sort(people.begin(), people.end(), [](Person &a, Person &b){return ( a.getTicket() > b.getTicket() ) || (a.getTicket() == b.getTicket() && a.getId() > b.getId());});
    for(Person person:people){
        boolAdd = false;
        // person.Print();
        // cout << endl;
        for(tuple<double,int> distance:person.getDistances()){
            if(stores[get<1>(distance)].getCapacity() > 0 && !boolAdd){
                printf("Pessoa %i alocada na loja %i \n",person.getId(), stores[get<1>(distance)].getId());
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

