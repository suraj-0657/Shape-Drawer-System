//Design a shape drawer system using factory design pattern.
#include <iostream>
using namespace std;

enum UserShape
{
    Cir,Rec,Sq
};

class Shape
{
    public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
    public:
    void draw()
    {
        cout<<"Circle Drawn"<<endl;
    }
};

class Square : public Shape
{
    public:
    void draw()
    {
        cout<<"Square Drawn"<<endl;
    }
};

class Rectangle : public Shape
{
    public:
    void draw()
    {
        cout<<"Rectangle Drawn"<<endl;
    }
};

class ShapeFactoryInterface
{
    public:
    virtual Shape* constructShape(UserShape inputShape) = 0;
};

class ShapeFactory : public ShapeFactoryInterface
{
    public:
    Shape* constructShape(UserShape inputShape)
    {
        switch(inputShape)
        {
            case Cir: return (new Circle);
            case Rec: return (new Rectangle);
            case Sq: return (new Square);
            default: return NULL;
        }
    }
};

int main() {
	ShapeFactoryInterface *ptr = new ShapeFactory;
	Shape *drawer = ptr->constructShape(Cir);
	drawer->draw();
	drawer = ptr->constructShape(Rec);
	drawer->draw();
	drawer = ptr->constructShape(Sq);
	drawer->draw();
	return 0;
}