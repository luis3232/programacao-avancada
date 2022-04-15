/* TRABALHO REPESCAGEM
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#include <iostream>

#include "Imprimivel.h"
#include "VetorInt.h"

using namespace std;

int main()
{
    VetorInt* v1 = new VetorInt(10);
    VetorInt* v2 = new VetorInt(10);
    VetorInt* v3 = new VetorInt(10);

    for (int i = 0; i < 10; i++) {
        v1->setInteiro(i, i + 1);
        v2->setInteiro(i, i + 2);
    }

    cout << "Imprimindo v1 original: " << endl;
    v1->imprime();

    cout << "\nImprimindo v2 original: " << endl;
    v2->imprime();

    v3 = (*v1) + v2;

    cout << "\nImprimindo v3 + " << endl;
    v3->imprime();

    v3 = (*v1) - v2;

    cout << "\nImprimindo v3 - " << endl;
    v3->imprime();

    v3 = (*v1) * v2;

    cout << "\nImprimindo v3 * " << endl;
    v3->imprime();

    if ((*v1) == v2) {
        cout << "\nOs vetores v1 e v2 sao iguais!" << endl;
    }
    else {
        cout << "\nOs vetores v1 e v2 nao sao iguais!" << endl;
    }

    if ((*v1) != v2) {
        cout << "\nOs vetores v1 e v2 sao diferentes!" << endl;
    }
    else {
        cout << "\nOs vetores v1 e v2 nao sao diferentes!" << endl;
    }

    (*v1) += v2;

    cout << "\nImprimindo v1 += v2 " << endl;
    v1->imprime();

    (*v2) -= v2;

    cout << "\nImprimindo v2 -= v1 " << endl;
    v2->imprime();

    v3 = (*v1) * 2;

    cout << "\nImprimindo v3 * escalar 2 v1 " << endl;
    v3->imprime();

    (*v1) *= 2;

    cout << "\nImprimindo v1 escalar 2 " << endl;
    v1->imprime();

    delete v1;
    v1 = nullptr;

    delete v2;
    v2 = nullptr;

    delete v3;
    v3 = nullptr;

    return 1;
}