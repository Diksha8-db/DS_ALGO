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
    int findSmallest(TreeNode* root, int& idx, int k){
        // if idx == k return root->val
        if(root == NULL) return -1;

        int fromLeft = findSmallest(root->left,idx,k);
        if(fromLeft != -1) return fromLeft;

        idx++;
        if(idx == k) return root->val;

        return findSmallest(root->right,idx,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        return findSmallest(root,idx,k);
    }
};
