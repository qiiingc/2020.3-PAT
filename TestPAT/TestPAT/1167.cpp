#include "0.h"
int n,m,k;
int G[205][205];
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1167.in","r", stdin);
    scanf("%d %d\n",&n,&m);
    int u,v,l;
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&u,&v);
        G[u][v]=G[v][u]=1;
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
            for(int j=0;j<l-1;j++){
                for(int k=1;k<=n;k++){
                    if(G[a[j]][k]==1 && s.find(k)==s.end()){
                        f2=false;
                        bool f3=true;
                        for(auto it:s){
                            if(G[k][it]!=1){
                                f3=false;
                            }
                        }
                        if(f3 && k<minn)minn=k;
                    }
                }
            }
            if(!f2){
                printf("Area %d is OK.\n",i+1);
            }else{
                printf("Area %d may invite more people, such as %d.\n",i+1,minn);
            }
        }

    }


    return 0;
}

