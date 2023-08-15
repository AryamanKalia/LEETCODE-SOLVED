class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        
        string longest = s.substr(0, 1); // Single character is a palindrome
        
        for (int i = 0; i < n - 1; ++i) {
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > longest.size()) {
                longest = odd;
            }
            
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > longest.size()) {
                longest = even;
            }
        }
        
        return longest;
    }
};
