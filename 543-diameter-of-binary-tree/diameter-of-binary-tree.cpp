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
    private:
    int solve(TreeNode* root,int& diameter){
        if(root==NULL){
            return 0;
        }

        int left=solve(root->left,diameter);
        int right=solve(root->right,diameter);

        int height=max(left,right)+1;

        diameter=max(diameter,left+right);

        return height;
    }

    
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter=0;
       solve(root,diameter);

       return diameter;

    }
};