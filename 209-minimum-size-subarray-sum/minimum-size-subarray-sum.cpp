class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int high =0;
        int low =0;
        int sum =0;
        
        int result =INT_MAX;
            while(high<=nums.size()-1){
                
                 sum =sum +nums[high];
                while(sum>=target){
                    //firing process
                    int length = high - low +1; 
                    result = min(result,length);
                    sum =sum - nums[low];
                    low++;
                }
                high ++;
               
            }
            if(result ==INT_MAX){
                return 0;
            }
            return result;
    }
};