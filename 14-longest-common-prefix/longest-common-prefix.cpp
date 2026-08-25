class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Solution {
public:
    class Trie{
        
    public: 
        Node* root;
        
        Trie(){
            root = new Node();
        }

         void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
        }

        bool search(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }


    };



   

    

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        Trie trie;

        for(int i=0; i<strs.size(); i++){
            if(strs[i].empty()) return "";
            trie.insert(strs[i]);
        }
        
        

        string ans = "";
        Node* temp = trie.root;

        for(int i=0; i<strs[0].size(); i++){
            char ch = strs[0][i];

            if(temp->children.size() != 1 || temp->endOfWord){
                break;
            }

            ans += ch;
            temp = temp->children[ch];
        }
        return ans;
    }
};