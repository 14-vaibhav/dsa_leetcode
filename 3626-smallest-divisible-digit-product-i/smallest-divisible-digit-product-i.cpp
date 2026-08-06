class Solution {
public:
    int smallestNumber(int n, int t) {
       while(true){
           
         
    int temp =n;int digit;
    int product =1;
        while(temp>0){
            digit =temp%10;
            product*=digit;
            temp =temp/10;          
        }
        if(product%t==0){
            return n;
        }n++;
       }   
     
    }
};