#include<stdio.h>
# define N 5000
int k = N-1;
void fibonacci(int n){
    char first[N],second[N],result[N],carry = 0;
    for(int i = 0;i<N;i++){
        first[i] = 0;
        second[i] = 0;
    }
    if(n == 0 || n == 1){
        printf("%d",n);
        return;
    }
    first[N-1] = 1;
    second[N-1] = 0;
    for(int i = 2;i<=n;i++){
        int j = N-1;
        while(j>=k){
            int sum = first[j] + second[j] + carry;
            result[j] = (sum%10);
            carry = sum/10;
            j--;
            if(j == k && carry>0)k--;
        }
        int m = N-1;
        while(m>=k){
            second[m]=first[m];
            first[m]=result[m];
            m--;
        }
    }
    for(int i=k; i<N; i++) {
        printf("%d", result[i]);
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}