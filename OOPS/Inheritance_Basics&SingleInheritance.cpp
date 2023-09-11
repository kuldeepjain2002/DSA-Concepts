#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

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

// parent class
class Employees
{
private:
	string name;
	int eid;

public:
	Employees(int x, string n)
	{
		name = n;
		eid = x;
	}
	string getname()
	{
		return name;
	}
	int geteid()
	{
		return eid;
	}
};

// access modifier : public
class FulltimeEmployees : public Employees
{
private:
	int salary;

public:
	// since name and eid are private in base class we cant access them neither here nor outside the class,
	// getname() is public in the base class , so it is public here also;
	FulltimeEmployees(int x, string n, int sal) : Employees(x, n)
	{
		salary = sal;
	}
	int getsal()
	{
		return salary;
	}
};

class FulltimeEmployees2 : protected Employees
{
private:
	int salary;

public:
	FulltimeEmployees2(int x, string n, int sal) : Employees(x, n)
	{
		salary = sal;
	}
	int getsal()
	{
		return salary;
	}
	// 	since it is a protected class, getname() of the parent class is now
	// protected , so can be called directly, only be accessed inside the class
	// so we create a new public function that calls the protected getname();
	string getname2()
	{
		return getname();
	}
};

class ParttimeEmployees : public Employees
{
private:
	int wages;

public:
	ParttimeEmployees(int x, string n, int wage) : Employees(x, n)
	{
		wages = wage;
	}
	int getwages()
	{
		return wages;
	}
};

int main()
{
	int t;
	cin >> t;
	ParttimeEmployees p1(1, "johnny", 2100);
	FulltimeEmployees p2(1, "deepti", 21000);
	FulltimeEmployees2 p3(1, "Manisha", 24000);

	cout << p1.getname() << " earns - " << p1.getwages() << endl;
	cout << p2.getname() << " earns - " << p2.getsal() << endl;
	cout << p3.getname2() << " earns - " << p3.getsal() << endl;

	return 0;
}

// output
// johnny earns - 2100
// deepti earns - 21000
// Manisha earns - 24000
