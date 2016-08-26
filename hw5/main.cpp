#include<bits/stdc++.h>
using namespace std;
vector<string> arr[1000010];
int hashfunc(string str){
    int tmp=0;
    for(int i=0;i<str.size();i++){
        tmp=(tmp*257+str[i])%1000007;
    }
    return tmp;
}
bool findstr(string str){
    int tmp=hashfunc(str),flag=0;
    for(int i=0;i<arr[tmp].size();i++){
        if(arr[tmp][i]==str){
            flag=1;
            break;
        }
    }
    return flag;
}
void instr(string str){
    int tmp=hashfunc(str),flag=0;
    for(int i=0;i<arr[tmp].size();i++){
        if(arr[tmp][i]==str){
            flag=1;
            break;
        }
    }
    if(!flag) arr[tmp].push_back(str);
}
vector<string> ed1,ed2,ans;
void finded1(string str,vector<string> &ED){
    //insert
    for(int i=0;i<=str.size();i++){
        string tmp=str;
        tmp.insert(i,"a");
        ED.push_back(tmp);
        for(int j='b';j<='z';j++){
            tmp[i]=j;
            ED.push_back(tmp);
        }
    }
    //delete
    for(int i=0;i<str.size();i++){
        string tmp=str;
        tmp.erase(i,1);
        ED.push_back(tmp);
    }
    //substitute
    for(int i=0;i<str.size();i++){
        string tmp=str;
        for(int j='a';j<='z';j++){
            if(tmp[i]==j) continue;
            tmp[i]=j;
            ED.push_back(tmp);
        }
    }
    //transpose
    for(int i=0;i<str.size()-1;i++){
        string tmp=str;
        swap(tmp[i],tmp[i+1]);
        ED.push_back(tmp);
    }
}
char in[1000],s[1000];
int main(){
    FILE *fp;
    fp=fopen("/tmp2/dsa2016_hw5/cmudict-0.7b","r");
    while(fgets(in,1000,fp)!=NULL){
        sscanf(in,"%s",s);
        for(int i=0;s[i];i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        instr(string(s));
    }
    //finded1("face",ed1);
    //for(int i=0;i<ed1.size();i++)  puts(ed1[i].c_str());
    while(fgets(in,1000,stdin)!=NULL){
        sscanf(in,"%s",s);
        if(findstr(string(s))){
            printf("%s ==> OK\n",s);
            continue;
        }
        ed1.clear();
        ed2.clear();
        ans.clear();
        finded1(string(s),ed1);
        for(int i=0;i<ed1.size();i++){
            finded1(ed1[i],ed2);
            if(findstr(ed1[i])) ans.push_back(ed1[i]);
        }
        for(int i=0;i<ed2.size();i++){
            if(findstr(ed2[i])) ans.push_back(ed2[i]);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()){
            printf("%s ==>",s);
            for(int i=0;i<ans.size();i++){
                if(i && ans[i]==ans[i-1]) continue;
                printf(" %s",ans[i].c_str());
            }
            puts("");
            continue;
        }
        printf("%s ==> NONE\n",s);
    }
}
