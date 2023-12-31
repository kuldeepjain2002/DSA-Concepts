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
    string minWindow(string s, string t)
    {
        int r = 0;
        int l = 0;
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
        int countt = mp.size();
        // cout<<countt<<endl;
        int mn = INT_MAX;
        int mnl;
        int mnr;
        map<char, int> ex;
        int cnt = 0;
        while (r < n)
        {
            if (mp.find(s[r]) != mp.end())
            {
                ex[s[r]]++;
                if (ex[s[r]] == mp[s[r]])
                {
                    cnt++;
                }
            }
            // cout<<r<<" "<<cnt<<endl;
            while (l <= r && cnt == countt)
            {
                if (mp.find(s[l]) != mp.end())
                {
                    if (mp[s[l]] == ex[s[l]])
                    {
                        cnt--;
                        ex[s[l]]--;
                        if (mn > r - l + 1)
                        {
                            mn = r - l + 1;
                            mnr = r;
                            mnl = l;
                        }
                        l++;
                        break;
                    }
                    else
                    {
                        ex[s[l]]--;
                    }
                }
                l++;
            }
            r++;
        }
        // cout<<mn<<" "<<mnl<<endl;
        if (mn >= INT_MAX)
            return "";
        return s.substr(mnl, mn);
    }
};