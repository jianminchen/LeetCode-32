/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1, sum = 0, res = nums.size();
	bool found = false;
	if (s == 0) return 0;
	if (nums.empty()) return 0;
	while (r < (int)nums.size()) {
		if (sum >= s) {
			if (sum == s) {
				found = true;
				res = min(r-l+1, res);
			}
			sum -= nums[l++];
		} else {
			sum += nums[++r];
		}
    // cout << l << " " << r << " " << sum << endl;
	}

	return found ? res : 0;
    }
};
