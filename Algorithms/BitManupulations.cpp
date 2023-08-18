#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<cmath>

#define rep(i,n) for(long long int i=0;i<n;i++)
#define repinv(i,n) for(long long int i=n-1;i>=0;i--)
#define for1(i,n) for(long long int i=1;i<=n;i++)
#define loop(i,a,b,k) for(long long int i=a;i<=b;i=i+k)

#define pb push_back
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define uii unordered_map<int,int>
#define vc vector<char>
#define vb vector<bool>
#define vstr vector<string>
#define vd vector<double>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define maxpq priority_queue<int,vector<int>>
#define minpq priority_queue<int,vector<int>,greater<int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define mp make_pair

#define modulo 1000000007
#define longmodulo 1000000000000000000
using namespace std;

bool isSet(int x, int pos){
	return(x&(1<<pos));
}

bool isPowerOf2(int x){
	return !(x&(x-1));
}

int setpos(int x, int pos){
	return x|(1<<pos);
}
int clearbit(int x, int pos){
	return x& (~(1<<pos));
}
int clearRightMostBit(int x){
	return x&(x-1) ;
}

int countSetBits(int n)
{
    int count = 0;
    while (n){
        n = n & (n - 1);
        count++;
    }
    return count;
}

// n&(n+1) clears all the trailing ones
// n|(n+1) sets last cleared bit
// n&(-n) - extracts last bit
int main(){
	int x,y;
	cin>>x;
	cin>>y;
	cout<<isSet(x,2)<<endl;
	cout<<isPowerOf2(x)<<endl;
	cout<<setpos(x,1)<<endl;
	cout<<clearbit(x,1)<<endl;
	
	return 0;
}