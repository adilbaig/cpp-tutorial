#include <thread>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void print(size_t n, const string &str)  {
  string msg = to_string(n) + " : " + str;
  cout << msg  << endl;
}
 
int main() {
  vector<string> s = {
      "Educative.blog",
      "Educative",
      "courses",
      "are great",
  };
  vector<thread> threads;
 
  for (size_t i = 0; i < s.size(); i++) {
    threads.push_back(
      thread(print, i, s[i])
    );
  }
 
  for (auto &th: threads) {
    th.join();
  }

  return 0;
}
