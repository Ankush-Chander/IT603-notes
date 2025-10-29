#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

struct Node {
    int key;
    int value;
    Node* left;
    Node* right;
};

void printBST(Node* root, int space = 0, int indent = 4) {
    if (root == nullptr) return;
    
    space += indent;
    printBST(root->right, space);
    
    std::cout << std::endl;
    for (int i = indent; i < space; i++) std::cout << " ";
    std::cout << root->key << "(" << root->value << ")\n";
    
    printBST(root->left, space);
}

Node* insertBST(Node* root, int key, int value) {
    if (root == nullptr) return new Node{key, value, nullptr, nullptr};
    if (key < root->key){
        root->left = insertBST(root->left, key, value);
    
    }else{
        root->right = insertBST(root->right, key, value);
    }
    return root;
}

int main() {
    std::map<int, int> map;
    Node* root = nullptr;
    
    std::cout << "Inserting elements into std::map (ordered map):" << std::endl;
    int keys[] = {31,  21, 1, 41, 11, };
    for (int i = 0; i < 5; ++i) {
        map[keys[i]] = keys[i] * 10;
        root = insertBST(root, keys[i], keys[i] * 10);
    }
    
    std::cout << "\nElements in map (ordered by key):" << std::endl;
    for (const auto& pair : map) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
    
    std::cout << "\nVisual representation of the BST used in std::map:" << std::endl;
    printBST(root);

    // loop over map
    std::cout << "\nLooping over map (ordered by key):" << std::endl;
    for (const auto& pair : map) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }    
    return 0;
}
