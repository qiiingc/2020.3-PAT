#include "0.h"
int n,m,k,u,w,c;
int G[maxn][maxn];
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1150.in","r", stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&w,&c);
        G[u][w]=G[w][u]=c;
    }
    cin>>k;
    int sp=1,sd=9999999;
    for(int i=1;i<=k;i++){
        cin>>u;
        vector<int> v(u+5);
        set<int> s;
        int dis=0,f=0;
        for(int i=1;i<=u;i++){
            scanf("%d",&v[i]);
            s.insert(v[i]);
            if(i!=1){
                dis+=G[v[i-1]][v[i]];
                if(G[v[i-1]][v[i]]==0)f=1;
            }
        }
        printf("Path %d: ",i);
        if(f==1) printf("NA ");
        else printf("%d ",dis);
        if(s.size()!=n || v[1]!=v[u] ||f==1){
            printf("(Not a TS cycle)\n");
            continue;
        }else if(u>n+1){
            printf("(TS cycle)\n");
        }else{
            printf("(TS simple cycle)\n");
            
        }
        if(sd>dis){
            sd=dis;
            sp=i;
        }
    }
    printf("Shortest Dist(%d) = %d\n",sp,sd);
    return 0;
}

