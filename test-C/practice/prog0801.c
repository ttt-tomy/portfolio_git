/*prog0801.c*/
//実行エラーだった
//入力用に用意した変数のデータ型が違う予測

#include <stdio.h>

int main (void){
	FILE * file ;
	int fname ;
	
	printf("ファイル名を入力して下さい\n");
	scanf("%d",&fname);
	
	file = fopen(fname ,"r");
	if (file == NULL ){
		printf("ファイルを開けません。\n");
	} else {
		printf("ファイルを開けました。\n");
		fclose (file);
	}
	return 0;
}

/*
実行結果
prog0801.c: 関数 ‘main’ 内:
prog0801.c:12:2: 警告: 1 番目の ‘fopen’ の引数へ渡すときに整数からキャスト無しにポインタを作成しています [デフォルトで有効]
  file = fopen(fname ,"r");
  ^
In file included from prog0801.c:3:0:
/usr/include/stdio.h:272:14: 備考: expected ‘const char * __restrict__’ but argument is of type ‘int’
 extern FILE *fopen (const char *__restrict __filename,
*/
