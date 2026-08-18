class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0, l=0, n=s.size(), maxF=0, maxLen=0 ;
         unordered_map<char, int>mp;
        while(r<n){
            mp[s[r]-'A']++;
            maxF=max(maxF, mp[s[r]-'A']);

            if((r-l+1)-maxF>k){
                mp[s[l]-'A']--;
                    l++;
            }

            if((r-l+1)-maxF<=k){
                maxLen=max(maxLen, r-l+1);
            }

            r++;
        }

        return maxLen;
    }
};