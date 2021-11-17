#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<string> &books, string s) {
  if (books.empty()) {
    books.push(s);
    return;
  }
  string sa = books.top();
  books.pop();
  insertBottom(books, s);
  books.push(sa);
}

void reverseStack(stack<string> &s) {
  if (s.empty()) return;
  string temp = s.top();
  s.pop();
  reverseStack(s);
  insertBottom(s, temp);
}
int main() {
  stack<string> books;
  books.push("book1");
  books.push("book2");
  books.push("books3");
  insertBottom(books, "book0");
  reverseStack(books);
  while (!books.empty()) {
    cout << books.top() << endl;
    books.pop();
  }
}