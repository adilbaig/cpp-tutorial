#include "thread_pool.hpp"

int main()
{
    thread_pool pool(10);
    size_t squares[100];
    pool.parallelize_loop(0, 99, [&squares](size_t i) { squares[i] = i * i; });
    std::cout << "16^2 = " << squares[16] << '\n';
    std::cout << "32^2 = " << squares[32] << '\n';
}
