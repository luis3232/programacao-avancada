/* TRABALHO ESTUDO DIRIGIDO 4
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#include <iostream>

#include "Cliente.h"
#include "Conta.h"
#include "Hora.h"
#include "Banco.h"

using namespace std;

int main()
{
    Cliente* clientes[2];

    clientes[0] = new Cliente("luis", "luis.hihi", "17/09/1998", 23);
    clientes[1] = new Cliente("joao", "joao.hihi", "17/09/2006", 16);

    Conta* conta[5];
    
    conta[0] = new Conta("26735-0", "997", clientes[0]);
    conta[1] = new Conta("99999-0", "123", clientes[1]);
    conta[2] = new Conta("88888-0", "123", clientes[1]);
    conta[3] = new Conta("77777-0", "123", clientes[1]);
    conta[4] = new Conta("66666-0", "123", clientes[1]);

    Banco *meubanco = new Banco(10);
    
    for (int i = 0; i < 5; i++) {
        meubanco->setConta(conta[i]);
    }

    meubanco->imprime_contas();

    Banco* SuperBanco = new Banco(10000);

    SuperBanco->setConta(conta[0]);

    SuperBanco->imprime_contas();

    delete[] clientes;

    delete[] conta;

    delete meubanco;
    meubanco = nullptr;

    delete SuperBanco;
    SuperBanco = nullptr;
}