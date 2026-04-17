/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-03 19:49:03
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-03 20:39:12
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\qianzuihe\luogu2004.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

#define int long long
const int N=2100;
int a[N][N];

signed main(){
    int m,n,c;
    cin>>m>>n>>c;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];a[i][j]+=a[i-1][j]+a[i][j-1];a[i][j]-=a[i-1][j-1];
        }
    }
    
    int ans=-122443323322;
    int u,v;
    for(int i=c;i<=m;i++)
    for(int j=c;j<=n;j++){
        int x1=i-c+1;
        int y1=j-c+1;
        int res=a[i][j]-a[x1-1][j]-a[i][y1-1]+a[x1-1][y1-1];

        if(res>ans){
            u=x1,v=y1;
            ans=res;
        }
    }

    cout<< u <<" "<< v <<"\n";
    return  0;
}