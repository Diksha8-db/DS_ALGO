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
    pair<int,int> calcDia(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> leftPart = calcDia(root->left);
        pair<int,int> rightPart = calcDia(root->right);

        pair<int,int> ans;
        ans.first = max(leftPart.first,rightPart.first) + 1; // calculate height
        ans.second = max({leftPart.second,rightPart.second,leftPart.first+rightPart.first+1});
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> diameter = calcDia(root); // height, diameter
        return diameter.second - 1;
    }
};
