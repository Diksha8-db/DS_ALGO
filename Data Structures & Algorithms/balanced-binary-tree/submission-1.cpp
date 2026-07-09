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
    pair<int,bool> findBalanced(TreeNode* root){
        if(root == NULL){
            // already balanced
            return {0,true};
        }

        pair<int,bool> leftPart = findBalanced(root->left);
        pair<int,bool> rightPart = findBalanced(root->right);

        pair<int,bool> ans;
        ans.first = max(leftPart.first,rightPart.first) + 1;
        ans.second = (((abs(leftPart.first - rightPart.first) > 1) ? false : true) && (leftPart.second && rightPart.second));
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans = findBalanced(root);
        return ans.second;
    }
};
