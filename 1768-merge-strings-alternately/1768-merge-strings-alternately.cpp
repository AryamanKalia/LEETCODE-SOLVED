class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         int s= max(word1.size(),word2.size());
        string mer="";
            for(int i = 0 ; i<s;i++){
                string a1;
                string a2;
                if(i<word1.size()){
                    a1=word1[i];
                }
                else a1="";
        if(i<word2.size()){
                    a2=word2[i];
                }
                else a2="";
                mer=mer+a1+a2;
            }
        return mer;
        }
};