#include<bits/stdc++.h>
using namespace std;
vector<int> sta,ans;
int n;
void dfs(int u,int add){
    if(u==n*2){
        int flag=0;
        for(int i=0;i<ans.size();i++){
            if(i) putchar(' ');
            printf("%d",ans[i]);
        }
        puts("");
        return;
    }

    if(sta.size()){
        ans.push_back(sta.back());
        sta.pop_back();
        dfs(u+1,add);
        sta.push_back(ans.back());
        ans.pop_back();
    }

    if(add<=n){
        sta.push_back(add);
        dfs(u+1,add+1);
        sta.pop_back();
    }
}
int main(){
    scanf("%d",&n);
    dfs(0,1);
}
