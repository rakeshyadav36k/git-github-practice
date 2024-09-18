#include<bits/stdc++.h>
using namespace std;


bool cmp(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);

    // custom comparison to check which concatenation is larger
    if((sa + sb) > (sb + sa))
        return true;

    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort using the custom comparator
        sort(nums.begin(), nums.end(), cmp);

        // if the largest number after sorting is '0', the result is "0"
        if(nums[0] == 0)
            return "0";

        string ans = "";
        for(int num : nums){
            ans += to_string(num);
        }

        return ans;
    }
};


int main(){

    Solution obj;
    string s;
    cin >> s;

    cout<< "Largest Number is " << obj.largestNumber(s); 

    return 0;
}