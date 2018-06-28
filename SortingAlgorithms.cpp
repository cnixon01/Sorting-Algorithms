#include "SortingAlgorithms.h"
#include <time.h>
#define NUMBERS_PER_LINE_TO_PRINT 5

// Returns the count
void SortingAlgorithms::SetCount(int count)
{
    this->count = count;
}

// Prints the list:
void SortingAlgorithms::PrintList()
{
    int numbersPrintedSoFar = 0;

    if (arr == nullptr)
        return;

    cout << "Displaying " << NUMBERS_PER_LINE_TO_PRINT <<" elements per line\n";

    for (int i = 0; i < count; i++)
    {
        cout << "  " << arr[i] << "\t|";
        numbersPrintedSoFar++;
        if (numbersPrintedSoFar == NUMBERS_PER_LINE_TO_PRINT)
        {
            cout << "\n";
            numbersPrintedSoFar = 0;
        }

    }
}

// Default Constructor:
SortingAlgorithms::SortingAlgorithms()
{
    count = 0;
    arr = nullptr;
}

// Destructor
SortingAlgorithms::~SortingAlgorithms()
{
    if (this->arr != nullptr)
        delete[] arr;
}

// Clears the array and then randomizes it:
void SortingAlgorithms::Randomize()
{
    if (arr == nullptr)
        arr = new int[count];
    else
    {
        delete[] arr;
        arr = new int[count];
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++)
        arr[i] = rand() % 1000 + 1;

}

void SortingAlgorithms::Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// |===========================================================================|
// |                                 Bubble Sort                               |
// |===========================================================================|
void SortingAlgorithms::BubbleSort()
{
    bool swappedSomething = false;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swappedSomething = true;
            }
        }
        if (!swappedSomething)
            break;
        else
            swappedSomething = false;
    }
}
