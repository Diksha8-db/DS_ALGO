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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(!p || !q) return false;

        bool leftPart = isSameTree(p->left,q->left);
        bool rightPart = isSameTree(p->right,q->right);

        return (leftPart && rightPart && (p->val == q->val));
    }
    bool traverse(TreeNode* root, TreeNode* subRoot){
        if(root == NULL) return false;

        if(isSameTree(root,subRoot)) return true;
        return traverse(root->left,subRoot) || traverse(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        return traverse(root,subRoot);
    }
};
