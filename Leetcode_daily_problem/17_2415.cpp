/**
 * Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 
 */

// ------------ BFS
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;  // Return null if the tree is empty.
        }

        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node.
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentLevelNodes;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;  // Return the modified tree root.
    }
};