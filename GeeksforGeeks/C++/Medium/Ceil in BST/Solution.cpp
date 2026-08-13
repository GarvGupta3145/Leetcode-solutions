/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        if(!root)return -1;
        if(!root->left && root->data > x)return root->data;
        if(root->data == x)return root->data;
        if(root->data < x) return findCeil(root->right,x);
        else if(root->data > x) {
            int find=findCeil(root->left,x);
            if(find==-1)return root->data;
            return find;
        }
        return -1;
    }
};
