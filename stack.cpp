#include <iostream>
#include <string>
using namespace std;
struct Stack{
    int data[1000];
    int size = 0;
    Stack(){
      size = 0;
    }
    void push(int n) {
        data[size] = n;
       size ++;
    }
    int pop(){
        if (isEmpty()) return -1;
        size--;
        return data[size];
    }
    bool isEmpty(){
       if(size == 0) return true;
       else return false;
    }
    int top(){
        if(isEmpty()) return -1;
       else return data[size-1];
    }

};

int main() {
    int n;
    cin >> n;
    Stack s;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            s.push(num);
        }
        else if (cmd == "top") {
            cout << (s.isEmpty() ? -1 : s.top()) << '\n';
        }
        else if (cmd == "size") {
            cout << s.size << '\n';
        }
        else if (cmd == "empty") {
            cout << s.isEmpty() << '\n';
        }
        else if (cmd == "pop") {
            cout << (s.isEmpty() ? -1 : s.top()) << '\n';
            if(!s.isEmpty()){
                s.pop();
            }
        }
    }
    return 0;
}