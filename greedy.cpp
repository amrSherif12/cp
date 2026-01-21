// kaden

int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, cur = 0;
        for (int x : nums) {
            cur += x;
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
        return mx;
    }