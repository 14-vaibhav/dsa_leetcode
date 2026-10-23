class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a ;
       unordered_map<int,int> repeat;
       for(int i =0;i<nums.size();i++){ 
        repeat[nums[i]]++;
        }
        for(int i =0 ;i<nums.size();i++){
            if(repeat[nums[i]]>nums.size()/2){
                a=nums[i];
            }
        }return a;
    };
};