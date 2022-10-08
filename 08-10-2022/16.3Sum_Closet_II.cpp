class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n = nums.size(), ans = 1e9;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (abs(ans - tar) > abs(cur - tar)) ans = cur;
                if (cur < tar) left++;
                else right--;
            }
        }
        return ans;
    }
};