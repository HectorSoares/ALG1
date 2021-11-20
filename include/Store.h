#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>

using namespace std;

class Store 
{
    public:
        Store(int id, int x, int y, int capacity);
        void Print();  
        void PrintResult();
        void SetPerson(int id);
        int getX();
        int getY();
        int getId();
        int getCapacity();
        void removePerson(int id);

    private:
        int id, x, y, capacity;
        vector<int> allocatedPeople;
};

#endif