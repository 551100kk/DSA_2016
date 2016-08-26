#include<bits/stdc++.h>
using namespace std;
#define M 31
int n,m;
char s[M][M];
vector<int> L[205],U[205];
int addL[205],addU[205];
vector<int> A[205],B[205];
int checkA[205],checkB[205];
int cntA[205],cntB[205];
void test(int x,int y,int z){
    printf("(%d,%d---%d)\n",x,y,z);
    for(int i=0;i<n;i++) puts(s[i]);
}
int check;
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            putchar(s[i][j]);
        }
        puts("");
    }
}
void testL(){
    int tmp[M][M]={0};
    for(int i=0;i<n;i++){
        int id=0,rrr=0,ppp=L[i].size()-1;
        for(int j=0;j<m && id<L[i].size();j++){
            if(s[i][j]=='.') continue;
            if(j+L[i][id]<m && s[i][j+L[i][id]]=='#'){
                if(id==rrr && s[i][j]==0) if(s[i][j]==0) s[i][j]='.';
                continue;
            }
            int flag=-1;
            for(int k=j;k<m && k<j+L[i][id];k++){
                if(s[i][k]=='.') flag=k;
            }
            if(flag!=-1){
                if(id==rrr) for(int k=j;k<flag;k++){
                    if(s[i][k]==0) s[i][k]='.';
                }
                j=flag;
            }
            else{
                if(id==rrr){
                    int l=-1,r;
                    for(int k=j;k<m && k<j+L[i][id];k++){
                        if(s[i][k]=='#'){
                            if(l==-1) l=k;
                            r=k;
                        }
                    }
                    if(l!=-1){
                        for(int k=l;k<r;k++) if(s[i][k]==0) s[i][k]='#';
                    }
                }
                if(id==rrr && s[i][j]=='#'){
                    for(int k=j;k<m && k<j+L[i][id];k++){
                        if(s[i][k]==0) s[i][k]='#';
                    }
                    if(j+L[i][id]<m) s[i][j+L[i][id]]='.';
                    rrr++;
                }
                for(int k=j;k<m && k<j+L[i][id];k++){
                    tmp[i][k]=id+1;
                }
                j=j+L[i][id];
                id++;
            }
        }
        id=L[i].size()-1;
        for(int j=m-1;j>=0 && id>=0;j--){
            if(s[i][j]=='.') continue;
            if(j-L[i][id]>=0 && s[i][j-L[i][id]]=='#'){
                if(id==ppp && s[i][j]==0) if(s[i][j]==0) s[i][j]='.';
                continue;
            }
            int flag=-1;
            for(int k=j;k>=0 && k>j-L[i][id];k--){
                if(s[i][k]=='.') flag=k;
            }
            if(flag!=-1){
                if(id==ppp) for(int k=j;k>flag;k--){
                    if(s[i][k]==0) s[i][k]='.';
                }
                j=flag;
            }
            else{
                if(id==ppp){
                    int l=-1,r;
                    for(int k=j;k>=0 && k>j-L[i][id];k--){
                        if(s[i][k]=='#'){
                            if(l==-1) l=k;
                            r=k;
                        }
                    }
                    if(l!=-1){
                        for(int k=l;k>r;k--) if(s[i][k]==0) s[i][k]='#';
                    }
                }
                if(id==ppp && s[i][j]=='#'){
                    for(int k=j;k>=0 && k>j-L[i][id];k--){
                        if(s[i][k]==0) s[i][k]='#';
                    }
                    if(j-L[i][id]>=0) if(s[i][j-L[i][id]]==0) s[i][j-L[i][id]]='.';
                    ppp--;
                }
                for(int k=j;k>=0 && k>j-L[i][id];k--){
                    if(tmp[i][k]==id+1){
                        if(s[i][k]==0) s[i][k]='#';
                    }
                }
                j=j-L[i][id];
                id--;
            }
        }
    }
}
void testU(){
    int tmp[M][M]={0};
    for(int i=0;i<m;i++){
        int id=0,rrr=0,ppp=U[i].size()-1;
        for(int j=0;j<n && id<U[i].size();j++){
            if(s[j][i]=='.') continue;
            if(j+U[i][id]<n && s[j+U[i][id]][i]=='#'){
                if(id==rrr && s[j][i]==0) if(s[j][i]==0) s[j][i]='.';
                continue;
            }
            int flag=-1;
            for(int k=j;k<n && k<j+U[i][id];k++){
                if(s[k][i]=='.') flag=k;
            }
            if(flag!=-1){
                if(id==rrr) for(int k=j;k<flag;k++){
                    if(s[k][i]==0) s[k][i]='.';
                }
                j=flag;
            }
            else{
                if(id==rrr){
                    int l=-1,r;
                    for(int k=j;k<m && k<j+U[i][id];k++){
                        if(s[k][i]=='#'){
                            if(l==-1) l=k;
                            r=k;
                        }
                    }
                    if(l!=-1){
                        for(int k=l;k<r;k++) if(s[k][i]==0) s[k][i]='#';
                    }
                }
                if(id==rrr && s[j][i]=='#'){
                    for(int k=j;k<n && k<j+U[i][id];k++){
                        if(s[k][i]==0) s[k][i]='#';
                    }
                    if(j+U[i][id]<n) if(s[j+U[i][id]][i]==0) s[j+U[i][id]][i]='.';
                    rrr++;
                }
                for(int k=j;k<n && k<j+U[i][id];k++){
                    tmp[k][i]=id+1;
                }
                j=j+U[i][id];
                id++;
            }
        }
        id=U[i].size()-1;
        for(int j=n-1;j>=0 && id>=0;j--){
            if(s[j][i]=='.') continue;
            if(j-U[i][id]>=0 && s[j-U[i][id]][i]=='#'){
                if(id==ppp && s[j][i]==0) if(s[j][i]==0) s[j][i]='.';
                continue;
            }
            int flag=-1;
            for(int k=j;k>=0 && k>j-U[i][id];k--){
                if(s[k][i]=='.') flag=k;
            }
            if(flag!=-1){
                if(id==ppp) for(int k=j;k>flag;k--){
                    if(s[k][i]==0) s[k][i]='.';
                }
                j=flag;
            }
            else{
                if(id==ppp){
                    int l=-1,r;
                    for(int k=j;k>=0 && k>j-U[i][id];k--){
                        if(s[k][i]=='#'){
                            if(l==-1) l=k;
                            r=k;
                        }
                    }
                    if(l!=-1){
                        for(int k=l;k>r;k--) if(s[k][i]==0) s[k][i]='#';
                    }
                }
                if(id==ppp && s[j][i]=='#'){
                    for(int k=j;k>=0 && k>j-U[i][id];k--){
                        if(s[k][i]==0) s[k][i]='#';
                    }
                    if(j-U[i][id]>=0) if(s[j-U[i][id]][i]==0) s[j-U[i][id]][i]='.';
                    ppp--;
                }
                for(int k=j;k>=0 && k>j-U[i][id];k--){
                    if(tmp[k][i]==id+1){
                        if(s[k][i]==0) s[k][i]='#';
                    }
                }
                j=j-U[i][id];
                id--;
            }
        }
    }
}
void space(){
    for(int i=0;i<n;i++){
        vector<int> arr;
        int tmp=0;
        for(int j=0;j<m;j++){
            if(s[i][j]=='#') tmp++;
            else{
                if(tmp) arr.push_back(tmp);
                tmp=0;
            }
        }
        if(tmp) arr.push_back(tmp);
        if(L[i]==arr){
            for(int j=0;j<m;j++){
                if(s[i][j]==0){
                    s[i][j]='.';
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        vector<int> arr;
        int tmp=0;
        for(int j=0;j<n;j++){
            if(s[j][i]=='#') tmp++;
            else{
                if(tmp) arr.push_back(tmp);
                tmp=0;
            }
        }
        if(tmp) arr.push_back(tmp);
        if(U[i]==arr){
            for(int j=0;j<n;j++){
                if(s[j][i]==0){
                    s[j][i]='.';
                }
            }
        }
    }
}
void block(){
    for(int i=0;i<n;i++){
        vector<int> arr;
        int tmp=0;
        for(int j=0;j<m;j++){
            if(s[i][j]!='.') tmp++;
            else{
                if(tmp) arr.push_back(tmp);
                tmp=0;
            }
        }
        if(tmp) arr.push_back(tmp);
        if(L[i]==arr){
            for(int j=0;j<m;j++){
                if(s[i][j]==0){
                    s[i][j]='#';
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        vector<int> arr;
        int tmp=0;
        for(int j=0;j<n;j++){
            if(s[j][i]!='.') tmp++;
            else{
                if(tmp) arr.push_back(tmp);
                tmp=0;
            }
        }
        if(tmp) arr.push_back(tmp);
        if(U[i]==arr){
            for(int j=0;j<n;j++){
                if(s[j][i]==0){
                    s[j][i]='#';
                }
            }
        }
    }
}
int testt=300;
void dfs(int x,int y,int add){
    if(y==m) y=0,x++;
    if(x==n){
        for(int i=0;i<n;i++){
            puts(s[i]);
        }
        exit(0);
        return;
    }
    int flag=1;

    int is=1;
    if(s[x][y]) is=0;
    else add++;
    char pre[M][M];

    if(s[x][y]!='.' && (A[x].size()==L[x].size() && (A[x].size()==0 || A[x].back()==L[x].back()))==0 && (B[y].size()==U[y].size() && (B[y].size()==0 || B[y].back()==U[y].back()))==0){
        if(is){
            if((add)%testt==0) memcpy(pre,s,sizeof(s));
            s[x][y]='#';
            if((add)%testt==0) for(int i=0;i<1;i++){
                testU();
                testL();
                space();
                block();
            }
        }
        int a=0,b=0,c=0,d=0;
        if(y && s[x][y-1]=='#'){
            if(A[x].back()==L[x][A[x].size()-1]) flag=0;
            else A[x].back()++,a=1;
        }
        else{
            if(A[x].size() && A[x].back()<L[x][A[x].size()-1]) flag=0;
            else A[x].push_back(1),b=1;
        }
        if(x && s[x-1][y]=='#'){
            if(B[y].back()==U[y][B[y].size()-1]) flag=0;
            else B[y].back()++,c=1;
        }
        else{
            if(B[y].size() && B[y].back()<U[y][B[y].size()-1]) flag=0;
            else B[y].push_back(1),d=1;
        }
        if(flag){
            cntA[x]++,cntB[y]++;
            if(m-y-1<addL[x]-cntA[x]+(int)L[x].size()-(int)A[x].size()) flag=0;
            if(n-x-1<addU[y]-cntB[y]+(int)U[y].size()-(int)B[y].size()) flag=0;
            if(flag) dfs(x,y+1,add);
            cntA[x]--,cntB[y]--;
        }
        if(a) A[x].back()--;
        if(b) A[x].pop_back();
        if(c) B[y].back()--;
        if(d) B[y].pop_back();
        if(is){
            s[x][y]=0;
            if((add)%testt==0) memcpy(s,pre,sizeof(pre));
        }
    }
    flag=1;
    if(s[x][y]!='#'){
        if(is){
            if((add)%testt==0) memcpy(pre,s,sizeof(s));
            s[x][y]='.';
            if((add)%testt==0) for(int i=0;i<1;i++){
                testU();
                testL();
                space();
                block();
            }
        }
        if(A[x].size() && A[x].back()<L[x][A[x].size()-1]) flag=0;
        if(B[y].size() && B[y].back()<U[y][B[y].size()-1]) flag=0;
        if(flag){
            if(m-y-1<addL[x]-cntA[x]+(int)L[x].size()-(int)A[x].size()-1) flag=0;
            if(n-x-1<addU[y]-cntB[y]+(int)U[y].size()-(int)B[y].size()-1) flag=0;
            if(flag) dfs(x,y+1,add);
        }
        if(is){
            s[x][y]=0;
            if((add)%testt==0) memcpy(s,pre,sizeof(pre));
        }
    }

}
int main(){
    //freopen("random_30x30_02.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++){
        char s[1005]={0};
        fgets(s,1000,stdin);
        for(int j=0;s[j];j++){
            if(s[j]>='0' && s[j]<='9' && (j==0 || s[j-1]<'0' || s[j-1]>'9')){
                int x;
                sscanf(&s[j],"%d",&x);
                L[i].push_back(x);
                addL[i]+=x;
            }
        }
    }
    for(int i=0;i<m;i++){
        char s[1005]={0};
        fgets(s,1000,stdin);
        for(int j=0;s[j];j++){
            if(s[j]>='0' && s[j]<='9' && (j==0 || s[j-1]<'0' || s[j-1]>'9')){
                int x;
                sscanf(&s[j],"%d",&x);
                U[i].push_back(x);
                addU[i]+=x;
            }
        }
    }
    //s[3][2]='#';
    for(int i=0;i<100;i++){
        testU();
        testL();
        space();
        block();
    }
    //print();
    dfs(0,0,-1);
}
