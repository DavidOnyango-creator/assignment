#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[20];
    int odd[20], even[20];
    int oddCount = 0, evenCount = 0;

    srand(time(0));  // Seed random generator

    // Fill array with random numbers between 1 and 100
    for(int i = 0; i < 20; i++) {
        arr[i] = rand() % 100 + 1;

        if(arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }

    cout << "Original Array:\n";
    for(int i = 0; i < 20; i++)
        cout << arr[i] << " ";

    cout << "\n\nEven Numbers:\n";
    for(int i = 0; i < evenCount; i++)
        cout << even[i] << " ";

    cout << "\n\nOdd Numbers:\n";
    for(int i = 0; i < oddCount; i++)
        cout << odd[i] << " ";

    return 0;
}