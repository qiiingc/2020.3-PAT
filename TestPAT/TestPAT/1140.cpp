#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1140.in","r", stdin);
    int d,n;
    cin>>d>>n;
    string s=to_string(d);
    for(int i=0;i<n-1;i++){
        int len=s.size(),same=1;
        string t="";
        for(int j=0;j<len;j++){
            if(j+1<len){
                if(s[j]==s[j+1]){
                    same++;
                }else {
                    t+=s[j];
                    t+=to_string(same);
                    same=1;
                }
            }else {
                t+=s[j];
                t+=to_string(same);
            }
            
        }
        s=t;

    }
    cout<<s<<endl;
    return 0;
}
