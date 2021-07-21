#include <vector>
#include <iostream>
#include <thread>

int func() { 
  static int i = 0; 
  // synchronized { 
    std::cout << "Not interleaved \n"; 
    ++i; 
    std::cout << i << "\n"; 
    return i;  
  // } 
}
 
int main(){
  std::vector<std::thread> v(10); 
  for(auto& t: v) 
    t = std::thread([]{ for(int n = 0; n < 10; ++n) func(); });
}