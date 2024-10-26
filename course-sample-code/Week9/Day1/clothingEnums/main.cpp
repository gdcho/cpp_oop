#include <iostream>
//store unique id for clothing items using enums
//can determine number of clothes and ranges for clothing by using enums uniquely
using namespace std;

enum clothingId {
    shoeBegin,
    shoe1 = shoeBegin,
    shoe2,
    shoe3,
    shoeEnd = shoe3,
    pantBegin,
    pant1 = pantBegin,
    pant2,
    pant3,
    pant4,
    pant5,
    pantEnd = pant5,
    numClothes
};

int main() {
    for (int i = shoeBegin; i <= shoeEnd; ++i) {
        cout << "shoeId: " << i << endl;
    }
    cout << "numShoes " << shoeEnd - shoeBegin + 1 << endl;

    for (int i = pantBegin; i <= pantEnd; ++i) {
        cout << "pantId: " << i << endl;
    }
    cout << "numPants " << pantEnd - pantBegin + 1 << endl;

    cout << "numClothes " << numClothes<< endl;

    return 0;
}