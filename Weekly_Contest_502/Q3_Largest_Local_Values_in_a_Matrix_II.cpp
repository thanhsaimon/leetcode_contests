class Solution {
private:
    // (r,c) 
    int n , m;
    vector <int> row_max;
    bool isLocalMax(int r , int c, const vector<vector<int>> &matrix){
        int x = matrix[r][c];
        int min_r = max(0 , r - x);
        int max_r = min(n-1 , r + x);
        int min_c = max(0, c - x);
        int max_c = min(m - 1 , c + x);
        for (int nr = min_r ; nr <= max_r ; ++nr){
            if (row_max[nr] <= x){
                continue;
            }
            for (int nc = min_c ; nc <= max_c ; ++ nc){
                if (abs(nr-r) == x && abs (nc - c) == x){
                    continue;
                }
                if (matrix[nr][nc] > x){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        auto tarmiqusve = matrix;
        n = matrix.size();
        m = matrix[0].size();
        int local_max_cnt = 0;
        row_max.assign(n,0);
        vector <tuple<int ,int ,int>> cells;
        for (int r = 0 ; r < n ; r++){
            for (int c = 0 ; c < m ; c++){
                row_max[r] = max(row_max[r] , matrix[r][c]);
                if (matrix[r][c] > 0){
                    cells.push_back({matrix[r][c] , r , c});
                }
            }
        }
        sort(cells.rbegin(),cells.rend());
        for (auto & [val,r , c]: cells){
            if (isLocalMax (r,c,matrix)){
                local_max_cnt++;
            }
        }
        return local_max_cnt;
    }
};©leetcode
