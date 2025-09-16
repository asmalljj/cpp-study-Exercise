#include<iostream>
using namespace std;

const int MAX_NODES = 100;//图中的最大结点数量
const int INF = 9999999;//无穷大

int graph[MAX_NODES][MAX_NODES];//邻接矩阵
int dist[MAX_NODES];//最短的距离
bool visited[MAX_NODES];//是否已经确定最短距离
int numNodes;//节点数量

void initialgraph(){//初始化图，将所有节点间的距离变为无穷大
    for (int i = 0; i < MAX_NODES; i++){
        for (int j = 0; j < MAX_NODES; j++){
            graph[i][j] = INF;
        }
        graph[i][i] = 0;
    }
}

void addEdge(int from, int to, int weight){
    graph[from][to] = weight;
}

//查找当前未访问的节点中距离最小的点
int findmindistance(){
    int mindist = INF;
    int minindex = -1;

    for (int i = 0; i < numNodes; i++){
        if(!visited[i] && dist[i] < mindist){
            mindist = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

void Dijkstra(int source){//source是源节点的意思  就是起点
    //初始化距离数组和访问标记数组
    for (int i = 0; i < numNodes; i++){
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;
    for (int i = 0; i < numNodes - 1; i++){
        int u = findmindistance();
        if (u == -1) break;
        visited[u] = true;
        for (int i = 0; i < numNodes; i++){
            if(!visited[i] && graph[u][i] != INF && dist[u] + graph[u][i] < dist[i]){
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }
}

//打印结果
void printresult(int source){
    cout << "从节点" << source << "到各个结点的最短距离：" <<endl;
    for ( int i = 0; i < numNodes; i++){
        if(dist[i] == INF) cout << "无法到达" <<endl;
        else cout << dist[i] <<endl;
     }
}

int main() {
    // 设置节点数量
    numNodes = 6;
    
    // 初始化图
    initialgraph();
    
    // 添加边 (起点, 终点, 权重)
    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 5);
    addEdge(2, 3, 8);
    addEdge(2, 4, 10);
    addEdge(3, 4, 2);
    addEdge(3, 5, 6);
    addEdge(4, 5, 3);
    
    // 从节点0开始执行Dijkstra算法
    int sourceNode = 0;
    Dijkstra(sourceNode);
    
    // 打印结果
    printresult(sourceNode);
    
    return 0;
}