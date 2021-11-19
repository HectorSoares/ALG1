#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <tuple>
#include "Store.h"

using namespace std;

class Person 
{
    public:
        Person(int id, int x, int y, int age, float ticket, vector<Store> store);
        void Print();  
        int getX();
        int getY();
        int getId();
        int getAge();
        float getTicket();
        vector<tuple<int,int>> getDistances();
        vector<tuple<int,int>> getDistanceByStores(vector<Store> store);
        friend bool operator< (const Person &p1,const Person &p2);

    private:
        int id, x, y, age;
        float ticket;
        vector<tuple<int,int>> distances;
};

#endif