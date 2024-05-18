/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> current, next;
        if (root == nullptr)
            return root;
        else
            current.push(root);
        
        while (!current.empty()) {
            
            Node* fir = nullptr;
            
            while (!current.empty()) {
                Node* node = current.front();
                current.pop();
                
                if (fir != nullptr)
                    fir->next = node;
                
                fir = node;

                if (node->left != nullptr) next.push(node->left);
                if (node->right != nullptr) next.push(node->right);
            }

            swap(next, current);
        }
        return root; 
    }
};
