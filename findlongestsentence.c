#include <stdio.h>
#define LENGTHLIMIT 18

//声明sucknewline函数的 函数原型
int sucknewline( char s[] , int limit);

//声明copy函数的 函数原型
void copy( char from[], char to[]);

int main()
{
	int currentlength, maxlength;
	
	char currentmemory[LENGTHLIMIT] , safememory[LENGTHLIMIT];
	
	maxlength = 0;
	
	/**main将调用 自定义函数sucknewline 以及 自定义函数copy。
	***只要sucknewline返回的值大于0，main的控制语句while就可以让它反复吸收新句子。
	***给sucknewline提供数组currentmemory是为了让它把吸收到的句子储存进去，传递LENGTHLIMIT值是为了限制它吸收的句子的长度。
	**/
	while( (currentlength = sucknewline(currentmemory, LENGTHLIMIT)) > 0){
		
		if(currentlength > maxlength){
			
			maxlength = currentlength;
			
			{//自定义函数copy
			//给copy函数两个数组的目的就是让它把数组currentmemory中的信息复制到数组safememory中去。
			}
			copy(currentmemory, safememory);
		}
	}
	
	if( maxlength > 0){
		printf("\n你输入的最长句子的长度是%3d个字符", maxlength);
		printf("\n最长的输入句子是：");
	
		int i;
		for(i = 0; i <= maxlength; ++i)
			printf("%c", safememory[i]);
	}
	
	else
		printf("输入的最大长度是0，没有可以输出的内容");
	
	return 0;
	
}

/**对sucknewline函数的要求：
***1.只有遇到EOF才会返回长度0 平时都是返回正的整型值
***2.用getchar（）函数来吸取新的字符
***3.遇到回车 或者 EOF 或者超长 就视同将要结束一个句子的吸取
***4.只使用两个参数，一个是用来储存的字符型数组，另一个是进行长度限制的字符型常量。
***5.每个句子的结尾要加\0字符
**/

int sucknewline(char line[], int limit)
{
	int i;
	char c;
	
	//吸取字符，除非遇到超长、回车 或者 EOF 才停止吸取
	for(i = 0; i < limit && (c = getchar()) != '\n' && c != EOF; ++i)
		line[i] = c;

	//分析停止吸取的原因，如果是回车，要在末尾加上换行符，然后i后移一位
	if(c == '\n'){
		line[i] = '\n';
		++i;
	}
		
	//不论是什么原因停止了吸取，末尾必须加上句子结束符
	line[i] = '\0';
	
	//这个吸取函数只有在字符流中断的状态下直接输入EOF（control+D)才能让i保持为0并且被返回给main
	return i;
	
}//sucknewline函数执行完以后，数组currentmemory中应该存储有完整的一句话。

//定义copy函数，将currentmemory中的内容完整复制到safememory当中
void copy(char from[], char to[])
{	
	for(int i = 0; (to[i] = from[i]) != '\0'; ++i)
		;	//这里就能看出sucknewline在每个句子的末尾加上\0的重要性了！最近的\0意味着句子结束了，后面都是没用的。	
}
