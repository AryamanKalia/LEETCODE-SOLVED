class Solution {
public:
    int minBitFlips(int start, int goal) {
         int a =  start^goal;
        int  b= 0 ; 
        while(a>0){
            if(a&1==1)
            {
                b++;
            }
            a=a>>1;
        }
        return b ;
    }
};