class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(!word.find(ch)) return word;

        size_t found = word.find(ch);
        reverse(word.begin(), word.begin()+found+1);

        return word;
    }
};