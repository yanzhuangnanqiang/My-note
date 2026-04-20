/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-10 21:27:29
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-19 11:59:09
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\cupidity\luogu1250.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n; vector<int> b;
    BIT(int n=0): n(n), b(n+1,0) {}
    void add(int i,int v){ for(; i<=n; i+=i&-i) b[i]+=v; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=b[i]; return s; }
    int rangeSum(int l,int r){ return sum(r)-sum(l-1); }
};

struct Q{ int l,r,w; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; 
    cin >> n >> m;
    vector<Q> q(m);
    for(int i=0;i<m;i++) cin >> q[i].l >> q[i].r >> q[i].w;

    sort(q.begin(), q.end(), [](const Q& a, const Q& b){ return a.r < b.r; });

    // DSU: find(x) = <=x 的最右空位(还没种树的位置)，0 表示没有
    vector<int> fa(n+1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> findp = [&](int x){
        if(x<=0) return 0;
        return fa[x]==x ? x : fa[x]=findp(fa[x]);
    };

    BIT bit(n);
    int ans=0;

    for(auto &cur: q){
        int L=cur.l, R=cur.r, W=cur.w;
        int have = bit.rangeSum(L,R);     // 区间已种树数量
        while(have < W){
            int pos = findp(R);           // 从R往左找空位
            if(pos < L) break;            // 若题目保证可行，这句不会触发
            bit.add(pos, 1);              // 种树
            ans++; have++;
            fa[pos] = findp(pos-1);       // 删除空位：下次跳到左边
        }
    }

    cout << ans << "\n";
    return 0;
}