/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)
            return "null";
        s+=to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        return s;
    }

    TreeNode* solve(stringstream &ss){
        string token;
        getline(ss,token,',');
        if(token == "null")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        root->left = solve(ss);
        root->right=solve(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return solve(ss);
        
        

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));