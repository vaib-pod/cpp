// 543. Diameter of binary tree

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
    int diam = 0;
    int calculateHeight(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int count1 = calculateHeight(node->left);
        int count2 = calculateHeight(node->right);

        diam=max(diam,count1+count2);

        return 1+ max(count2,count1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        calculateHeight(root);
        return diam;
    }
};
