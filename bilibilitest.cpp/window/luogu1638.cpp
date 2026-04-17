#include<iostream>
#include<queue>
using namespace std;
const int N=1e8;
int b[2005];
int a[N],s,ans = 0;
int  main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1 ;i <= n;i++)
    {
        cin>>a[i];
    }
    int ans= n,pl=0,pr =0;
    int l=1;
    for(int i = 1;i<=n; i++){
        if(b[a[i]]==0){
            s++;
        }
        b[a[i]]++;

        if(s==m){
           while(b[a[l]]>1){
            b[a[l]]--;
            l++;
           }
           if(i-l<ans){
              ans = i-l;
              pl = l;
              pr = i;
           }
        }
    }

    cout<< pl <<" "<<pr<<"\n";
    return 0;
}