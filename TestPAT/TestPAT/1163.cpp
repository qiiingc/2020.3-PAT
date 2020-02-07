#include "0.h"
int d[maxn],s[maxn];
int G[maxn][maxn];
bool visit[maxn];
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1163.in","r", stdin);
    int n,m,a,b,c,k;
    scanf("%d %d\n",&n,&m);
    fill(G[0],G[0]+maxn*maxn,INF);
    while(m--){
        scanf("%d %d %d\n",&a,&b,&c);
        G[a][b]=G[b][a]=c;
    }
    scanf("%d\n",&k);
    while(k--){
        m=n;
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
        }
        bool f=true;
        int start=s[1];
        fill(visit,visit+maxn,false);
        fill(d,d+maxn,INF);
        d[start]=0;
        printf("s[i] u minn d[s[i]]\n");
        for(int i=1;i<=n;i++){
            int u = -1, minn = INF;
            for (int j = 1; j <= n; j++) {
                if (!visit[j] && d[j] < minn) {
                    u = j;
                    minn = d[j];
                }
            }
            printf("%3d %2d %3d %3d\n",s[i],u,minn,d[s[i]]);
            if (u == -1 || minn != d[s[i]]){
                f=false;
                break;
            }
            u = s[i];
            visit[u]=true;
            for(int v=1;v<=n;v++){
                if(!visit[v] && G[u][v]!=INF && G[u][v]+d[u]<d[v]){
                    d[v]=G[u][v]+d[u];
                }
            }
        }
        if(!f)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
