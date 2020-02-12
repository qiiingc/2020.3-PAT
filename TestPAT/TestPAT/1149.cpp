#include "0.h"
int n,m,k,a,b;
map<int, set<int>> mp;
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1149.in","r", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    cin>>k;
    for(int i=0;i<m;i++){
        set<int> s;
        bool f=true;
        for(int j=0;j<k;j++){
            cin>>a;
            if(!s.empty()){
                for(auto it:s){
                    if(mp[a].find(it)!=mp[a].end()){
                        cout<<"No"<<endl;
                        f=false;
                        break;
                    }
                }
                if(!f)break;
            }
            s.insert(a);
        }
        if(f)cout<<"Yes"<<endl;
    }
    return 0;
}
