#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int nHighest;
int nmax;
int ntotal;

class Item {
public:
    int nweight;
    int nhappy;
};

Item getItem() {
    Item item;

    cout << "Enter another item." << endl << "Enter weight: ";
    cin >> item.nweight;

    cout << "Enter happiness: ";
    cin >> item.nhappy;

    return item;
}

int getItems(Item item[]){
    int i;
    for (i = 0; i < ntotal; i++){
        item[i] = getItem();
    }
    return i;
}

int calculate(Item item[]){
    int value1;
    int value2;
    int value3;
    int naddw1;
    int naddh1;
    int naddw2;
    int naddh2;
    for (int j = 0; j < ntotal; j++){
        if (nHighest < item[j].nhappy && item[j].nweight <= nmax){
            nHighest = item[j].nhappy;
        }
    }
    if (ntotal >= 2){
        for (value1 = 0; value1 < ntotal; value1++){
            for (value2 = value1 + 1; value2 < ntotal; value2++) {
                naddw1 = item[value1].nweight + item[value2].nweight;
                naddh1 = item[value1].nhappy + item[value2].nhappy;
                if(nHighest < naddh1 && naddw1 <= nmax){
                    nHighest = naddh1;
                }
            }
        }
    }
    if (ntotal >= 3) {
        for (value1 = 0; value1 < ntotal; value1++) {
            for (value2 = value1 + 1; value2 < ntotal; value2++) {
                for (value3 = value2 + 1; value3 < ntotal; value3++){
                    naddw2 = item[value1].nweight + item[value2].nweight + item[value3].nweight;
                    naddh2 = item[value1].nhappy + item[value2].nhappy + item[value3].nhappy;
                    if(nHighest < naddh2 && naddw2 <= nmax){
                        nHighest = naddh2;
                    }
                }
            }
        }
    }
    return nHighest;
}

int main()
{
    cout << "Write in the value for maximum weight: ";
    cin >> nmax;

    cout << "Write in the total amount of items to be keyed in: ";
    cin >> ntotal;

    Item item[ntotal];

    getItems(item);

    cout << "Calculating....." << endl;

    calculate(item);

    cout << "The highest possible happiness is: " << nHighest;

    getch();
}
