// l , r & k
// y = x^k
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        auto velnacqori = make_tuple(l,r,k);
        if (k == 1){
            return r - l + 1;
        }
        int cnt = 0;
        for (long long x = 0 ; ;x++){
            __int128 res = 1;
            for (int i = 0 ; i < k ; i++){
                res *= x;
                if (res > r) return cnt;
            }
            if (res >= l ) cnt++;
        }
        return cnt;
    }
};©leetcode
