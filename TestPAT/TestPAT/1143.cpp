#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
vector<int> pre;
int main() {
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1143.in","r", stdin);
    int m, n, a, b,root;
    scanf("%d %d",&m,&n);
    pre.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
        mp[pre[i]]=true;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        for(int j=1;j<=n;j++){
            root=pre[j];
            if((root>=a && root<=b)||(root>=b && root<=a))break;
        }
        if(mp[a]==false && mp[b]==false){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(mp[a]==false || mp[b]==false){
            printf("ERROR: %d is not found.\n",mp[a]==0?a:b);
        }else if(a==root || b==root){
            printf("%d is an ancestor of %d.\n",root,a==root?b:a);
        }else{
            printf("LCA of %d and %d is %d.\n",a,b,root);
        }
    }
    return 0;
}
