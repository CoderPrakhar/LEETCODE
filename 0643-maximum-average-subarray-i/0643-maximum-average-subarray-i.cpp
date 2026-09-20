class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0, r=0, sum=0;
        int maxSum = INT_MIN;

        while(r< nums.size()){
            sum += nums[r];

            if( r-l+1 == k ){
                maxSum = max(maxSum, sum);
                sum-=nums[l];
                l++;
            }

            r++;
        }

        return (double)maxSum/k;
    }
};