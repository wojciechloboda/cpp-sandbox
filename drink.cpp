//Implementation of a decorator design pattern
//There is abstract class Drink and derrived classes Coffee, SugarDecorator, CreamDecorator
//Diffrent coffees can be composed with decorators as shown in main

#include<iostream>

using namespace std;

class Drink{
public:
    string opis = "Unknown";
    double koszt = 0.0f;

    virtual string getOpis(){
        cout << opis << endl;
    }

    virtual double getKoszt() = 0;
    virtual ~Drink() = default;
};

class Coffee : public Drink{
public:
    Coffee(){
        this->opis = "Kawa";
        this->koszt = 1.5;
    }

    double getKoszt() override{
        return this->koszt;
    }

    string getOpis() override{
        return this->opis;
    }
};

class CreamDecorator : public Drink{
public:
    Drink* drink;

    CreamDecorator(Drink* d){
        this->drink = d;
        this->koszt = 0.20;
        this->opis = "Mleko";
    }

    double getKoszt() override{
        return this->koszt + this->drink->getKoszt();
    }

    string getOpis() override{
        return this->drink->getOpis() + " " + this->opis;
    }

    ~CreamDecorator(){
        delete this->drink;
    }
};

class SugarDecorator : public Drink{
public:
    Drink* drink;
    SugarDecorator(Drink* d){
        this->opis = "Cukier";
        this->koszt = 0.7;
        this->drink = d;
    }
    ~SugarDecorator(){
        delete this->drink;
    }

    double getKoszt() override{
        return this->koszt + this->drink->getKoszt();
    }

    string getOpis() override{
        return this->drink->getOpis() + " " + this->opis;
    }
};


int main(){
    Drink* napoj = new Coffee();
    napoj = new CreamDecorator(napoj);
    napoj = new SugarDecorator(napoj);
    napoj = new SugarDecorator(napoj);

    cout << napoj->getOpis() << endl;
    cout << napoj->getKoszt() << endl;

    delete napoj;
}

