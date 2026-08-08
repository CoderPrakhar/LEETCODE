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

                // duplicate i ko skip karo
                if (i == 0 || nums[i] != nums[i - 1]) {
                    count++;
                }

                i++;
                j++;
            }
        }

        return count;
    }
};