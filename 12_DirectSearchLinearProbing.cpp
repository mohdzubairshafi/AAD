#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

int hashFun(int key)
{
    return key % SIZE;
}
int probe(int H[], int key)
{
    int index = hashFun(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
        i++;
    return (index + i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = hashFun(key);
    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}
int Search(int H[], int key)
{
    int index = hashFun(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key && i < SIZE)
    {
        i++;
    }
    if (H[(index + i) % SIZE] == key)
    {
        return (index + i) % SIZE;
    }
    return -1;
}
int main()
{
    int HT[10] = {0};
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    cout << "HashTable: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << HT[i] << " ";
    }
    cout << endl;
    cout << "\nSearching for 25: " << endl;
    printf("Key found at %d\n", Search(HT, 25));
    cout << "\nSearching for 21: " << endl;
    printf("Key found at %d\n", Search(HT, 21));
    return 0;
}