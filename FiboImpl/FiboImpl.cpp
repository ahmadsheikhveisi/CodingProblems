/* COPYRIGHT 2021 
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <utility>
#include <tuple>
#include <unordered_map>

int fib_classic(int i) {
    if (i <= 1) {
        return 1;
    }
    return fib_classic(i - 1) + fib_classic(i - 2);
}

// we can use a global map also
std::unordered_map<int, int> map;
int fib_hash(int i) {
    if (i <= 1) {
        return 1;
    }
    if (map.find(i) != map.end()) {
        return map[i];
    }
    int ret_val = fib_hash(i - 1) + fib_hash(i - 2);
    map[i] = ret_val;
    return ret_val;
}

int fib_close_form(int i) {
    constexpr auto sqrt_5 = std::sqrt(5);

    return static_cast<int>((std::pow(sqrt_5 + 1, i) - std::pow(1 - sqrt_5, i))
                             / (std::pow(2, i) * sqrt_5));
}

// limitation is only to a limit values are generated at compile time
constexpr int fib_constexpr(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fib_constexpr(i-1)+fib_constexpr(i-2);
}

// code size is limitation
template<int I>
struct Fib_struct {
    static const int val = Fib_struct<I-1>::val + Fib_struct<I - 2>::val;
};

template<>
struct Fib_struct<0>{
    static const int val = 0;
};

template<>
struct Fib_struct<1>{
    static const int val = 1;
};

// variadic template. fills the array at compile time
template<size_t ... I>
int fib_impl_m(std::index_sequence<I...>, const int i) {
    constexpr std::array<int, sizeof...(I)> a
            = {Fib_struct<I>::val...};
    return a[i];
}
int fib_template_variadic(const int i) {
    return fib_impl_m(std::make_index_sequence<47>{}, i);
}



int main(int argc, char **argv) {
    std::cout << "Hello world\n";
    std::vector<int> vec_a = {0, 0, 0, 1};
    for (auto cnt : vec_a) {
        std::cout << cnt << '\n';
    }

    std::cout << "FIB constexpr fun " << fib_constexpr(30) << '\n';

    std::cout << "Close form " << fib_close_form(46) << '\n';
    std::cout << "Template " << Fib_struct<46>::val << '\n';
    std::cout << "Variadic Template " << fib_template_variadic(46) << '\n';

    auto fib_lambda = [a = 0, b = 1]() mutable {
        struct Results {
            int &a;
            int &b;
            Results next(int num = 1) {
                while (num > 0) {
                    a = std::exchange(b, b+a);
                    --num;
                }
                return *this;
            }

            operator int() {
                return a;
            }
        };

        return Results{a, b}.next();
    };

    std::cout << "Lambda " << fib_lambda().next(45) << '\n';

    std::cout << "fib hash " << fib_hash(45) << '\n';

    int num = 10;
    //  std::cin >> num;
    std::cout << fib_template_variadic(num) << '\n';


    return 0;
}
