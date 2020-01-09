#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1140.in","r", stdin);
    int d,n;
    cin>>d>>n;
    string s=to_string(d),t;
    for(int i=0;i<n;i++){
        map<char,int> mp;
        int num=1,len=(int)s.size();
        vector<int> a(len+5);
        vector<char> b(len+5);
        for(int j=0;j<len;j++){
            if(mp[s[j]]!=0)a[mp[s[j]]]++;
            else {
                mp[s[j]]=num;
                b[num]=s[j];
                a[num]++;
                num++;
            }
        }
        s="";
        len=(int)mp.size();
        for(int j=1;j<=len;j++){
            s+=b[j];
            s+=to_string(a[j]);
        }
        cout<<s<<endl;
    }
    return 0;
}
