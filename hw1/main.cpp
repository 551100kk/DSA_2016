#include<bits/stdc++.h>
using namespace std;
double A[1005][1005],B[1005][2005];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&B[i][j]);
            A[i][j]=B[i][j];
        }
        B[i][i+n]=1;
    }
    for(i=0;i<n;i++){
        int id=i;
        for(j=i+1;j<n;j++){
            if(B[j][i]!=0) id=j;
        }
        for(j=0;j<n*2;j++){
            swap(B[i][j],B[id][j]);
        }

        double tmp=B[i][i];
        for(k=0;k<n*2;k++){
            B[i][k]/=tmp;
        }
        for(j=0;j<n;j++){
            if(i==j) continue;
            tmp=B[j][i];
            for(k=0;k<n*2;k++){
                B[j][k]-=B[i][k]*tmp;
            }
        }
    }
    double max_error=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            double cur_error=0,I=0;
            if(i==j) I=1;
            for(k=0;k<n;k++){
                cur_error+=A[i][k]*B[k][j+n];
            }
            max_error=max(max_error,cur_error-I);
        }
    }
    printf("%.12f\n",max_error);
    for(i=0;i<n;i++){
        for(j=n;j<n*2;j++){
            if(j>n) cout << " ";
            printf("%.12f",B[i][j]);
        }
        puts("");
    }
}
