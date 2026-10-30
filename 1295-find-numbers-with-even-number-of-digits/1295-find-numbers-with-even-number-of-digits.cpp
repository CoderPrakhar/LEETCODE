class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0 , n=nums.size();

        for(int i=0; i<n; i++){
            int n=nums[i];
            int d=0;

            while(n>0){
                d++;
                n=n/10;
            }

            if(d%2 ==0 ){
                c++;
            }
        }
        return c;
    }
};