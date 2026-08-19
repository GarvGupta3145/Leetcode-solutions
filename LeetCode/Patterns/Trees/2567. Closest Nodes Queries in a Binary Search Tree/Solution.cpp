class Solution {
public:
    // Inorder traversal of a BST visits values in ascending order —
    // gives us a sorted array to binary search over. O(n).
    void ans(TreeNode*root,vector<int>&inorder){
        if(!root)return;
        ans(root->left,inorder);
        inorder.push_back(root->val);
        ans(root->right,inorder);
    }

    // Standard binary search. Returns the index of an exact match if
    // found. If not found, returns the index of the last position
    // checked before low/high crossed — this ends up being adjacent
    // to where `num` would be inserted, which is what we need to find
    // the closest smaller/larger neighbors.
    int binary(vector<int>& inorder,int num){
        int low=0;
        int high=inorder.size()-1;
        int mid=-1;
        while(low<=high){
            mid=low+(high-low)/2;   // assign to outer mid, don't shadow it
            if(inorder[mid]>num){
                high=mid-1;
            }
            else if(inorder[mid]<num)low=mid+1;
            else return mid;
        }
        return mid;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>inorder;
        vector<vector<int>>res(queries.size(),vector<int>(2, -1));
        ans(root,inorder);
        int n=inorder.size();

        for(int i=0;i<queries.size();i++){
            int mid=binary(inorder,queries[i]);

            if(inorder[mid]!=queries[i]){
                // No exact match — mid landed on the closest value on
                // one side. Scan past any duplicates of inorder[mid],
                // then read the next distinct value for the other side.
                if(inorder[mid]<queries[i]){
                    // mid is the floor (closest ≤ query). Find ceiling
                    // by scanning forward past equal values.
                    res[i][0]=inorder[mid];
                    int k=mid;
                    while(k<n && inorder[k]==inorder[mid]){
                        k++;
                    }
                    res[i][1] = (k==n) ? -1 : inorder[k];
                }
                else{
                    // mid is the ceiling (closest ≥ query). Find floor
                    // by scanning backward past equal values.
                    res[i][1]=inorder[mid];
                    int k=mid;
                    while(k>=0 && inorder[k]==inorder[mid]){
                        k--;
                    }
                    res[i][0] = (k<0) ? -1 : inorder[k];
                }
            }
            else{
                // Exact match: query itself is both the floor and ceiling.
                res[i][0]=inorder[mid];
                res[i][1]=inorder[mid];
            }
        }
        return res;
    }
};