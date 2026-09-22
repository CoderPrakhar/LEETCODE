class Solution {
public:
    void solve(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int i, int target){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(ds);
                
            }
            return;
        }

        if(arr[i] <= target){
            ds.push_back(arr[i]);
            solve(arr, ds, ans, i, target-arr[i]);
            ds.pop_back();
        }
        solve(arr, ds, ans, i+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(arr, ds, ans, 0, target);
        return ans;
    }
};