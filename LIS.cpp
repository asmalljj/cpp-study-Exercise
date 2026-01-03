#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    求一组序列的最长严格上升子序列长度（LIS）
    dp[i] 表示：以第 i 个元素结尾的最长上升子序列长度
*/

int main() {
    int zushu; // 测试数据组数 T
    cin >> zushu;

    for (int t = 1; t <= zushu; ++t) {

        int n;
        cin >> n;

        vector<int> arr(n);   // 存储序列
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // dp[i]：以 i 结尾的 LIS 的长度
        vector<int> dp(n, 1); // 每个元素自身都能形成长度为 1 的上升子序列

        int ans = 1; // 最终答案，至少为 1

        /*
            状态转移：
            如果 arr[j] < arr[i]，那么 arr[i] 可以接在 arr[j] 后面
            dp[i] = max(dp[i], dp[j] + 1)
        */

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        cout << ans << endl;

        // 每两组测试输出之间空一行（最后一组不输出空行）
        if (t != zushu) cout << endl;
    }

    return 0;
}
