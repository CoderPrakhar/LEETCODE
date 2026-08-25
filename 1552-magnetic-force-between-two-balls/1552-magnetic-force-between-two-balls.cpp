class Solution {
public:
    bool isPossible(vector<int> &arr, int mid,int  m){
        int cow=1;
        int pos=arr[0];
        int n=arr.size();
        //
        for(int i=1; i<n; i++){
            if(arr[i]-pos >= mid){
                cow++;
                pos=arr[i];
            }
            if(cow==m){
                return true;
            }
        }
        
        return false;
    }
    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin() , arr.end());
        int n=arr.size();
        int st=1;
        int end=arr[n-1]-arr[0];
        int ans;
        while(st<=end){
            int mid=(st+end)/2;
            
            if(isPossible(arr, mid, m)){
                ans=mid;
                st=mid+1; //distance badhyengey jisse ladai na hoo jye!
            }
            
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};