#include <bits/stdc++.h>
using namespace std;

class Car {
 public:
  string name;
  int x, y;
  Car(string id, int x, int y) {
    this->name = id;
    this->x = x;
    this->y = y;
  }
  int distance() const {
    return x * x + y * y;
  }  // why const makes error in
     // L29
};

class Compare {
 public:
  bool operator()(Car a, Car b) { return a.distance() < b.distance(); }
};
bool compare(Car a, Car b) { return a.distance() < b.distance(); }

void printNearestCars(vector<Car> cars, int k) {
  priority_queue<Car, vector<Car>, Compare> max_heap(cars.begin(),
                                                     cars.begin() + k);
  for (int i = k; i < cars.size(); i++) {
    auto car = cars[i];
    if (car.distance() < max_heap.top().distance()) {
      max_heap.pop();
      max_heap.push(car);
    }
  }

  // but this max  heap will be in Descending order so
  vector<Car> output;
  while (!max_heap.empty()) {
    output.push_back(max_heap.top());
    max_heap.pop();
  }
  reverse(output.begin(), output.end());
  for (auto a : output) cout << a.name << endl;
}

int main() {
  int n, k;
  cin >> n >> k;

  string name;
  int x, y;
  vector<Car> cars;
  for (int i = 0; i < n; i++) {
    cin >> name >> x >> y;
    Car car(name, x, y);
    cars.push_back(car);
  }
  printNearestCars(cars, k);
}