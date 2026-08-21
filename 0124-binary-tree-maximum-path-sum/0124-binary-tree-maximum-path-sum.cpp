/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mpath(TreeNode* root, int& msum) {
        if(!root)
            return 0;
        int left = max(0, mpath(root->left, msum));
        int right = max(0, mpath(root->right, msum));
        // Best path passing through this node
        msum = max(msum, left + root->val + right);
        // Return only one side to the parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int msum = INT_MIN;

        mpath(root, msum);

        return msum;
    }
};