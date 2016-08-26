#include<bits/stdc++.h>
using namespace std;
struct P{
    int id,usr,pri,num;
};
struct cmp1{
    bool operator () (P &a,P &b) const{
        if(a.pri!=b.pri) return a.pri<b.pri;
        return a.id>b.id;
    }
};
struct cmp2{
    bool operator () (P &a,P &b) const{
        if(a.pri!=b.pri) return a.pri>b.pri;
        return a.id>b.id;
    }
};
priority_queue<P,vector<P>,cmp1> buy;
priority_queue<P,vector<P>,cmp2> sell;
int cancel[10000005];
int main(){
    int id,usr,type,pri,num,C=0;
    while(scanf("%d%d%d%d%d",&id,&usr,&type,&pri,&num)!=EOF){
        if(type==0){
            while(sell.size() && sell.top().pri<=pri && num>0){
                P out=sell.top();
                sell.pop();
                if(cancel[out.id]) continue;
                int cnt=min(out.num,num);
                out.num-=cnt;
                num-=cnt;
                printf("%d\t%d\t%d\t%d\t%d\n",C++,usr,out.usr,out.pri,cnt);
                if(out.num){
                    sell.push(out);
                }
            }
            if(num){
                buy.push((P){id,usr,pri,num});
            }
        }
        if(type==1){
            while(buy.size() && buy.top().pri>=pri && num>0){
                P out=buy.top();
                buy.pop();
                if(cancel[out.id]) continue;
                int cnt=min(out.num,num);
                out.num-=cnt;
                num-=cnt;
                printf("%d\t%d\t%d\t%d\t%d\n",C++,out.usr,usr,pri,cnt);
                if(out.num){
                    buy.push(out);
                }
            }
            if(num){
                sell.push((P){id,usr,pri,num});
            }
        }
        if(type==2){
            cancel[pri]=1;
        }
    }
}
