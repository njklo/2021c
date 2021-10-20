//tab按键的意义是：以8个字符为一个小列制表。
#include <stdio.h>
#define TABLENGTH 8

int main()
{
	char c;
	
	int i, length, printjob;
	
	length = printjob = 0 ;
	
	while( (c = getchar()) != EOF){
		if( c != '\t' && c != '\n'){
			++length;
			putchar(c); //这里c作为char变量让putchar使用。
		}
		
		else if(c == '\n'){
			length = 0;
			putchar('\n');
		}
		
		else if(c == '\t'){
			printjob = TABLENGTH - ( length % TABLENGTH);
			for(i = 0; i < printjob; ++i)
				putchar('#');
				
			length = 0;
		}
		
	}
	
	return 0;
}
