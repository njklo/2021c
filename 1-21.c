//将文本流中的空格替换为tab

#include <stdio.h>

int main()
{
	int i;
	char c;
	char memory[8];
	
	//吸收8个字符，存放到memory[0]至memory[7]当中。
	for(i = 0; i <8; ++i){
		memory[i] = getchar();
	}
	
	//统计从右至左首先在哪出现字母
	while( memory[i] == ' ')
		--i;	//跳出while循环意味着momery[i]中储存的不是空格（是字母）。
	
	
	//根据不是空格的memory[i]所处的位置，判定是否需要用tab。
	//情况一：这是需要在末尾加tab的情况。
	if(i < 7){
		while(i >=0 ){
			putchar(memory[i]);
			--i;
		}	//先打印出已有的字符
		putchar('\t'); 	//再最后加一个tab
	}
	//情况二（情况一的反面）：不需要在末尾加tab的情况。
		else 
			while(i >=0 ){
				putchar(memory[i]);
				--i;
			}	//仅仅将memory[i]全部打印一遍
	
	return 0;
}