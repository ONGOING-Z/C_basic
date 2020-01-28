// 从1开始按从小到大的顺序输出所有回文数
#include <cstdio>
int main(){
    int n, y, x;
    scanf("%d", &n);
    // 将翻转数字求出，再做比较
    for(int i = 1; i <= n; i++){
        y = i, x = 0;
        while(y > 0){
            x = x * 10 + y % 10;
            y /= 10;
        }
        if(x == i) printf("%d\n", i);
    }
    return 0;
}
