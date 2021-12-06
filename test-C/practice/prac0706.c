//階乗を求める関数を作る
//まずはプログラムを作る
//関数でまとめる ←次回

#include <stdio.h>

int factorial(int n){
	int i,anser;
	
	anser = n;
	for(i=0;i<n-1;i++){
		anser = anser*(n-i-1);
	}
	
	return anser ;
}

int main (void){
	int n,anser;
	
	printf("数値を入力してください\n階乗を計算します。\n");
	scanf("%d",&n);
	
	anser = factorial(n);
	
	printf("階乗後の値は%dです\n",anser);
	
	return 0;
}
