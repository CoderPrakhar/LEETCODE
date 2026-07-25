class Solution {
public:
    int merge(vector<int>& nums, int st, int mid, int end) {
        int cnt = 0;

        // Count reverse pairs
        int j = mid + 1;
        for (int i = st; i <= mid; i++) {
            while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int left = st, right = mid + 1;

        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid)
            temp.push_back(nums[left++]);

        while (right <= end)
            temp.push_back(nums[right++]);

        for (int i = 0; i < temp.size(); i++)
            nums[st + i] = temp[i];

        return cnt;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        if (st >= end)
            return 0;

        int mid = st + (end - st) / 2;

        int left = mergeSort(nums, st, mid);
        int right = mergeSort(nums, mid + 1, end);
        int curr = merge(nums, st, mid, end);

        return left + right + curr;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};