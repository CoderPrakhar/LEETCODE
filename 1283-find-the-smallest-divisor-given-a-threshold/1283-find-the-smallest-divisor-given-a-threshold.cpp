class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int divisor){
        int sum=0;    
        for(int i=0; i<nums.size(); i++){
            sum+=ceil((double)nums[i]/divisor);
        }
        if( sum<=threshold){
            return true;
        }
        return false;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int st=1;
        int maxi=INT_MIN;
       

        for(int i=0; i<n; i++){
            maxi=max(maxi, nums[i]);
        }

         int end=maxi;

        while(st<=end){
            int mid=st+(end-st)/2;
            if(isPossible(nums,threshold,mid)){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};