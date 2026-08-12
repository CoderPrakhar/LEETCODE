class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int st=0,n=arr.size(), end=n-1;

        while(st<=end){
            int mid=(st+end)/2;

            if(arr[mid]<arr[mid+1]){ //left side
                st=mid+1;
            }

            else if(arr[mid-1]>arr[mid]){ //right side
                end=mid-1;
            }

            else if(arr[mid]>arr[mid+1]){ //peak index
                return mid;
            }
        }

        return -1;
    }
};