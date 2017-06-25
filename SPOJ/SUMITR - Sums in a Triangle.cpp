#include <iostream>
#define a std::
#define b for(j=0;j<=i;++j)
int t,i,j,n,g[101][101];int main(){a cin>>t;while(t--){a cin>>n;for(i=0;i<n;++i)b a cin>>g[i][j];for(i=n-2;i>=0;--i)b g[i][j]+=a max(g[i+1][j],g[i+1][j+1]);a cout<<g[0][0]<<'\n';}}

