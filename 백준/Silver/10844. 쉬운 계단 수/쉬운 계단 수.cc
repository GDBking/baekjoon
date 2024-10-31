#include <iostream>
using namespace std;
int main(){
    long long DP[101][10] = {0,};
    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }
    int n;
    cin >> n;
    long long di = 1000000000;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0) DP[i][0] = (DP[i-1][1])%di;
            else if(j==9) DP[i][9] = (DP[i-1][8])%di;
            else DP[i][j] = (DP[i-1][j-1]+DP[i-1][j+1])%di;
        }
    }
    long long sum = 0;
    for(int i=0; i<10; i++){
        sum += DP[n][i];
        sum %= di;
    }
    cout << sum;
}