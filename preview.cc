#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

void print_out(const vector<int>& res) {
  for (auto r : res) {
    cout << r << endl;
  }
}

int main() {
  vector<int> test{1, 2, 3, 4};
  print_out(test);
}
