#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
/**
 * Source: https://refactoring.guru/design-patterns/builder/cpp/example#example-0
 * It makes sense to use the Builder pattern only when your products are quite
 * complex and require extensive configuration.
 *
 * Unlike in other creational patterns, different concrete builders can produce
 * unrelated products. In other words, results of various builders may not
 * always follow the same interface.
 */

class Product{
    public:

    Product() = default;

    std::vector<std::string> toppings;
    string base = "";
    string sauce = "";

    friend ostream& operator<<(ostream& os, const Product& p) {
        stringstream toppings_str;
        os << "Product parts: ";
        for (size_t i=0;i<p.toppings.size();i++){
            if(p.toppings[i]== p.toppings.back()){
                toppings_str << p.toppings[i];
            }else{
                toppings_str << p.toppings[i] << ", ";
            }
        }
        os << p.base << ", ";
        os << p.sauce << ", ";
        os << toppings_str.str();
        os << "\n\n";
        return os;
    }
};


/**
 * The Builder interface specifies methods for creating the different parts of
 * the Product objects.
 */
class Builder{
    public:
    virtual ~Builder(){}
    virtual void AddTopping(string topping) const =0;
    virtual void AddBase(string base) const =0;
    virtual void AddSauce(string sauce) const =0;
};
/**
 * The Concrete Builder classes follow the Builder interface and provide
 * specific implementations of the building steps. Your program may have several
 * variations of Builders, implemented differently.
 */
class ConcreteBuilder1 : public Builder{
    private:

    Product* product;

    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
    public:
    ConcreteBuilder1(){
        this->Reset(); //builder has an instance of Product ready
    }

    ~ConcreteBuilder1(){
        delete product;
    }

    void Reset(){
        this->product= new Product();
    }
    /**
     * All production steps work with the same product instance.
     */

    void AddTopping(string topping)const override{
        this->product->toppings.push_back(topping);
    }

    void AddBase(string base)const override{
        this->product->base = base;
    }

    void AddSauce(string sauce)const override{
        this->product->sauce = sauce;
    }

    /**
     * Concrete Builders are supposed to provide their own methods for
     * retrieving results. That's because various types of builders may create
     * entirely different products that don't follow the same interface.
     * Therefore, such methods cannot be declared in the base Builder interface
     * (at least in a statically typed programming language). Note that PHP is a
     * dynamically typed language and this method CAN be in the base interface.
     * However, we won't declare it there for the sake of clarity.
     *
     * Usually, after returning the end result to the client, a builder instance
     * is expected to be ready to start producing another product. That's why
     * it's a usual practice to call the reset method at the end of the
     * `getProduct` method body. However, this behavior is not mandatory, and
     * you can make your builders wait for an explicit reset call from the
     * client code before disposing of the previous result.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsible to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */

    Product* GetProduct() {
        Product* result= this->product;
        this->Reset(); //resets product pointer to be ready for next pizza to build
        return result;
    }
};

Product* makeProduct() {
    return new Product;
}

int main(){
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    // Remember, the Builder pattern can be used without a Director class.
    std::cout << "Custom product:\n";
    builder->AddBase("Sour dough Pizza");
    builder->AddTopping("Mushrooms");
    builder->AddSauce("Sour cream");

    Product* p = builder->GetProduct();
    cout << *p;

    delete p;
    delete builder;

    return 0;
}