class Solution {
public:
    int hammingWeight(uint32_t n) {
        int j =0 ; 
        while(n>0){
            if(n&1==1){
                j++;
            }
            n=n>>1;
        }
        return j ; 
    }
};