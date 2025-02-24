#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *p, *q;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        p = q = NULL;
    }
};

// Compare function for priority queue
struct Compare {
    bool operator()(Node* p, Node* q) {
        return p->freq > q->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->p && !root->q) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->p, code + "0", huffmanCodes);
    generateCodes(root->q, code + "1", huffmanCodes);
}

// Build Huffman Tree
Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *p = pq.top(); pq.pop();
        Node *q = pq.top(); pq.pop();

        int sum = p->freq + q->freq;
        Node* newNode = new Node('\0', sum);
        newNode->p = p;
        newNode->q = q;
        pq.push(newNode);
    }

    return pq.top();
}

// Compress File
void compressFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    unordered_map<char, int> freq;
    string content;
    char ch;

    // Count frequency of characters
    while (inFile.get(ch)) {
        freq[ch]++;
        content += ch;
    }

    inFile.close();

    Node* root = buildHuffmanTree(freq);
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Encode the content
    string encodedData;
    for (char c : content) {
        encodedData += huffmanCodes[c];
    }

    // Write compressed data to file
    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    // Write metadata: frequency table size and data
    outFile << freq.size() << '\n';
    for (auto pair : freq) {
        outFile << pair.first << ' ' << pair.second << '\n';
    }

    // Write encoded data length and actual encoded data
    outFile << encodedData.size() << '\n';
    outFile << encodedData;
    outFile.close();

    cout << "File successfully compressed!" << endl;
}

// Decompress File
void decompressFile(const string& compressedFile, const string& outputFile) {
    ifstream inFile(compressedFile, ios::binary);
    if (!inFile) {
        cerr << "Error opening compressed file." << endl;
        return;
    }

    int freqSize;
    inFile >> freqSize;
    unordered_map<char, int> freq;

    for (int i = 0; i < freqSize; ++i) {
        char ch;
        int frequency;
        inFile >> ch >> frequency;
        freq[ch] = frequency;
    }

    Node* root = buildHuffmanTree(freq);

    int dataLength;
    inFile >> dataLength;
    inFile.ignore(); // Ignore the newline character

    string encodedData;
    inFile >> encodedData;
    inFile.close();

    // Decode the data
    string decodedData;
    Node* currentent = root;
    for (char bit : encodedData) {
        currentent = (bit == '0') ? currentent->p : currentent->q;

        if (!currentent->p && !currentent->q) {
            decodedData += currentent->ch;
            currentent = root;
        }
    }

    // Write decoded data to output file
    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Error creating output file." << endl;
        return;
    }

    outFile << decodedData;
    outFile.close();

    cout << "File successfully decompressed!" << endl;
}

int main() {
    int choice;
    string inputFile, outputFile;

    cout << "Huffman File Compressor\n";
    cout << "1. Compress File\n2. Decompress File\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter input file to compress: ";
            cin >> inputFile;
            cout << "Enter output compressed file: ";
            cin >> outputFile;
            compressFile(inputFile, outputFile);
            break;
        case 2:
            cout << "Enter compressed file to decompress: ";
            cin >> inputFile;
            cout << "Enter output decompressed file: ";
            cin >> outputFile;
            decompressFile(inputFile, outputFile);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
