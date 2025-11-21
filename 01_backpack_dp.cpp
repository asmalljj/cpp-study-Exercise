#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1001;
int dp[N];

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> weight(n + 1), value(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> weight[i] >> value[i];
    }
    
    for (int i = 1; i <= n; ++i){
        for (int j = c; j >= weight[i]; --j){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}