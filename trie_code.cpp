#include <iostream>
#include <string>
using namespace std;

// Define the number of possible characters (a-z)
#define ALPHABET_SIZE 26

// Trie Node structure
class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE]; // Array for 26 lowercase English letters
    bool isEndOfWord;                 // Marks the end of a word

    // Constructor
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() { root = new TrieNode(); }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a'; // Get the index for the current character
            if (!current->children[index]) {
                current->children[index] = new TrieNode(); // Create a new node if it doesn't exist
            }
            current = current->children[index]; // Move to the next node
        }
        current->isEndOfWord = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a'; // Get the index for the current character
            if (!current->children[index]) return false; // If the path doesn't exist, return false
            current = current->children[index]; // Move to the next node
        }
        return current->isEndOfWord; // Return true if it's the end of a word
    }
};

// Main function
int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    // Search for words in the Trie
    cout << "Search for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search for 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search for 'ball': " << (trie.search("ball") ? "Found" : "Not Found") << endl;
    cout << "Search for 'batman': " << (trie.search("batman") ? "Found" : "Not Found") << endl;

    return 0;
}
