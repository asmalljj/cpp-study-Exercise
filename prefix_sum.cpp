// 首先一行整数N，代表序列长度。

// 接下来一行N个整数，为序列内容。

// 接下来一行整数K，代表对区间和的询问次数。

// 接下来K行，每行两个整数a和b，请你输入序列的第a到b号元素（含）的和取模后的结果。
#include<iostream>
using namespace std;
#include<vector>
int main(){
    int N;
    cin >> N;
    int a, b;
    vector<long long> sum(N + 1);
    int mod = 10000019;
    vector<long long> arr(N + 1);
    for ( int i = 1; i <= N; i++){
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++){
    cin >> a >> b;
    cout << ((sum[b] - sum[a - 1]) % mod + mod) % mod << endl;
    }
    return 0;
}