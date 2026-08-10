class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> hash;
        int low =0;int length=0 ;
        int result=0;
        for(int high =0;high<fruits.size();high++){
             hash[fruits[high]]++;
             while(hash.size()> 2){
                hash[fruits[low]]--;
                if(hash[fruits[low]]==0){
                    hash.erase(fruits[low]);
                }
                low++;
             }
             
                    length =high-low+1;
                    result =max(result,length);
                    
             
        }return result;
    }
};