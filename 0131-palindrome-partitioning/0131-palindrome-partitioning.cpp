class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;

        func(0, s, ds, ans);
        return ans;
    }

    void func(int index, string s, vector<string> &ds, vector<vector<string>> &ans){

        //base case
        if (index == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                func(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int st, int end){
        while(st<=end){
            if(s[st++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};