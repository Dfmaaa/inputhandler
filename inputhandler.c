/*
A NOTE:
- Every function has a comment of its own
- All the input functions have INPUT at the start of their comment
- Don't edit the prototypes, unless the function arguments need to be changed. In that case, the arguments of the prototype must be edited.
- getchar is the core of all the input functions, using scanf, gets, or fgets would be against the purpose of this program, which is to not use any of the normal input functions except getchar.
- Why is register used so many times? It's used to make the program as fast as possible, register storage class is faster than auto storage class.
- Why are chars defined as ints? chars are ints, they're represented by ASCII codes, for example 'A' is actually 65 in ASCII.
- A git repo comes with this directory, the first commit is 16159c8af7ee95df731bd1fb1ea62a0225a8f306, do "git checkout 16159c8af7ee95df731bd1fb1ea62a0225a8f306" to play with it. It's really basic.
- Current commit hash: 16159c8af7ee95df731bd1fb1ea62a0225a8f306
*/
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define bool int
#define STRBOUND 100
#define INTBOUND 50
#define LONGBOUND 100
#define FLOATBOUND 500
#define CHARBOUND 1
//prototypes
void input(char *,int,int);
void input_str(void *,char *);
bool lnsrch(char*[],char *,int);
bool strcmpr(char *,char*);
bool lenstr(char *);
//INPUT only for strings
void input(char * str,int delimeter, int bound){
	int inpchar;
	register int incvar=0;
	while(incvar<bound){
		inpchar=getchar();
		if(inpchar=='\n'||inpchar==delimeter){
			*(str+incvar)='\0';
			return;
		}
		*(str+(incvar++))=inpchar;
	}
	*(str+incvar)='\0';
}
//for getting length of a string, without the null terminator
int lenstr(char * str){
	register int varinc=0;
	while(*(str+varinc)!='\0'){
		varinc++;
	}
	return varinc;
}
//for comparing two strings, should be of equal length.
bool strcmpr(char *str1,char *str2){
 register int cmpint=0;
 while(*(str1+cmpint)!='\0'){
 	if(*(str1+cmpint)!=*(str2+cmpint))
    	return FALSE;
    cmpint++;
 }
 return TRUE;
}
//an iterative implementation of linear search
bool lnsrch(char *elsource[],char *fstr,int srclen){
	register int last=srclen-1,first=0;
	int _mstrlen=lenstr(fstr);
	while(last>-1){
     if(lenstr(elsource+first)==_mstrlen){
     	if(strcmpr(elsource+first,fstr)==TRUE)
     		return TRUE;
     }
     if(lenstr(elsource+last)==_mstrlen){
     	if(strcmpr(elsource+last,fstr)==TRUE)
     		return TRUE;
     }
     first++;
     last--;
	}
	return FALSE;
}
//INPUT for everything except strings
bool input_str(void *abptr,char *typestr){
	char *validtypes[]={"int",
	"char",
	"float",
	"double",
	"long double",
	"unsigned int",
	"unsigned char",
	"unsigned long int",
	"long long int",
	"unsigned long long int",
	"signed char"
    };
    if(lnsrch(validtypes,typestr,sizeof(validtypes)/sizeof(char*))==FALSE)
    	return FALSE;
}
int main(void){
 int delm='t';
 char x[STRBOUND];
 input(x,delm,STRBOUND);
 printf("%s\n",x);
 return 0;
}