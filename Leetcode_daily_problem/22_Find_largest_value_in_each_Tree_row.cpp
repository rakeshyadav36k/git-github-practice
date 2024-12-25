/**
 * 515
 * Given the root of a binary tree, 
 * return an array of the largest value in each row of the tree (0-indexed).
 */

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


 // ------------------using BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front()->val;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                temp = max(temp, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// using dfs

class Solution {
public:
    vector<int> ans;
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
        
        if (depth == ans.size()) {
            ans.push_back(node->val);
        } else {
            ans[depth] = max(ans[depth], node->val);
        }
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};