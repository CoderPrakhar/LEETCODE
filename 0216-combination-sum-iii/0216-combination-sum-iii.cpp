class Solution {
   void solve(vector<int>&candidates,vector<int>&temp,vector<vector<int>>&answer,int i,int n,int k)
  {
    if(n==0)//base case1
    {
        if(temp.size()==k)
            { 
                answer.push_back(temp);
                return;
            }
    }


    if(i==candidates.size())//base case2
    return;
     

     //recursive case
     if(candidates[i]<=n)
     {
        temp.push_back(candidates[i]);
        solve(candidates,temp,answer,i+1,n-candidates[i],k);
        temp.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1])
        {
            i++;
        }
     }
     

    
     
     solve(candidates,temp,answer,i+1,n,k);



  }



public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>answer;
        vector<int>temp ;
         vector<int> candidates = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
         
         
         
        solve(candidates,temp,answer,0,n,k);
        return answer;

    }
};