class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i = 0 ;i<numRows;i++){
            vector<int> vv;
            for(int j = 0 ; j<i+1;j++){
                if(j==0 || j==i){
                    vv.push_back(1);
                    
                }
                else{
                    vv.push_back(v[i-1][j-1]+v[i-1][j]);
                }
                if(j==i){}
            
            }
            v.push_back(vv); 
        }
        return v;
    }
};