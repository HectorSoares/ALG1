#include "Store.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Store::Store(int id, int x, int y, int capacity) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->capacity = capacity;
    for(int i = 0; i < capacity; i++){
        this->allocatedPeople.push_back(-1);
    }
}

void Store::SetPerson(int id){
    if(this->capacity){
        //this->allocatedPeople.push_back(id);
        //this->capacity--;
        // if(this->allocatedPeople.size() == 0){
        //     this->allocatedPeople.push_back(id);
        //     this->capacity--;
        // } else {
            for (long unsigned int i = 0; i < this->allocatedPeople.size(); i++ ){
                if(this->allocatedPeople[i] == -1){
                    this->allocatedPeople[i] = id;
                    this->capacity--;
                    break;
                }
            }  
        // }
        
        
    }  

    
}

void Store::removePerson(int id){
    
    for (long unsigned int i = 0; i < this->allocatedPeople.size(); i++ ){
        if(this->allocatedPeople[i] == id){
            this->allocatedPeople[i] = -1;
        }
    }    
    this->capacity++; 
}

int Store::getX(){return this->x;}

int Store::getY(){return this->y;}

int Store::getId(){return this->id;}

int Store::getCapacity(){return this->capacity;}


void Store::Print(){
    cout << "Id: " << this->id << endl;
    cout << "Capacidade: " << this->capacity << endl;
    cout << "(x,y): " << '(' << this->x << ',' << this->y << ')' << endl;    
}

void Store::PrintResult(){
    if (this->allocatedPeople.size()) {
        cout << this->id << endl;
        for (int id : this->allocatedPeople) {
        cout << id << " ";
        }
        cout << endl;
  }  
}

