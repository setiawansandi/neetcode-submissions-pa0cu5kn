class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int sub;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(matrix[mid][0] > target) {
                r = mid - 1;
                continue;
            }
            if(mid == matrix.size()-1 || matrix[mid+1][0] > target) {
                sub = mid;
                break;
            } else {
                l = mid + 1;
            }
        }

        l = 0;
        r = matrix[sub].size() - 1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(matrix[sub][mid] > target) {
                r = mid - 1;
            } else if (matrix[sub][mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }

        }
        return false;
    }
};
