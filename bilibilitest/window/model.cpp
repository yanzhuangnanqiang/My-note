#include<iostream>

#include<queue>
using namespace std;

#define ll long long
const ll N = 1000;
ll target;
int  a[N];

int main(){
    
    int n;

    //仅仅作为样例
    int l=1,r=1,sum =0,ans =2e9;
    while(r <= n){
        sum+=a[r];
        
        //当窗口满足条件时，尝试收缩 L 指针

        while( sum>= target ){
            ans =min(ans,r-l+1);
            sum-=a[l];
            l++;
        }
        r++;
    }
    return 0;
}