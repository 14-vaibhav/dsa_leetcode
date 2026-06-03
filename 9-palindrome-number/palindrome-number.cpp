class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        int y =x;
        if (x<0){
            return false;
        }
        else{    
        while(x>0){
           
            int lastDigit = x%10;
            x=x/10;
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return false;
            }
            rev=rev*10+lastDigit;
            
        }
        if(y==rev){
                return true;
            }
       
            else{
                return false;
            }
            
     }
    }  
};