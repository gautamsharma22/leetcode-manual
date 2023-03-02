class Solution
{
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==0 || n==1)return n;
        int i=0;
        int j=1;
        int last=1;
        while(i<n){
            while( j < n && chars[i]==chars[j]){
                j++;
            }
            int count=j-i;
            if(i>0)chars[last++]=chars[i];
            if (count > 1) {
                string str1 = to_string(count);
                for (char c : str1) {
                    chars[last++]=c;
                }
            }
            i=j;
        }
        return last;
    }

};