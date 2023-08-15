class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int length = 0; 
    int start = 0; 
    int end = 0; 
    int sl = s.size();
    int maxlen = 0;  // Initialize maxlen to 0
    unordered_map<char, int> abc;
    
    while (end < s.size()) {
        if (abc.find(s[end]) == abc.end()) {
            abc[s[end]] = end;
            end++;
            length = end - start;  // Update length here
        } else {
            int st = abc[s[end]] + 1;  // Use the correct index
            start = max(start, st);   // Update start only if the new start is greater
            abc[s[end]] = end;
            end++;
            length = end - start;     // Update length here
        }
        maxlen = max(maxlen, length);
    }
    return maxlen;
}

};