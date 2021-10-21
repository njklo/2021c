#include <stdio.h>
#define FINISH 0
#define CONTINUE 1

int getlinee(char mem[]);
int analysis(char mem[]);
void convert(char mem[], int from);
void print(char mem[]);

int main()
{
	int director, bacon;
	char memory[8];
	
	director = CONTINUE;
	
	while(director != FINISH ){
		
		director = getlinee(memory);
		
		bacon = analysis(memory);
		
		convert(memory, bacon);
		
		print(memory);
	}
	
}

int getlinee(char mem[])
{
	int notification, i ;
	
	notification = CONTINUE;
	
	for(i = 0; i <=7 && (mem[i] = getchar()) != EOF ; ++i)
		//i <= 7的判定要放在前面，否则会浪费一个getchar得到的字符！
		;
	
	if(mem[i] == EOF){
		notification = FINISH ;
		
		while(i <= 7 ){
			mem[i] = '\0';
			 ++i;
		}
	}	
	
	return notification;
}

int analysis(char arow[])
{
	int i;
	for(i = 7; arow[i] == ' '; --i)
		;
	
	return i; //由此得知了arow[i]不是空格。
}

void convert(char mem[], int from)
{
	if(from < 7){
		++from;
		mem[from] = '\t';
		++from;
		
		while(from <= 7){
			mem[from] = '\0';
			++from;
		}
	}
	
	
}

void print(char row[])
{
	int i;
	for(i = 0; i <=7 && row[i] != '\0' ; ++i)
		printf("%c", row[i] );	
}