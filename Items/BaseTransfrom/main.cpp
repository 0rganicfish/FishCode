#include <iostream>
#include "funclass.hpp"
using namespace std;

int main()
{
    while (1)
    {
        Transf Tf;
        cout << "\nConfirm the Base you want to Enter(en): \n"
             << "  Bin(2), Oct(8), Dec(10), Hex(16)? \n";
        cin >> Tf.Cur;
        cout << "   Then enter a string: \n";
        cin >> Tf.Base;
        Tf.run();
    }
    return 0;
}