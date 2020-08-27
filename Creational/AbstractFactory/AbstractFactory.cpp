/*
 The AbstractFactory let's  you create the objects of similar type 
    
    + The major advantage is open/closed principle : adding the new code without altering the older code
    + Seperation of concern is already there 
    - Code is much more complicated

    Example 
        The example below explains the usage of abstractFactory pattern
        Furniture can be Modern or Vinatge 
        and owner wants Furniture of same type either modern or vintage  both table chair 
 

*/

#include <iostream>
using namespace std;


class AbstractChair {

    public:

   virtual void feature() = 0;
};


class ModernChair : public AbstractChair 
{
    public :

    void feature() override {
        cout << "This is a feature of modern Chair" << endl;
    }
};
class VintageChair : public AbstractChair 
{
    public :

    void feature() override {
        cout << "This is a feature of vintage Chair" << endl;
    }
};




class AbstractTable {

    public:

   virtual void feature() = 0;
};


class VintageTable : public AbstractTable 
{
    public :

    void feature() override {
        cout << "This is a feature of Vintage Table" << endl;
    }
};


class ModernTable : public AbstractTable 
{
    public :

    void feature() override {
        cout << "This is a feature of modern Table" << endl;
    }
};


class AbstractFactory 
{
    public: 

    virtual AbstractChair* createChairInstance() = 0 ;
     virtual AbstractTable* createTableInstance() = 0 ;
};

class ModernFurniture :public AbstractFactory
{
    public: 

     AbstractChair* createChairInstance()
     {
            return new ModernChair();
     }
      AbstractTable* createTableInstance()
      {
            return new ModernTable();
      }
};

class VinatgeFurniture :public AbstractFactory
{
    public: 

     AbstractChair* createChairInstance()
     {
            return new VintageChair();
     }
      AbstractTable* createTableInstance()
      {
            return new VintageTable();
      }
};



void client(AbstractFactory *factory)
{
        AbstractChair *chair  = factory->createChairInstance();

        AbstractTable *table = factory->createTableInstance();

        chair->feature();
        
        delete chair;
        delete table;

        return ;
}




int main() {

    AbstractFactory *factory = new ModernFurniture();

    client(factory);

    return 0;
}