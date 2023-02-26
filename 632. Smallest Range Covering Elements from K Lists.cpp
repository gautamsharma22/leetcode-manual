class Solution {
public:
    struct Node {
    int val, row, column;
    Node(int val, int i, int j) : val(val), row(i), column(j) {}
    };
    struct compare {
        bool operator() (Node a, Node b) {
            return a.val > b.val;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        if(nums.size()==0)return ans;


        int maxi=INT_MIN;
        int mini=INT_MAX;
        int range=INT_MAX;
        int start = mini, end = maxi;

        priority_queue<Node ,vector<Node>,compare> pq;

        for(int i=0;i<nums.size();i++){
            if(nums[i][0] > maxi)maxi=nums[i][0];
            Node temp( nums[i][0] ,i , 0 );
            pq.push(temp);
        }
        while(true){
            Node min = pq.top();
            pq.pop();
            mini=min.val;

            if(maxi-mini < range){
                start = mini;
                end = maxi;
                range = maxi - mini;
            }

            if(min.column+1 < nums[min.row].size()){
                Node temp( nums[min.row][min.column+1] ,min.row ,min.column+1 );
                pq.push(temp);
                cout<<temp.val<<"\n";
                if(temp.val > maxi)maxi = temp.val;
            }
            else{
                break;
            }

        }
        return {start, end};
    }
};