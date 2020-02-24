#include "0.h"
int G[maxn][maxn];
int a[maxn],b[maxn];
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1142.in","r", stdin);
    int n,m,k,l,u,v;
    cin>>n>>m;
    fill(G[0],G[0]+maxn*maxn,0);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u][v]=G[v][u]=1;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>l;
        fill(a,a+maxn,0);
        fill(b,b+maxn,0);
        for(int j=0;j<l;j++){
            cin>>u;
            a[u]=1;
            b[j]=u;
        }
        int maxc=0,cliq=1;
        for(int j=0;j<l-1;j++){
            for(int p=j+1;p<l;p++){
                if(G[b[j]][b[p]]==0){
                    cliq=0;
                }
            }
        }
        if(cliq==0){
            cout<<"Not a Clique"<<endl;
            continue;
        }
        for(int p=1;p<=n;p++){
            for(int j=0;j<l;j++){
                if(a[p]==0 && G[b[j]][p]==1){
                    maxc++;
                }
            }
            if(maxc==l){
                break;
            }else{
                maxc=0;
            }
        }
        if(maxc==l){
            cout<<"Not Maximal"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
        
    }
    return 0;
}


