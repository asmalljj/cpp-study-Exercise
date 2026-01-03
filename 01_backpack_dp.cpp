#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// N 表示背包容量最大值，这里设为 1000（可根据题目调整）
// dp[j] 表示：背包容量为 j 时，能够获得的最大价值
const int N = 1001;
int dp[N];  // 默认全局数组会初始化为 0

int main(){
    int n, c;
    cin >> n >> c;
    // n 表示物品数量
    // c 表示背包容量（最大重量）

    // weight[i] 表示第 i 个物品重量
    // value[i] 表示第 i 个物品价值
    // 下标从 1 开始，方便理解
    vector<int> weight(n + 1), value(n + 1);

    // 输入每个物品的重量和价值
    for (int i = 1; i <= n; ++i){
        cin >> weight[i] >> value[i];
    }

    /*
        01 背包核心思路：
        每件物品只能选 0 次或 1 次

        dp[j] = max(dp[j], dp[j - weight[i]] + value[i])

        含义：
        - dp[j]：不选第 i 件物品时，容量 j 的最大价值
        - dp[j - weight[i]] + value[i]：选第 i 件物品时的最大价值
            需要空出 weight[i] 的容量放第 i 件物品

        两者取最大值
    */

    // 遍历每一件物品（外层循环是物品）
    for (int i = 1; i <= n; ++i){

        /*
            ⚠️ 关键：背包容量 j 必须从大到小遍历！

            为什么要倒序？
            - 为了保证每个物品最多使用一次（01 背包）
            - 如果正序遍历，会导致 dp[j - weight[i]] 可能已经被本轮更新过，
              相当于同一件物品被用多次，变成完全背包

            举例：
            正序会出现：dp[2] 依赖 dp[1]，dp[1] 又刚更新过，从而多次使用第 i 件物品
        */

        // j 从 c（最大容量）到 weight[i]（最小可放下 i 的容量）倒序遍历
        for (int j = c; j >= weight[i]; --j){

            // 状态转移：不选 or 选第 i 件物品
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // dp[c] 表示容量为 c 的背包，最终可以获得的最大价值
    cout << dp[c] << endl;
    return 0;
}
