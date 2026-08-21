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
    void countgood(TreeNode* root,int rmax1,int &count){
        if(root){
            if(rmax1 > root->val){
                countgood(root->right,rmax1,count);
                countgood(root->left,rmax1,count);
            }
            else{
                count++;
            rmax1=root->val;
            countgood(root->right,rmax1,count);
            countgood(root->left,rmax1,count);
            }
        }
            
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int max1=root->val;
        int count=1;
        countgood(root->right,max1,count);
        countgood(root->left,max1,count);
        return count;
    }   
};