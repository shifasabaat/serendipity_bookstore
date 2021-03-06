#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Book.h"
#include <string>
#include <fstream>

const int SIZE = 1024;
using namespace std;

class Inventory
{
private:
    Book *inventory[SIZE];
    double retailmarkup;
    double salestax;
    int currentSize;
    string filepath;
    
public:
    Inventory(string, double, double);
    ~Inventory();
    void pullInventoryFromFile(string);

    int getCurrentSize() { return currentSize; }
    void addBook(Book input);
    void deleteBook(int index);
    int searchTitle(string);
    void sortByTitle();
    void sortByQuantity();
    void sortByCost();
    void sortByDate();
    friend ostream &operator<<(ostream &, const Inventory &);
    long long totalWholesale();
    
    long long totalRetail() { return totalWholesale() * retailmarkup; }
    Book *operator[] (int index) { return inventory[index]; }
    //To throw exceptions:
    class InvalidFile {};
    class EmptyInventory {};
    class FullInventory {};
};

#endif
