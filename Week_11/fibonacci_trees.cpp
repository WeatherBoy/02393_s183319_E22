#include <iostream>
using namespace std;

// Global variables because then I don't have to make
// a tree structure.
// It is lazy I know... yes.
bool max_depth_reached = false;
int max_depth = 0;
int leaf_nodes = 0;
int calls = 0;

// Basic structure for a binary tree structure
struct Node {
    int val;            // Contains the value
    Node *parent;       // pointer to the parent Node
    Node *left_child;   // Pointer to the left child
    Node *right_child;  // Pointer to the right child
};

int fibonacci_tree(int n, Node *curr_node) {
    cout << "We reach fibonacci_tree" << endl;

    // simple recursive function for calculating the fibonacci sequence.
    //
    // Everytime we go into this function, then we have done an
    // extra call.
    calls++;

    if (!max_depth_reached) {
        // If we haven't reached max depth yet, well
        // then it is one deeper. 
        max_depth++;

    }
    
    if (n == 1 || n == 0) {
        // Because of the structure of this program, then first time
        // we reach either n == 1 or n == 0, we have reached
        // the maximum depth of our "call tree".
        max_depth_reached = true;

        // Everytime we reach either n == 1 or n == 0, we have
        // reached a leaf node in our "call tree".
        leaf_nodes++;

        // Additionally we must show that we have reached a leaf Node
        // and leaf Nodes are defined by not having children.
        // Therefore its children shall be nullptrs.
        curr_node->left_child = nullptr;
        curr_node->right_child = nullptr;

        return 1;

    } else if (n < 0) {
        // This should also be defined in this edge-case.
        curr_node->left_child = nullptr;
        curr_node->right_child = nullptr;

        // I think it was a mistake, that the catch of this
        // edge-case wasn't there on my first implementation.
        return 0;

    }
    
    // Creating Nodes which are supposed to function as the children
    // of the node we just parsed.
    // I have defined it such that their parent is the current Node.
    Node *left_child{};
    left_child->parent = curr_node;
    Node *right_child{};
    right_child->parent = curr_node;
    

    left_child->val = fibonacci_tree(n - 1, left_child);
    right_child->val = fibonacci_tree(n - 2, right_child);

    curr_node->left_child = left_child;
    curr_node->right_child = right_child;

    return left_child->val + right_child->val;
}

void callTreePreOrder(Node curr_node) {
    cout << "We reach callTreePreOrder" << endl;

    // Here it doesn't make as much sense to take a pointer as
    // input, since we do not change the values of the Node.
    cout << curr_node.val << " ";
    if (curr_node.left_child != nullptr) {
        // First we go down the left nodes.
        //
        // Dereferencing the pointer, such that it can be a
        // valid input for this function which no longer takes
        // a pointer.
        callTreePreOrder(*curr_node.left_child);

    }
    if (curr_node.right_child != nullptr) {
        // Secondly we go down the right Nodes.
        //
        // Dereferencing here as well.
        callTreePreOrder(*curr_node.right_child);

    }

    // If both children are nullptr, then we have reached
    // a leaf Node and can rightfully return.
    return;
}


int main() {
    cout << "We at least start the script..." << endl;
    // A temporary value for the input
    int temp_value{};

    // Maybe this is a bit hack aswell.
    cout << "We define an int?" << endl;
    Node *root;
    cout << "We define the root Node pointer" << endl;
    root->parent = nullptr;
    cout << "We make its parent a nullptr" << endl;

    cout << "We try to take in a value" << endl;
    cin >> temp_value;
    cout << "We get the value! Hurray. Success!" << endl;

    cout << "We get this far!!" << endl;
    root->val = fibonacci_tree(temp_value, root);

    

    cout << "Call tree in pre-order: ";
    callTreePreOrder(*root);
    cout << "\nCall tree size: " << calls;
    cout << "\nCall tree depth: " << max_depth;
    cout << "\nCall tree leafs: " << leaf_nodes;

    return 0;
}