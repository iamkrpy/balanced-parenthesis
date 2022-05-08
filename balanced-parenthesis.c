#include <stdio.h>
#include <string.h>
#define MAX 50
int stack[MAX];
int top = -1;
void check(char[],int);
void push(char);
void pop();
int main(void) {
    char str[50];
    int length;
	printf("Enter the string: ");
	scanf("%s",str);
	length = strlen(str);
	check(str,length);
	return 0;
}
void check(char str[],int length){
    int i = 0,flag = 1;
    if(length == 0){
        printf("Please Enter the string!");
        return;
    }
    for(i=0;i<length;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(str[i]);
        }
        else if(str[i]==')'||str[i]=='}'||str[i]==']'){
            if(str[i]==')'&&stack[top]=='('){
                pop();
            }
            else if(str[i]==']'&&stack[top]=='['){
                pop();
            }
            else if(str[i]=='}'&&stack[top]=='{'){
                pop();
            }
            else{
                flag = 0;
            }
            
        }
    }
    if(flag == 1){
        printf("The string is BALANCED !!!");
    }
    else{
        printf("The string is NOT balanced !");
    }
    return;
}
void push(char c){
    if(top == MAX-1){
        printf("The Stack is full!");
        return;
    }
    else{
        top++;
        stack[top] = c;
    }
}
void pop(){
    if(top == -1){
        printf("The Stack is empty!");
        return;
    }
    else{
        top--;
    }
}
