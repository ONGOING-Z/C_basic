// 求出a到b之间有多少个数数位之和为5的倍数
#include <cstdio>
int main(){
    int x, y, ans = 0;
    scanf("%d%d", &x, &y);
    for(int i = x; i <= y; i++){
        int sum = 0, temp = i;
        while(temp){
            sum += temp%10;
            temp /= 10;
        }
        // 为5的倍数，自增；不为5的倍数，跳出循环
        if(sum % 5) continue;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
