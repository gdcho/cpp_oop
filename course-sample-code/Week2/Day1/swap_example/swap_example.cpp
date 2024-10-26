#include <iostream>

using namespace std;
//pass by value
void swap1(int arg1, int arg2){
    int temp{arg1};
    arg1 = arg2;
    arg2 = temp;
}

//pass by value with array
void swap2(int array [], int length, int arg1, int arg2){
    cout << "size of array inside: " << sizeof(array) << endl;
    int temp{array[arg1]};
    array[arg1] = array[arg2];
    array[arg2] = temp;
}

//pass by value with pointers
void swap3(int* first, int* second)
{
    int tmp{*first};
    *first = *second;
    *second = tmp;
}

int main()
{
    //swap pointers/ints
    int a{3512};
    int b{2526};
    cout << a << " " << b << endl;
    swap1(a, b); //swap with copy
    //swap3(&a, &b); //swap with pointers
    cout << a << " " << b << endl;

    //swap array
    int numbers [] = {1, 2, 3, 4};
    cout << "size of array: " << sizeof(numbers) << endl;
    for(int i=0; i<4; i++)
    {
        cout << numbers[i];
    }
    cout << endl;
    swap2(numbers, 4, 0, 3); //swap with array
    for(int i=0; i<4; i++)
    {
        cout << numbers[i];
    }
    cout << endl;
}

