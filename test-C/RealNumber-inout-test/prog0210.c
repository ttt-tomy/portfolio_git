/*prog0210.c*/

#include <stdio.h>

int main(void)
{
	double temperature ;//実数の変数として発行
	double humidity ;
	double DiscomfortIndex ;
	
	printf("%s\n","気温を入力してください");
	scanf("%lf",&temperature);//%lfは実数
	printf("%s\n","湿度を入力してください");
	scanf("%lf",&humidity);
	
	DiscomfortIndex = 0.81 * temperature + 0.01 * humidity * (0.99 * temperature -14.3) + 46.3;
	
	printf("不快指数は、\"%lf\"です\n",DiscomfortIndex);
	//「\」でエスケープできた
	//第1引数が出力形式、%fが実数の出力フォーマットの記述("%.1f"で小数点以下1桁となる、第2引数以降が扱う変数指定。
	
	return 0;
	}
