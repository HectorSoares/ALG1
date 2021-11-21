#include "FileHandler.h"
#include "Person.h"
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

vector<Store> FileHandler::getStores(string filePath) {
    string line, age, state, distance;
    int  storeCount;
    int  storeCapacity, storeX, storeY ;
    vector<Store> stores;
    
    ifstream File(filePath);
    if (!File.eof() && File.fail()){
        cout << "error reading " << filePath << endl;
    } else {
        getline (File, line);
        getline (File, line);
        storeCount = stoi(line);  
        
        for(int i = 0; storeCount > i; i++){
            getline (File, line);
            storeCapacity = stoi(ReturnNextWord(line));
            storeX = stoi(ReturnNextWord(line));
            storeY = stoi(ReturnNextWord(line));
            stores.push_back(Store(i, storeX, storeY, storeCapacity));            
            cout << endl;            
        }
    }
    File.close();
    return stores;
}

vector<Person> FileHandler::getPeople(string filePath, vector<Store> stores) {
    string line, state, payment, distance;
    int   storeCount, peopleCount;
    int  personAge, personX, personY ;
    float ticket;
    vector<Person> people;
    
    ifstream File(filePath);
    if (!File.eof() && File.fail()){
        cout << "error reading " << filePath << endl;
    } else {
        getline (File, line);
        getline (File, line);
        storeCount = stoi(line);
        for(int i = 0; storeCount > i; i++){
            getline (File, line);          
        }
        getline (File, line);
        peopleCount = stoi(line);
        for(int i = 0; peopleCount > i; i++){
            getline (File, line); 
            personAge = stoi(ReturnNextWord(line));
            state = ReturnNextWord(line);
            payment = ReturnNextWord(line);
            personX = stoi(ReturnNextWord(line));
            personY = stoi(ReturnNextWord(line));  
            ticket =  (abs(60-personAge)+scoreState.find(state)->second) / scorePayment.find(payment)->second;   
            people.push_back(Person(i, personX, personY, personAge, ticket, stores));           
        }
    }
    File.close();
    return people;
}