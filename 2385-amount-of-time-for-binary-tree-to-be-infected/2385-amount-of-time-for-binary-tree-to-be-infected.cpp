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
    int findMaxDistance(map<TreeNode*, TreeNode*> &mp, TreeNode* target){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode* , int>vis;

        vis[target]=1;
        int maxi=0;
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            for(int i=0; i<n; i++){
                auto node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    flag = true;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    flag = true;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(mp[node] && !vis[mp[node]]){
                    flag = true;
                    vis[mp[node]] =1;
                    q.push(mp[node]);
                }

            }
            
                if(flag) maxi++;
        
        }
        return maxi;
    } 

    TreeNode* bfsToMapParent(TreeNode* root, map<TreeNode* ,TreeNode*> &mp, int start){
        queue<TreeNode* >q;
        q.push(root);
        TreeNode* res;

        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == start){
                res = node;
            }
            q.pop();

            if(node->left!=NULL){
                mp[node->left] = node;
                q.push(node->left);
            }

            if(node->right!=NULL){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode* >mp;
        TreeNode* target = bfsToMapParent(root, mp, start);

        int maxi = findMaxDistance( mp, target);
        return maxi;
    }
};