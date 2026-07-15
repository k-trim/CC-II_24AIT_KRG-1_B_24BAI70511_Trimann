class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = 0, ub = nums.size() - 1, ans = nums.size();
        while(lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if(nums[mid] >= target)
            {
                ans = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return ans;
    }
};