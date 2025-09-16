#include<iostream>
using namespace std;

const int rows = 7;
const int cols = 13;

char graph[rows][cols] = {
    {'A','A','I','A','A','A','A','A','A','A','A','A','A'},
    {'A','A',' ','A','A',' ',' ',' ',' ',' ','A','A','A'},
    {'A',' ',' ',' ',' ',' ','A',' ','A',' ',' ',' ','A'},
    {'A','A','A',' ','A','A',' ',' ',' ','A','A',' ','A'},
    {'A','A',' ',' ',' ',' ',' ',' ','A','A',' ',' ','A'},
    {'A',' ',' ','A','A','A','A',' ',' ',' ',' ','A','A'},
    {'A','A','A','A','A','A','A','A','A','A','O','A','A'}
};

string allpaths[1000];//记录所有路径
int pathcount = 0;//路径数量

//是否违规，超出边界
bool isvalid(int x, int y){
    return x >= 0 && x <= rows && y >= 0 && y <= cols && graph[x][y] != 'A';
}
//遍历探索函数
void Findallpaths(int x, int y, string path, bool visited[rows][cols]){
    if (graph[x][y] == 'O'){
        allpaths[pathcount] = path;
        pathcount++;
        return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char directions[] = {'w', 's', 'a', 'd'};

    for (int i = 0; i < 4; i++){
        int NewX = x + dx[i];
        int NewY = y + dy[i];

        if (isvalid(NewX, NewY) && !visited[NewX][NewY]){
            visited[NewX][NewY] = true;
            Findallpaths(NewX, NewY, path + directions[i], visited);
            visited[NewX][NewY] = false;
        }
    }
}
//可视化路径函数
void visualizepath(string path){
    //重制一个新图
    char display[rows][cols];

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            display[i][j] = graph[i][j];
        }
    }
    //标识起点
    int x = 0, y = 2;
    display[x][y] ='S';
    //利用循环开始遍历探索
    for (int i = 0; i < path.length(); i++){
         char step = path[i];
        switch (step)
        {
            case 'w': x--; break;
            case 's': x++; break;
            case 'a': y--; break;
            case 'd': y++; break;
        }
        if (display[x][y] != 'O'){
            display[x][y] = '*';
        }
    }
    //最后打印出可视化路径
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            cout << display[i][j];
        }
        cout << endl;
    }
}
//冒泡排序的应用
void sortpaths(){
    for (int i = 0; i < pathcount - 1; i++){
        for (int j = 0; j < pathcount - j - 1; j++){
            if (allpaths[j].length() > allpaths[j + 1].length()){
                string temp = allpaths[j];
                allpaths[j] = allpaths[j + 1];
                allpaths[j + 1] = temp;
            }
        }
    }
}

int main(){
    cout << "原始迷宫" << endl;
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            cout << graph[i][j];
        }
        cout << endl;
    }
    bool visited[rows][cols] = {false};
    visited[0][2] = true;
    string path = "";

    Findallpaths(0, 2, "", visited);

    if (pathcount > 0){
        sortpaths();
        for (int i = 0; i < pathcount; i ++){
            cout << "所有路径：" << allpaths[i] << ' ' << "长度为：" << allpaths[i].length() << endl;
        }
        visualizepath(allpaths[0]);
    }
    else{
        cout << "未找到路径" << endl;
    }
}