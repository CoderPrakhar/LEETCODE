class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxLen=0;
        int hash[256]={-1};
        fill(hash, hash + 256, -1);

        while(r<s.size()){
            if (hash[s[r]] != -1){ //in the map

                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }

            }

            int len=r-l+1;
            maxLen=max(maxLen, len);
            hash[s[r]]=r; //---ek character de rha hai aur ek ----index
            r++;
        }
        return maxLen;
    }
};