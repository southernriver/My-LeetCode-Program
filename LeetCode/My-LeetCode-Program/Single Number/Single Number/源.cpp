#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<unordered_map>
using namespace std;

int singleNumber(int A[], int n){
    int x=0;
    for (int i = 0; i < n; i++){
        x = x^A[i];
    }
    return x;
}
int singleNumberII(int A[], int n){
    unordered_map<int,int>   umap;
    for (int i = 0; i < n; i++){
        umap[A[i]]++;
    }
    for (int i = 0; i < n; i++){
        if(umap[A[i]]!=3)
            return A[i];
    }
    return -1;
}
int main(){
    int A[7] = {3,3,3,4,4,5,5};
    int num=singleNumberII(A,7);
    cout<<num<<endl;



    system("pause");
    return 0;
}