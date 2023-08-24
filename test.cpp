#include <iostream>
using namespace std;

// Binary Search Function
void searchForWord(string s, string array[], int left, int right) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == s) {
            cout << "Found at index: " << mid << endl;
            return;
        } else if (array[mid] < s) {
            searchForWord(s, array, mid + 1, right);  // Adjusted range for the right half
            return;
        } else {
            searchForWord(s, array, left, mid - 1);   // Adjusted range for the left half
            return;
        }
    }

    cout << "Not here!" << endl;
}

// Selection Sort Function
template <class swapType>
void sort(swapType list[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int lowestPos = i;  // Corrected variable name
        for (int j = i + 1; j < length; j++) {
            if (list[j] < list[lowestPos]) {  // Changed 'array' to 'list'
                lowestPos = j;
            }
        }
        swap(list[i], list[lowestPos]);
    }
}

int main() {
    string target = "nokia";

    string phones[9] = {"samsung", "oneplus", "huawei", "sony", "iphone", "tlc", "google", "xiaomi", "nokia"};

    // Using selection sort to sort the array
    sort(phones, 9);

    // Searching for the target word
    searchForWord(target, phones, 0, 8);  // Corrected range for the search

    return 0;
}
