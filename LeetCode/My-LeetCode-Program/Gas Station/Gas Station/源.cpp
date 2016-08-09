#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int j=-1;
    int sum=0;
    int total=0;   
    for (int i = 0; i < gas.size(); i++){
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if (sum < 0){
            j=i;
            sum=0;
        }
    }
    return total>=0?j+1:-1;

}
int main(){
    vector<int> gas = {4,5,6};
    vector<int> cost = {2,8,3};
    cout << canCompleteCircuit(gas,cost)<<endl;



    system("pause");
    return 0;
}