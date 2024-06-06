//Problem Statement: Given the root of a Binary Tree, return the height of the tree. The height of the tree is equal to the number of nodes on the longest path from root to a leaf.
/*
Algorithm / Intuition
To find the maximum depth of the binary tree using level order traversal, we employ a breadth-first approach. Initialise a queue and push the root node. Traverse through the levels and track the depth by counting the number of levels traversed. At each level pop the nodes and push their left and right children, incrementing the depth counter as we explore.This process continues until all levels are traversed at which point the depth variable holds the maximum depth of the tree.

Algorithm:

Step 1: Initialise a queue for level order traversal and a variable `level` to track the depth.Check if the root is null, if so return the answer as 0 indicating an empty tree.
Step 2: Insert the root of the Binary Tree into the queue and set the level as 0.
Step 3: Begin a loop that continues until the queue becomes empty where at each level:
Increment `level` by 1, indicating we are moving to the next level.
Determine the number of nodes at the current level by storing the size of the queue.
Iterate over the number of nodes equal to the size of the queue and at each node, Pop it from front of the queue and push its left and right children (if they exist).
Step 4: After the queue loop gets over, return the `level` variable representing the maximum depth of the tree calculated during the level order traversal.

*/

                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find the
    // maximum depth of a binary tree
    int maxDepth(Node* root){
        // If the root is NULL
        // (empty tree), depth is 0
        if(root == NULL){
            return 0;
        }
        
        // Recursive call to find the
        // maximum depth of the left subtree
        int lh = maxDepth(root->left);
        
        // Recursive call to find the
        // maximum depth of the right subtree
        int rh = maxDepth(root->right);
        
        // Return the maximum depth of the
        // tree, adding 1 for the current node
        return 1 + max(lh, rh);
    }
};




// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. 
This complexity arises from visiting each node exactly once during the traversal to determine the maximum depth.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree because in the worst case scenario the tree is balanced and has N/2 nodes in its last level which will have to be stored in the queue.
*/                           
                        