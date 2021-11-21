#include "FileHandler.h"
#include "Client.h"
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
    vector<Client> clients;
    FileHandler* file = new FileHandler();
    stores = file->getStores(filePath);
    clients = file->getClients(filePath, stores);
    sort(clients.begin(), clients.end(), [](Client &a, Client &b){return ( a.getTicket() > b.getTicket() ) || (a.getTicket() == b.getTicket() && a.getId() < b.getId());});
    bool hasAvailableStore = false;

    for (long unsigned int i = 0; i < stores.size(); i++){   
        while(stores[i].getCapacity() > 0){
            bool boolAdd = false;           
            for(long unsigned int j = 0; j < clients.size(); j++){
                if(clients[j].getStoreId() == -1 && stores[i].getCapacity() > 0){                      
                    clients[j].setStore(stores[i].getId());
                    stores[i].setClient(clients[j].getId());
                    boolAdd = true;                   
                } else {                   
                    if(clients[j].getDistanceToTheStore(stores[i]) < clients[j].getDistanceToTheStore(stores[clients[j].getStoreId()]) || 
                        (clients[j].getDistanceToTheStore(stores[i]) == clients[j].getDistanceToTheStore(stores[clients[j].getStoreId()]) && stores[i].getId() < clients[j].getStoreId())) {                       
                        stores[clients[j].getStoreId()].removeClient(clients[j].getId());                       
                        hasAvailableStore = true;                       
                        clients[j].setStore(stores[i].getId());
                        stores[i].setClient(clients[j].getId());                       
                        boolAdd = true;
                    }
                }               
                if(stores[i].getCapacity() == 0) break;
                if(boolAdd) continue;
            }            
        }
        if(hasAvailableStore){ i = -1; hasAvailableStore=false; }        
    }
    for(long unsigned int i = 0; i < stores.size(); i++){
        stores[i].printResult();
    }
    return 0;
}