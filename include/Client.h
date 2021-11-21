#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <tuple>
#include "Store.h"

using namespace std;

class Client 
{
    public:
        Client(int id, int x, int y, int age, float ticket, vector<Store> store);
        int getX();
        int getY();
        int getId();
        int getAge();
        int getStoreId();
        int getDistanceToTheStore(Store store);
        float getTicket();
        void setStore(int storeId);
        vector<tuple<int,int>> getDistances();
    private:
        int id, x, y, age, storeId, distanceToTheStore;
        float ticket;
        vector<tuple<int,int>> distances;
};

#endif