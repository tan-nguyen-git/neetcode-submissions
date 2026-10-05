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
    void dfs(TreeNode* curr, int& res, int currMax){
        if(curr == nullptr) return;
        if(curr->val >= currMax){
            res++;
        }
        cout<<curr->val <<endl;
        currMax = max(curr->val, currMax);
        dfs(curr->left, res, currMax  );
        dfs(curr->right, res, currMax );



    }

    int goodNodes(TreeNode* root) {
        //root count too...
        int res =0;
        int currMax = root -> val ;
        dfs(root, res, currMax);

        return res;
        
    }
};
