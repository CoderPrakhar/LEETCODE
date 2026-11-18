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
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        
        int lh = findLeftHeight(root); //Yahan tum root ke left aur right child se height calculate kar rahe ho.

        //Lekin humein current root se hi leftmost aur rightmost height calculate karni hai.
        int rh = findRightHeight(root);

        if(lh == rh) return (1<<lh) -1; //2H -1

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }

    int findRightHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
};