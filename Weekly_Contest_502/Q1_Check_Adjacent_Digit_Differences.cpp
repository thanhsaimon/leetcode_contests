// true - false
// abs(a-b)
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
    int n = s.length();
    for (int i = 1 ; i < n ; i++){
        int diff = abs(s[i] - s[i-1]);
        if (diff > 2){
            return false;
        }
    }
        return true;
    }
};©leetcode
