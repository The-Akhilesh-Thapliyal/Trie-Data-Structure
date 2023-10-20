#include<iostream>

using namespace std;

class TrieNode {
public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    TrieNode* root;

public:
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        // Base Case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Asumption, word will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if(root -> children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        return insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base Case
        if(word.length() == 0) {
            return root->isTerminal;
        }
        
        // Assuming, word will be lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if(root -> children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool startWithUtil(TrieNode* root, string prefix) {
        // Base Case
        if(prefix.length() == 0) {
            return true;
        }

        // Assuming, word is lowercase
        int index = prefix[0] - 'a';
        TrieNode* child;

        // Present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            // Absent
            return false;
        }

        // Recursion
        return startWithUtil(child, prefix.substr(1));
    }

    bool startWith(string prefix) {
        return startWithUtil(root, prefix);
    }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("abcd");

    cout << "'abcd' : 1 for Present or 0 for Absent : " << t->searchWord("abcd") << endl;

    cout << "Start With 'ab' : 1 for true or 0 for false : " << t->startWith("ab") << endl;

    return 0;
}