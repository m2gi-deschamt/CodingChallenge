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
    if(argc != 4) {
        std::cout << "Please give 3 arguments (value, base1, base2)\n";
        return 0;
    }
    std::string value = argv[1];
    int base1 = std::stoi(argv[2]);
    int base2 = std::stoi(argv[3]);

    std::string result = from_X_to_10(value, base1);
    result = from_10_to_X(result, base2);
    std::cout << result << "\n";
    return 0;
}