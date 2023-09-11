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
    vector<vector<int>> memo;
    int sol(int n, int k)
    {

        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (k == 1)
            return n;
        if (memo[n][k] != -1)
            return memo[n][k];
        int l = 0;
        int r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int x = sol(mid - 1, k - 1);
            int y = sol(n - mid, k);
            if (x < y)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return memo[n][k] = 1 + max(sol(l - 1, k - 1), sol(n - l, k));
    }
    int superEggDrop(int k, int n)
    {
        memo.resize(n + 1, vector<int>(k + 1, -1));
        return sol(n, k);
    }
};