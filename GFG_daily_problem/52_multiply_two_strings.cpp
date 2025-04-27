/**
 * Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.
 */

 class Solution{
    public:
      /*You are required to complete below function */
      string multiplyStrings(string str1, string str2) {
          // case if any string have '-' sign
          string s1 = str1 , s2 = str2;
          if (str1[0] == '-' && str2[0] != '-') {
              s1 = str1.substr(1);
          }
          else if (str1[0] != '-' && str2[0] == '-') {
              s2 = str2.substr(1);
          }
          else if (str1[0] == '-' && str2[0] == '-') {
              s1 = str1.substr(1);
              s2 = str2.substr(1);
          }
          
          // convert string s1 into a vector of integers
          int n = s1.size();
          vector<int> num1(n);
          for(int i = 0;i < n;i++){
             num1[i] = s1[n - i -1] - '0';
          }
          // convert string s2 into a vector of integers
          int m = s2.size();
          vector<int> num2(m);
          for(int i = 0;i < m;i++){
             num2[i] = s2[m - i -1] - '0';
          }
      
          vector<int> res(m + n,0); // store the integers of product at appropriate position
          
          for(int i = 0;i < n;i++){
              int carry = 0;
              for(int j = 0;j < m;j++){
                  int product = num1[i]*num2[j] + carry + res[i+j];
                  carry = product / 10;
                  res[i+j] = product % 10;
              }
              res[i + m] = carry;
          }
          // remove the leading zeros
          while(res.size() > 1 && res.back() == 0){
              res.pop_back();
          }
          // store the res into string
          string ans(res.size(),'0');
          
          for(int i = 0;i < res.size();i++){
              ans[res.size() - i - 1] = res[i] + '0';
          }
          
          // Check condition if one string is negative
          if (str1[0] == '-' && str2[0] != '-') {
              ans = "-" + ans;
          }
          else if (str1[0] != '-' && str2[0] == '-') {
              ans = "-" + ans;
          }
          
          return ans;
      }
  
  };