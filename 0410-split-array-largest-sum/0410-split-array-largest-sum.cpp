class Solution {
public:
    bool isPossible(vector<int>& arr, long long mid, int k) {
        long long wd = 1;
        long long sl = 0;

        for (int i = 0; i < arr.size(); ) {

            if (sl + arr[i] <= mid) {
                sl += arr[i];
                i++;
            }
            else {
                wd++;
                sl = 0;
            }

            if (wd > k) {
                return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {

        int n = arr.size();

        if (k > n) {
            return -1;
        }

        long long total = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            total += arr[i];
            maxi = max(maxi, arr[i]);
        }

        long long st = maxi;
        long long end = total;
        long long ans = -1;

        while (st <= end) {

            long long mid = st + (end - st) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }

    int splitArray(vector<int>& arr, int k) {
        return findPages(arr, k);
    }
};