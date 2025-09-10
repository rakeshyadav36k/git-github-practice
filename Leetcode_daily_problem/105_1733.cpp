/**
 * On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
 
 */
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> cncon;
        for (auto friendship : friendships) {
            unordered_map<int, int> mp;
            bool conm = false;
            for (int lan : languages[friendship[0] - 1]) {
                mp[lan] = 1;
            }
            for (int lan : languages[friendship[1] - 1]) {
                if (mp[lan]) {
                    conm = true;
                    break;
                }
            }
            if (!conm) {
                cncon.insert(friendship[0] - 1);
                cncon.insert(friendship[1] - 1);
            }
        }
        int max_cnt = 0;
        vector<int> cnt(n + 1, 0);
        for (auto friendship : cncon) {
            for (int lan : languages[friendship]) {
                cnt[lan]++;
                max_cnt = max(max_cnt, cnt[lan]);
            }
        }
        return cncon.size() - max_cnt;
    }
};