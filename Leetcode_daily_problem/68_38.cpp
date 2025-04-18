/**
 * The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
 */
// 1st - Brute force
class Solution {
    public:
        string countAndSay(int n) {
            string res = "1";
            for (int i = 1; i < n; i++) {
                string temp = "";
                int count = 1;
                for (int j = 1; j < res.size(); j++) {
                    if (res[j] == res[j - 1]) {
                        count++;
                    } else {
                        temp += to_string(count) + res[j - 1];
                        count = 1;
                    }
                }
                temp += to_string(count) + res.back();
                res = temp;
            }
            return res;
        }
    };


    // 2nd - recursion
    class Solution {
        public:
            string countAndSay(int n) {
                if (n == 1) return "1";
        
                string prev = countAndSay(n - 1);
                string res = "";
                int i = 0;
        
                while (i < prev.size()) {
                    int count = 1;
                    while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                        i++;
                        count++;
                    }
                    res += to_string(count) + prev[i];
                    i++;
                }
        
                return res;
            }
        };
        ---
        
        ```javascript []
        var countAndSay = function(n) {
            if (n === 1) return "1";
        
            const prev = countAndSay(n - 1);
            let res = "", i = 0;
        
            while (i < prev.length) {
                let count = 1;
                while (i + 1 < prev.length && prev[i] === prev[i + 1]) {
                    i++;
                    count++;
                }
                res += count + prev[i];
                i++;
            }
        
            return res;
        };