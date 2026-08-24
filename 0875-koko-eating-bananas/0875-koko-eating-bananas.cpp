class Solution {
public:
    int findMax(vector<int> &v){
        int maxi=INT_MIN;
        int n=v.size();

        for(int i=0; i<n; i++){
            maxi=max(maxi, v[i]);
        }
        return maxi;
    }

    long long calculateTotalH(vector<int>& v, int hr){
        long long totalH=0;
        int n=v.size();

        for(int i=0; i<n; i++){
            totalH+=ceil((double)v[i]/hr);
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int st=1, end=findMax(v);
        while(st<=end){
            int mid=(st+end)/2;
            long long totalH=calculateTotalH(v, mid);

            if(totalH<=h){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        return st;
    }
};