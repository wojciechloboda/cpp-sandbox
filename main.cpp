#include <iostream>
#include <memory>
#include "decorator.cpp"
#include "factory.cpp"

using namespace std;

int main(){
    shared_ptr<RectangleFactory> greenRectFactory = make_shared<GreenRectangleFactory>();
    shared_ptr<RectangleFactory> yellowRectFactory = make_shared<YellowRectangleFactory>();
    shared_ptr<Rectangle> rect = greenRectFactory->constructRectangle("Small");
}

