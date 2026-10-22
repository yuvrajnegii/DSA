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
    void levelod(TreeNode* root,vector<vector<int>>& arr,int level){
        if(!root) return;
        if(level == arr.size()){
            arr.push_back({});
        }
        arr[level].push_back(root->val);
        levelod(root->left,arr,level+1);
        levelod(root->right,arr,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>arr;
        levelod(root,arr,0);
        return arr;

    }
};