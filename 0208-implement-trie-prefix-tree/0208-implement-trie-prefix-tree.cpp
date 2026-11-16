
class Trie {
public:

    struct Node {
        Node* links[26];
        bool flag;
    };
    Node* getNode(){
        Node* newnode= new Node();
        newnode->flag=false;
        for(int i = 0;i < 26;i ++)
            newnode->links[i]=NULL;
        return newnode;
    }
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(node->links[idx] == nullptr) 
                node->links[idx] = getNode();
            node=node->links[idx];
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            int idx = ch - 'a';

            if(node->links[idx] == nullptr)
                return false;
            node = node->links[idx];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(node->links[idx] == nullptr)
                return false;
            node = node->links[idx];
        }
        return true;
    }
};
