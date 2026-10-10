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

class Codec {
public:

    // Encodes a tree to a single string.
    //use dfs and string pre-order
    void dfs(TreeNode* curr, std::string& res){
        if(!curr){
            res += "n,";
            return;
        }
        res = res + std::to_string(curr->val) +",";
        dfs(curr->left, res);
        dfs(curr->right, res);
    }
    string serialize(TreeNode* root) {
        if(!root) return {};
        std::string res{};

        dfs(root, res);
        return res;
    }
    TreeNode* dfsMakeNode(const std::string& data, int& commaIdx ){
        //process the string data first
        auto i = data.find(',', commaIdx);
        if( i!= string::npos ){
            string num = data.substr(commaIdx, i - commaIdx);
            //advance
            commaIdx = i +1;

            if(num.compare("n") == 0) {
                return nullptr;
            }
            else{
                auto curr =new TreeNode(std::stoi(num));
                curr->left = dfsMakeNode(data, commaIdx);
                curr->right = dfsMakeNode(data, commaIdx);
                return curr;
            }
        } 
        else{
            return nullptr;
        }
        return nullptr;


    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if(data.size()==0) return nullptr;

        
        TreeNode* root = nullptr;
        int start =0;
        root = dfsMakeNode(data, start);
        return root;

    }
};
