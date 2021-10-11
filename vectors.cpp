#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v) // Good practice - whenever passing a vector to a function, always pass by reference so that the function donot have to make a copy of the vector and O(n) time compexity will be saved.
{
    cout << "Size: " << v.size() << endl; // O(n)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr; /* Creating a vector with no value */
    // vector<int> arr(1, 0); /* Create a vector of 1 element which is 0*/
    // vector<int> arr(10); /* Creating a vector of 10 elements. It will automatically initialize all values by 0.*/
    // vector<int> arr(10, 2); /* Creating a vector of 10 elements. It will automatically initialize all values by 2.*/

    // size of the vector
    cout << "Initial Size: " << arr.size() << endl;

    // pushig values 1 to 9 into the vector
    for (int i = 1; i < 9; i++)
    {
        arr.push_back(i); // O(1)
    }
    //Printing the vector.
    printVec(arr);

    // Poping out elements from the last
    for (int i = 0; i < 3; i++)
    {
        arr.pop_back(); // O(1)
    }
    printVec(arr);

    // Copying a vector
    vector<int> arr1 = arr; // O(n) required for copying a vector
    arr1.push_back(10);
    cout << "Printing copied vector: " << endl;
    printVec(arr1);

    vector<string> str;
    cout << "Enter value of n and then enter n strings" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }

    return 0;
}