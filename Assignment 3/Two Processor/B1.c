#include<stdio.h>
#include<string.h>
#include<unistd.h>
int charinRange(char c){
	if(c=='=') return 1;
	if(c=='+') return 1;
	if(c>='0' && c<='9') return 1;
	if(c>='a' && c<='z') return 1;
	return 0;
}
void add_var_var(char x[], int a[], int b[]){
	a[x[0]]=a[x[2]]+a[x[4]];
	b[x[0]]=b[x[2]]+b[x[4]];
}
void init_var_num(char x[], int a[], int b[]){
	a[x[0]]=x[2]-48;
	b[x[0]]=x[2]-48;
}
void init_var_var(char x[], int a[], int b[]){
	a[x[0]]=a[x[2]];
	b[x[0]]=b[x[2]];
}
void init_var_index(char x[], int a[], int b[]){
	if(x[3]>='0' && x[3]<='9'){
		a[x[0]]=a[x[3]-'0'+'a'-1];
		b[x[0]]=b[x[3]-'0'+'a'-1];
	}
	if(x[3]>='a' && x[3]<='z'){
		a[x[0]]=a[a[x[3]]+'a'-1];
		b[x[0]]=b[b[x[3]]+'a'-1];
	}
}
void init_index(char x[], int a[], int b[]){
	int m, n;
	if(x[1]>='0' && x[1]<='9') m=x[1]-'0'-1+'a';
	if(x[1]>='a' && x[1]<='z') m=a[x[1]]-1+'a';
	if(x[4]>='0' && x[4]<='9') n=x[4]-'0';
	if(x[4]>='a' && x[4]<='z') n=a[x[4]];
	a[m]=n;
	b[m]=n;
}
void print(char x[], int a[], int b[]){
	printf("%d %d\n", a[x[6]], b[x[6]]);
	sleep(1);
}
void equalization(char x[], int a[], int b[]){
	if(x[3]=='+') add_var_var(x, a, b);
	if(x[2]>='0' && x[2]<='9') init_var_num(x, a, b);
	if(x[3]=='\0' && x[2]>='a' && x[2]<='z') init_var_var(x, a, b);
	if(x[2]=='[') init_var_index(x, a, b);
	if(x[0]=='[') init_index(x, a, b);
}
void if_loop(char x[], int a[], int b[]){
	char y[20];
	int i=7;
	while(charinRange(x[i])){
		y[i-7]=x[i];
		i+=1;
	}
	y[i-7]='\0';
	int m, n;
	if(x[3]>='0' && x[3]<='9') m=x[3]-'0';
	if(x[3]>='a' && x[3]<='z') m=a[x[3]];
	if(x[5]>='0' && x[5]<='9') n=x[5]-'0';
	if(x[5]>='a' && x[5]<='z') n=a[x[5]];
	if(x[4]=='<' && m<n) equalization(y, a, b);
	if(x[4]=='>' && m>n) equalization(y, a, b);
}
void arr_init(int a[]){
	for(int i='a';i<='z';i++)
		a[i]=-1;
	for(int i='0';i<='9';i++)
		a[i]=i-'0';
}
void arr_print(int a[]){
	for(int i='a';i<='z';i++){
		printf("%c=%d, ", i, a[i]);
	}
	printf("\n");
}
int main(){
	char x[20];
	int a[200], b[200];
	arr_init(a);
	arr_init(b);
	a[122]=1;
	b[122]=2;
	do{
		scanf("%s", x);
		if(x[1]=='=' || x[3]=='=') equalization(x, a, b);
		if(x[1]=='r') print(x, a, b);
		if(x[0]=='i' && x[1]=='f') if_loop(x, a, b);
		//arr_print(a);
	}while(1);
	return 0;
}