// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// Difficulty: Medium
//
// A trie (pronounced "try") or prefix tree is a tree data structure used to
// efficiently store and retrieve keys in a dataset of strings. Applications
// include autocomplete and spellchecker.
//
// Implement the Trie class:
//   - Trie() Initializes the trie object.
//   - void insert(string word) Inserts the string word into the trie.
//   - bool search(string word) Returns true if word is in the trie (was inserted
//     before), and false otherwise.
//   - bool startsWith(string prefix) Returns true if there is a previously
//     inserted word that has the prefix prefix, and false otherwise.
//
// Example 1:
//   Input:
//     ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//     [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
//   Output:
//     [null, null, true, false, true, null, true]
//   Explanation:
//     Trie trie = new Trie();
//     trie.insert("apple");
//     trie.search("apple");   // return true
//     trie.search("app");     // return false
//     trie.startsWith("app"); // return true
//     trie.insert("app");
//     trie.search("app");     // return true
//
// Constraints:
//   - 1 <= word.length, prefix.length <= 2000
//   - word and prefix consist only of lowercase English letters.
//   - At most 3 * 10^4 calls in total to insert, search, and startsWith.

#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    struct Node {
    public:
        bool end = false;
        std::array<Node*, 26> children = {};

        Node() {
            
        }
    };

    std::array<Node*, 26> roots = {};
    
    Trie() {
    }

    void insert(string word) {
        auto* nodes = &roots;
        Node* node = nullptr;
        
        for (char c : word) {
            int i = c - 'a';
            node = nodes->at(i);

            if (node == nullptr) {
                node = new Node{};
                nodes->at(i) = node;
            }

            nodes = &node->children;
        }

        node->end = true;
    }

    bool search(string word) {
        auto* nodes = &roots;
        Node* node = nullptr;

        for (char c : word) {
            int i = c - 'a';
            node = nodes->at(i);

            if (node == nullptr) {
                return false;
            }

            nodes = &node->children;
        }
        
        return node != nullptr && node->end;
    }

    bool startsWith(string prefix) {
        auto* nodes = &roots;
        Node* node = nullptr;

        for (char c : prefix) {
            int i = c - 'a';
            node = nodes->at(i);

            if (node == nullptr) {
                return false;
            }

            nodes = &node->children;
        }

        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() { return 0; }
