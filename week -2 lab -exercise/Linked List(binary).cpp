#include <iostream>
#include <string>
using namespace std;

// Node structure for the binary search tree
struct Node {
    string identifier;
    string value; // Associated information
    Node* left;
    Node* right;
    Node(string id, string val) : identifier(id), value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new identifier and its associated information into the symbol table
Node* insert(Node* root, string identifier, string value) {
    if (root == nullptr) {
        return new Node(identifier, value);
    }

    if (identifier < root->identifier) {
        root->left = insert(root->left, identifier, value);
    } else if (identifier > root->identifier) {
        root->right = insert(root->right, identifier, value);
    }

    return root;
}

// Function to search for an identifier in the symbol table
string search(Node* root, string identifier) {
    if (root == nullptr) {
        return "Identifier not found";
    }

    if (identifier == root->identifier) {
        return root->value;
    } else if (identifier < root->identifier) {
        return search(root->left, identifier);
    } else {
        return search(root->right, identifier);
    }
}

int main() {
    Node* symbolTable = nullptr;

    symbolTable = insert(symbolTable, "81", "int");
    symbolTable = insert(symbolTable, "82", "int");
    symbolTable = insert(symbolTable, "83", "class");
    // ... Insert more identifiers and associated information

    string targetIdentifier;
    cout << "Enter the identifier to search for: ";
    cin >> targetIdentifier;

    string result = search(symbolTable, targetIdentifier);
    cout << "Associated information: " << result << endl;

   return 0;
}