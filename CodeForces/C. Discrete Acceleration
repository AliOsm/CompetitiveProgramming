#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define nl cout<<"\n";
#define ll double
#define REP(i,a,n) for(i=a;i<=n;i++)
#define F(i,a,b) for(i=a;i<b;i++)
#define RF(i,b,a) for(i=b;i>=a;i--)
#define IOS  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const ll mod=1e9;
const ll MAXN=100200;
ll i,j,mask,test;
int main()
{
IOS
/*#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE*/
ll test;
cin>>test;
while(test--)
{
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    F(i,0,n)
    {
        cin>>a[i];
    }
    ll l=0,r=d;
    i=0;j=n-1;
    ll time=0;
    ll s=1,p=1;
    while(i<=j)
    {
        ll minn=min((double)(a[i]-l)/s,(double)(r-a[j])/p);
        l+=(double)s*minn;
        r-=(double)p*minn;
        time+=minn;
        if(l==a[i])
            {
                i++;
                s++;
            }
        if(r==a[j])
            {
                j--;
                p++;
            }
    }
    //cout<<r<<" "<<l<<" "<<s<<" "<<p;nl
    time+=(double)(r-l)/(s+p);
    cout << fixed << setprecision(13) <<time;
    nl
}
return 0;
}
