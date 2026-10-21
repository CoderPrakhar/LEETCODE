
class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n), pse(n);
        stack<int> st;
        long long total = 0;

        // Next Smaller Element
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += 1LL * arr[i] * left * right;
        }

        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n), pge(n);
        stack<int> st;
        long long total = 0;

        // Next Greater Element
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Greater Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += 1LL * arr[i] * left * right;
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
