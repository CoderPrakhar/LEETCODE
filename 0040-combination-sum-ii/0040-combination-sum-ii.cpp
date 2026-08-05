class Solution {
public:

    void getAllCombinations(vector<int>& arr,
                            int idx,
                            int tar,
                            vector<vector<int>>& ans,
                            vector<int>& combin) {

        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx == arr.size() || tar < 0) {
            return;
        }

        // Include
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin);

        // Backtrack
        combin.pop_back();

        // Skip duplicates
        while (idx + 1 < arr.size() && arr[idx + 1] == arr[idx]) {
            idx++;
        }

        // Exclude
        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, target, ans, combin);

        return ans;
    }
};