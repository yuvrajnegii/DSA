class Solution {
public:
    void pushright(TreeNode* root, vector<int>& arr, int level) {
        if(!root)
            return;
        if(level == arr.size())
            arr.push_back(root->val);
        pushright(root->right, arr, level + 1);
        pushright(root->left, arr, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        pushright(root, arr, 0);
        return arr;
    }
};