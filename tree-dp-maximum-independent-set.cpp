#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 3005;
vector<int> tree[N + 1];
bool has_parent[N];
int dp[N][2], weight[N], n;

void dfs(int u){
    dp[u][1] = weight[u];
    dp[u][0] = 0;
    for(int v : tree[u]){
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> weight[i];
    }
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        tree[y].push_back(x);
        has_parent[x] = true;
    }
    int root = 1;
    while(has_parent[root]) root++;
    dfs(root);
    cout << max(dp[root][1], dp[root][0]) << endl;
    return 0;

}