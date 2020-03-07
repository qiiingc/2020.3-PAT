#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,int> pos;
vector<int> pre,in;
void lca(int inl,int inr,int preRoot,int a,int b){
    if(inl>inr)return;
    int inRoot=pos[pre[preRoot]],aIn=pos[a],bIn=pos[b];
    if(aIn<inRoot && bIn<inRoot){
        lca(inl,inRoot-1,preRoot+1,a,b);
    }else if(aIn>inRoot && bIn>inRoot){
        lca(inRoot+1,inr,preRoot+inRoot-inl+1,a,b);
    }else if((aIn<inRoot && bIn>inRoot)||(aIn>inRoot && bIn<inRoot)){
        printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
    }else if(aIn==inRoot){
        printf("%d is an ancestor of %d.\n",a,b);
    }else if(bIn==inRoot){
        printf("%d is an ancestor of %d.\n",b,a);
    }
}
int main() {
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1151.in","r", stdin);
    int m, n, a, b;
    scanf("%d %d",&m,&n);
    pre.resize(n+1);
    in.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&in[i]);
        pos[in[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        if(pos[a]==0 && pos[b]==0){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(pos[a]==0 || pos[b]==0){
            printf("ERROR: %d is not found.\n",pos[a]==0?a:b);
        }else{
            lca(1,n,1,a,b);
        }
    }
    return 0;
}
