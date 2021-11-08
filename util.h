
template <typename T>
bool isOdd(T n);

template <typename T>
bool isEven(T n);

template <typename T>
bool isOdd(T n) {
    return !isEven(n);
}

template <typename T>
bool isEven(T n) {
    return n % 2 == 0;
}
