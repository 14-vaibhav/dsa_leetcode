class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum =nums[0];
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
    

        unordered_set<int> number;
        for(int i =0;i<nums.size();i++){
            number.insert(nums[i]);
        }
        while (number.find(sum) != number.end()) {
    sum++;
}
return sum;
}           
};