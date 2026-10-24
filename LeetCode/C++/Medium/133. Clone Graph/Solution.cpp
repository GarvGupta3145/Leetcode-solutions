/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*>mpp;
        Node* rcopy = new Node(node->val);
        mpp[node]=rcopy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* n=q.front();
            q.pop();
            if(mpp.count(node)){
                for (Node* nbr : n->neighbors) {
                    if(!mpp.count(nbr)){
                        Node* copy = new Node(nbr->val);
                        mpp[nbr]=copy;
                        q.push(nbr);
                    }
                    mpp[n]->neighbors.push_back(mpp[nbr]); 
                }
            }
        }
        return mpp[node];
    }
};