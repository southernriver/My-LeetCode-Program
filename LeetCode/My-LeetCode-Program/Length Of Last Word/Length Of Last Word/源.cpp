#include<iostream>
#include<string>
#include<functional>
#include<numeric>
#include<algorithm>
using namespace std;
int lengthOfLastWord(string s) {
    auto i = find_if(s.rbegin(), s.rend(),::isalpha);
    auto j = find_if(i,s.rend(),::isspace);
    return distance(i,j);
}
int main(){
    cout << lengthOfLastWord("hello world\n");

    system("pause");
    return 0;
}