#include<stdio.h>
#include<signal.h>

//Write a function checks if the entered integer is prime or not. 
//The function should return nonzero if the integer is prime, zero if the integer is not prime.
//Use the function in a program that receives integers from user and tells if the integer is prime or not, repeatedly. 
//The program can be terminated only by pressing CTRL+C.

int INThandler(int sig){
	signal(sig,SIG_IGN);
	exit(1);
}

int main(){
	
	int n;
	for(;;){
		printf("\nPlease enter an integer:");
		scanf("%d",&n);
		int y=prime(n);
		if(y==0){
			printf("NOT A PRIME NUMBER.");
		}
		else if(y==1){
			printf("PRIME NUMBER");
		}
		signal(SIGINT,INThandler);
	}
	return 0;
}

int prime(int a){
	
	int i;
	int count=0;
	for(i=2;i<a;i++){
		if(a%i==0){
			count++;
		}	
	}
	if(count==0){
		return 1;
	}
	else{
		return 0;
	}

}
