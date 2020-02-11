#include "0.h"
int n,i,a[100005];
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1144.in","r", stdin);
    scanf("%d\n",&n);
    while(n--){
        scanf("%d",&i);
        if(i>0 && i<100001)a[i]=1;
    }
    for(i=1;i<=100001;i++){
        if(a[i]!=1){
            cout<<i;
            break;
        }
    }
    return 0;
}
