#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1152.in","r", stdin);
    int l,n,k;
    cin>>l>>n;
    string s,t;
    cin>>s;
    for(int i=0;i<l-n+1;i++){
        k=stoi(s.substr(i,n));
        if(k<2)continue;
        int x=(int)sqrt(k*1.0);
        bool f=true;
        for(int j=2;j<=x;j++){
            if(k%j==0)f=false;
        }
        if(f){
            cout<<s.substr(i,n)<<endl;
            return 0;
        }
    }
    cout<<"404";
    return 0;
}
