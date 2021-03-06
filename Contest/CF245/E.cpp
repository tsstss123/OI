#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
pair<int,int>st[maxn];
vector<int>G[maxn];
int col[maxn],suc=1;
void dfs(int u){
	for(int i=0;i<G[u].size();i++)
		if(col[G[u][i]]==-1)
			col[G[u][i]]=col[u]^1,dfs(G[u][i]);
		else if(col[G[u][i]]!=(col[u]^1))
			suc=0;
}	   
int main(){
	scanf("%d",&n);
	for(int i=0,l,r;i<n;i++){
		scanf("%d%d",&l,&r);
		st[m++]=make_pair(l<<1,i<<1);
		st[m++]=make_pair((r<<1)+1,(i<<1)+1);
		G[i<<1].push_back(1+(i<<1));
		G[(i<<1)+1].push_back(i<<1);
	}sort(st,st+m);
	for(int i=0;i<n;i++){
		int u=st[i<<1].second,v=st[1+(i<<1)].second;
		G[u].push_back(v);
		G[v].push_back(u);
	}memset(col,-1,sizeof col);
	for(int i=0;i<(n<<1);i++)
		if(col[i]==-1)col[i]=0,dfs(i);
	if(!suc)return puts("-1"),0;
	for(int i=0;i<(n<<1);i+=2)
		printf("%d ",col[i]);
	puts("");
}
