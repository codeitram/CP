#include <bits/stdc++.h>

#include "StackLL.h"
using namespace std;

int main() {
  Stack<string> a;
  a.push("Ram ");
  a.push("Krishna ");
  a.push("Singh ");
  while (!a.isEmpty()) {
    cout << a.top();
    a.pop();
  }
}