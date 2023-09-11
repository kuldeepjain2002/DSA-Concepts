#include <iostream>
using namespace std;

class Animal
{

public:
    int age;
    int weight;

public:
    void communicate()
    {
        cout << "communicating " << endl;
    }
};

class Human
{

public:
    int height;

public:
    void speak()
    {
        cout << "Speaking " << endl;
    }
};

// Multi Level Inheritence

// dog is child of animal
class Dog : public Animal
{
public:
    void bark()
    {
        cout << "barking " << endl;
    }
};

// GermanShepherd is child of dog
class GermanShepherd : public Dog
{
};

// Multiple Inheritence : making a class hybrod which is child of both Human class and Animal class
class Hybrid : public Animal, public Human
{
};

// Heirarchical Inheritence : making more than one child of animal class;
class Cat : public Animal
{
public:
    void meow()
    {
        cout << "meowing " << endl;
    }
};
class Bear : public Animal
{
public:
    void howl()
    {
        cout << "howling " << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    cout << "Multi Level Inheritence" << endl;
    GermanShepherd g;
    g.communicate();
    cout << endl;

    cout << "Multiple Inheritence" << endl;
    Hybrid h1;
    h1.speak();
    h1.communicate();
    cout << endl;

    cout << "Heirarchical Inheritance" << endl;
    Cat c1;
    Bear b1;
    c1.communicate();
    b1.communicate();
    c1.meow();
    b1.howl();

    return 0;
}