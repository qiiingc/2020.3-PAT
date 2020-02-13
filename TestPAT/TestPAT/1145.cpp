#include "0.h"
int ms,n,m,k,u,w;
bool f(int x){
    if(x<2)return 2;
    int sqt=(int)sqrt(x);
    for(int i=2;i<=sqt;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1145.in","r", stdin);
    cin>>ms>>n>>m;
    while(!f(ms))ms++;
    vector<int> v(ms);
    for(int i=0;i<n;i++){
        scanf("%d",&u);
        bool flag=true;
        cout<<"~~~"<<u<<" ";
        for(int j=0;j<=ms;j++){
            int pos=(u+j*j)%ms;
            cout<<pos<<" ";
            if(v[pos]==0){
                v[pos]=u;
                flag=false;
                break;
            }
        }
        cout<<endl;
        if(flag)printf("%d cannot be inserted.\n",u);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        scanf("%d",&u);
        cout<<endl;
        for(int j=0;j<=ms;j++){
            ans++;
            int pos=(u+j*j)%ms;
            cout<<pos<<" ";
            if(v[pos]==u || v[pos]==0)break;
        }
    }
    printf("%.1f",ans*1.0/m);
    return 0;
}


