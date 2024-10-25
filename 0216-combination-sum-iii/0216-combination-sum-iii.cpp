#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, 1, n, k);

        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &path, int start, int n, int k)
    {
        // here n denotes the target value
        if (n == 0 and k == 0)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= 10 - k and i <= n; i++)
        {
            path.push_back(i);
            backtrack(res, path, i + 1, n - i, k - 1);
            path.pop_back(); // this is backtracking step
        }
    }
};