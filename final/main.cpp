#include<bits/stdc++.h>
using namespace std;
string prep[]={"of", "to", "in", "for", "with", "on", "at", "by", "from", "up", "about", "than", "after", "before", "down", "between", "under", "since", "without", "near"};
int all = 41929539;
struct P{
    int pos;
    unsigned int sval;
}arr[45000005];
char str[850001000];
int it=0;
char s[1000];
int cmp(P a,P b){
    char *pt1,*pt2;
    pt1=&str[a.pos];
    pt2=&str[b.pos];
    while(*pt1 || *pt2){
        if(*pt1==*pt2){
            pt1++;
            pt2++;
            continue;
        }
        return *pt1<*pt2;
    }
    return 1;
}
inline int same(char *pt1,char *pt2){
    while(*pt1 || *pt2){
        if(*pt1==*pt2){
            pt1++;
            pt2++;
            continue;
        }
        return *pt1<*pt2;
    }
    return 1;
}
struct T{
    unsigned cnt;
    int pos;
};
int cmp2(T a,T b){
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    return cmp((P){a.pos,0},(P){b.pos,0});
}
vector<string> words;
vector<int> isp;
int cand[6];
vector<T> ans;
inline bool finds(){
    int l=0,r=all,m;
    while(l+1!=r){
        m=(l+r)/2;
        if(same(&str[arr[m].pos],&str[850000000])) l=m;
        else r=m;
    }
    if(strcmp(&str[arr[l].pos],&str[850000000])==0) ans.push_back((T){arr[l].sval,arr[l].pos});
}
void dfs1(int ptr,int add,int now,int ed){
    if(now==words.size()){
        //ssss++;
        //puts(&str[850000000]);
        finds();
    }
    if(add==5) return;
    if(ed<2){
        for(int i=0;i<20;i++){
            if(ptr>850000000) str[ptr]=' ';
            str[ptr+1]=0;
            strcat(&str[ptr],prep[i].c_str());
            dfs1(ptr+(ptr>850000000)+prep[i].size(),add+1,now,ed+1);
            str[ptr]=0;
        }
    }
    if(now<words.size()){
        if(ptr>850000000) str[ptr]=' ';
        str[ptr+1]=0;
        strcat(&str[ptr],words[now].c_str());
        dfs1(ptr+(ptr>850000000)+words[now].size(),add+1,now+1,ed);
        str[ptr]=0;
    }
}
void dfs2(int ptr,int add,int now,int ed){
    if(now==words.size()){
        //ssss++;
        //puts(&str[850000000]);
        finds();
    }
    if(now<words.size()){
        if(isp[now]){
            if(ed==0){
                dfs2(ptr,add,now+1,ed+1);
            }
        }
    }
    if(add==5) return;
    if(ed==0 && (now<words.size() && isp[now] || now && isp[now-1])){
        for(int i=0;i<20;i++){
            if(ptr>850000000) str[ptr]=' ';
            str[ptr+1]=0;
            strcat(&str[ptr],prep[i].c_str());
            dfs2(ptr+(ptr>850000000)+prep[i].size(),add+1,now,ed+1);
            str[ptr]=0;
        }
    }
    if(now<words.size()){
        if(isp[now]){
            //keep
            if(ptr>850000000) str[ptr]=' ';
            str[ptr+1]=0;
            strcat(&str[ptr],words[now].c_str());
            dfs2(ptr+(ptr>850000000)+words[now].size(),add+1,now+1,ed);
            str[ptr]=0;
            //del
            /*if(ed==0){
                dfs2(ptr,add,now+1,ed+1);
            }*/
            //sub
            if(ed==0){
                for(int i=0;i<20;i++){
                    if(ptr>850000000) str[ptr]=' ';
                    str[ptr+1]=0;
                    strcat(&str[ptr],prep[i].c_str());
                    dfs2(ptr+(ptr>850000000)+prep[i].size(),add+1,now+1,ed+1);
                    str[ptr]=0;
                }
            }
        }
        else{

            if(ptr>850000000) str[ptr]=' ';
            str[ptr+1]=0;
            strcat(&str[ptr],words[now].c_str());
            dfs2(ptr+(ptr>850000000)+words[now].size(),add+1,now+1,0);
            str[ptr]=0;
        }
    }
}
int main(int argc,char* argv[]){
    unordered_set<string> ma={"of", "to", "in", "for", "with", "on", "at", "by", "from", "up", "about", "than", "after", "before", "down", "between", "under", "since", "without", "near"};
    FILE *fp;
    fp=fopen(argv[1],"rb");
    fread(str,1,850000000,fp);
    fread(arr,sizeof(P),45000000,fp);
    fclose(fp);

    //freopen("input01.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(fgets(s,500,stdin)!=NULL){
        words.clear();
        isp.clear();
        string vocab;
        int type=0;
        for(int i=0;;i++){
            if(s[i]>='a' && s[i]<='z'){
                vocab.push_back(s[i]);
            }
            else{
                if(s[i]=='\n') s[i]=0;
                if(vocab.size()) words.push_back(vocab);
                if(vocab.size() && ma.find(vocab)!=ma.end()) type=1,isp.push_back(1);
                else isp.push_back(0);
                vocab.clear();
            }
            if(!s[i]) break;
        }
        /**type1**/
        if(type==0){
            ans.clear();
            str[850000000]=0;
            dfs1(850000000,0,0,0);
            sort(ans.begin(),ans.end(),cmp2);
            printf("query: %s\n",s);
            int add=0;
            for(int i=0;i<ans.size() && add<10;i++){
                if(i && ans[i].pos==ans[i-1].pos) continue;
                add++;
            }
            printf("output: %d\n",min(10,add));
            add=0;
            for(int i=0;i<ans.size() && add<10;i++){
                if(i && ans[i].pos==ans[i-1].pos) continue;
                add++;
                printf("%s\t%u\n",&str[ans[i].pos],ans[i].cnt);
            }
        }
        /**type2**/

        if(type==1){
            ans.clear();
            str[850000000]=0;
            dfs2(850000000,0,0,0);
            sort(ans.begin(),ans.end(),cmp2);
            printf("query: %s\n",s);
            int add=0;
            for(int i=0;i<ans.size() && add<10;i++){
                if(i && ans[i].pos==ans[i-1].pos) continue;
                add++;
            }
            printf("output: %d\n",min(10,add));
            add=0;
            for(int i=0;i<ans.size() && add<10;i++){
                if(i && ans[i].pos==ans[i-1].pos) continue;
                add++;
                printf("%s\t%u\n",&str[ans[i].pos],ans[i].cnt);
            }
        }
    }
}
