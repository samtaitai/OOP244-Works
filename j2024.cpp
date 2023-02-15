// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    char ch;
    char num1[50];
    char num2[50];
    
    std::cout << "Enter: "; // " j,20,24\n"
    std::cin >> ch; //j
    std::cout << "ch is: " << ch << std::endl;
    
    std::cin.ignore(9999, ',');
    std::cin.get(num1, 3); //20 
    //only cin.get ok 
    //..or istream ends here by getline
    std::cout << "num1 is: " << num1 << std::endl;
    
    std::cin.ignore(9999, ',');
    std::cin.get(num2, 7); //getline or get both ok
    std::cout << "num2 is: " << num2 << std::endl;
    
    std::cout << "end" << std::endl;
    
    return 0;
}