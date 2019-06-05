#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <limits.h>
#define rep(i,a) for(i=0;i<a;i++)
#define lp(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
typedef long long ll;
typedef unsigned long ul;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //begin here
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,m,i,j;
    cin>>n>>m;
    ll **mat,**dp1,**dp2,**dp3,**dp4;
    mat = new ll*[n+2];
    dp1 = new ll*[n+2];
    dp2 = new ll*[n+2];
    dp3 = new ll*[n+2];
    dp4 = new ll*[n+2];
    for(i=0;i<=n+1;i++){
        mat[i] = new ll[m+2];
        dp1[i] = new ll[m+2];
        dp2[i] = new ll[m+2];
        dp3[i] = new ll[m+2];
        dp4[i] = new ll[m+2];
        for(j=0;j<=m+1;j++){
            mat[i][j] = dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){cin>>mat[i][j];}
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+mat[i][j];
        }
    }
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            dp2[i][j] = max(dp2[i+1][j],dp2[i][j-1])+mat[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp4[i][j] = max(dp4[i-1][j],dp4[i][j+1])+mat[i][j];
        }
    }
    for(i=n;i>=1;i--){
        for(j=m;j>=1;j--){
            dp3[i][j] = max(dp3[i+1][j],dp3[i][j+1])+mat[i][j];
        }
    }
    ll ans=-1;
    for(i=2;i<n;i++){
        for(j=2;j<m;j++){
            ans= max(ans,max(dp1[i][j-1]+dp2[i+1][j]+dp4[i-1][j]+dp3[i][j+1],dp1[i-1][j]+dp2[i][j-1]+dp3[i+1][j]+dp4[i][j+1]));
        }
    }
    cout<<ans;
    return 0;
}
