#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
#define PRIME 7
int hashFun(int key)
{
    return key % SIZE;
}
int hashFun2(int key)
{

    return (PRIME - (key % PRIME));
}
int probe(int H[], int key)
{
    int h1 = hashFun(key);
    int h2 = hashFun2(key);
    int i = 0;
    while (H[(h1 + (i * h2)) % SIZE] != 0)
        i++;
    return (h1 + (i * h2)) % SIZE;
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
    Insert(HT, 5);
    Insert(HT, 25);
    Insert(HT, 15);
    Insert(HT, 35);
    Insert(HT, 95);
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