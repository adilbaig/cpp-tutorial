#include <iostream>

class Pos {
    float x{};
    float y{};

    public:

    constexpr Pos() = default;
    constexpr Pos(float x, float y): x(x), y(y) {}
    constexpr Pos operator +(Pos other) const { // NOTE: Pass by value
        return Pos(x + other.x, y + other.y);
    }

    // Cout
    friend std::ostream& operator<<(std::ostream& os, const Pos& dt);  
};

std::ostream& operator <<(std::ostream& os, const Pos& pos)  
{  
    os << "X:" << pos.x << " Y:" << pos.y;  
    return os;
}

int main(int argc, char const *argv[])
{
    auto p = Pos(1,2);

    std::cout << p << "\n";
    
    return 0;
}
