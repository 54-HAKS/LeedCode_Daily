class Solution {
public:
    int helper(TreeNode* x, int &line) {
        if (x == NULL) return INT_MIN;
        int ll = 0, rl = 0, lm = helper(x->left, ll), rm = helper(x->right, rl);
        line = max(0, max(ll, rl) + x->val);
        return max(ll + rl + x->val, max(lm, rm));
    }
    int maxPathSum(TreeNode* root) {
        int line = 0;
        return helper(root, line);
    }
};