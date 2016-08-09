#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string simplifyPath(string path) {
    int index = path.find_last_of("/");
    
     return path.substr(index,path.size()-index);
   
}
int main(){
    cout<<simplifyPath("cv/vb/v/")<<endl;


    system("pause");
    return 0;
}