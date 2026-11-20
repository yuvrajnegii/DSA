class Solution {
public:
    struct TrieNode{
        TrieNode* links[26];
        bool endnode;
        string w;
    };
    TrieNode* getnode(){
        TrieNode* newnode= new TrieNode();
        newnode->endnode=false;
        for(int i = 0;i < 26;i ++){
            newnode->links[i]=NULL;
        }
        return newnode;
    }

    void solve(int i,int j, TrieNode* root, vector<string> &ans,vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if(board[i][j] == '#' || root->links[board[i][j]-'a'] == nullptr)
            return;
        char temp=board[i][j];
        board[i][j]='#';
        int idx=temp - 'a';
        root=root->links[idx];
        
        if(root->w != "") {
            ans.push_back(root->w);
            root->w = "";
        }    
        solve(i-1, j,root,ans,board);
        solve(i+1, j,root,ans,board);
        solve(i, j-1,root,ans,board);
        solve(i, j+1,root,ans,board);
        board[i][j] = temp;

    }
        void insert(TrieNode* root,string word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(node->links[idx] == nullptr) 
                node->links[idx] = getnode();
            node=node->links[idx];
        }
        node->endnode = true;
        node->w=word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = getnode();
        vector<string>ans;
        for(string w:words)
            insert(root,w);
        int m=board.size();
        int n=board[0].size();
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                solve(i,j,root,ans,board);
            }
        }
        return ans;
    }
};