/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(vector<int>& preorder,unordered_map<int,int>& idxCount, int& idx, int start, int end){
        if(start > end) return NULL;

        int rootVal = preorder[idx];
        TreeNode* root = new TreeNode(rootVal);

        idx++;
        root->left = solve(preorder,idxCount,idx,start,idxCount[rootVal] - 1);
        root->right = solve(preorder, idxCount,idx,idxCount[rootVal] + 1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        unordered_map<int,int> idxCount;

        for(int i = 0; i < inorder.size(); i++){
            idxCount[inorder[i]] = i;
        }

        return solve(preorder,idxCount,idx,0,preorder.size() - 1);
    }
};
