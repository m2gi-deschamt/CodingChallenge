#include <string>
#include <vector>
#include <iostream>

std::vector vec = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

int convert_from_char_to_int(char c) {
    return ((int) c) < 65 ? ((int) c) - 48 : ((int) c) - 55;
}

int pow(int value, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= value;
    }
    return result;
}

std::string from_10_to_X(std::string v, int base) {
    int value = std::stoi(v);
    int quotient = value / base;
    int rest = value % base;
    std::string result = "";
    result = vec[rest] + result;
    while (quotient != 0) {
        rest = quotient % base;
        quotient = quotient / base;
        result = vec[rest] + result;
    }
    return result ;
}

std::string from_X_to_10(std::string value, int base) {
    int result = 0;
    for(int i = 0; i < value.size(); i++) {
        result += convert_from_char_to_int(value[i]) * pow(base, (value.size()-1)-i);
    }
    return std::to_string(result);
};

int main(int argc, char const *argv[]) {
    std::string init = "32DFE";
    std::string a = from_X_to_10(init, 16);
    std::string b = from_10_to_X(a, 16);

    std::cout << "init value = " << init << "\n"; 
    std::cout << "a value = " << a << "\n"; 
    std::cout << "b value = " << b << "\n";
    return 0;
}