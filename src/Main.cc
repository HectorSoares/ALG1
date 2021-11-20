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
    sort(people.begin(), people.end(), [](Person &a, Person &b){return ( a.getTicket() > b.getTicket() ) || (a.getTicket() == b.getTicket() && a.getId() > b.getId());});

    bool hasAvailableStore = false ;
    for (long unsigned int i = 0; i < stores.size(); i++){
        //inverter loja se pa
        //printf("Loja %i com capacidade %i", stores[i].getId(), stores[i].getCapacity());
        while(stores[i].getCapacity() > 0){
            bool boolAdd = false;
            for(long unsigned int j = 0; j < people.size(); j++){
                if(people[j].getStoreId() == -1 && stores[i].getCapacity() > 0){      
                    //printf("Loja %i vazia, então adiciona o cliente %i \n", stores[i].getId(), people[j].getId());                                     
                    people[j].setStore(stores[i].getId());
                    stores[i].SetPerson(people[j].getId());
                    boolAdd = true;                   
                } else {
                    //printf("Aluno %i preencida... \t", stores[i].getId());
                    //printf("Pessoa %i preencida com Loja %i... \n", people[j].getId(), people[j].getStoreId());
                    if(people[j].getDistanceToTheStore(stores[i]) < people[j].getDistanceToTheStore(stores[people[j].getStoreId()])) {
                        //printf("Mas a distancia da Loja %i eh menor que a loja %i para o aluno %i \n", stores[i].getId(), people[j].getStoreId(), people[j].getId());
                        stores[people[j].getStoreId()].removePerson(people[j].getId());                       
                        hasAvailableStore = true;
                        //printf("Removeu pessoa %i da Loja %i \n", people[j].getId(), stores[people[j].getStoreId()].getId());
                        people[j].setStore(stores[i].getId());
                        stores[i].SetPerson(people[j].getId());
                        //printf("Adicionou pessoa %i na Loja %i \n", people[j].getId(), stores[i].getId());
                        boolAdd = true;
                    }
                }
                // people[people[j].getId()].setStore(people[j].getStoreId());
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

