class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int ans = 1;  // 1 for the leftmost building
        
        int leftMaxHeight = height[0];
        
        for(int i = 1; i < height.size(); i++){
            if(height[i] > leftMaxHeight){
                ans++;
                leftMaxHeight = height[i];
            }
        }
        
        return ans;
    }
};