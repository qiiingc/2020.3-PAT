#include "0.h"
int n,m;
//int a[maxn];
//struct node{
//    int a[7][7];
//};
//vector<node> v[26];
char v[26][7][5];
void prtarr(int w,int x,int s,int e){
    cout<<w<<" "<<x<<endl;
    for(int z=s;z<=e;z++){
        cout<<v[w][x][z];
    }
    cout<<endl;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1164.in","r", stdin);
    for(int i=0;i<26;i++){
       for(int j=0;j<7;j++){
           for(int k=0;k<5;k++){
                scanf("%c",&v[i][j][k]);
                //printf("%c",v[i][j][k]);
            }
            getchar();
            //cout<<endl;
        }
    }
    char ch;
    bool f=false;
    vector<int> word;
    while(cin>>ch){
        if(isupper(ch)){
            word.push_back(ch-'A');
        }else {
            //cout<<word[0]<<" "<<word[1]<<endl;
            if(f)printf("\n");
            int len=word.size()*6;
            char w[7][len];
            for(int i=0;i<7;i++){
                //cout<<word[k]+'A';
                //printf("%c",word[k]+'A');
                int k=0;
                for(int j=0;j<len;j++){

                        if(j>0&& (j+1)%6==0){
                            w[i][j]=' ';
                            k++;
                        }
                        else w[i][j]=v[word[k]][i][j%6];


                }
            }
            for(int i=0;i<7;i++){
                for(int j=0;j<len;j++){
                    if(w[i][j]-' '!=0)printf("%c",w[i][j]);
                    else printf(" ");
                }
                printf("\n");
            }
            f=true;
            word.clear();
        }
    }
    return 0;
}
