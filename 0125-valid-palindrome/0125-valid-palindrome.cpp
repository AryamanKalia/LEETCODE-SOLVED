class Solution {
public:
    bool isPalindrome(string s) {
        auto start = s.begin();
        auto ed = s.end();
        ed--;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(start<ed){
            if(!(isalnum(*start))){start++;continue;}
            if(!(isalnum(*ed))){ed--;continue;}
            if(*start!=*ed){return false;}
            start++;
            ed--;
        }
        return true;
    }
};