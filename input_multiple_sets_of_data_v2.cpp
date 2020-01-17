// 输入描述：
// 多组数据，每组输入两个整数，当两个整数都为0时表示输入结束
#include <cstdio>
int main(){
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF){
        if(m == 0 && n == 0) break;
        else   
            printf("%d\n", m+n);
    }
    return 0;
}
