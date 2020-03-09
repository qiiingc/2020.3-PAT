#include "0.h"
vector<int> pre,in;
bool flag=false;
void dfs(int ps,int is,int ie){
    if(is>ie || flag)return;
    int mid=is;
    while(mid<ie && pre[ps]!=in[mid])mid++;
    dfs(ps+1,is,mid-1);
    dfs(ps+mid-is+1,mid+1,ie);
    if(!flag){
        flag=true;
        printf("%d",pre[ps]);
    }
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1138.in", "r", stdin);
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        pre.push_back(a);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        in.push_back(a);
    }
    dfs(0,0,n-1);
    return 0;
}
