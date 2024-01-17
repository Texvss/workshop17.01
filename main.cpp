#include <iostream>

int main(){
    int a, b;
    std::string name;
    std::cin >> name >> a >> b;
    std::cout << "Hello," << name << std::endl;
    std::cout << "The sum is:" << " " << a << "+" << b << "=" << a + b;
    return 0;
}
