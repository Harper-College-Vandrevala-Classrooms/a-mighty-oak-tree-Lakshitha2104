#include <iostream>
#include <string>
using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) : name(name) {}

    string get_name() {
        return name;
    }
};

class Node {
private:
    Squirrel* squirrel; 
    Node* leftChild;    
    Node* rightChild;   

public:
    Node(Squirrel* squirrel) : squirrel(squirrel), leftChild(nullptr), rightChild(nullptr) {}

    void set_left(Node* child) {
        leftChild = child;
    }

    void set_right(Node* child) {
        rightChild = child;
    }

    Node* left() {
        return leftChild;
    }

    Node* right() {
        return rightChild;
    }

    Squirrel* get_squirrel() {
        return squirrel;
    }
};

void traverse_in_order(Node* root) {
    if (root == nullptr) return;

    traverse_in_order(root->left());
  
    cout << root->get_squirrel()->get_name() << "\n";

    traverse_in_order(root->right());
}

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);  
    node_one.set_right(&node_three); 

    cout << "Left child of " << node_one.get_squirrel()->get_name() << ": " 
         << node_one.left()->get_squirrel()->get_name() << "\n";
    cout << "Right child of " << node_one.get_squirrel()->get_name() << ": " 
         << node_one.right()->get_squirrel()->get_name() << "\n";

    cout << "\nIn-order traversal of the tree:\n";
    traverse_in_order(&node_one);

    return 0;
}
