#include "0.h"
int n,l;
long long a,b,c;
string s;
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1156.in","r", stdin);
    scanf("%d\n",&n);
    while(n--){
        cin>>s;
        l=(int)s.size();
        a=stoll(s.substr(0,l/2));
        b=stoll(s.substr(l/2,l/2));
        c=stoll(s);
        if(a==0||b==0)cout<<"No"<<endl;
        else if(c%(a*b)==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
