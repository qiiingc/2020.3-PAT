#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1136.in","r", stdin);
    string s,r;
    long long p;
    cin>>s;
    r=s;
    reverse(r.begin(), r.end());
    if(r==s){
        cout<<s<<" is a palindromic number.";
        return 0;
    }
    bool f=false;
    for(int i=0;i<10;i++){
        p=stoll(s)+stoll(r);
        cout<<s<<" + "<<r<<" = "<<p<<endl;
        s=to_string(p);
        r=s;
        reverse(r.begin(), r.end());
        if(r==s){
            cout<<p<<" is a palindromic number.";
            f=true;
            break;
        }
    }
    if(!f){
        cout<<"Not found in 10 iterations.";
    }
    return 0;
}
