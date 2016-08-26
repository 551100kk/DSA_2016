#include<bits/stdc++.h>
using namespace std;
struct P{
    int pos;
    unsigned int sval;
}arr[45000005];
char str[850000000];
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
    return 0;
}

int main(int argc,char* argv[]){
    FILE *fp;
    int all=0;
    for(int i=2;i<=5;i++){
        sprintf(s,"/tmp2/dsa2016_project/%dgm.small.txt",i);
        fp=fopen(s,"r");
        while(fgets(s,500,fp)!=NULL){
            int i;
            arr[all].pos=it;
            unsigned hashval=0;
            for(i=0;s[i]!='\t';i++){
                str[it++]=s[i];
            }
            str[it++]=0;
            unsigned int val=0;
            for(i++;s[i]>='0' && s[i]<='9';i++){
                val=val*10+s[i]-'0';
            }
            arr[all].sval=val;
            all++;
        }
        fclose(fp);
    }
    sort(arr,arr+all,cmp);
    fp=fopen(argv[1],"wb");
    fwrite(str,1,850000000,fp);
    fwrite(arr,sizeof(P),45000000,fp);
    fclose(fp);
}
