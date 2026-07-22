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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        if (root == nullptr) {
            return new TreeNode(val);
        }
        while(true){
            if(val<temp->val){
                if(temp->left == NULL){ 
                    temp->left =  new TreeNode(val);
                    break; 
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){ 
                    temp->right =  new TreeNode(val);
                    break; 
                }
                else{
                    temp = temp->right;
                }
            }
        }
        
        return root;
    }
};