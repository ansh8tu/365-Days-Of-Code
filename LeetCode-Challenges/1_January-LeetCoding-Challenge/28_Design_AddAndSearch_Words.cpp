#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
    TrieNode* link[26];
    bool flag = false;
    TrieNode(){
        for(int i=0; i<26; i++){
            link[i] = NULL;
        }
        flag = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int n = word.size();
        TrieNode* temp = root;
        for(auto ch: word)
        {
            if(!temp->link[ch-'a'])
                temp->link[ch-'a'] = new TrieNode;
            temp = temp->link[ch-'a'];
        }
        temp->flag = true;
    }
    
    bool mySearch(string word, TrieNode* root){
        int n = word.size();
        TrieNode* temp = root;
        for(int i=0; i<n; i++){
            if(word[i] == '.'){
                for(auto child: temp->link){
                    if(child && mySearch(word.substr(i+1), child))
                        return true;
                }
                return false;
            }
            else{
                if(!temp->link[word[i]-'a'])
                    return false;
                temp = temp->link[word[i]-'a'];
            }
            
        }
        return temp->flag;
    }
    
    bool search(string word) {
        return mySearch(word, root);
    }
};


int main(){
    WordDictionary w;
}