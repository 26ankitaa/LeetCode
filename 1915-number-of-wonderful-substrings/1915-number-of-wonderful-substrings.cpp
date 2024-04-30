#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<long long> count(1 << 10, 0); // count[i] stores the number of substrings with bitmask i
        count[0] = 1; // Empty substring has no letters, so it's wonderful
        long long bitmask = 0, ans = 0;

        for (char c : word) {
            int idx = c - 'a';
            bitmask ^= (1 << idx); // Toggle the bit corresponding to the current letter
            ans += count[bitmask]; // Add the count of substrings with the current bitmask
            for (int i = 0; i < 10; ++i) {
                int newBitmask = bitmask ^ (1 << i); // Toggle the bit for the i-th letter
                ans += count[newBitmask]; // Add the count of substrings with the new bitmask
            }
            ++count[bitmask]; // Increment the count of substrings with the current bitmask
        }

        return ans;
    }
};