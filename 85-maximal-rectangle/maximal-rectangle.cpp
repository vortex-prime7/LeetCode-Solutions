class Solution {
    private:
    vector<int> nextSmaller(vector<int>& heights){
        int n=heights.size();
        vector<int> next(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }
            st.push(i);
        }
        return next;
    }
    vector<int> prevSmaller(vector<int>& heights){
        int n=heights.size();
        vector<int> prev(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        return prev;
    }
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> next=nextSmaller(heights);
        vector<int> prev=prevSmaller(heights);

        int maxi=0;
        for(int i=0;i<n;i++){
            int l=heights[i];
            int b=next[i]-prev[i]-1;
            int area=l*b;
            maxi=max(maxi,area);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> heights(m,0);

        for(int j=0;j<m;j++){
            heights[j]=matrix[0][j]-'0';
        }
        int area=largestRectangleArea(heights);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[j]=heights[j]+1;
                }
                else{
                    heights[j]=0;
                }
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
        
    }
};