class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=0, maxLen=0;
        unordered_map<int,int>mp;

        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                 l++;
            }
                if(mp.size()<=2){
                    maxLen=max(maxLen, r-l+1);
                }
                r++;
            
        }

        return maxLen;
    }
};