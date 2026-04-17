/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-09 19:51:32
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-09 20:36:23
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\serch\DFS\luogu1596.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;
const int N=150;
bool visited[N][N];
int cnt;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
char pool[N][N];
int n,m;
void dfs(int x,int y){
     
    visited[x][y] =true;

    for(int i=0;i<8;i++){
        int nx= x + dx[i];
        int ny= y + dy[i];
        if(nx>=0 && nx < n && ny>=0 && ny<m && 
            pool[nx][ny]=='W'&&!visited[nx][ny]){
            dfs(nx,ny);
        }
    }

}

int main(){
    

    cin>>n >>m;

    for(int i=0;i<n;i++){
        cin>>pool[i];
    }   
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pool[i][j]=='W'&& !visited[i][j])
            {
                dfs(i,j);
                cnt++;
            }
        }
    }   

    cout<< cnt <<"\n";
    return 0;
}