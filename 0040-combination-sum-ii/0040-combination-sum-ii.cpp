class Solution {
public:

    void solve( vector<int>&candidates, vector<int>&temp, int i, int target,vector<vector<int>>&answer){
        
        // base case
        if (target==0){
            answer.push_back(temp);
            return;
        }
        //base case2
        if (i==candidates.size()){
            return;
        }

        if (candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(candidates,temp,i+1,target-candidates[i],answer);
            temp.pop_back();

            while (i+1<candidates.size() && candidates[i]==candidates[i+1]){
                i++; // skip duplicates
            }
        }

        solve(candidates,temp,i+1,target,answer);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>answer;

        solve(candidates,temp,0,target,answer);
        return answer;
    }
};