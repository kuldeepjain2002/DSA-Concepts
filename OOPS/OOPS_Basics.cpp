#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (long long int i = 0; i < n; i++)
#define repinv(i, n) for (long long int i = n - 1; i >= 0; i--)
#define for1(i, n) for (long long int i = 1; i <= n; i++)
#define loop(i, a, b, k) for (long long int i = a; i <= b; i = i + k)

#define pb push_back
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define uii unordered_map<int, int>
#define vc vector<char>
#define vb vector<bool>
#define vstr vector<string>
#define vd vector<double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define maxpq priority_queue<int, vector<int>>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vii vector<pair<int, int>>
#define vll vector<pair<long long, long long>>
#define mp make_pair

#define modulo 1000000007
#define longmodulo 1000000000000000000
using namespace std;

// object =  entity having states/properties and behaviour
// class = user defined data type
// object = instance of class

class Rectangle
{

    // 	public access can be accessed outside class

public:
    int length;
    int breadth;
    // int length, int breadth
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

class Rectangle2
{
    // 	private: can't be accessed outside the class , only accessed inside the class'
private:
    int length;
    int breadth;

public:
    // getters and setters to get set the private properties
    // can use if conditions in these funcs to allow only specific people to use get/set
    void setlength(int l)
    {
        if (l > 0)
        {
            length = l;
        }
        else
        {
            length = 0;
        }
    }
    void setbreadth(int b)
    {
        if (b > 0)
        {
            breadth = b;
        }
        else
        {
            breadth = 0;
        }
    }
    int getlength()
    {
        return length;
    }
    int getbreadth()
    {
        return breadth;
    }

    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

class RectangleConst
{
private:
    int length;
    int breadth;

public:
    RectangleConst(int length, int breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }
    void setlength(int l)
    {
        if (l > 0)
        {
            length = l;
        }
        else
        {
            length = 0;
        }
    }
    void setbreadth(int b)
    {
        if (b > 0)
        {
            breadth = b;
        }
        else
        {
            breadth = 0;
        }
    }
    int getlength()
    {
        return length;
    }
    int getbreadth()
    {
        return breadth;
    }

    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

// Parametrized constructor	and copy constructor- inbuilt whenever u create an instance of class
// can also write your own cnstructor
// default copy constructor - shallow copy
// Using deep copy
// destructor
class Rectangle3
{
private:
    int length;
    int breadth;
    int *p;

public:
    void setlength(int l)
    {
        if (l > 0)
        {
            length = l;
        }
        else
        {
            length = 0;
        }
    }
    void setbreadth(int b)
    {
        if (b > 0)
        {
            breadth = b;
        }
        else
        {
            breadth = 0;
        }
    }

    Rectangle3(int l = 0, int b = 0)
    {
        setlength(l);
        setbreadth(b);
        p = new int[l];
        // 		deep copy
    }
    Rectangle3(Rectangle3 &rect)
    {
        setlength(rect.length);
        setbreadth(rect.breadth);
        p = new int[rect.length];
    }
    ~Rectangle3()
    {
        cout << "destructor being called" << endl;
    }
    int getlength()
    {
        return length;
    }
    int getbreadth()
    {
        return breadth;
    }

    int area()
    {
        return length * breadth;
    }
    int perimeter();
};

class cuboid : public Rectangle3
{
private:
    int height;

public:
    void setheight(int h)
    {
        height = h;
    }
    cuboid(int l, int b, int h)
    {
        setlength(l);
        setbreadth(b);
        setheight(h);
    }
    int volume()
    {
        return getlength() * getbreadth() * height;
    }
};

// static int
class Rectangle4
{

    // 	public access can be accessed outside class

public:
    int length;
    int breadth;
    static int cnt;
    // int length, int breadth
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
    static int printt()
    {
        cout << cnt << " can use only the static member" << endl;
    }
};

class complex
{
public:
    int real;
    int imaginary;

    complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    complex operator+(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }

    friend complex operator-(complex c1, complex c2);
};

int main()
{
    int t;
    cin >> t;

    // 	creating instances of class - static allocation
    Rectangle r1, r2;
    // 	on creating like this , the properties have garbage values stored in it
    // access properties/data members using dot operators
    cout << "accessing public properties/functions using dot operators" << endl;
    r1.length = 3;
    r1.breadth = 8;
    int ans = r1.area();
    r2.length = 9;
    r2.breadth = 2;
    cout << r2.area() << endl;
    cout << ans << endl;
    cout << endl;

    // 	Dynamic allocation
    cout << "Dynamic allocation" << endl;
    Rectangle *p = new Rectangle();
    cout << "using ->" << endl;
    p->length = 5;
    cout << p->length << endl;
    cout << "Address of p" << &p << endl;
    cout << "using derefrencing" << endl;
    cout << (*p).length << endl;
    p->length = 2;
    p->breadth = 3;
    cout << p->area() << endl;
    cout << endl;

    // 	Getters and setters for private properties

    cout << "Rectangle2 having private properties" << endl;
    Rectangle2 r3, r4;
    r3.setlength(5);
    // cout<<r3.getlength()<<endl;
    r3.setbreadth(2);
    cout << r3.area() << endl;
    cout << endl;

    // constructor
    cout << "constructor on rc and use of this" << endl;
    RectangleConst rc(2, 3);
    cout << rc.area() << endl;
    cout << endl;

    // copy constructor	, deep copy , copy assignment operator
    cout << "copy constructor" << endl;
    Rectangle3 r5(5, 3);
    Rectangle3 r7(8, 4);
    Rectangle3 r6(r5);

    cout << r5.area() << endl;
    cout << r6.area() << endl;
    cout << r5.perimeter() << endl;
    cout << "copy assignment operator" << endl;
    cout << "before copying :" << r7.area() << endl;
    r7 = r5;
    cout << "after copying :" << r7.area() << endl;

    // 	destructor in case of dynamic allocation needs to be called manually by delete
    Rectangle3 *r8 = new Rectangle3(2, 4);
    cout << r8->area() << endl;
    delete r8;
    cout << endl;

    //  static int
    cout << "static int" << endl;
    cout << Rectangle4::cnt << endl;
    Rectangle4 r9, r10;
    cout << r9.cnt << endl;
    r10.cnt = 10;
    cout << r9.cnt << " " << r10.cnt << " " << Rectangle4::cnt << endl;
    Rectangle4::printt();
    cout << endl;

    complex c1(5, 6);
    complex c2(3, 4);
    complex c3, c4;
    c3 = c1 + c2;
    c4 = c1 - c2;
    cout << c3.real << " " << c3.imaginary << endl;
    cout << c4.real << " " << c4.imaginary << endl;

    cuboid c5(3, 4, 5);
    cout << c5.volume() << " " << c5.area() << endl;
    return 0;
}

int Rectangle3 ::perimeter()
{
    return 2 * (length + breadth);
}

int Rectangle4 ::cnt = 5;

complex operator-(complex c1, complex c2)
{
    complex temp;
    temp.real = c1.real - c2.real;
    temp.imaginary = c1.imaginary - c2.imaginary;
    return temp;
}

// outputs:

// accessing public properties/functions using dot operators
// 18
// 24

// Dynamic allocation
// using ->
// 5
// Address of p0xce303ffbd0
// using derefrencing
// 5
// 6

// Rectangle2 having private properties
// 10

// constructor on rc and use of this
// 6

// copy constructor
// 15
// 15
// 16
// copy assignment operator
// before copying :32
// after copying :15
// 8
// destructor being called

// static int
// 5
// 5
// 10 10 10
// 10 can use only the static member

// 8 10
// 2 2
// 60 12
// destructor being called
// destructor being called
// destructor being called
// destructor being called
