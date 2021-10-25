/*prog0210.c*/

#include <stdio.h>

int main(void)
{
	int i = 2147483647;
	int sum1 ;
	
	printf("intの最大値は、%d\n",i);
	
	sum1 = i+1;
	
	printf("%s\n","最大値を超えた(+1した)場合の出力結果↓");
	printf("%d\n",sum1);
	
	return 0;
}

/*出力結果*/
/*intの最大値は、2147483647*/
/*最大値を超えた(+1した)場合の出力結果↓*/
/*-2147483648*/


