#include <bits/stdc++.h>
using namespace std;

// class Product
// {
//   private:
//     int id;
//     char name[100];
//     int mrp;
//     int selling_price;

//   public:
//     // Constructor
//     Product()
//     {
//         cout << "Inside constructor";
//     }
//     // Parameterised Constructor
//     Product(int id, char *n, int mrp, int selling_price)
//     {
//         this->id = id;
//         this->mrp = mrp;
//         this->selling_price = selling_price;
//         strcpy(name, n);
//     }

//     Product(Product &X)
//     {
//         // Create to the copy
//         id = X.id;
//         strcpy(name, X.name); // Array
//         mrp = X.mrp;
//         selling_price = X.selling_price;
//     }

//     // Setters
//     void setMrp(int price)
//     {
//         if (price > 0)
//         {
//             mrp = price;
//         }
//     }
//     void setSellingPrice(int price)
//     {
//         // additional checks
//         if (price > mrp)
//         {
//             selling_price = mrp;
//         }
//         else
//         {
//             selling_price = price;
//         }
//     }
//     // Getters
//     int getMrp()
//     {
//         return mrp;
//     }
//     int getSellingPrice()
//     {
//         return selling_price;
//     }

//     void showDetails()
//     {
//         cout << "Name : " << name << endl;
//         cout << "Id : " << id << endl;
//         cout << "Selling Price " << selling_price << endl;
//         cout << "MRP : " << mrp << endl;

//         cout << "----------" << endl;
//     }
// };

class Product {
  int id;
  char name[100];
  int mrp;
  int sp;

 public:
  // constructors
  Product() { cout << "I am inside a constructor\n"; }
  Product(int id, char *name, int mrp, int sp)  // parameterized constructor
  {
    this->id = id;
    this->mrp = mrp;
    this->sp = sp;
    strcpy(this->name, name);
  }

  // Product(Product &X) // copy constructor is there by default but it does
  // shallow copy
  // {
  //     // Create to the copy
  //     id = X.id;
  //     strcpy(name, X.name); // Array
  //     mrp = X.mrp;
  //     sp = X.sp;
  // }

  void getId() { cout << id << endl; }
  void getName() { cout << name << endl; }
  void getMrp() { cout << mrp << endl; }
  void getSp() { cout << sp << endl; }
};

int main() {
  class Product y(1, "Ram", 100, 102);
  class Product x(y);
  y.getId();
  y.getName();
  x.getName();
}