#include <iostream>

long gcd(long a, long b){
      if(a == 0){
          return b;
      }else if(b == 0){
          return a;
      }else{
          return gcd(b, a % b);
      }
  }
  
int main(int argc, const char * argv[]) {
    std::cout << gcd(190, 76);
}

