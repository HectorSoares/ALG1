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
}

void Store::SetPerson(int id){
    if(this->capacity){
        this->allocatedPeople.push_back(id);
        this->capacity--;
    }    
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

