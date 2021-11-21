#include "FileHandler.h"
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
    sort(people.begin(), people.end(), [](Person &a, Person &b){return ( a.getTicket() > b.getTicket() ) || (a.getTicket() == b.getTicket() && a.getId() < b.getId());});
    bool hasAvailableStore = false;

    for (long unsigned int i = 0; i < stores.size(); i++){   
        while(stores[i].getCapacity() > 0){
            bool boolAdd = false;           
            for(long unsigned int j = 0; j < people.size(); j++){
                if(people[j].getStoreId() == -1 && stores[i].getCapacity() > 0){                      
                    people[j].setStore(stores[i].getId());
                    stores[i].SetPerson(people[j].getId());
                    boolAdd = true;                   
                } else {                   
                    if(people[j].getDistanceToTheStore(stores[i]) < people[j].getDistanceToTheStore(stores[people[j].getStoreId()]) || 
                        (people[j].getDistanceToTheStore(stores[i]) == people[j].getDistanceToTheStore(stores[people[j].getStoreId()]) && stores[i].getId() < people[j].getStoreId())) {                       
                        stores[people[j].getStoreId()].removePerson(people[j].getId());                       
                        hasAvailableStore = true;                       
                        people[j].setStore(stores[i].getId());
                        stores[i].SetPerson(people[j].getId());                       
                        boolAdd = true;
                    }
                }               
                if(stores[i].getCapacity() == 0) break;
                if(boolAdd) continue;
            }            
        }
        if(hasAvailableStore){ i = -1; hasAvailableStore=false; }        
    }
    for(long unsigned int i = 0; i < stores.size(); i++){
        stores[i].PrintResult();
    }
    return 0;
}