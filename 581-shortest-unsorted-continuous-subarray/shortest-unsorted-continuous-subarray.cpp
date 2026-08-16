class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < nums.size() - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        if (left == nums.size() - 1) {
            return 0;
        }

        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        int minimum = nums[left];
        int maximum = nums[left];

        for (int i = left; i <= right; i++) {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }

        while (left > 0 && nums[left - 1] > minimum) {
            left--;
        }

        while (right < nums.size() - 1 && nums[right + 1] < maximum) {
            right++;
        }

        return right - left + 1;
    }
};