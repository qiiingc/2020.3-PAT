#include "0.h"
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
bool isPrime(int n){
    if(n<3)return false;
    int x=(int)sqrt(n);
    for(int i=2;i<=x;i++){
        if(n%i==0)return false;
    }
    return true;
}
int sum(int n){
    if(n==0)return 0;
    return sum(n/10)+n%10;
}
struct node{
    int id,data;
};
bool cmp(node a,node b){
    return a.id==b.id?a.data<b.data:a.id<b.id;
}
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1160.in","r", stdin);
    int n=6,k=4,m=45;
    //scanf("%d\n",&n);
    for(int j=1;j<=n;j++){
        printf("Case %d\n",j);
        int a=pow(10,k-1),b=pow(10,k);
        vector<node> v;
        for(int p=a;p<b;p++){
            if(sum(p)==m){
                int c=sum(p+1);
                if(isPrime(gcd(m, c))){
                    v.push_back({c,p});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(int q=0;q<v.size();q++){
            if(v[q].data%100!=99)printf("%d %d\n",v[q].id,v[q].data);
        }
        if(v.size()==0){
            printf("No Solution\n");
        }
        k++;
    }
    return 0;
}



