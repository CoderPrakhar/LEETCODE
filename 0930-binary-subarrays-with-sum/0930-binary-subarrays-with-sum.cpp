class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int r=0, l=0, sum=0, c=0, n=nums.size();

        while(r<n){
            sum+=nums[r];

            while(sum>goal){//shrink hoo rhi hai hamari window
                sum-=nums[l];
                l++;
            }
            c=c+(r-l+1);
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal-1);
    }
};