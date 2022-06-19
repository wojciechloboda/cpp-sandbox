//Implementation of a decorator design pattern
//There is abstract class Drink and derrived classes Coffee, SugarDecorator, CreamDecorator
//Diffrent coffees can be composed with decorators as shown in main

#include<iostream>
#include<memory>

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
    std::shared_ptr<Drink> drink;

    CreamDecorator(std::shared_ptr<Drink> d){
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
};

class SugarDecorator : public Drink{
public:
    std::shared_ptr<Drink> drink;
    SugarDecorator(std::shared_ptr<Drink> d){
        this->opis = "Cukier";
        this->koszt = 0.7;
        this->drink = d;
    }
    double getKoszt() override{
        return this->koszt + this->drink->getKoszt();
    }

    string getOpis() override{
        return this->drink->getOpis() + " " + this->opis;
    }
};




