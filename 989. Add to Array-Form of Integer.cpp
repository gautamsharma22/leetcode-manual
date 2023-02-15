class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int index=num.size()-1;
        int carry=0;
        while(index>=0){
            int sum=num[index]+(k%10)+carry;
            k=k/10;
            num[index--]=sum%10;
            carry=sum/10;
        }
        while(k > 0)
        {
         int sum = (k % 10) + carry;
         k /= 10;
         num.insert(num.begin(), sum%10);
         carry = sum/10;
        }

        if(carry > 0) num.insert(num.begin(), carry);
        return num;
    }
};