#include<iostream>
#include<string>
using namespace std;
bool isNumber(string s) {
    const char *ss = s.c_str();  
    char *endptr;
    strtod(ss, &endptr);
    cout<<endptr<<endl;
    if (ss == endptr)   return false;
    for (; *endptr!=NULL; ++endptr){
        if (!isspace(*endptr))  return false;
    }
    return true;
}
int main(){
    cout << isNumber(".1")<<endl;


    system("pause");
    return 0;
}