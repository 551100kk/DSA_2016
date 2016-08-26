#include<bits/stdc++.h>
using namespace std;
vector<int> all,pre,post;
int s[5000000];
int flag,tmp,big;
void check(int u){
    if(s[u]==-1) return;
    tmp++;
    if(u>big) big=u;
    if(s[u*2]==-1 && s[u*2+1]!=-1 || s[u*2]!=-1 && s[u*2+1]==-1){
        flag=0;
        return;
    }
    check(u*2);
    check(u*2+1);
}
void dfs(int u,int l,int r,int L,int R){
    if(l==r) return;
    if(pre[l]!=post[R-1]) return;
    s[u]=pre[l];
    flag=1,tmp=0,big=0;
    check(1);
    if(flag && tmp==pre.size()){
        for(int i=0;i<=big;i++){
            printf("%d ",s[i]);
        }
        puts("");
        exit(0);
    }
    for(int i=l+2;i<=r-1;i++){
        vector<int> A,B;
        for(int j=l+1;j<i;j++){
            A.push_back(pre[j]);
            B.push_back(post[j-l-1+L]);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        if(A==B){
            dfs(u*2,l+1,i,L,i-l-1+L);
            dfs(u*2+1,i,r,i-l-1+L,R-1);
            //break;
        }
    }
}
int main(){
    int x;
    memset(s,-1,sizeof(s));
    while(scanf("%d",&x)!=EOF){
        all.push_back(x);
    }
    int n=all.size()/2;
    for(int i=0;i<n;i++){
        pre.push_back(all[i]);
        post.push_back(all[i+n]);
    }
    dfs(1,0,n,0,n);
}
