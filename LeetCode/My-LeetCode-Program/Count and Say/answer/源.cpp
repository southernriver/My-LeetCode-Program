#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<functional>
using namespace std;
string getNext(const string &s);
string countAndSay(int n) {
    string s("1");
    while (--n)
        s = getNext(s);
    return s;
}
string getNext(const string &s) {
    ostringstream ss;
    for (auto i = s.begin(); i != s.end();) {
                                    //将二元算子转换成一元算子
        auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));//找到第一个与当前值不相等的地方
        ss << distance(i, j) << *i;
        i = j;
    }
    return ss.str();
}
int main(){
  //  for (int i=1;i<=10;i++)
        cout << countAndSay(4)<<endl;
        cout << countAndSay(5) << endl;



    system("pause");
    return 0;
}