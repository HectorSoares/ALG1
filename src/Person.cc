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

int findDistance(int x, int y, int xDestiny, int yDestiny){
    int moves = 0;
    printf("(%i,%i) to (%i,%i)", x, y, xDestiny, yDestiny);
    while (x != xDestiny || y != yDestiny){
        if(x > xDestiny){
            x--;
        } else if (x < xDestiny){
            x++;
        }
        
        if(y > yDestiny){
            y--;
        } else if (y < yDestiny){
            y++;
        }

        moves++;
    }
    return moves;
}

// bool operator< (const Person &person_1,const Person &person_2)
// {
//   return person_1.age > person_2.age || (person_1.age == person_2.age && person_1.id<person_2.id);
// }

vector<tuple<int,int>> Person::getDistances(){return this->distances;}

vector<tuple<int,int>> Person::getDistanceByStores(vector<Store> stores){
    vector<tuple<int,int>> distances;
    int distance;
    cout << "Pessoa: " << this->getId() << "------" << endl;
    for(Store store: stores){
        distance = findDistance(this->x, this->y, store.getX(), store.getY());
        cout << "distance: " << distance << endl <<" lojaId: " << store.getId() << endl ;
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
