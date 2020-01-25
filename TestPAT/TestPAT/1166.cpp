#include "0.h"
int n,m,k;
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1167.in","r", stdin);
    scanf("%d %d\n",&n,&m);
    int G[n+5][n+5];
    vector<vector<int>> va(n+5);
    va.clear();
    int u,v,l;
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&u,&v);
        G[u][v]=G[v][u]=1;
        va[u].push_back(v);
        va[v].push_back(u);
    }
    scanf("%d\n",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&l);
        int a[l];
        set<int> s;
        for(int j=0;j<l;j++){
            scanf("%d",&a[j]);
            s.insert(a[j]);
        }
        if(l==1&&va[a[0]].size()==0){
            printf("Area %d is OK.\n",i+1);
            continue;
        }
        bool f1=true,f2=true;
        for(int j=0;j<l-1;j++){
            for(int k=j+1;k<l;k++){
                int x=a[j],y=a[k];
                if(G[x][y]!=1){
                    f1=false;
                }
            }
        }
        if(!f1){
            printf("Area %d needs help.\n",i+1);
        }else{
            int minn=n+1;
            for(int j=0;j<l;j++){
                for(int k=1;k<=n;k++){
                    bool f3=true;
                    for(auto it:s){
                        if(G[k][it]!=1){
                            f3=false;
                        }
                    }
                    if(f3 && s.find(k)==s.end() && k<minn){
                        minn=k;
                        f2=false;
                    }
                }
            }
            if(f2){
                printf("Area %d is OK.\n",i+1);
            }else{
                printf("Area %d may invite more people, such as %d.\n",i+1,minn);
            }
        }

    }


    return 0;
}


