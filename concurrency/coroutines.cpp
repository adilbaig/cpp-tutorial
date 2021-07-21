#include <iostream>
#include <coroutine>

generator<int> getInts(int first, int last){
  for (auto i= first; i <= last; ++i){
    co_yield i;
  }
}

int main(){
  for (auto i: getInts(5, 10)){
    std::cout << i << " ";
  }
}