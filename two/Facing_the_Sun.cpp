#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int t;
    cin >> t;

    while(--t){
        vector<int> height;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        if(ss >> number){
            height.push_back(number);
        }

        Solution obj;
        int ans = obj.countBuildings(height);
        cout<<ans<<endl;

    }

    return 0;
}