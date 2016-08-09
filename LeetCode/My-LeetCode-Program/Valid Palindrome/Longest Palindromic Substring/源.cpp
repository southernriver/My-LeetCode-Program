#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;
string longestPalindrome(string const &s){
    size_t len = s.size();
    int mid=len/2;
    map<int,int>  imap;
    vector<string>   svec;
    int start = 0;
    int end=0;
    int i=mid-1;int j=mid+1;
    //while (mid>=0&&mid<=len-1)
    //{
    //    i = mid - 1;
    //    if (len % 2 == 0){
    //         j=mid;
    //    }
    //    else
    //    {
    //        j=mid+1;
    //    }

    //    //从中间往两边遍历 <--|-->
    //    for (; i >= 0 && j <= len - 1;)
    //    {
    //        if (s[i]!=s[j])    break;
    //        i--;j++;
    //    }
    //    if (i>=0&&j<=len-1)  {mid--;  continue;}
    //    if (i<0){
    //          start=0; end=j;}
    //    else if (i>=0&&j > len - 1){
    //        start=i+1;end=len;
    //    }
    //    else
    //    {
    //        start=i+1;end=j;
    //    }
    //    svec.push_back(s.substr(start,end));
    //    mid--;
    //}
    //mid = len / 2;

    while (mid >= 0 && mid <= len - 1)
    {
        i = mid - 1;
        if (len % 2 == 0){
            j = mid;
        }
        else
        {
            j = mid + 1;
        }

        //从中间往两边遍历 <--|-->
        for (; i >= 0 && j <= len - 1;)
        {
            if (s[i] != s[j])    break;
            i--; j++;
        }
        if (i >= 0 && j <= len - 1)  { mid++;  continue; }
        if (i<0){
            start = 0; end = j;
        }
        else if (i >= 0 && j > len - 1){
            start = i + 1; end = len;
        }
        else
        {
            start = i + 1; end = j;
        }
        svec.push_back(s.substr(start, end));
        mid++;
    }
    sort(svec.begin(), svec.end(),[](const string &a,const string &b){return a.size()<b.size();});
    return *svec.rbegin();
}


int main(){
    cout << longestPalindrome("abba");



    system("pause");
    return 0;
}