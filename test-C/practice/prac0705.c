/*記録*/
/*まず、プログラムを組んだ*/
/*後に関数としてまとめた*/
/*関数から書こうとしたら頭で整理できず*/

#include <stdio.h>
#include <string.h>

void reverse (char orig[],char rev[]){
	int i , length;
	
	length = strlen(orig);
	
	for(i=0;i<length;i++){
	rev[i] = orig[length - 1 - i ];
	}
}

int main (void){
	
	char orig[128];
	char rev[128];
	
	printf ("文字を入力してください\n");
	scanf("%s",orig);
	
	reverse(orig,rev);
	
	printf("逆さ文字は%s\n",rev);
	return 0 ;
}

/*
実行結果
文字を入力してください
Apple
逆さ文字はelppA
*/
