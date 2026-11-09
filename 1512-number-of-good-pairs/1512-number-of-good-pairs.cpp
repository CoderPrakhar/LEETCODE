class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int>mp;
        int c=0;
        for(int i=0; i<nums.size(); i++){
            c += mp[nums[i]];
            mp[nums[i]]++;
        }
        return c;
    }
};