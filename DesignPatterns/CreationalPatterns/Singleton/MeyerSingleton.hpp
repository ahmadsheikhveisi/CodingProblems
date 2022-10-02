
#ifndef DESIGNPATTERNS_CREATIONALPATTERNS_SINGLETON_MEYERSINGLETON_HPP_
#define DESIGNPATTERNS_CREATIONALPATTERNS_SINGLETON_MEYERSINGLETON_HPP_

class MeyerSingleton {
 public:
    int& get();
    MeyerSingleton();
 private:
    class imple;
    static imple& SingletonImple();
    imple& cachedImple;
};

#endif  // DESIGNPATTERNS_CREATIONALPATTERNS_SINGLETON_MEYERSINGLETON_HPP_
