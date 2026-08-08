class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 1;
        int count = 0;

        while (j < nums.size()) {
            if (i == j) {
                j++;
                continue;
            }

            int diff = nums[j] - nums[i];
            if (diff < k) {
                j++;
            }
            else if (diff > k) {
                i++;
            }
            else {
                count++;

                //avoid dupicates
                int left = nums[i];
                int right = nums[j];

                while (i < nums.size() && nums[i] == left) {
                    i++;
                }

                while (j < nums.size() && nums[j] == right) {
                    j++;
                }
            }
        }

        return count;
    }
};