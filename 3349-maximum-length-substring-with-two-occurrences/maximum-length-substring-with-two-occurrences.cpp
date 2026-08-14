class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> hash;
        int high ;int low =0;int result =INT_MIN;
        for(high =0;high<s.size();high++){
            hash[s[high]]++;
            while(hash[s[high]]>2){
                hash[s[low]]--;
                if(hash[s[low]]==0){
                    hash.erase(s[low]);
                }
                low++;

                
            }int length = high -low +1;
                result =max(result,length);
            
        }return result;
    }
};