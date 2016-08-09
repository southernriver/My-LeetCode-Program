#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string  getPermutation(int n, int k){
   

    string s(n,'0');
    for (int i=0;i<n;i++)
        s[i] = s[i]+i+1;
    cout<<s<<endl;
    for (int j = 1; j <k; j++){
        next_permutation(s.begin(),s.end());
        cout << s << endl;
    }
    return s;
}


int main()
{
    cout<<getPermutation(3,7)<<endl ;

    system("pause");
    return 0;
}