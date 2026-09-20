class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, sum = 0, len = INT_MAX;
        
        while(r < nums.size()){
            sum += nums[r];
           
            while(sum>=target){  // jb tk minimun subarray n mile tb tk chalao yeh loop
             
                
                len = min(len, r-l+1);
                   sum -= nums[l];
                l++;
            }

            r++;
            
        }
        if( len == INT_MAX){
            return 0;
        }
        else {
            return len;
        }

    }
};