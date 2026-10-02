class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        int output=INT_MIN;
        for(int i =0;i<accounts.size();i++){ 
            for(int j =0 ;j<accounts[i].size();j++){
                 sum += accounts[i][j];
            }
            if(sum>output){
                    output = sum;
                }
                sum =0 ;
        }return output;
    }
};