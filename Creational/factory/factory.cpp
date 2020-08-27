/*
 * Factory Pattern :
 *  
 *  This pattern helps the parent class to create the object of specific type
 *  but lets the concrete or child class to change the type of the object .
 *
 *
 * 
 *  It is basically a creational pattern that helps to create the  object,
 *  moving away the complexity from the creator of the object, it provides the
 *  abstraction for the client 
 *
 *
 * So basically you don't directly create the object, you just specify the
 * factory to create the object for you 
 *
 */

#include <iostream>
using namespace std;


class AbstractLogistics  
{
  
  public:
  virtual void deliver() = 0 ;

};

class Truck :public AbstractLogistics 
{
    public:

      void deliver() override 
      {
          cout << "We are starting to delivering via Truck" << endl;
      }
};

class Ship :public AbstractLogistics
{
  public:
  
    void deliver() override
    {
      cout << "We are delivering via ship" << endl;
    }

};

class AbstractDeliver 
{
  public:
    virtual AbstractLogistics* create() = 0;
};

class CreateTruck : public AbstractDeliver
{
  public :

    AbstractLogistics* create() override
    {
      return new Truck();
    }
      
};


class CreateShip: public AbstractDeliver
{
  public:
    AbstractLogistics* create() override
    {
      return new Ship();
    }
};

void client(AbstractDeliver *deliver) 
{
    AbstractLogistics *logistic = deliver->create();
    return;
}

int main() 
{
    AbstractDeliver *deliever = new CreateTruck();
    client(deliever);
    

    return  0 ;

}

