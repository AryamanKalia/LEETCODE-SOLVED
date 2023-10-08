class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n, 0, 0, result);
        return result;
    }

private:
    void generate(string current, int n, int open, int close, vector<string>& result) {
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        if (open < n)
            generate(current + "(", n, open + 1, close, result);
        if (close < open)
            generate(current + ")", n, open, close + 1, result);
    }
};
