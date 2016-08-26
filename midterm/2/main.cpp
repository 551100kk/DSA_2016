#include<bits/stdc++.h>
using namespace std;
vector<int> arr,pre,in,post;
void dfs(int u){
    if(u>=arr.size() || arr[u]==-1) return;
    pre.push_back(arr[u]);
    dfs(u*2);
    in.push_back(arr[u]);
    dfs(u*2+1);
    post.push_back(arr[u]);
}
int main(){
    int x;
    while(scanf("%d",&x)!=EOF){
        arr.push_back(x);
    }
    dfs(1);
    for(int i=0;i<pre.size();i++){
        if(i) putchar(' ');
        printf("%d",pre[i]);
    }
    puts("");
    for(int i=0;i<in.size();i++){
        if(i) putchar(' ');
        printf("%d",in[i]);
    }
    puts("");
    for(int i=0;i<post.size();i++){
        if(i) putchar(' ');
        printf("%d",post[i]);
    }
    puts("");
}
