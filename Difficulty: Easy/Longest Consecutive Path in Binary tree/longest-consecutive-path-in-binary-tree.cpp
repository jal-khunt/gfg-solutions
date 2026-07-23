/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  
    void dfs(Node* node, int current_length, int expected_value, int &max_length){
        if(node == nullptr) return;
        
        if(node->data == expected_value){
            current_length++;
        }
        else{
            current_length = 1;
        }
        
        max_length = max(max_length, current_length);
        
        dfs(node->left, current_length, node->data + 1, max_length);
        dfs(node->right, current_length, node->data + 1, max_length);
    }
  
    int longestConsecutive(Node* root) {
        // code here
        if(!root) return -1;
        
        int max_length = 0;
        
        dfs(root, 0, root->data, max_length);
        
        return max_length > 1 ? max_length : -1;
    }
};