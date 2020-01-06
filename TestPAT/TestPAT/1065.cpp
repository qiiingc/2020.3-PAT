#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1065.in","r", stdin);
    int n;
    long long a,b,c,sum;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        sum=a+b;
        if(a>0&&b>0&&sum<0)printf("Case #%d: true\n",i+1);
        else if(a<0&&b<0&&sum>=0)printf("Case #%d: false\n",i+1);
        else {
            printf("Case #%d: %s\n",i+1,sum>c?"true":"false");
        }
//        if(a > 0 && b > 0 && sum < 0) {
//            printf("Case #%d: true\n", i + 1);
//        } else if(a < 0 && b < 0 && sum >= 0){
//            printf("Case #%d: false\n", i + 1);
//        } else if(sum > c) {
//            printf("Case #%d: true\n", i + 1);
//        } else {
//            printf("Case #%d: false\n", i + 1);
//        }
//        cout<<sum<<" "<<a<<" "<<b<<endl;
    }
    
    return 0;
}

