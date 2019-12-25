#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1042.in","r", stdin);
    int n,x;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]=i;
    }
    for(int i=1;i<=n;i++){
        if(i!=1)cout<<" ";
        int y=(a[i]-1)/13;
        if(y==0)cout<<"S";
        else if(y==1)cout<<"H";
        else if(y==1)cout<<"C";
        else if(y==1)cout<<"D";
        else if(y==1)cout<<"J";
        cout<<(a[i]-1)%13+1;
    }
    cout<<"S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5"<<endl;
    return 0;
}

