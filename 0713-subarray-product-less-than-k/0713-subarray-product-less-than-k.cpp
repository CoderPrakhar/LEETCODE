class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0, l=0, r=0;
        int product=1;
        while(r<nums.size()){
            product*=nums[r];
            while(product>=k && l<=r){
                product/=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};