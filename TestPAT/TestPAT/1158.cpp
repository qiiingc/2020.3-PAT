#include "0.h"
int n,m,k;
int father[maxn],G[maxn][maxn],visit[maxn];
vector<int> gang;
int findfather(int v){
    if(v==father[v])return v;
    int F=findfather(father[v]);//曾经写错过
    father[v]=F;
    return F;
}
void u(int a,int b){
    int faA=findfather(a);
    int faB=findfather(b);
    if(faA < faB){
        father[faA]=faB;
    }else if(faA > faB){
        father[faB]=faA;
    }
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1158.in","r", stdin);
    scanf("%d %d %d",&k,&n,&m);
    fill(G[0],G[0]+maxn*maxn,0);
    fill(visit,visit+maxn,0);
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        G[a][b]+=c;
    }
    for(int i=1;i<=n;i++){
        int sc=0,bc=0;
        for(int j=1;j<=n;j++){//曾经写错过
            if(i==j)continue;
            if(G[i][j]>0 && G[i][j]<=5){
                sc++;
                if(G[j][i]>0){
                    bc++;
                }
            }
        }
        //cout<<sc<<" "<<bc<<endl;
        if(sc>k && bc*5<=sc){//曾经写错过
            gang.push_back(i);
        }
    }
    for(int i=0;i<gang.size();i++){//曾经写错过
        for(int j=0;j<gang.size();j++){//曾经写错过
            if(i==j)continue;
            int x=gang[i],y=gang[j];//曾经写错过
            if(G[x][y]!=0 && G[y][x]!=0){
                u(x,y);
            }
        }
    }
    for(int i=0;i<gang.size();i++){//曾经写错过
        int x=gang[i];
        if(visit[x]==1)continue;
        visit[x]=1;
        printf("%d",x);
        for(int j=i+1;j<gang.size();j++){
            int y=gang[j];
            if(visit[y]==0 && findfather(x)==findfather(y)){
                visit[y]=1;
                printf(" %d",y);
            }
        }
        printf("\n");
    }
    if(gang.size()==0)printf("None\n");
    return 0;
}
