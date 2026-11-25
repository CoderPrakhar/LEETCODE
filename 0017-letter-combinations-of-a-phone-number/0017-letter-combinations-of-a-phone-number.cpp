class Solution {
public:
    void solve(string digits, string output, int index, vector<string>&ans, string mapping[]){
        if(index>=digits.size()) {
            ans.push_back(output) ; //vector<int>& ans → It should be vector<string>& ans because you are storing strings.
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);//solve(digit, output, index, ans, mapping) → Pass index + 1, otherwise infinite recursion will occur
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
                if(digits.size()==0) return ans;

        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};