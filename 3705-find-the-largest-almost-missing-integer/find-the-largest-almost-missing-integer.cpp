class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int res = -1;

        for(int start = 0; start <= nums.size() - k; start++) {
            unordered_map<int, int> hash;

            for(int i = start; i < start + k; i++) {
                hash[nums[i]]++;
            }

            for(auto it = hash.begin(); it != hash.end(); it++) {
                count[it->first]++;
            }
        }

        for(auto it = count.begin(); it != count.end(); it++) {
            if(it->second == 1) {
                res = max(res, it->first);
            }
        }

        return res;
    }
};