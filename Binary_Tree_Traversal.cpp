//Traversals in hierarchical data structures like Binary Trees can be broadly classified into two categories: Depth-First Search (DFS) and Breadth-First Search (BFS). 
// Each of them utilises a different strategy to visit the nodes within the tree.
/*
Depth-First Search (DFS) explores a binary tree by going as deeply as possible along each branch before backtracking.

It starts from the root and explores as deeply as possible along each branch, visiting nodes until it reaches a leaf node. 
It then backtracks to the most recent unexplored node and continues until all nodes are visited.
The order in which we visit a node determines if that traversal would be preorder, inorder and postorder.
DFS uses recursion or a stack to traverse deeper levels of the tree before visiting nodes at the same level.
Breadth-First Search (BFS) explores a binary tree level by level, visiting all nodes at a given level before processing to the next level.
It starts from the root and visits all nodes at level 0, then proceeds to level 1, level 2, and so on. Nodes at a level are visited from left to right.
BFS uses a queue data structure to maintain nodes at each level, ensuring that nodes at higher levels are visited moving to lower levels.


Inorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Root, Right.
It's named "inorder" because it traverses the nodes in a sequence where the "Visit" step occurs between the left and right child nodes.
Procedure of Inorder Traversal:
Visit the Left Subtree: Recursively traverse the left subtree until a leaf node or a node with no left child is reached.
Visit the Current Node: Once at a node, perform the visitation operation (such as printing the node's value or performing an operation with the node's data).
Traverse the Right Subtree: After visiting the current node, recursively traverse the right subtree, following the same steps as the left subtree.

Preorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Root, Left then Right.
It's named "preorder" because the "Visit" step occurs before traversing the left and right child nodes.
Procedure of Preorder Traversal:
Visit the Current Node: Begin by visiting the current node, performing the visitation operation (such as printing the node's value or performing an operation with the node's data).
Traverse the Left Subtree: Recursively traverse the left subtree, following the same steps starting from step 1.
Traverse the Right Subtree: After fully traversing the left subtree, recursively traverse the right subtree, following the same steps starting from step 1.

Postorder Traversal is the type of Depth First Traversal where nodes are visited in the order: Left, Right then Root.
It's named "postorder" because the "Visit" step occurs after traversing the left and right child nodes.
Procedure of Postorder Traversal:
Traverse the Left Subtree: Recursively traverse the left subtree, following the same steps starting from step 1.
Traverse the Right Subtree: Similarly, recursively traverse the right subtree, following the same steps starting from step 1.
Visit the Current Node: After fully traversing both left and right subtrees, visit the current node, performing the visitation operation (such as printing the node's value or performing an operation with the node's data).

*/

/*
Order of Visitation:

Inorder: Left, Visit, Right
Visits nodes in ascending order in a BST, accessing left children before the parent and then the right children.

Preorder: Visit, Left, Right
Starts with the root node, visits the current node before its children, then moves to left and right children.

Postorder: Left, Right, Visit
Visits the children nodes before the parent node, exploring left and right subtrees before visiting the current node.
*/

/*
Level Order Traversal is the type of Breadth First Traversal where nodes are visited level by level, exploring each level completely before moving to the next level.
Level order traversal utilises a queue data structure to maintain the nodes at each level, ensuring that nodes at higher levels are visited before moving to lower levels.
Procedure of Level Order Traversal:
Visit Nodes at Each Level: Starting from the root node, visit all nodes at level 0.
Move to Next Level: After visiting all nodes at level 0, move to level 1 and visit all nodes at this level from left to right.
Continue Level-wise: Repeat this process for subsequent levels, visiting nodes at each level from left to right until all levels are visited.
*/



//PREORDER TRAVERSAL :
/*
Algorithm / Intuition
Preorder traversal is one of the depth-first traversal methods used to explore nodes in a binary tree. 
The algorithm first visits the root node then in the preorder traversal, we visit (ie. add to the array) the current node by accessing its value then we recursively traverse the left subtree in the same manner. 
We repeat these steps for the left subtree then when we return to the current node, we recursively travel to the right subtree in a preorder manner as well.
The sequence of steps in preorder traversal follows: Root, Left, Right.

Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. 
Hence the recursive function stops and we return from that particular recursive call.
Recursive Function:
Process Current Node: The recursive function begins by processing ie. adding to the array or printing the current node.
Traverse Left Subtree: Recursively traverse the left subtree by invoking the preorder function on the left child of the current node. 
This step continues the exploration of nodes in a depth first manner.
Traverse Right Subtree: After traversing the entire left subtree,we traverse the right subtree recursively. 
We once again invoke the preorder function, but this time on the right child of the current node.



Algorithm : 
Step 1: Check for base case that if the current node is null, exit the void function.
Step 2: Push the value of the current node into the preorder traversal array.
Step 3: Invoke the preorder function on the left child then right child to traverse the left and right subtrees in the preorder manner respectively.


*/                            
#include <iostream>
#include <vector>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the left subtree
    preorder(root->left, arr);
    // Recursively traverse 
    // the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to
    // store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector
    // containing preorder traversal values
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.
*/


//INORDER TRAVERSAL 
/*
Algorithm / Intuition
Inorder traversal stands as one of the depth-first traversal techniques for navigating nodes in a binary tree. The method starts by exploring the left subtree recursively in the following order: left child, root node, right child. Initially, it traverses the left subtree until reaching the leftmost node. Upon reaching a null node, signifying the end of a subtree, the recursive process halts.
Then we visit the current node that had invoked the inorder on its left child. After visiting the current node we visit the right subtree in the inorder manner as well.
Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. Hence the recursive function stops and we return from that particular recursive call.

Recursive Function:
Traverse Left Subtree: Recursively traverse the left subtree by invoking the preorder function on the left child of the current node. 
This step continues the exploration of nodes in a depth first manner.
Process Current Node: The recursive function begins by processing ie. adding to the array or printing the current node.
Traverse Right Subtree: After traversing the entire left subtree,we traverse the right subtree recursively. 
We once again invoke the preorder function, but this time on the right child of the current node.

Algorithm:

Step 1: Check for base case that if the current node is null, return the void function.
Step 2: Invoke the inorder function on the left child to traverse the entire left subtree first.
Step 3: Push the value of the current node into the preorder traversal array.
Step 4: After visiting the current node, we invoke the inorder function on the right child to traverse the right subtree in the end.

*/
                                  
#include <iostream>
#include <vector>

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

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
Space Complexity: O(N) where N is the number of nodes in the binary tree. 
This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.
In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).
*/           

//POSTORDER TRAVERSAL 
/*
Postorder traversal, another depth-first method in tree exploration, follows a sequence where the algorithm first explores the left subtree, then the right subtree, and finally visits the root node. 
In postorder traversal, we visit (or add to the array) the current node after traversing both its left and right subtrees.
The sequence of steps in preorder traversal follows: Left, Right, Root.

Base Case: If the current node is null, it means we have reached the end of a subtree and there are no further nodes to explore. Hence the recursive function stops and we return from that particular recursive call.

Recursive Function:
Traverse Left Subtree: Explore the left subtree by recursively invoking the postorder function on the left child of the current node, ensuring a depth-first approach to node exploration.
Traverse Right Subtree: After fully traversing the left subtree, we move on to the right subtree, invoking the postorder function on the right child of the current node.
Process Current Node: After exploring the children of the current node, we process it by adding its value to the postorder traversal array.

Algorithm:

Step 1: Check for base case that if the current node is null, exit the void function.
Step 2: Traverse the left subtree using a recursive postorder call on the left child.
Step 3: Traverse the right subtree using a recursive postorder call on the right child.
Step 4: Add the value of the current node to the postorder traversal array.
This recursive approach implicitly uses the call stack to handle backtracking while exploring the tree nodes in a postorder manner.

*/

                            
#include <iostream>
#include <vector>

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

// Function to perform postorder
// traversal recursively
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root==NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node
    // (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder
// traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to
    // store the traversal result
    vector<int> arr;
    // Perform postorder traversal
    // starting from the root
    postorder(root, arr);
    // Return the postorder
    // traversal result
    return arr;
}

// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.
Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.
*/     

//LEVEL ORDER TRAVERSAL
/*
Algorithm / Intuition
To perform a level-order traversal on a binary tree and store the nodes’ values in a 2D vector representing each level, start by initialising an empty queue to hold the level by level nodes.Enqueue the root node into the queue and traverse until the queue is empty. For each level, track the number of nodes in that level, creating a temporary vector to deque and store them. At each node, store its value in the temporary vector and enqueue its left and right children if they exist.Once all the nodes at a level are processed add this 1D temporary vector to the final 2D vector, representing that level. This process repeats until all levels are traversed. Finally, return this 2D vector containing the level order traversal of the binary tree.

Algorithm:
Step 1: nitialise an empty queue data structure to store the nodes during traversal. 
Create a 2D array or a vector of a vector to store the level order traversal. If the tree is empty, return this empty 2D vector.
Step 2: Enqueue the root node ie. Add the root node of the binary tree to the queue.
Step 3:
Iterate until the queue is empty:
Get the current size of the queue. This size indicates the number of nodes at the current level.
Create a vector ‘level’ to store the nodes at the current level.
Iterate through ‘size’ number of nodes at the current level:
Pop the front node from the queue.
Store the node’s value in the level vector.
Enqueue the left and right child nodes of the current node (if they exist) into the queue.
After processing all the nodes at the current level, add the ‘level’ vector to the ‘ans’ 2D vector, representing the current level.

Step 4: Once the traversal loop completes ie. all levels have been processed, return the ‘ans’ 2D vector containing the level-order traversal.

*/
                            
#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

// TreeNode struct represents
// a node in a binary tree
struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;

    // Default constructor for TreeNode
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    // parameter for TreeNode
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left
    // child, and right child
    // parameters for TreeNode
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    // Function to perform level-order
    // traversal of a binary tree
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Create a 2D vector to store levels
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }
        
        // Create a queue to store nodes
        // for level-order traversal
        queue<TreeNode*> q; 
        // Push the root node to the queue
        q.push(root); 

        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store
            // nodes at the current level
            vector<int> level; 

            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                TreeNode* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node value
                // in the current level vector
                level.push_back(node->val); 

                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order
        // traversal of the tree
        return ans; 
    }
};

// Function to print
// the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the
    // vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance
    // of the Solution class
    Solution solution; 
    // Perform level-order traversal
    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) {
        printVector(level);
    }

    return 0;
}


/*
Time Complexity: O(N) where N is the number of nodes in the binary tree. 
Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. 
Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. 
In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).
The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.
*/
                        
                                                                
                        

