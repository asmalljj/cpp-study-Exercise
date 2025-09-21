#include<iostream>
using namespace std;

const int MAXN = 500;
const int INF = 2137483647;

struct Road
{
    int length;//路径长度
    int cost;//收费
};

int main(){

    int n, m , s, d;//n是城市个数，m是高速条数，s是起点，d是终点
    cin >> n >> m >> s >> d;

    Road graph[MAXN][MAXN];
    for (int i = 0; i < n; i ++){
        for ( int j = 0; j < n; j ++){
            graph[i][j].length = INF;
            graph[i][j].cost = INF;
        }
    } 

    for (int i = 0; i < m; i ++){
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        graph[u][v].length = graph[v][u].length = l;
        graph[u][v].cost = graph[v][u].cost = c;
    }

    int dist[MAXN], fee[MAXN];
    bool isVisited[MAXN] = {false};

    for (int i = 0; i < n; i++){
        dist[i] = INF;
        fee[i] = INF;
    }
    dist[s] = fee[s] = 0;

    for (int i = 0; i < n; i ++){
        int u = -1, min_dist = INF;
        for ( int j = 0; j < n; j++){
            if (!isVisited[j] && dist[j] < min_dist){
                u = j;
                min_dist = dist[j];
            }
        }

        if (u == -1) break;
        isVisited[u] = true;

        for (int k = 0; k < n; k++){
            if (!isVisited[k] && graph[u][k].length != INF){
                int new_dist = dist[u] + graph[u][k].length;
                int new_fee = fee[u] + graph[u][k].cost;
                if (new_dist < dist[k] || (new_dist == dist[k] && new_fee < fee[k])){
                    dist[k] = new_dist;
                    fee[k] = new_fee;
                }
            }
        }
    }
    cout << dist[d] << " " << fee[d] << endl;
    return 0;
}