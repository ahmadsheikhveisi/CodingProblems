
#include <iostream>

class num {
 private:
    int m_x;
 public:
    num(int x): m_x(x) {}
    // num operator+(const num & rhs) const {
    //     return num(m_x + rhs.m_x);
    // }
    friend num operator+(const num& rhs, const num& lhs);
    int get() {
        return m_x;
    }
};
num operator+(const num& rhs, const num& lhs) {
    return num(rhs.m_x + lhs.m_x);
}

template<typename T>
class numTemp {
    T m_x;
 public:
    numTemp(T x): m_x(x) {}  // if marked as explicit, int + num won't compile.
    T get() {
        return m_x;
    }
    template<typename U>
    friend numTemp<U> operator+(const numTemp<U>& rhs, const numTemp<U>& lhs) {
        return numTemp<U>(rhs.m_x + lhs.m_x);
    }
};

template<typename T>
class numTempCorrect {
    T m_x;
 public:
    numTempCorrect(T x): m_x(x) {}  // if marked as explicit, int + num won't compile.
    T get() {
        return m_x;
    }
    // this must be defined inline
    friend numTempCorrect operator+(const numTempCorrect& rhs,
        const numTempCorrect& lhs) {
        return numTempCorrect(rhs.m_x + lhs.m_x);
    }
};

int main() {
    {
        auto temp{num(5)};
        auto res{3 + temp + 2};  // implicit conversions
        std::cout << res.get() << '\n';
    }
    {
        auto temp{numTemp<int>(2)};
        auto temp2{numTemp<int>(5)};
        // auto res{temp + 2};  // implicit conversion can't be done.
        auto res{temp + temp2};
        std::cout << res.get() << '\n';
    }
    {
        auto temp{numTempCorrect<double>(5.3)};
        auto res{3.1 + temp + 2.2};  // implicit conversions
        std::cout << res.get() << '\n';
    }
    return 0;
}
