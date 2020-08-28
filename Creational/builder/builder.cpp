/* BuilderPattern :
 *        Lets you create the object step by step avoiding the telescopic
 *        constructors
 *
 *
 *
 * 
 *
 */

#include <iostream>
#include <vector>
using namespace std;


class Products
{   
    public:

      vector <std::string> list_parts; 
      
      void add_parts(string part) {
        list_parts.push_back(part);  
      }

};


class Builder 
{
  public:
    virtual void set() = 0 ; 

    virtual void reset() = 0 ;
    virtual void addPartA() = 0;
    virtual void addPartB() = 0;
    virtual void addPartC() = 0 ;
};


class ConcreteBuilder: public Builder 
{
  public:

    Products *product;
    
    void set() override 
    {
      this->product = new Products();
    }

    void reset() override
    {
      this->product = new Products();
    }


    void addPartA() 
    {
        this->product->add_parts("partA");
    }

    void addPartB() 
    {
        this->product->add_parts("partB");
    }


    void addPartC() 
    {
        this->product->add_parts("partC");
    }

};

class Director 
{

  public: 
    Builder *builder ; 

    void set(Builder *builder) 
    {
      this->builder = builder;
    }


    void buildMin() 
    {
      this->builder->addPartA();
    }
};



void client(Director *director)
{
  Builder *builder = new ConcreteBuilder() ;
  builder->set();
  director->set(builder);
  director->buildMin();
}
int main() 
{
    Director *dir =new Director() ;

    client(dir);
    return  0;
}
