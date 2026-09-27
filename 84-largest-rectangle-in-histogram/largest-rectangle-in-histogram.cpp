class Solution {
    private:
    vector<int> NextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> PrevSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> next=NextSmaller(heights);
        vector<int> prev=PrevSmaller(heights);

        int maxArea=0;
        for (int i =0;i<n;i++){
            int l=heights[i];
            int b= next[i]-prev[i]-1;

            int area=l*b;

            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};