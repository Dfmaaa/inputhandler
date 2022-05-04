/*
A NOTE:
- Every function has a comment of its own
- All the input functions have INPUT at the start of their comment
- Don't edit the prototypes, unless the function arguments need to be changed. In that case, the arguments of the prototype must be edited.
- getchar is the core of all the input functions, using scanf, gets, or fgets would be against the purpose of this program, which is to not use any of the normal input functions except getchar.
- Why is register used so many times? It's used to make the program as fast as possible, register storage class is faster than auto storage class.
- Why are chars defined as ints? chars are ints, they're represented by ASCII codes, for example 'A' is actually 65 in ASCII.
- A git repo comes with this directory, the first commit is 16159c8af7ee95df731bd1fb1ea62a0225a8f306, do "git checkout 16159c8af7ee95df731bd1fb1ea62a0225a8f306" to play with it. It's really basic.
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define bool int
#define GENDELM \n
//bounds
#define STRBOUND 101
#define SINTBOUND 12
#define UINTBOUND 15
#define LONGBOUND 20
#define UBIGLONGBOUND 200
#define FLOATBOUND 40
#define CHARBOUND 1
#define BIGLONGBOUND 100
#define ULONGBOUND 30
#define SMALLFLOATBOUND 10
#define SHORTBOUND 6
#define BIGFLOATBOUND 200
//prototypes
void input_str(char *,int,int);
void input(void *,char *,char*);
bool lnsrch(char**,char *,int,char *);
bool strcmpr(char *,char*);
bool lenstr(char *);
void storech(char **,int,struct store_bounds*,int *);
int getbnd(struct store_bounds*, char *);
void storech(char **charr,int arrlen,struct store_bounds *root, int *bndint){
	struct store_bounds *current=root;
    register int incr=0;
    while(incr<arrlen){
     current -> type=(charr+incr);
     current -> bound=*(bndint+incr);
     incr++;
     current=current -> next;
    }
}
int getbnd(struct store_bounds *root, char *dtype){
	struct store_bounds *selected=root;
	int tplen=lenstr(dtype);
	while(selected -> next!=NULL){
     if(tplen==lenstr(selected -> type)){
     	if(strcmpr(dtype,selected -> type)==TRUE){
     		return selected -> bound;
     	}
     }
     selected=selected -> next;
	}
	return FALSE;
}
struct store_bounds{
 char *type;
 int bound;
 struct store_bounds *next;
};
//INPUT only for strings
void input_str(char * str,int delimeter, int bound){
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
bool lnsrch(char *elsource[],char *fstr,int srclen,char *store){
	register int last=srclen-1,first=0;
	int _mstrlen=lenstr(fstr);
	while(last>-1){
     if(lenstr(elsource+first)==_mstrlen){
     	if(strcmpr(elsource+first,fstr)==TRUE)
     		store=elsource+first;
     		return TRUE;
     }
     if(lenstr(elsource+last)==_mstrlen){
     	if(strcmpr(elsource+last,fstr)==TRUE)
     		store=elsource+last;
     		return TRUE;
     }
     first++;
     last--;
	}
	return FALSE;
}
//INPUT for everything except strings
bool input(void *abptr,char *typestr,char *simple_str_inp){
	char *valid_types[]={"int",
	"char",
	"float",
	"double",
	"short",
	"long double",
	"unsigned int",
	"signed int",
	"unsigned char",
	"unsigned long int",
	"long long int",
	"unsigned long long int",
	"signed char"
    };
    int valid_bounds={SINTBOUND,CHARBOUND,
    	SMALLFLOATBOUND,
    	FLOATBOUND,
    	SHORTBOUND,
    	BIGFLOATBOUND,
    	UINTBOUND,
    	SINTBOUND,
    	CHARBOUND,
    	ULONGBOUND,
    	BIGLONGBOUND,
    	UBIGLONGBOUND,
    	CHARBOUND};
    char *ln_result;
    if(lnsrch(valid_types,typestr,sizeof(valid_types)/sizeof(char*),ln_result)==FALSE)
    	return FALSE;
    struct store_bounds *init_bounds=(struct store_bounds*)malloc(sizeof(struct store_bounds));
    storech(valid_types,sizeof(valid_types)/sizeof(char*),init_bounds,valid_bounds);
    int real_bound=getbnd(init_bounds,ln_result);
    free(init_bounds);
    char simple_str_inp[real_bound];
    input_str(simple_str_inp,GENDELM,real_bound);
    switch(*ln_result){
    	case "char":
            abptr=&simple_str_inp[0];
            break;
        case "int":

    }
}
int main(void){
 int delm='t';
 char x[STRBOUND];
 input_str(x,delm,STRBOUND);
 printf("%s\n",x);
 return 0;
}
