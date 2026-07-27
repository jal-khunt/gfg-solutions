/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    Node* buildTree(vector<int> &pre, vector<int> &preMirror, int &preIndex, unordered_map<int,int> &hashMirror,
    int l, int h){
        
        if(l > h || preIndex >= preMirror.size())
            return nullptr;
        
        Node *root = new Node(pre[preIndex++]);
        
        if(l == h)
            return root;
            
        int leftChild = pre[preIndex];
        
        int mid = hashMirror[leftChild];
        
        root->left = buildTree(pre, preMirror, preIndex, hashMirror, mid, h);
        root->right = buildTree(pre, preMirror, preIndex, hashMirror, l+1, mid-1);
        
        return root;
    }
  
    Node* helper(vector<int> &pre, vector<int> &preMirror){
        if(pre.size() == 0)
            return  nullptr;
            
        unordered_map<int,int> hashMirror;
        for(int i = 0; i < preMirror.size(); i++){
            hashMirror[preMirror[i]] = i;
        }
        int preIndex = 0;
        return buildTree(pre, preMirror, preIndex, hashMirror, 0, preMirror.size()-1);
    }
  
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        Node* root = helper(pre, preMirror);
        
        return root;
    }
};