class Solution {
public:
    vector<vector<string>> ans;
    bool check(string last){
        int st=0;
        int lt = last.size()-1;
        while(st<=lt){
            if(last[st]!=last[lt]){
            return false;
            }
            st++;
            lt--;
        }
        return true;
    }
    void part(string s,string lastsubstring, vector<string> ss,int lastsudd){
       if(lastsudd==s.size()-1 && check(lastsubstring) ){
           ans.push_back(ss);
           return;
       }
        if(!check(lastsubstring)){return;}
        int j=1;
        for(int i =lastsudd+1;i<s.size();i++){
        string last=s.substr(lastsudd+1,j);
            ss.push_back(last);
            part(s,last,ss,i);
            ss.pop_back();
            j++;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>sss;
        part(s,"",sss,-1);
        return ans;
    }
};