#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1065.in","r", stdin);
    int n;
    string a;
    
    cin>>n;
    for(int i=0;i<n;i++){
        long long b=0,c=0,d=0;
        cin>>a;
        if(a=="9223372036854775808"){
            b=9223372036854775807;
            d-=1;
        }else b=stoll(a);
        cin>>a;
        if(a=="9223372036854775808"){
            c=9223372036854775807;
            d-=1;
        }else c=stoll(a);
        cin>>a;
        if(a=="9223372036854775808"){
            d+=9223372036854775807;
            b-=1;
        }else d+=stoll(a);
        if(b>0&&c>0&&d<0)printf("Case #%d: %s\n",i+1,"false");
        else if(b<0&&c<0&&d>0)printf("Case #%d: %s\n",i+1,"false");
        else printf("Case #%d: %s\n",i+1,b+c>d?"true":"false");
        
    }
    
    return 0;
}

