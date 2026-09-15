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
    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* curr = root;
        
        int pVal = p->val;
        int qVal = q->val;
        if(pVal > qVal) {
            swap(p,q);
            swap(pVal,qVal);
        }
        
        while(curr){
            int currVal = curr->val;
            if(currVal == pVal){
                return p;
            }
            else if(currVal == qVal){
                return q;
            }
            else if(currVal >pVal && currVal <qVal){
                return curr;

            }
            else if(currVal <pVal ){
                curr=curr->right;
            }
            else if(currVal > qVal){
                curr=curr->left;
            }
        }
        
        return curr;





    }
};
