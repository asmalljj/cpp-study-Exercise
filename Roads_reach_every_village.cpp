#include<iostream>
using namespace std;

const int MAXN = 1005;//最大村庄数
const int MAXM = 3005;//最多道路数

struct Edge{
    int u, v;
    long long w;
};
Edge edge[MAXM];//定义了一个结构体存储村庄之间的权重，起点终点。

int Parents[MAXN], height[MAXN];//一个是父节点，另一个是树的高度
//并查集的应用
//快速查找集合的代表
int findparent(int x){
    while (Parents[x] != x){
        Parents[x] = Parents[Parents[x]];
        x = Parents[x];//这两行是压缩路径，为了快速找到这一节点的根节点
    }
    return x;
}
//合并集合
bool unite(int a, int b){
    a = findparent(a);
    b = findparent(b);
    if (a == b) return false;//根节点一样说明二者在同一个集合中 不需要合并
    if (height[a] < height[b]) swap (a, b);//为了让a更长一点，为下面这一行做个铺垫
    Parents[b] = a;//把b的根节点挂在a的树下，可以让树尽量短，查询更便利
    if (height[a] == height[b]) height[a] ++;//两个树一样长的话合并要加1高度
    return true;
}

//快速排序
void sort(int l, int r){
    if (l >= r) return;
    int i = l, j = r;
    Edge pivot = edge[(l + r) / 2];//找一个基准点来比较左右两边的数字
    while (i <= j){
        while (edge[i].w < pivot.w) i++;
        while (edge[j].w > pivot.w) j--;//这两行是为了左右各自遍历寻找不合群的数 遇到不符合的直接跳入下面的交换 完成初步的快排
        if (i <= j){
            Edge temp = edge[i];
            edge[i] = edge[j];
            edge[j] = temp;
            i++;
            j--;
        }
    }
    if (l < j) sort(l, j);
    if (i < r) sort(i, r);//分别分组左右两边再进行递归排序 直至只剩一个数据
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;//存储读入各个村庄的数据
    }
//初始化并查集
    for (int i = 1; i <= n; i++){
        Parents[i] = i;
        height[i] = 0;
    }
//进行初步快排
    sort(0, m - 1);

    long long totalCost = 0;
    int usedRoads = 0;
    for ( int i = 0; i < m; i ++){
        if (unite(edge[i].u, edge[i].v)){
            totalCost += edge[i].w;
            usedRoads ++;
            if (usedRoads == n - 1) break;
        }
    }

    if (n <= 1) cout << 0 << endl;
    else if (usedRoads == n - 1) cout << totalCost << endl;
    else cout << -1 << endl;

    return 0;

}