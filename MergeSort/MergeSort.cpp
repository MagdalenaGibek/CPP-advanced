#include <iostream>

void merge(int tab[], int firstIndex, int midIndex, int lastIndex);

void mergesort(int tab[], int firstIndex, int lastIndex)
{
    if (firstIndex >= lastIndex)
    {
        return;
    }
    int midIndex = (firstIndex + lastIndex) / 2;
    mergesort(tab, firstIndex, midIndex);
    mergesort(tab, (midIndex + 1), lastIndex); 
    merge(tab, firstIndex, midIndex, lastIndex);
}

void merge(int tab[], int firstIndex, int midIndex, int lastIndex)
{
    int size1 = midIndex - firstIndex + 1;
    int size2 = lastIndex - midIndex;

    int* leftSide = new int[size1];
    int* rightSide = new int[size2]; 

    for (int i = 0; i < size1; ++i)
    {
        leftSide[i] = tab[firstIndex+i];
    }
    for (int j = 0; j < size2; ++j)
    {
        rightSide[j] = tab[midIndex + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = firstIndex;

    while (i < size1 && j < size2)
    {
        if (leftSide[i] <= rightSide[j])
        {
            tab[k] = leftSide[i];
            ++i;
        }
        else
        {
            tab[k] = rightSide[j];
            ++j;
        }
        ++k;
    }
    while (i < size1)
    {
        tab[k] = leftSide[i];
        ++i;
        ++k;
    }
    while (j < size2)
    {
        tab[k] = rightSide[j];
        ++j;
        ++k;
    }
    delete[] leftSide;
    delete[] rightSide;

}

int main()
{
    unsigned const int size = 6;
    int tab[] = { 6, 5, 12, 10, 9, 1 };
    mergesort(tab, 0, 5);
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]" << tab[i] << std::endl;
    }
}

