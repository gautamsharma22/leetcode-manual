class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom=matrix.size()-1;
        int right=matrix[0].size()-1;
        int left=0;
        int top=0;
        int step=0;
        vector<int> x;
        while(left<=right && top<=bottom){
        if(step==0){
            for(int i=left;i<=right;i++){
                x.push_back(matrix[top][i]);
            }
            top+=1;
            step=1;
        }else if(step==1){
            for(int i=top;i<=bottom;i++){
                x.push_back(matrix[i][right]);
            }
            right-=1;
            step=2;
        }else if(step==2){
            for(int i=right;i>=left;i--){
                x.push_back(matrix[bottom][i]);
            }
            bottom-=1;
            step=3;
        }else if(step==3){
            for(int i=bottom;i>=top;i--){
                x.push_back(matrix[i][left]);
            }
            left++;
            step=0;
        }
            }
        return x;
    }
};