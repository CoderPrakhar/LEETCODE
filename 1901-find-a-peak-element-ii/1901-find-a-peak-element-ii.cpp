class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n ,int m, int col){
        int maxValue = -1;
        int index = -1;
        for(int i = 0; i<n ; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;
        int st = 0, end = m-1;

        while(st<=end){
            int mid = (st+end)/2;

            int maxRowIndex = findMaxIndex( mat, n, m, mid);

            int left = -1;

            if(mid - 1>=0){
                left = mat[maxRowIndex][mid-1];
            }
            int right = -1;

            if(mid+1<m){
                right = mat[maxRowIndex][mid+1];
            }

            if(mat[maxRowIndex][mid]> left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex , mid};
            }

            else if(mat[maxRowIndex][mid] < left){
                end= mid-1;
            }

            else{
                st=mid+1;
            }

        }
        return {-1 , -1};
    }
};