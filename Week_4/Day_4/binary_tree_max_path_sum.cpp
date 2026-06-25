class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));

        maxSum = max(maxSum, root->val + leftGain + rightGain);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};