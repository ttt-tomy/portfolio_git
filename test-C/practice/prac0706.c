//階乗を求める関数を作る
//まずはプログラムを作る
//関数でまとめる ←次回

#include <stdio.h>

int factorial(int n){
	
}

int main (void){
	int n,i;
	printf("数値を入力してください\n階乗を計算します。\n");
	scanf("%d",&n);
	
	int anser = n;
	for(i=0;i<n-1;i++){
		anser = anser*(n-i-1);
	}
	printf("階乗後の値は%dです\n",anser);
	
	return 0;
}
