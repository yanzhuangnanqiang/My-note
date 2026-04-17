/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-05 21:23:48
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-06 11:53:45
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\sort\sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
ll n;
const int N = 100000;
int a[N];
int c[N];

int max_val;



struct arr{
    int q,w;
};

//自定义规则
bool cmp(arr a1,arr a2){
    return a1.q > a2.q;
}

arr a1[N];

void solve(){
    //三种方式

    int n;
    cin>>n;
    //数组
    int a[N]; 
    sort(a+1,a+n+1);//这是一个半开半闭区间， 前一个为起点，后一个为边界的下一个数

    //vector容器
    vector<int> vl;
    sort(vl.begin()+1,vl.end());
 
    // struct 结构体
   
    for(int i=1;i<=n;i++){
        cin>>a1[i].q;
        a1[i].w=i;
    }
    sort(a+1,a+n+1,cmp); //自定义规则
}

int main(){
    //插入排序
    //个人理解就是对前 i-1 个数进行排序
    // for (int i=2;i<=n;i++){
    //     int key=a[i];
    //     int j=i-1;
    //     while(j>=1 && a[j]>key){
    //         a[j+1]=a[j];
    //         j--;
    //     }

    //     a[j+1] =key;
    // }

    //桶排序(计数排序)
    for(int i=1;i<=n;i++){
        c[a[i]]++;
        max_val=max(max_val,a[i]);
    }

    int t=0;
    for(int i=0;i<=max_val;i++){
        while(c[i]>0)
        {
            a[++t] = i;
            c[i] --;
        }
    }
    // 自定义排序


    return 0;
}