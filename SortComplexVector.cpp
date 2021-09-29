#include <bits/stdc++.h>
using namespace std;
int calculateMarks(vector<int> a)
{
    return a[0] + a[1] + a[2];
}
bool compare(pair<string, vector<int>> a, pair<string, vector<int>> b)
{
    vector<int> marks1 = a.second; // you can assing vec1 to vec
    vector<int> marks2 = b.second;
    return calculateMarks(marks1) > calculateMarks(marks2);
}

int main()
{
    vector<pair<string, vector<int>>> student_marks = {
        {"Ram", {0, 20, 30}}, {"Vivek", {21, 23, 34}}, {"Rohan", {23, 33, 23}}};
    sort(student_marks.begin(), student_marks.end());
    for (auto i : student_marks) // as this works for pair, braced list like {1,2}
        cout << i.first << endl;
    sort(student_marks.begin(), student_marks.end(), compare);
    for (auto i : student_marks)
        cout << i.first << endl;
}