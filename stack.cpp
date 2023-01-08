#include <iostream>

using namespace std;
#define siz 10
struct Stack{
    char arr[siz];
    int top;

};
Stack s;
//push
void push(char exp){
    if(s.top == siz-1){
        cout << "stack overflow ";
    }
    else {
        s.top++;
        s.arr[s.top] = exp ;
    }
}
//pop
void pop(){
    if(s.top == -1){
        cout << "stack underflow";
    }
    else{
        s.top--;
    }
}
// display
void display(){
    if(s.top == -1){
        cout << "stack is empty";
}
    else{
        for(int i=s.top ; i>=0; i--){
            cout << s.arr[i];
    }
}
}

int main()
{
    s.top = -1;
    push(5);
    push(8);
    pop();
    display();


    return 0;
}

