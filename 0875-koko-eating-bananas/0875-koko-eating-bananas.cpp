class Solution {
public:
    bool isPossible(vector<int>& piles,int mid, int h){
        int hr=0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]<=mid){
            hr++;
            }
        else if(piles[i]%mid == 0){
            hr+= piles[i]/mid;
            }
        else if(piles[i]%mid != 0){
            hr+= (piles[i]/mid)+1;
            }

        if(hr>h){
            return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int maxi= INT_MIN;
        int ans;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        int end= maxi;

        while(st<=end){
            int mid=(st+end)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
    return ans;
    }
};