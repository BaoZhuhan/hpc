#include <bits/stdc++.h>
#include <thread>

void f(int) {std::cout << "hello world!\n" ;}

int main(){
    std::thread t {f,1};
    t.join(); //有参数的构造函数，会启动一个线程
    std::thread t2;/*无参数的构造函数，不会启动一个线程*/
    
    return 0;
}