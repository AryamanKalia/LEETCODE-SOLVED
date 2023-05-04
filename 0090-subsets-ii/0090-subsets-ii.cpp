class Solution {
public:
    vector<vector<int>>abc;
    void subsetWithoutDup(vector<int>& num, int k , int N , vector<int>& acc){
        if(k==N){
            sort(acc.begin(),acc.end());
            abc.push_back(acc);
            return ;
                }
        vector<int>abc(acc);
        acc.push_back(num[k]);
        subsetWithoutDup(num, k+1 , N ,abc);
        vector<int> acd(acc);
        subsetWithoutDup(num,k+1,N,acd);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& num) {
        vector<int> abb;
        subsetWithoutDup(num,0,num.size(),abb);
         map<vector<int>,int> ad; 
        vector<vector<int>>er;
        for(int i = 0 ; i< abc.size();i++){
            ad[abc[i]]=i;
        }
        for(auto it = ad.begin(); it!=ad.end();it++){
            er.push_back(it->first);
        }
        return er;
        
    }
};