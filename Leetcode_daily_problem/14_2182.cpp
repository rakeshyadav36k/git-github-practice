/**
 * You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s 
 * such that no letter appears more than repeatLimit times in a row. 
 * You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, 
string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, 
then the longer string is the lexicographically larger one.
 */

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());

        string result;
        int freq = 1;
        int pointer = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (!result.empty() && result.back() == s[i]) {
                if (freq < repeatLimit) {
                    result += s[i];
                    freq++;
                } else {
                    pointer = max(pointer, i + 1);
                    while (pointer < s.size() && s[pointer] == s[i]) {
                        pointer++;
                    }

                    if (pointer < s.size()) {
                        result += s[pointer];
                        swap(s[i], s[pointer]);
                        freq = 1;
                    } else {
                        break;
                    }
                }
            } else {
                result += s[i];
                freq = 1;
            }
        }

        return result;                                                           
    }
};


/// using priority queue
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> vec(26, 0);
        for(auto &ch : s){
            vec[ch - 'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++){
            if(vec[i] > 0){
                pq.push(i + 'a');
            }
        }

        string result = "";
        while(!pq.empty()){
            char topChar = pq.top();
            pq.pop();


            int freq = vec[topChar - 'a'];
            freq = min(freq, repeatLimit);

            result.append(freq, topChar);
            vec[topChar - 'a'] -= freq;

            if(!pq.empty()){
                char secChar = pq.top();
                pq.pop();

                if(vec[topChar - 'a'] > 0){
                    result += secChar;
                    vec[secChar - 'a']--;
                }

                if(vec[topChar - 'a'] > 0) pq.push(topChar);
                if(vec[secChar - 'a'] > 0) pq.push(secChar);
            }
            else{
                break;
            }


        }

        return result;
    }
};