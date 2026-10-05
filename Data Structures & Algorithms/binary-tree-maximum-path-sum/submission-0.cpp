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
    //parent only choose 1 path left or right
public:
    int currMax = INT_MIN;
    int dfs(TreeNode* curr){
        if(curr == nullptr) return 0 ;

        int l = dfs(curr->left);
        int r= dfs(curr->right);
        
        auto leftContributed = max(0,l);
        auto rightContributed = max(0,r);


        int includeCurr = curr->val + leftContributed + rightContributed;
        currMax = max(currMax, includeCurr);

       
        
        //only return to parent 1 path
        return curr->val + max(leftContributed, rightContributed);




    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return currMax;
    }
};
