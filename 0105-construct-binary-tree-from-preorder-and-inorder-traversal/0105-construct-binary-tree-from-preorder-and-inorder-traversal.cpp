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
    TreeNode* buildTree(vector<int>&preorder, int preSTART, int preEND,
                        vector<int>&inorder , int inSTART , int inEND, map<int, int>&mp){
                        
                        if(preSTART>preEND || inSTART>inEND) return NULL;

                        TreeNode* root = new TreeNode(preorder[preSTART]);

                        int inROOT = mp[root->val];
                        int numsLeft = inROOT - inSTART;

                        root->left = buildTree(preorder, preSTART+1, preSTART+numsLeft, inorder, inSTART, inROOT-1,mp);

                        root->right = buildTree(preorder, preSTART+numsLeft+1, preEND, inorder, inROOT+1, inEND, mp);

                        return root;
                        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mp;

        for(int i=0; i<inorder.size() ; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = buildTree( preorder, 0 , preorder.size()-1, 
                                   inorder, 0, inorder.size()-1 , mp );
        return root;
    }
};