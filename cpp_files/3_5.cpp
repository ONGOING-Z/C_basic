// 输出1~n中能被3整除，且至少有一位数字是5的所有整数.
#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        int temp = i;
        if(temp % 3 == 0){
            while(temp > 0){  // 此判断条件很重要
                if(temp % 10 == 5){
                    printf("%d\n", i);
                    break;
                }
                temp /= 10;
            }
        }
    }
    return 0;
}
