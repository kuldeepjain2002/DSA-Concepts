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

int l;
vector<int> level;
vector<vector<int>> up;
vector<vector<int>> adj;

void dfs(int src, int par, vector<vector<int>> &adj, int lev)
{
    level[src] = lev;
    up[src][0] = par;
    for (int i = 1; i <= l; i++)
    {
        up[src][i] = up[up[src][i - 1]][i - 1];
    }
    for (auto v : adj[src])
    {
        dfs(v, src, adj, lev + 1);
    }
    return;
}

int LCA(int u, int v)
{
    // 	the farthest node from root must be u;

    if (level[u] < level[v])
    {
        swap(u, v);
    }

    // 	keeping the level of u n v same;
    for (int i = l; i >= 0; i--)
    {
        if (level[u] - pow(2, i) >= level[v])
        {
            u = up[u][i];
        }
    }

    if (u == v)
        return u;

    for (int i = l; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    l = ceil(log2(n));
    up.resize(n, vector<int>(l + 1));
    dfs(0, 0, adj, 0);

    int q;
    cin >> q;
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }

    return 0;
}