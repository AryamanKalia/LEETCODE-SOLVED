class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> ab;
        int sol=0;
        for(int i =0;i<tokens.size();i++){
            int a ; 
            int b;
            if(tokens[i]=="+"){
              a=stoi(ab.top());
                ab.pop();
              b=stoi(ab.top());
                ab.pop();
              ab.push(to_string((a+b)));
            }
            else if(tokens[i]=="-"){
             a=stoi(ab.top());
                ab.pop();
              b=stoi(ab.top());
                ab.pop();
              ab.push(to_string((b-a)));
            }
            else if(tokens[i]=="*"){
              a=stoi(ab.top());
                ab.pop();
              b=stoi(ab.top());
                ab.pop();
              ab.push(to_string(a*b));
            }
            else if(tokens[i]=="/"){
              a=stoi(ab.top());
                ab.pop();
              b=stoi(ab.top());
                ab.pop();
              ab.push(to_string((int)(b/a)));
            }
            else 
             ab.push(tokens[i]);
            }
        int aa= stoi(ab.top());
        ab.pop();
        return aa ;
        }
};