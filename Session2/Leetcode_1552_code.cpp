class Solution {
public:
    bool possible(vector<int>& position, int d, int m)
    {
        int ans = 1, curr= position[0];
        for(int i = 0; i < position.size(); i++)
        {
            if(position[i] - curr >= d)
            {
                ans++;
                curr = position[i];
            }
        }
        return (ans >= m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lb = 1, ub = position.back() - position[0], ans = 0;
        while(lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if(possible(position, mid, m))
            {
                ans = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
        return ans;
    }
};