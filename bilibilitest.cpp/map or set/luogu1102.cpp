#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
#define ll long long
const ll N=1e8;
ll a[N],ans;

unordered_map<ll,ll>  cnt;
int  main(){
    int n,c;
    cin>>n>>c;
    ans =0;

    for(ll i=1; i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        a[i]-=c;
    }

    for(ll i=1;i<=n;i++){
        ans+=cnt[a[i]];
    }
    
    cout<<ans<<"\n";

    return 0;
}

//双指针
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include<algorithm>//双指针！！！

// using namespace std;
// int a[200010];
// int main()
// {
// 	int N, C;long long count = 0;
// 	scanf("%d %d", &N, &C);
// 	int r1=0, r2=0, l=0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		scanf("%d", & a[i]);
// 	}
// 	sort(a, a + N);
// 	for (l; l < N; l++)
// 	{
// 		while (r1<N && a[r1] - a[l] < C)  r1++;
// 		while (r2<N && a[r2] - a[l] <= C)  r2++;
// 		if (a[r1] - a[l] == C && a[r2 - 1] - a[l] == C && r2 - 1 >= 1)
// 		count += r2 - r1;
// 	}
// 	printf("%lld", count);
// 	return 0;
// }