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

class LRUCache
{
public:
    map<int, pair<int, int>> mp;
    queue<pair<int, int>> q;
    int cap = 0;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            int val = mp[key].first;
            int cnt = mp[key].second;
            mp[key] = {val, cnt + 1};
            q.push({key, cnt + 1});
            while (!q.empty() && mp[q.front().first].second > q.front().second)
            {
                q.pop();
            }
            return val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            mp[key] = {value, 1};
            q.push({key, 1});
        }
        else
        {
            int cnt = mp[key].second;
            mp[key] = {value, cnt + 1};
            q.push({key, cnt + 1});
        }
        while (!q.empty() && mp[q.front().first].second > q.front().second)
        {
            q.pop();
        }
        if (mp.size() > cap)
        {
            int keytopop = q.front().first;
            cout << key << " " << keytopop << endl;
            mp.erase(mp.find(keytopop));
            q.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */