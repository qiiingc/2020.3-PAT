#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1136.in","r", stdin);
    string s,r,k,t;
    cin>>s;
    r=s;
    reverse(r.begin(), r.end());
    if(r==s){
        cout<<s<<" is a palindromic number.";
        return 0;
    }
    bool f=false;
    for(int i=0;i<10;i++){
        k="";
        int carry=0,x;
        for(int i=0;i<s.size();i++){
            x=(s[i]-'0')+(r[i]-'0');
            k+=to_string((x%10+carry)%10);
            carry=x/10+(x%10+carry)/10;
        }
        if(carry!=0)k+=to_string(carry);
        cout<<s<<" + "<<r<<" = ";
        r=k;
        s=r;
        reverse(s.begin(), s.end());
        cout<<s<<endl;
        if(s==r){
            cout<<k<<" is a palindromic number.";
            f=true;
            break;
        }
    }
    if(!f){
        cout<<"Not found in 10 iterations.";
    }
    
    return 0;
}
