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

void Store::setClient(int id){
    if(this->capacity){        
        for (long unsigned int i = 0; i < this->allocatedPeople.size(); i++ ){
            if(this->allocatedPeople[i] == -1){
                long unsigned int j = i;
                for(; j < this->allocatedPeople.size()-1;  j++ ){
                    this->allocatedPeople[j] = this->allocatedPeople[j+1];
                }
                this->allocatedPeople[this->allocatedPeople.size()-1] = id;
                this->capacity--;
                break;
            }
        }    
    }   
}

void Store::removeClient(int id){
    
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

void Store::printResult(){
    if (this->allocatedPeople.size()) {
        cout << this->id << endl;
        for (long unsigned int i = 0; i < this->allocatedPeople.size(); i++) {
            cout << this->allocatedPeople[i];
            if(i != this->allocatedPeople.size()-1){
                cout  << " ";
            }
        }
        cout << endl;
    }  
}

