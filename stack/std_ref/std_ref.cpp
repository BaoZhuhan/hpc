#include <bits/stdc++.h>

//what is std::ref and std::cref ?

/*
the create
std::reference_wrapper<Type>
and
std::reference_wrapper<const Type>
*/

void func(int &i) {
    ++i;
}

int main(){
    int local_i = 0;
    auto bound = std::bind(func , local_i);
    bound();
    bound();
    std::cout << local_i;
    return 0;
}