#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "Store.h"
#include "Client.h"

using namespace std;

class FileHandler 
{
    public:
        FileHandler();
        vector<Store> getStores(string filePath);
        vector<Client> getClients(string filePath, vector<Store> stores);
};

#endif