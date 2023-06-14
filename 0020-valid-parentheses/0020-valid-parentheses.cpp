class Solution {
public:
    bool isInput(char a){return( a=='[' || a=='{' || a=='(');}
    bool isOutput(char a){return( a==']' || a=='}' || a==')');}
    bool isCheck(char a,char b){
        if((a=='}'&& b=='{') ||(a==')'&& b=='(')||( a==']'&& b=='[')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>ss;
        for(int i = 0;i<s.size();i++){
            if(isInput(s[i])){
                ss.push(s[i]);
            }
            else if(isOutput(s[i])){
                if(ss.empty()==true){
                    return false;
                }
                else if(isCheck(s[i],ss.top())){
                    ss.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(ss.empty()==true){
            return true;
        }
        return false;
    }
};