class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;
        while(i>=0 || j>=0){
            int bit1= i>=0 ? a[i--] - '0':0;
            int bit2= j>=0 ? b[j--] - '0':0;
            // cout<<bit1<<" "<<bit2<<" "<<endl;
            int sum=bit1+bit2+carry;
            carry=sum/2;
            result.push_back(sum%2 + '0');
            // cout<<carry<<endl;
            }
        if(carry){
            result.push_back('1');
        }
            reverse(result.begin(),result.end());
        return result;
    }
};