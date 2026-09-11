class Solution {
public:
    void func(int i , vector<int>& nums ,int sum ,int target , int &count){
        if(i== nums.size()){
            if(sum == target ){
                count++ ;
            }
              return ;
        }
        
        func(i+1, nums , sum - nums[i],target , count );
  
        func(i+1, nums , sum + nums[i],target , count);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count=0;
        int sum=0;
        func(0, nums, 0 , target , count);
        return count;
    }
};