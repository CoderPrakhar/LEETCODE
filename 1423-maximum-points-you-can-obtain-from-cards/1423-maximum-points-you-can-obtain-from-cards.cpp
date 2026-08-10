class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();

        int l=0, r=n-1, rSum=0, lSum=0, maxSum=0;

        for(int i=0; i<k; i++){
            lSum=lSum+nums[i];
        }
        maxSum=lSum;

        for(int i=k-1; i>=0; i--){
            lSum=lSum-nums[i];
            rSum=rSum+nums[r];

            r--;
            maxSum=max(maxSum, lSum+rSum);
        }

        return maxSum;
    }
};