#include <stdio.h>

int main(){
    int n ;
    scanf("%d",&n);
    int a[10005] = {0};
    int dp[10005] = {0};
    
    scanf("%d",a);
    dp[0] = 1;

    for(int i = 1 ; i < n ; i++){
        scanf("%d",a+i);
        if(a[i] == a[i-1]+1) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
    }

    int mx = 1;
    for(int i = 0  ; i < n ; i++){
        mx = mx > dp[i] ? mx : dp[i];
    }

    printf("%d",mx);
    return 0;
}