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

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();

        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[wordList[i]] = i;
        }
        if (mp.find(endWord) == mp.end())
            return 0;

        if (mp.find(beginWord) == mp.end())
        {
            mp[beginWord] = n;
            n++;
            wordList.push_back(beginWord);
        }

        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < wordList[i].size(); j++)
            {
                string s = wordList[i];
                for (int k = 0; k < 26; k++)
                {
                    s[j] = ('a' + k);
                    if (s != wordList[i] && mp.find(s) != mp.end())
                    {
                        g[i].push_back(mp[s]);
                    }
                }
            }
        }

        // dijkstra;
        int src = mp[beginWord];
        int dest = mp[endWord];
        queue<int> q;
        q.push(src);
        vector<int> vis(n, 0);
        vector<int> lev(n, -1);
        vis[src] = 1;
        lev[src] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << g[u].size() << " " << u << endl;
            for (auto v : g[u])
            {
                // cout<<"v"<<v<<endl;
                if (!vis[v])
                {
                    // cout<<"v"<<v<<endl;
                    vis[v] = 1;
                    lev[v] = lev[u] + 1;
                    q.push(v);
                }
            }
        }

        return lev[dest] + 1;
    }
};