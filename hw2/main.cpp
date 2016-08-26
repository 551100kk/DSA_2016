#include<bits/stdc++.h>
using namespace std;
struct P{
    int usr,itm,time,res;
    void print(){
        printf("(%d,%d,%d,%d)\n",usr,itm,time,res);
    }
};
vector<int> arr;
vector<P> A,B;
int cnt[10000000];
set<int> ma[10000000];
bool operator == (const P& a,const P& b){
    return a.usr==b.usr &&
            a.itm==b.itm &&
            a.time==b.time &&
            a.res==b.res;
}
struct Cmp1 {
    bool operator () (const P& a,const P& b) const{
        if(a.itm!=b.itm) return a.itm<b.itm;
        if(a.usr!=b.usr) return a.usr<b.usr;
        if(a.time!=b.time) return a.time<b.time;
        return a.res<b.res;
    }
};
struct Cmp2{
    bool operator () (const P& a,const P& b) const{
        if(a.usr!=b.usr) return a.usr<b.usr;
        if(a.itm!=b.itm) return a.itm<b.itm;
        if(a.time!=b.time) return a.time<b.time;
        return a.res<b.res;
    }
};
void accept(int U,int I,int T){
    vector<P>::iterator it=lower_bound(A.begin(),A.end(),(P){U,I,T,-2},Cmp1());
    if(it!=A.end() && it->usr==U && it->itm==I && it->time==T){
        printf("%d\n",it->res);
    }
    else puts("0");
}
void items(int u1,int u2){
    vector<P>::iterator it1,it2;
    it1=lower_bound(B.begin(),B.end(),(P){u1,-1,0,0},Cmp2());
    it2=lower_bound(B.begin(),B.end(),(P){u2,-1,0,0},Cmp2());
    int pre=-1;
    while(it1!=B.end() && it2!=B.end() && it1->usr==u1 && it2->usr==u2){
        if(it1->itm==it2->itm){
            if(pre!=it1->itm){
                printf("%d\n",it1->itm);
                pre=it1->itm;
            }
        }
        if(it1->itm<it2->itm) it1++;
        else it2++;
    }
    if(pre==-1) puts("EMPTY");
}
void users(int i1,int i2,int t1,int t2){
    vector<P>::iterator it1,it2;
    it1=lower_bound(A.begin(),A.end(),(P){-1,i1,0,0},Cmp1());
    it2=lower_bound(A.begin(),A.end(),(P){-1,i2,0,0},Cmp1());
    int pre=-1;
    while(it1!=A.end() && it2!=A.end() && it1->itm==i1 && it2->itm==i2){
        if(it1->usr==it2->usr && it1->time>=t1 && it1->time<=t2 && it2->time>=t1 && it2->time<=t2){
            if(pre!=it1->usr){
                printf("%d\n",it1->usr);
                pre=it1->usr;
            }
        }
        if(it1->usr!=it2->usr){
            if(it1->usr<it2->usr) it1++;
            else it2++;
        }
        else{
            if(it1->time<it2->time) it1++;
            else it2++;
        }
    }
    if(pre==-1) puts("EMPTY");
}
void ratio(int I,int N){
    int num=0,dom;
    dom=arr.size()-(upper_bound(arr.begin(),arr.end(),N)-arr.begin());
    set<int>::iterator it;
    for(it=ma[I].begin();it!=ma[I].end();it++){
        if(cnt[*it]>N) num++;
    }
    printf("%d/%d\n",num,dom);
}
vector<int> U;
void findtime(int I){
    vector<P>::iterator it1;
    vector<int>::iterator it2=U.begin();
    it1=lower_bound(A.begin(),A.end(),(P){-1,I,0,0},Cmp1());
    vector<int> tmp;
    while(it1!=A.end() && it2!=U.end() && it1->itm==I){
        if(it1->usr==*it2) tmp.push_back(it1->time);
        if(it1->usr<=*it2) it1++;
        else it2++;
    }
    sort(tmp.begin(),tmp.end());
    if(tmp.size()){
        for(int i=0;i<tmp.size();i++){
            if(i==0 || tmp[i]!=tmp[i-1]){
                printf("%d\n",tmp[i]);
            }
        }
    }
    else puts("EMPTY");
}
char ss[10000000];
int main(){
    A.reserve(73209277);
    int usr,itm,res,time;
    FILE *file;
    file=fopen("/tmp2/KDDCUP2012/track1/rec_log_train.txt","r");
    for(int i=0;i<73209277;i++){ //73209277
        fscanf(file,"%d%d%d%d",&usr,&itm,&res,&time);
        A.push_back((P){usr,itm,time,res});
    }
    fclose(file);
    sort(A.begin(),A.end(),Cmp1());
    vector<P>::iterator it=unique(A.begin(),A.end());
    A.resize(distance(A.begin(),it));
    for(int i=0;i<A.size();i++){
        cnt[A[i].usr]++;
        if(A[i].res==1){
            ma[A[i].itm].insert(A[i].usr);
        }
    }
    for(int i=0;i<10000000;i++){
        if(cnt[i]){
            arr.push_back(cnt[i]);
        }
    }
    sort(arr.begin(),arr.end());
    B=A;
    sort(B.begin(),B.end(),Cmp2());
    int t;
    scanf("%d",&t);
    char s[20];
    while(t--){
        scanf("%s",s);
        if(string(s)=="accept"){
            int u,i,t;
            scanf("%d%d%d",&u,&i,&t);
            accept(u,i,t);
        }
        if(string(s)=="items"){
            int u1,u2;
            scanf("%d%d",&u1,&u2);
            items(u1,u2);
        }
        if(string(s)=="users"){
            int i1,i2,t1,t2;
            scanf("%d%d%d%d",&i1,&i2,&t1,&t2);
            users(i1,i2,t1,t2);
        }
        if(string(s)=="ratio"){
            int i,n;
            scanf("%d%d",&i,&n);
            ratio(i,n);
        }
        if(string(s)=="findtime_item"){
            int itm;
            scanf("%d",&itm);
            U.clear();
            int x;
            while(scanf("%d", &x) == 1) U.push_back(x);
            sort(U.begin(),U.end());
            findtime(itm);
        }
    }
}
