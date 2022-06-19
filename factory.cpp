//Implementation of factory method design pattern
#include<iostream>
#include<memory>

using namespace std;

class Rectangle{
public:
    string color;
    string text;
    string size;

    void operation(){
        cout << "Kolor: " << this->color << endl;
        cout << "Text: " << this->text << endl;
        cout << "Size: " << this->size << endl;
    }
};

class GreenBigRectangle : public Rectangle{
public:
    GreenBigRectangle(){
        this->color = "Green";
        this->text = "t";
        this->size = "Big";
    }
};

class GreenMediumRectangle : public Rectangle{
public:
    GreenMediumRectangle(){
        this->color = "Green";
        this->text = "t";
        this->size = "Medium";
    }
};

class GreenSmallRectangle : public Rectangle{
public:
    GreenSmallRectangle(){
        this->color = "Green";
        this->text = "t";
        this->size = "Small";
    }
};

class GreenNoneRectangle : public Rectangle{
public:
    GreenNoneRectangle(){
        this->color = "Green";
        this->text = "t";
        this->size = "None";
    }
};

class YellowBigRectangle : public Rectangle{
public:
    YellowBigRectangle(){
        this->color = "Yellow";
        this->text = "t";
        this->size = "Big";
    }
};

class YellowMediumRectangle : public Rectangle{
public:
    YellowMediumRectangle(){
        this->color = "Yellow";
        this->text = "t";
        this->size = "Medium";
    }
};

class YellowSmallRectangle : public Rectangle{
public:
    YellowSmallRectangle(){
        this->color = "Yellow";
        this->text = "t";
        this->size = "Small";
    }
};

class YellowNoneRectangle : public Rectangle{
public:
    YellowNoneRectangle(){
        this->color = "Yellow";
        this->text = "t";
        this->size = "None";
    }
};

class RectangleFactory{
public:
    shared_ptr<Rectangle> constructRectangle(string type){
        shared_ptr<Rectangle> rect = make_shared<Rectangle>();
        rect = this->createRectangle(type);
        rect->operation();
        return rect;
    }

    virtual shared_ptr<Rectangle> createRectangle(string type) = 0;
};

class GreenRectangleFactory : public RectangleFactory{
public:
    shared_ptr<Rectangle> createRectangle(string type) override{
        if(type == "Big")
            return make_shared<GreenBigRectangle>();
        else if(type == "Medium")
            return make_shared<GreenMediumRectangle>();
        else if(type == "Small")
            return make_shared<GreenSmallRectangle>();
        else
            return make_shared<GreenNoneRectangle>();
    }
};

class YellowRectangleFactory : public RectangleFactory{
public:
    shared_ptr<Rectangle> createRectangle(string type) override{
        if(type == "Big")
            return make_shared<YellowBigRectangle>();
        else if(type == "Medium")
            return make_shared<YellowMediumRectangle>();
        else if(type == "Small")
            return make_shared<YellowSmallRectangle>();
        else
            return make_shared<YellowNoneRectangle>();
    }
};


