#include <iostream>
#include "math_utils.h"
#include "string_utils.h"

using namespace std;

int main() {
    int x;
    cin>>x;

    string y;
    cin>>y;

    std::cout << "Square of 5: " << square(x) << std::endl;
    std::cout << "Reversed string: " << reverseString(y) << std::endl;
    return 0;
}
