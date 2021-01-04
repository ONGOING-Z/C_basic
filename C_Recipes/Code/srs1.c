/* 使用calloc()动态分配内存 */

int main()
{
	int n;
	int *ptr, *list[10];
	printf("Enter an integer as size of list (1 <= n <= 20): ");
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		list[i] = (int *)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
			*(list[i] + j) = i + j + 10;
	}

	printf("Displaying the values of items in list\n");
	printf("-----------------\n");
	for (int i = 0; i < 10; i++) {
		printf("List[%d]: ", i);
		for (int j = 0; j < n; j++)
			printf("%d ", *(list[i] + j));
		printf("\n");
	}

	return 0;
}

/*
 * calloc(): 用于对数组动态分配内存.
 * calloc()函数返回一个指向void的指针，该指针指向已分配内存的第一个字节.
 * 使用calloc()的通用语法: 
 *   ptr = (dataType *) calloc(n, size);
 */
