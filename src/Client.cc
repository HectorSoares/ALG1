#include "Client.h"
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

Client::Client(int id, int x, int y, int age, float ticket, vector<Store> stores) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->age = age;
    this->ticket = ticket;
    this->storeId = -1;
    this->distanceToTheStore = -1;
}

int Client::getX(){return this->x;}

int Client::getY(){return this->y;}

int Client::getId(){return this->id;}

int Client::getAge(){return this->age;}

int Client::getStoreId(){return this->storeId;}

void Client::setStore(int storeId){this->storeId = storeId;}

float Client::getTicket(){return this->ticket;}

int findDistance(int x, int y, int xDestiny, int yDestiny){
    int moves = 0;
    while (abs(x - xDestiny) > 1 || abs(y - yDestiny) > 1){
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

int Client::getDistanceToTheStore(Store store){
    return findDistance(this->x, this->y, store.getX(), store.getY());
}

vector<tuple<int,int>> Client::getDistances(){return this->distances;}

