/* prog0803.c */

#include <stdio.h>

int main (void){
	FILE * file;
	char line[128];
	
	file = fopen ( "test.c","r");
	if (file == NULL){
		printf("ファイルを開けません。\n");
	}else{
		printf("ファイルを開けました。\n");
		fgets(line,128,file);
		//fgets関数：第1引数は入力した1行分の文字列、第2引数は入力値の配列の大きさ、第3引数はファイル指定
		printf("%s",line);
		fclose(file);
	}
	return 0;
}

/* 実行結果
ファイルを開けました。
/*ここの文字が標準出力に表示される想定*/
*/
