class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
        int count=0, nOfBouquets=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else{
                nOfBouquets+=(count/k);
                count=0;
            }
        }
        nOfBouquets+=(count/k);

        if(nOfBouquets>=m){
            return true;
        }

        return false;
    }



    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k> bloomDay.size()){
            return -1;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int st=mini, end=maxi ;

        while(st<=end){
            int mid=(st+end)/2;
            if(isPossible(bloomDay,m,k,mid)){
                end=mid-1; //eliminate the right half
            }

            else{
                st=mid+1;
            }
        }
        return st;
    }
};