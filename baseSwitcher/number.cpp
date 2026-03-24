#include <iostream>

int convert_from_char_to_int(char c) {
    return ((int) c) < 55 ? ((int) c) - 48 : ((int) c) - 55;
}

int main() {
    int result = convert_from_char_to_int('5');
    std::cout << "result = " << result << "\n";
    return 0;
}