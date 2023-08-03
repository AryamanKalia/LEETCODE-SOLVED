#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        unordered_map<string, int> memo;
        return helper(cuts, memo, 0, n);
    }

private:
    int helper(vector<int>& cuts, unordered_map<string, int>& memo, int l, int r) {
        int res = INT_MAX;
        string key = to_string(l) + "-" + to_string(r);
        if (memo.count(key)) return memo[key];

        for (int i = 0; i < cuts.size(); ++i) {
            if (cuts[i] <= l || cuts[i] >= r) continue;
            int cost = r - l;
            res = min(helper(cuts, memo, l, cuts[i]) + cost + helper(cuts, memo, cuts[i], r), res);
        }

        res = res == INT_MAX ? 0 : res;
        memo[key] = res;
        return res;
    }
};
