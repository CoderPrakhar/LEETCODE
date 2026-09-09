class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int>& ds, vector<int>& nums, int map[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!map[i]){
                ds.push_back(nums[i]);
                map[i] = 1;

                func(ans, ds, nums, map);

                map[i]=0;
                ds.pop_back();
            }
        }
    }

    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int map[nums.size()] ;
        for(int i=0; i<nums.size(); i++) {
            map[i] = 0;
        }
        func(ans,ds, nums, map);

        return ans;
    }
};