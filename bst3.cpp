//98. validate binary search tree

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
    bool valid(TreeNode* temp, long min_val, long max_val){
        if(temp==NULL){
            return true;;
        }
        if(temp->val <= min_val || temp->val >=max_val){
            return false;
        }

        return (valid(temp->right, temp->val , max_val) && valid(temp->left,min_val,temp->val));
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN,LONG_MAX);
    }
};
