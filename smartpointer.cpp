#include <iostream>
#include <memory>
using namespace std;

//unique_ptr, shared_ptr, weak_ptr

class Test {
    public : 
    Test(int x) : x(x) { cout << "constructor" << endl;}
    ~Test() { cout << "destructor" << endl;}
    int GetX() const {return x;}
    private : 
    int x;
};
int main() {
    // cout << "main 함수 시작" << endl;
    // unique_ptr<Test> a(new Test);
    // cout << "main 함수 종료" << endl;

    // int *a = new int(5);
    // int *b = a;
    
    // delete a;



    // unique_ptr<int> a(new int(5));
    // unique_ptr<int> b(a.release()); //소유권 이전

    // cout << *b << endl;


    // unique_ptr<int> a(new int(5));
    // a.reset(new int(6));
    // cout << *b << endl;



    //a와 b가 동일한 주소를 가리킴
    //a 가 먼저 소멸이 되어도 b가 소멸될 때까지 남아있음.
    // shared_ptr<Test> a(new Test(5));
    // {
    //   shared_ptr<Test> b = a;
    //   cout << a.use_count() <<endl;
    //   cout << b.use_count() <<endl;
    // }
    // cout << a.use_count() <<endl;


    //3. weak_ptr : 소유권 X (a가 소멸되면 b도 못씀)
    //              use_count도 증가X

    weak_ptr<Test> b;
    {
        shared_ptr<Test> a(new Test(5));
        b = a;
        cout << a.use_count() <<endl;
        cout << b.use_count() <<endl;
        if(!b.expired()) {
            cout << b.lock()->GetX() <<endl; //lock : shared point로 가져와서 접근 가능
        }
    }
    cout << b.use_count() <<endl; //이미 소멸됨.
    if(!b.expired()) {
        cout << b.lock()->GetX() <<endl;
    }
}