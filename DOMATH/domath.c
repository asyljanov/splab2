# include <stdio.h>
int main(int argc, char const *argv[]){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int p1 = fork();
	if(p1==0){
		printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
		addition(a,b);
	}
	else{
		int p2 = fork();
		if(p2==0){
			printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
			subtraction(a,b);
		}
		else{
			int p3 = fork();
			if(p3==0){
				printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
				multiplication(a,b);
			}
			else{
				int p4 = fork();
				if(p4==0){
					printf("I am child of %d with pid %d\n",(int)getppid(),(int)getpid());
					division(a,b);
				}
				else{
					wait(0);
					wait(0);
					wait(0);
					wait(0);
					printf("parent: done.\n");
				}
			}
		}
	}
	return 0;
}
void addition(int n1, int n2){
	printf("child1: %d+%d=%d\n",n1,n2,(n1+n2));
}
void subtraction(int n1, int n2){
	printf("child2: %d-%d=%d\n",n1,n2,(n1-n2));
}
void multiplication(int n1, int n2){
	printf("child3: %d*%d=%d\n",n1,n2,(n1*n2));;
}
void division(int n1, int n2){
	printf("child4: %d/%d=%d\n",n1,n2,(n1/n2));
}
