#include<stdio.h>
/* sample.c : Initial C on the Linux. */
int main(){
	printf("\nHello\n\n");
	return 0;
}

/* 
エディタはGEditを利用
$ gcc sample.c
$ cc sample.c
$ make sample.c
gcc コマンドと cc コマンドはなにも指定しなければ、 a.out という名でプログラムが出力されます。ファイル名を指定したい場合は以下のように -o （output）オプションを付与します。
$ gcc sample.c -o hogehoge
$ cc sample.c -o hogehoge 
参考https://slacknotebook.com/how-to-write-run-c-program-on-linux/
*/


