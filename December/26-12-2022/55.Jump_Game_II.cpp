class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> maxJump(nums.size(),0);
        maxJump[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(maxJump[i-1] < i) return false;
            maxJump[i] = max(maxJump[i-1],nums[i]+i);
        }
        return true;
    }
};