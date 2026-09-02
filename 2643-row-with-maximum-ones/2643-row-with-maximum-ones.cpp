class Solution {
public:

    // int lowerBound(vector<int>& arr, int n, int x) {
    //     int st = 0, end = n - 1;
    //     int ans = n;

    //     while(st <= end) {
    //         int mid = st + (end - st) / 2;

    //         if(arr[mid] >= x) {
    //             ans = mid;
    //             end = mid - 1;
    //         }
    //         else {
    //             st = mid + 1;
    //         }
    //     }

    //     return ans;
    // }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int countMax = 0;
        int index = 0;

        for(int i = 0; i < m; i++) {
            int countOnes = 0;

            for(int j=0; j<n; j++){
                countOnes += mat[i][j];
            }


            if(countOnes > countMax) {
                countMax = countOnes;
                index = i;
            }
        }

        return {index, countMax};
    }
};