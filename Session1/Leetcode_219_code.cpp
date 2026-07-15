class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++)
        {
            if(st.contains(nums[i]))
            {
                return true;
            }
            st.insert(nums[i]);
            if(st.size() > k)
            {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};