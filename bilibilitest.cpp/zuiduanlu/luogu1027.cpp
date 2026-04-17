/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-04 14:17:37
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-04 21:23:43
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\zuiduanlu\luogu1027.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define int long long
#define f(i,a,b) for(int i=a;i<=b;i++)
const int inf= 0x7f7f7f7f;
int s,A,B,T;
double x[410],y[410],_t[110];
double diss(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double ds(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
double ans =inf,t ,dis[410][410];

signed main()
{
    scanf("%lld",&T);
    while (T--){
        memset(dis,0 ,sizeof(dis)),ans =inf;
        scanf("%lld%lf%lld%lld",&s,&t,&A,&B);
        f(i,1,s){
            scanf("%lf%lf%lf%lf%lf%lf%lf",&x[(i-1)*4+1],&y[(i-1)*4+1],
            &x[(i-1)*4+2],& y[(i-1)*4+2],
            &x[(i-1)*4+3],&y[(i-1)*4+3],  &_t[i]);
        double dab=ds(x[(i-1)*4+1],y[(i-1)*4+1],x[(i-1)*4+2],y[(i-1)*4+2]);
        double dac= ds(x[(i-1)*4+1],y[(i-1)*4+1],x[(i-1)*4+3],y[(i-1)*4+3]);
        double dbc= ds(x[(i-1)*4+2],y[(i-1)*4+2],x[(i-1)*4+3],y[(i-1)*4+3]);
       if(dab+dac==dbc){ x[i*4]=x[(i-1)*4+2]+x[(i-1)*4+3]-x[(i-1)*4+1];
            y[i*4]=y[(i-1)*4+2]+y[(i-1)*4+3]-y[(i-1)*4+1];
       }
        else if(dab+dbc==dac){ x[i*4]=x[(i-1)*4+1]+x[(i-1)*4+3]-x[(i-1)*4+2];
            y[i*4]=y[(i-1)*4+1]+y[(i-1)*4+3]-y[(i-1)*4+2];
       }
        else if(dbc+dac==dab){ x[i*4]=x[(i-1)*4+2]+x[(i-1)*4+1]-x[(i-1)*4+3];
            y[i*4]=y[(i-1)*4+1]+y[(i-1)*4+2]-y[(i-1)*4+3];
       }
    }
    
    f(i,1,s*4) f(j,1,s*4)
    if(i!=j){
         if((i-1)/4!=(j-1)/4) dis[i][j]=t*diss(x[i],y[i],x[j],y[j]);
        else dis[i][j]=_t[(i-1)/4+1]*diss(x[i],y[i],x[j],y[j]);
    }

     //核心算法 floyd
     f(k,1,s*4)f(i,1,s*4)f(j,1,s*4) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
      
    //一个城市有有四个 机场 ，所以要遍历
     f(i,1,4)f(j,1,4) ans=min(ans,dis[(A-1)*4+i][(B-1)*4+j]);

     printf("%.1lf\n",ans);

    }
    
    return 0;
}