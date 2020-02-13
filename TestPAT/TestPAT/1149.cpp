#include "0.h"
int n,m,k,u,w;
map<int, vector<int>> mp;
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1149.in","r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d %d",&u,&w);
        mp[u].push_back(w);
        mp[w].push_back(u);
    }
    vector<int> v,a(100000);
    while(m--){
        v.clear();
        a.clear();
        cin>>k;
        for(int i=0;i<k;i++){
            scanf("%d",&u);
            v.push_back(u);
            a[u]=1;
        }
        bool f=true;
        for(auto i:v){
            for(auto j:mp[i]){
                if(a[j]==1){
                    f=false;
                    break;
                }
            }
        }
        printf("%s\n",f?"Yes":"No");
    }
    return 0;
}
