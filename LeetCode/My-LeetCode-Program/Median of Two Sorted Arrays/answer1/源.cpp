#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int find_kth(int A[], int  m, int B[], int n, int k){
    if (m>n) find_kth(B,n,A,m,k);
    if (m == 0)   return B[k-1];
    if (k == 1)      return min(A[0],B[0]);
    
    int ia = min(k/2,m),ib=k-ia;
    if (A[ia-1]<B[ib-1])
        return find_kth(A+ia,m-ia,B,n,k-ia);
    

}
int main(){



    system("pause");
    return 0;
}