class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin() , salary.end());
        int count = 0;
        double sum = 0;
        int n = salary.size();
        for(int i=1; i<salary.size()-1; i++){
            sum+=salary[i];
            count++;
        }
        double avg=sum/count;
        return avg;
    }
};