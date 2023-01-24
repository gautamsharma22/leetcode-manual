#include <iostream>
using namespace std;

string reverse(string  s,int i,int j){
    if(i>j){
        return s;
    }
    swap(s[i], s[j]);
    i++;
    j--;
    return reverse(s,i,j);
}
int main()
{
    string s = "abc";
    int size = s.length()-1;
    string x = reverse(s,0,size);
    cout << x;
    return 0;
}