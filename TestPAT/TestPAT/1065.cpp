#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1065.in","r", stdin);
    int n;
    long long a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        printf("Case #%d: %s\n",i+1,a+b>c?"true":"false");
    }
    
    return 0;
}

