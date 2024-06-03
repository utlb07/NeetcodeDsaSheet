class Solution {
public:
vector<int> previous_smaller(vector<int>& heights){
        vector<int> ans;
        stack<int>st;
        int n = heights.size();
        
        for(int i=0; i<n; i++){
            while(st.empty() == false && heights[st.top()] >= heights[i] ){
                st.pop();
            }
            int ele = (st.empty()) ? -1 : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        return ans;
    }

    vector<int> next_smaller(vector<int>& heights){
        vector<int> ans;
        stack<int>st;
        int n = heights.size();
        
        for(int i=n-1; i>=0; i--){
            while(st.empty() == false && heights[st.top()] >= heights[i] ){
                st.pop();
            }
            int ele = (st.empty()) ? n : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int>ps = previous_smaller(heights);
        vector<int>ns = next_smaller(heights);
        
        for(int i=0; i<n; i++){
            int curr = ( ns[i] - ps[i] -1 ) * heights[i];
            res = max(res , curr);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
          int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
                cout<<histogram[j]<<" ";
            }
            cout<<"nline"<<endl;
            result = max(result, largestRectangleArea(histogram));
            cout<<"ans is"<<result<<endl;
        }
        return result;
        
    }
};