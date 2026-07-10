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
    int countOfGoodNodes(TreeNode* node, int maxVal){
        if(node == NULL){
            return 0;
        }

        int countIsGood = ((node->val >= maxVal) ? 1 : 0);
        int newMaxVal = max(maxVal, node->val);

        int leftCount = countOfGoodNodes(node->left,max(newMaxVal,node->val));
        int rightCount = countOfGoodNodes(node->right,max(newMaxVal,node->val));
        return countIsGood + leftCount + rightCount;
    }
    int goodNodes(TreeNode* root) {
        return countOfGoodNodes(root,root->val);
    }
};
