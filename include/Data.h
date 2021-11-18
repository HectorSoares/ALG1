#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data 
{
    public:
        Data();
        void Print();
        void set(string worldName, int distance);
        string getWorld(); 
        int getDistance();       

    private:
        int distance;
        string worldName;
};

#endif