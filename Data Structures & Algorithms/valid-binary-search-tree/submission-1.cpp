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
   
    bool isValid(TreeNode* curr, int min , int max){
        if(curr == nullptr) return true;
        int currVal = curr->val;
        if(currVal >= max || currVal <= min) return false;

        return isValid(curr->left, min, curr->val)
            && isValid(curr->right, curr->val, max);



    }
    bool isValidBST(TreeNode* root) {
        return isValid(root->left, INT_MIN, root->val) 
            && isValid(root->right, root->val, INT_MAX);
    }
};
