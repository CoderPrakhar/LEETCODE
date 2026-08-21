class Solution {
public:
    bool isPossible(vector<int>& weights,int mid, int days){
        int wd=1;
        int sl=0;

        for(int i=0;i<weights.size();){
            if(sl+weights[i]<=mid){
                sl+=weights[i];
                i++;
            }
            else{
                wd++;
                sl=0;
            }
             if(wd>days){
            return false;
          }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total=0;
        for(int i=0; i<weights.size(); i++){
            total+=weights[i];
        }
        int st=1, end= total, ans=-1;
        while(st<=end){
            int mid=(st+end)/2;

            if(isPossible(weights, mid, days)){
                ans=mid;
                end=mid-1;
            }
            else{ //agr false aa rha
                st=mid+1;
            }
        }
        return ans;
    }

};