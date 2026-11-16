class WordDictionary {
public:
    struct Node{
        Node *links[26];
        bool flag;
    };
    Node* getNode(){
        Node* newnode= new Node();
        newnode->flag=false;
        for(int i = 0;i < 26;i++)
            newnode->links[i]=NULL;
        return newnode;
    }
    Node* root;
    WordDictionary(){
        root=getNode();
    }
    void addWord(string word) {
        Node *crawl = root;
        for(char ch : word){
            int idx=ch - 'a';
            if(crawl->links[idx] == nullptr)
                crawl->links[idx] = getNode();
            crawl = crawl->links[idx];
        }
        crawl->flag=true;
    }
    bool searchUtil(Node* root,string word){
        Node* crawl=root;
        for(int i = 0;i < word.length();i ++){
            char ch = word[i]; 
            if(ch == '.'){
                for(int j = 0;j < 26;j ++){
                    if(crawl->links[j] != NULL){
                        if(searchUtil(crawl->links[j],word.substr(i+1)) == true)
                            return true;
                    }
                }
                return false;
            }
            else if(crawl->links[ch-'a'] == NULL){
                return false;
            }
            crawl=crawl->links[ch-'a'];
        }
        return (crawl != NULL && crawl->flag == true);
    }
    bool search(string word) {
        return searchUtil(root,word);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */