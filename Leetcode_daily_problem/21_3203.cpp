/**
 * 3203
 * There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. 
 * You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and 
 * edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.
 */

class Solution {
public:
    int diameterOfTree1 = 0;
    int diameterOfTree2 = 0;

    int findDiameter(int src, unordered_map<int,vector<int>> &adj, int totalNodes, int treeNo){
        queue<int> q;
        vector<int> vis(totalNodes, 0);
        q.push(src);
        vis[src] = 1;

        int farthestNode = src;
        int diameter = -1;
        
        while(!q.empty()){
            int size = q.size();
            diameter++;
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                farthestNode = node;
                for(auto &nbr : adj[node]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr] = 1;
                    }
                }
            }
        }
        if(treeNo == 1) diameterOfTree1 = diameter;
        else if(treeNo == 2) diameterOfTree2 = diameter;

        return farthestNode;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        unordered_map<int,vector<int>> adj1;
        for(auto &it : edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        int m = edges2.size();
        unordered_map<int,vector<int>> adj2;
        for(auto &it : edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        // finding out one of the diameter node of tree 1
        int anyDiameterNode1 = findDiameter(0, adj1, n+1, -1);
        // to find the diameter of tree 1
        findDiameter(anyDiameterNode1, adj1, n+1, 1);


        // finding out one of the diameter node of tree 2
        int anyDiameterNode2 = findDiameter(0, adj2, m+1, -1);
        // to find the diameter of tree 2
        findDiameter(anyDiameterNode2, adj2, m+1, 2);

        int result = (diameterOfTree1 + 1) / 2 + (diameterOfTree2 + 1) / 2 + 1; // 1 for extra edge to join tree1 and tree2

        // edege cases
        // if the diameter lies itself in tree1 or tree2
        if(diameterOfTree1 > result || diameterOfTree2 > result){
            return max(diameterOfTree1, diameterOfTree2);
        }

        return result;
    }
};