#include<bits/stdc++.h>
using namespace std;
double p[1005],q[105];
double dp[1005][105];
int is[1005][105];
vector<int> arr;
int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%lf",&p[i]);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&q[i]);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=fabs(p[0]-q[0]);
    is[0][0]=1;
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=dp[i-1][j]+fabs(p[i]-q[j]);
            if(j && dp[i-1][j-1]+fabs(p[i]-q[j])<=dp[i][j]){
                dp[i][j]=dp[i-1][j-1]+fabs(p[i]-q[j]);
                is[i][j]=1;
            }
        }
    }
    double ans=1e18;
    int x=m-1,y;
    for(int i=0;i<n;i++){
        if(dp[m-1][i]<ans){
            ans=dp[m-1][i];
            y=i;
        }
    }
    while(x>=0){
        if(is[x][y]){
            arr.push_back(x);
            x--;
            y--;
        }
        else{
            x--;
        }
    }
    printf("%f\n",ans);
    for(int i=arr.size()-1;i>=0;i--){
        printf("%d",arr[i]);
        if(i) putchar(' ');
    }
    puts("");
    //test
    /*x=arr.size()-1,y=-1;
    double sum=0;
    for(int i=0;i<m;i++){
        if(x>=0 && i==arr[x]){
            x--;
            y++;
        }
        sum+=fabs(p[i]-q[y]);
    }
    printf("%f\n",sum);
    vector<int> TA;
    while(scanf("%d",&x)!=EOF){
        TA.push_back(x);
    }
    x=0,y=-1;
    sum=0;
    for(int i=0;i<m;i++){
        if(x<TA.size() && i==TA[x]){
            x++;
            y++;
        }
        sum+=fabs(p[i]-q[y]);
    }
    printf("%f\n",sum);*/
}
