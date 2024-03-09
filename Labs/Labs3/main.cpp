#include <iostream>

#include "complex.h"

int main(){
    Complex a{1.0, 2.0};
    Complex b{3.0, 4.0};

    auto c = a.add(b);
    std::cout << c << '\n'; // 4+6i

    auto d = c.div(a);
    std::cout << d << '\n'; // 3.2-0.4i

    Complex e{"3 + 4.2i"};
    std::cout << e << '\n';

    Complex z{"3 - 4.2i"};
    std::cout << z << '\n';
    Complex x{"3-4.2i"};
    std::cout << x << '\n';
    Complex y{"3- 4.2i"};
    std::cout << y << '\n';
    Complex w{"3 -4.2i"};
    std::cout << w << '\n';
    Complex m{"+4.2"};
    std::cout << m << '\n';
    Complex f{"- 4.2"};
    std::cout << f << '\n';
    Complex g{"-4.2i"};
    std::cout << g << '\n';
    Complex h{"- 4.2i"};
    std::cout << h << '\n';
    Complex i{"-3+ i"};
    std::cout << i << '\n';
    Complex j{"-i"};
    std::cout << j << '\n';
    Complex k{"- i"};
    std::cout << k << '\n';
}