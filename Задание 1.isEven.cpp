#include <iostream>
#include <algorithm>

bool isEven(int value) {
    return !(value&1);
}

int main() {
    std::cout<< isEven(552);
}
