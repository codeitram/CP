// there is todo at last see that and do it.
#include <bits/stdc++.h>
using namespace std;

template <typename T> class Vector
{
  private:
    T *arr;
    int currentCapacity = -1;
    int maximumCapacity;

  public:
    Vector(int cap = 1) // T default =?  to pass this as optional parameter, you cant use diff constructor for it
    {
        maximumCapacity = cap;
        arr = new T[maximumCapacity];
    }

    void push_back(T x)
    {
        currentCapacity++;
        if (currentCapacity == maximumCapacity)
        {
            T *oldArray = arr;
            maximumCapacity = 2 * maximumCapacity;
            arr = new T[maximumCapacity];
            for (int i = 0; i < currentCapacity; i++)
            {
                arr[i] = oldArray[i];
            }
            delete[] oldArray;
        }
        arr[currentCapacity] = x;
    }
    int pop_back()
    {
        if (currentCapacity >= 0)
            currentCapacity--;
        else
            return -1;
    }
    T operator[](const int x) const
    {
        return arr[x];
    }
    T at(int x) const
    {
        return arr[x];
    }
    T front()
    {
        return arr[0];
    }
    T back() const
    {
        return arr[currentCapacity];
    }
    int size() const
    {
        return currentCapacity;
    }
    int capacity() const
    {
        return maximumCapacity;
    }
};

int main()
{
    Vector<int> v;
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    // for(int i=0; i<5;i++) v.pop_back();
    cout << v[3];
    cout << v.back() << ' ';
    cout << v.capacity();
    // Vector<Vector<int>> something = {{ 1,2,3},{1,2,3}}; //TODO. This don't work in this implementation make it more
    // general to accomodate this in future
    Vector<string> s;
    s.push_back("ram krishna singh");
    cout << s.front();
}