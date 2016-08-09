#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

bool is_operator(const string &op){
    if(string("+-*/").find(op)!=string::npos)
        return true;
    return false;
}
int evalRPN(vector<string> &tokens){
    stack<int>   s;
    for (auto c : tokens){
        if (!is_operator(c)) { 

            s.push(stoi(c));
        }
        else
        {
            int  y= s.top();
            s.pop();
            int  x = s.top();
            s.pop();
            if (c == "+")   x+=y;
            else if(c == "-") x-=y;
            else if (c == "*") x*=y;
            else  x/=y;
            s.push(x);
        }
    }
    return s.top();
}
int main(){
    vector<string> tokens = { "4", "13", "5", "/", "+" };
   cout<<evalRPN (tokens)<<endl;;


    system("pause");
    return 0;
}