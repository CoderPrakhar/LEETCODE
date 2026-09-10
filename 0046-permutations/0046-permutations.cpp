class Solution {
public:
    void func(int index, vector<int>& nums , vector<vector<int>> & ans ){
        if(index== nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i=index; i<nums.size() ;  i++){ 
            swap(nums[index] , nums[i]);
            func(index+1, nums, ans);
            swap(nums[index], nums[i]); // backtracking...       
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0,nums , ans);

        return ans;
    }
};