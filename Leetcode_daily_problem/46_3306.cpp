/**
 * You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 */

 // 1st sliding window
 class Solution {
    private:
        bool isVowel(char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
    
    public:
        long countOfSubstrings(string word, int k) {
            long numValidSubstrings = 0;
            int start = 0;
            int end = 0;
            unordered_map<char, int> vowelCount;
            int consonantCount = 0;
    
            vector<int> nextConsonant(word.size());
            int nextConsonantIndex = word.size();
            for (int i = word.size() - 1; i >= 0; i--) {
                nextConsonant[i] = nextConsonantIndex;
                if (!isVowel(word[i])) {
                    nextConsonantIndex = i;
                }
            }
    
            while (end < word.size()) {
                char newLetter = word[end];
    
                if (isVowel(newLetter)) {
                    vowelCount[newLetter]++;
                } else {
                    consonantCount++;
                }
    
                while (consonantCount > k) {
                    char startLetter = word[start];
                    if (isVowel(startLetter)) {
                        vowelCount[startLetter]--;
                        if (vowelCount[startLetter] == 0) {
                            vowelCount.erase(startLetter);
                        }
                    } else {
                        consonantCount--;
                    }
                    start++;
                }
    
                while (start < word.size() && vowelCount.size() == 5 &&
                       consonantCount == k) {
                    numValidSubstrings += nextConsonant[end] - end;
                    char startLetter = word[start];
                    if (isVowel(startLetter)) {
                        vowelCount[startLetter]--;
                        if (vowelCount[startLetter] == 0) {
                            vowelCount.erase(startLetter);
                        }
                    } else {
                        consonantCount--;
                    }
    
                    start++;
                }
                end++;
            }
    
            return numValidSubstrings;
        }
    };


    // 2nd sliding window (relaxed constrained)
    class Solution {
        public:
            long countOfSubstrings(string word, int k) {
                return atLeastK(word, k) - atLeastK(word, k + 1);
            }
        
        private:
            long atLeastK(string word, int k) {
                long numValidSubstrings = 0;
                int start = 0;
                int end = 0;
                // Keep track of counts of vowels and consonants.
                unordered_map<char, int> vowelCount;
                int consonantCount = 0;
        
                // Start sliding window.
                while (end < word.length()) {
                    // Insert new letter.
                    char newLetter = word[end];
        
                    // Update counts.
                    if (isVowel(newLetter)) {
                        vowelCount[newLetter]++;
                    } else {
                        consonantCount++;
                    }
        
                    // Shrink window while we have a valid substring.
                    while (vowelCount.size() == 5 and consonantCount >= k) {
                        numValidSubstrings += word.length() - end;
                        char startLetter = word[start];
                        if (isVowel(startLetter)) {
                            if (--vowelCount[startLetter] == 0) {
                                vowelCount.erase(startLetter);
                            }
                        } else {
                            consonantCount--;
                        }
                        start++;
                    }
        
                    end++;
                }
        
                return numValidSubstrings;
            }
        
            bool isVowel(char c) {
                return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            }
        };