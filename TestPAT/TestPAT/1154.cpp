#include "0.h"

int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1154.in","r", stdin);
    int n,m,k,a,b;
    scanf("%d %d",&n,&m);
    vector<vector<int>> v(n);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        vector<int> t(n);
        set<int> kc;
        for(int j=0;j<n;j++){
            scanf("%d",&t[j]);
            kc.insert(t[j]);
        }
        bool flag=true;
        for(int j=0;j<n;j++){
            for(auto it:v[j]){
                if(t[it]==t[j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)printf("%d-coloring\n",kc.size());
        else printf("No\n");
    }
    return 0;
}
