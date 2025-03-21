/**
 * You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.
 */

 class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes,
                                      vector<vector<string>>& ingredients,
                                      vector<string>& supplies) {
            // Track available ingredients and recipes
            unordered_set<string> available(supplies.begin(), supplies.end());
    
            // Queue to process recipe indices
            queue<int> recipeQueue;
            for (int idx = 0; idx < recipes.size(); ++idx) {
                recipeQueue.push(idx);
            }
    
            vector<string> createdRecipes;
            int lastSize = -1;
    
            // Continue while we keep finding new recipes
            while (static_cast<int>(available.size()) > lastSize) {
                lastSize = available.size();
                int queueSize = recipeQueue.size();
    
                // Process all recipes in current queue
                while (queueSize-- > 0) {
                    int recipeIdx = recipeQueue.front();
                    recipeQueue.pop();
                    bool canCreate = true;
    
                    // Check if all ingredients are available
                    for (string& ingredient : ingredients[recipeIdx]) {
                        if (!available.count(ingredient)) {
                            canCreate = false;
                            break;
                        }
                    }
    
                    if (!canCreate) {
                        recipeQueue.push(recipeIdx);
                    } else {
                        // Recipe can be created - add to available items
                        available.insert(recipes[recipeIdx]);
                        createdRecipes.push_back(recipes[recipeIdx]);
                    }
                }
            }
    
            return createdRecipes;
        }
    };