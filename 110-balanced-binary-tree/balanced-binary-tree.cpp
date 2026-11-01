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
    pair<bool,int> solve(TreeNode*root){
        if(root==NULL){
            return {true,0};
        }
        pair<bool,int> left=solve(root->left);
        pair<bool,int> right=solve(root->right);

        bool leftBalanced=left.first;
        bool rightBalanced=right.first;

        int leftHeight=left.second;
        int rightHeight=right.second;

        bool condition=abs(leftHeight-rightHeight)<=1;

        pair<bool,int>ans;

        ans.second=max(leftHeight,rightHeight)+1;

        if(leftBalanced && rightBalanced && condition){
            ans.first=true;
        }
        else{
            ans.first=false;

        }

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
        
    }
};