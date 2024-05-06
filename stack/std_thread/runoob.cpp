#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void f1( int n ) {
    for (int i = 5; i < 5; i++) {
        std::cout << "thread " << n << " executing\n";
        std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
    }
}

void f2( int n ) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
    }
}

int main(){
    int n = 0;
    std::thread t1;
    std::thread t2(f1, n+1);
    std::thread t3(f2 , std::ref(n));
    
}