#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1108.in","r", stdin);
    int n,num=0;
    double total=0.0;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        bool f=true;
        int dot=0;
        int len=s.size();
        for(int j=0;j<len;j++){
            if(s[j]!='-' && s[j]!='.' && !isdigit(s[j])){
                f=false;
            }
            if(s[j]=='.'){
                dot++;
            }
        }
        if(dot>1){
            f=false;
        }
        
        if(f){
            int pos=s.find('.');
            int zero=s.find_last_not_of('0');
            if(pos!=-1){
                if(zero-pos>2){
                    f=false;
                }
            }
        }
        if(f && (stof(s)>1000.0 || stof(s)<-1000.0)){
            f=false;
        }
        if(!f){
            cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
        }else{
            num++;
            total+=stod(s);
        }
    }
    if(num==0){
        cout<<"The average of 0 numbers is Undefined";
    }else if(num==1){
        cout<<"The average of 1 numbers is "<<total;
    }else{
        printf("The average of %d numbers is %.2f",num,(double)total/num);
    }
    return 0;
}
