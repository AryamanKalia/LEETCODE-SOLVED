class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        
        vector<unordered_map<char, int>> abc(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                abc[i][strs[i][j]]++;
            }
        }
        
        vector<vector<string>> abcd;
        vector<int> visited(strs.size(), 0);
        
        for (int i = 0; i < strs.size(); i++) {
            if (visited[i] == 1) {
                continue;
            }
            
            vector<string> abcde;
            abcde.push_back(strs[i]);
            visited[i] = 1;
            
            for (int j = i + 1; j < strs.size(); j++) {
                if (visited[j] == 0 && isAnagram(abc[i], abc[j])) {
                    abcde.push_back(strs[j]);
                    visited[j] = 1;
                }
            }
            
            abcd.push_back(abcde);
        }
        
        return abcd;
    }
    
    bool isAnagram(const unordered_map<char, int>& map1, const unordered_map<char, int>& map2) {
        if (map1.size() != map2.size()) {
            return false;
        }
        
        for (const auto& [key, value] : map1) {
            if (map2.find(key) == map2.end() || map2.at(key) != value) {
                return false;
            }
        }
        
        return true;
    }
};
