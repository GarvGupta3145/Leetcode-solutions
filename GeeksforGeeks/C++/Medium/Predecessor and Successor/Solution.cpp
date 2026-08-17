/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node*pre=NULL;
        Node*succ=NULL;
        while(root){
            if(root->data==key){
                if(root->left){
                    pre=root->left;
                    Node*curr=pre;
                    while(curr->right){
                        curr=curr->right;
                    }
                    pre=curr;
                }
                if(root->right){
                    succ=root->right;
                    Node*curr=succ;
                    while(curr->left){
                        curr=curr->left;
                    }
                    succ=curr;
                }
                break;
            }
            else{
                if(root->data > key){
                    succ= succ && (succ->data<root->data)? succ:root;
                    root=root->left;
                }
                else{
                    pre=pre && (pre->data>root->data)?pre:root;
                    root=root->right;
                }
            }
        }
        vector<Node*>ans;
        ans.push_back(pre);
        ans.push_back(succ);
        return ans;
    }
};