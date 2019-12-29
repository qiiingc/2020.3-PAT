#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1065.in","r", stdin);
    int n;
    long long a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(a>0&&b>0&&c<=0)printf("Case #%d: %s\n",i+1,"false");
        else if(a<0&&b<0&&c>=0)printf("Case #%d: %s\n",i+1,"false");
        else printf("Case #%d: %s\n",i+1,a+b>c?"true":"false");
    }
    
    return 0;
}

