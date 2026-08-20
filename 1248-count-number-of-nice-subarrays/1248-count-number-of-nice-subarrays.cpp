class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int r=0, l=0, sum=0, c=0, n=nums.size();

        while(r<n){
            sum+=nums[r]%2;

            while(sum>k){//shrink hoo rhi hai hamari window
                sum-=nums[l]%2;
                l++;
            }
            c=c+(r-l+1);
            r++;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
                return func(nums, k) - func(nums, k-1);

    }
};