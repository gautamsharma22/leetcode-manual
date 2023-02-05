class Solution {
public:
    vector<int> nextsmaller(vector<int>& heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while( s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
                s.push(i);
            }
            else{
                ans[i]=heights[i];
                s.push(heights[i]);
            } 
            
        }
        return ans;
    }
    vector<int> prevsmaller(vector<int>& heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
            for(int i=0;i<n;i++){
                while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(!s.empty()){
                    ans[i]=s.top();
                    s.push(i);
                }else{
                    ans[i]=heights[i];
                    s.push(heights[i]);
                }
                
            }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next=nextsmaller(heights,n);
        vector<int> prev=prevsmaller(heights,n);
        int newarea=0;
        for(int i=0;i<n;i++){
            int length=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int breadth=next[i]-prev[i]-1;
            // cout<<prev[i]<<next[i]<<endl;
            int area=length*breadth;
            cout<<length<<breadth<<endl;
            newarea=max(area,newarea);
        }
        return newarea;
    }
};