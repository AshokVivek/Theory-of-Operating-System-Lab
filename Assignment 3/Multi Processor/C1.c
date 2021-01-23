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
void add_var_var(char x[], int a[][200], int ii){
	a[ii][x[0]]=a[ii][x[2]]+a[ii][x[4]];
}
void init_var_num(char x[], int a[][200], int ii){
	a[ii][x[0]]=x[2]-48;
}
void init_var_var(char x[], int a[][200], int ii){
	a[ii][x[0]]=a[ii][x[2]];
}
void init_var_index(char x[], int a[][200], int ii){
	if(x[3]>='0' && x[3]<='9') a[ii][x[0]]=a[ii][x[3]-'0'+'a'-1];
	if(x[3]>='a' && x[3]<='z') a[ii][x[0]]=a[ii][a[ii][x[3]]+'a'-1];
}
void init_index(char x[], int a[][200], int ii){
	int m, n;
	if(x[1]>='0' && x[1]<='9') m=x[1]-'0'-1+'a';
	if(x[1]>='a' && x[1]<='z') m=a[ii][x[1]]-1+'a';
	if(x[4]>='0' && x[4]<='9') n=x[4]-'0';
	if(x[4]>='a' && x[4]<='z') n=a[ii][x[4]];
	a[ii][m]=n;
}
void print(char x[], int a[][200], int ii){
	printf("%d ", a[ii][x[6]]);
	//sleep(1);
}
void equalization(char x[], int a[][200], int ii){
	if(x[3]=='+') add_var_var(x, a, ii);
	if(x[2]>='0' && x[2]<='9') init_var_num(x, a, ii);
	if(x[3]=='\0' && x[2]>='a' && x[2]<='z') init_var_var(x, a, ii);
	if(x[2]=='[') init_var_index(x, a, ii);
	if(x[0]=='[') init_index(x, a, ii);
}
void if_loop(char x[], int a[][200], int ii){
	char y[20];
	int i=7;
	while(charinRange(x[i])){
		y[i-7]=x[i];
		i+=1;
	}
	y[i-7]='\0';
	int m, n;
	if(x[3]>='0' && x[3]<='9') m=x[3]-'0';
	if(x[3]>='a' && x[3]<='z') m=a[ii][x[3]];
	if(x[5]>='0' && x[5]<='9') n=x[5]-'0';
	if(x[5]>='a' && x[5]<='z') n=a[ii][x[5]];
	if(x[4]=='<' && m<n) equalization(y, a, ii);
	if(x[4]=='>' && m>n) equalization(y, a, ii);
}
void arr_init(int a[][200], int n){
	for(int i=1;i<=n;i++){
		for(int j='a';j<='z';j++)
			a[i][j]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j='0';j<='9';j++)
			a[i][j]=j-'0';
	}
	for(int i=1;i<=n;i++)
		a[i]['z']=i;
}
void arr_print(int a[][200], int n){
	for(int i=1;i<=n;i++){
		printf("%d =>> ", i);
		for(int j='a';j<='z';j++){
			printf("%c=%d, ", j, a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	char x[20];
	int a[50][200];
	int i, n;
	printf("Give number of processes : ");
	scanf("%d", &n);
	arr_init(a, n);
	do{
		scanf("%s", x);
		for(i=1;i<=n;i++){
			if(x[1]=='=' || x[3]=='=') equalization(x, a, i);
			if(x[1]=='r') print(x, a, i);
			if(x[0]=='i' && x[1]=='f') if_loop(x, a, i);
		}
		if(x[1]=='r'){
			printf("\n");
			sleep(1);
		}
		//arr_print(a, n);
	}while(1);
	return 0;
}