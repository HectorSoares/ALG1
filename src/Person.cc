#include "Person.h"
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

Person::Person(int id, int x, int y, int age, float ticket, vector<Store> stores) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->age = age;
    this->ticket = ticket;
    this->distances = getDistanceByStores(stores);
}

int Person::getX(){return this->x;}

int Person::getY(){return this->y;}

int Person::getId(){return this->id;}

int Person::getAge(){return this->age;}

float Person::getTicket(){return this->ticket;}

// bool operator< (const Person &person_1,const Person &person_2)
// {
//   return person_1.age > person_2.age || (person_1.age == person_2.age && person_1.id<person_2.id);
// }

vector<tuple<double,int>> Person::getDistances(){return this->distances;}

vector<tuple<double,int>> Person::getDistanceByStores(vector<Store> stores){
    vector<tuple<double,int>> distances;
    double distance;
    for(Store store: stores){
        distance = sqrt(
        (pow(this->x-store.getX(),2))
        +
        (pow(this->y-store.getY(),2))
        );
        distances.push_back({distance , store.getId()});
    } 
    sort(distances.begin(),distances.end());
    return distances;
}

void Person::Print(){
    cout << "Id: " << this->id << endl;
    cout << "Age: " << this->age << endl;
    cout << "(x,y): " << '(' << this->x << ',' << this->y << ')' << endl;
    cout << "Ticket: " << this->ticket << endl;
}
