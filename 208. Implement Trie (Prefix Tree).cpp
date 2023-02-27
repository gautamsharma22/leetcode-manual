class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool end;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        end=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root =new TrieNode('\0');
    }
    void insertWord(TrieNode* root,string word) {
        if(word.length()==0){
            root->end=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }
    
    void insert(string word) {
        insertWord(root,word);
        return;
    }
    
    bool searchWord(TrieNode* root, string word) {
        if(word.length()==0)return root->end;
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        return searchWord(child,word.substr(1));
    }
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool startsWithWord(TrieNode* root, string word) {
        if(word.length()==0)return true;
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        return startsWithWord(child,word.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithWord(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */