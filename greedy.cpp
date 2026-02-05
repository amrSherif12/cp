// kaden
// for finding the finding the largest sum in an array with nega numbers
int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, cur = 0;
        for (int x : nums) {
            cur += x;
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
        return mx;
    }



// patience sort
// for finding lis

int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int in = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[in] = nums[i];
            }
        }
        return ans.size();
    }
