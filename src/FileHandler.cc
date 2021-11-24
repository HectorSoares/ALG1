#include "FileHandler.h"
#include "Client.h"
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

FileHandler::FileHandler() {}

string ReturnNextWord(string &line){
    int pos;
    string result, delimiter = " ";
    pos = line.find(delimiter);
    result = line.substr(0, pos);
    line = (line.substr(pos+1, line.length()-1));
    return result;
}

static const map<string, float> scoreState {
        { "MG",  0.0 },
        { "PR",  10.0 },
        { "SP",  20.0 },
        { "SC",  30.0 },
        { "RJ",  40.0 },
        { "RN",  50.0 },
        { "RS",  60.0 }
    };

static const map<string, float> scorePayment {
        { "DINHEIRO",  1.0 },
        { "DEBITO",  2.0 },
        { "CREDITO",  3.0 }
    };

vector<Store> FileHandler::getStores() {
    string line, age, state, distance;
    int  storeCount, x, y;
    int  storeCapacity, storeX, storeY ;
    vector<Store> stores;   

    scanf("%i %i",  &x,  &y); 
    scanf("%i", &storeCount); 

    for(int i=0; i < storeCount; i++){     
        scanf("%i %i %i", &storeCapacity, &storeX, &storeY);  
        stores.push_back(Store(i, storeX, storeY, storeCapacity));
    } 
    return stores;
}

vector<Client> FileHandler::getClients( vector<Store> stores) {
    string line, state, payment, distance;
    int    clientCount;
    int  personAge, personX, personY ;
    float ticket;
    vector<Client> client;

    scanf("%d", &clientCount);
    for(int i=0; i < clientCount; i++){ 
        cin >> line;
        personAge = stoi(line);
        cin >> state;
        cin >> payment;
        cin >> line;
        personX = stoi(line);
        cin >> line;
        personY = stoi(line);

        ticket =  (abs(60-personAge)+scoreState.find(state)->second) / scorePayment.find(payment)->second;
        client.push_back(Client(i, personX, personY, personAge, ticket, stores));
    }     
    
    return client;
}