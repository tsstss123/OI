#include<bits/stdc++.h>
using namespace std;
int f[1<<20];
int a[20][20];
int c[20][20];
char s[20][20];
int n,m;
int st[20][20];
int bit[1<<20];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<20;i++)bit[1<<i]=i;
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		int tmp=0;
		for(int k=0;k<n;k++)if(s[i][j]==s[k][j])
			st[i][j]|=1<<k,c[i][j]+=a[k][j],tmp=max(tmp,a[k][j]);
		c[i][j]-=tmp;
	}
	for(int S=1;S<(1<<n);S++){
		int l=bit[S&-S];f[S]=1e9;
		for(int i=0;i<m;i++){
			f[S]=min(f[S],f[S^(1<<l)]+a[l][i]);
			f[S]=min(f[S],f[S&(S^st[l][i])]+c[l][i]);
		}
	}
	cout<<f[(1<<n)-1]<<endl;
	return 0;
}
