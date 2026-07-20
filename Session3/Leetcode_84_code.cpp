class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) 
        {
            while (st.top() != -1 && heights[i] <= heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        while(st.top() != -1) {
            int h = heights[st.top()];
            st.pop();
            int w = heights.size() - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        return maxArea;   
    }
};