/* TRABALHO ESTUDO DIRIGIDO 5
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#include <iostream>

#include "Cliente.h"
#include "Hora.h"
#include "Banco.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "ContaSalario.h"

using namespace std;

int main()
{
    Cliente* clientes[2];

    clientes[0] = new Cliente("luis", "luis.hihi", "17/09/1998", 23);
    clientes[1] = new Cliente("joao", "joao.hihi", "17/09/2006", 16);

    ContaPoupanca* conta_poupanca   = new ContaPoupanca("11111-0", "997", clientes[1], 100);
    ContaPoupanca* conta_poupanca2  = new ContaPoupanca("11111-1", "997", clientes[1], 2000);

    ContaCorrente* conta_corrente   = new ContaCorrente("22222-0", "997", clientes[0], 100);
    ContaCorrente* conta_corrente2  = new ContaCorrente("22222-1", "997", clientes[0], 1000);

    ContaSalario* conta_salario     = new ContaSalario("33333-0", "997", clientes[1], 500);

    Banco* SuperBanco = new Banco(5);

    SuperBanco->setConta(conta_poupanca);
    SuperBanco->setConta(conta_poupanca2);
    SuperBanco->setConta(conta_corrente);
    SuperBanco->setConta(conta_corrente2);
    SuperBanco->setConta(conta_salario);

    SuperBanco->imprime_contas();

    for (int i = 0; i < 5; i++) {
        SuperBanco->getContaEspecifica(i)->aplicaJurosDiarios(40);
    }

    SuperBanco->imprime_contas();

    delete SuperBanco;
    SuperBanco = nullptr;

    delete conta_corrente;
    conta_corrente = nullptr;
    delete conta_corrente2;
    conta_corrente2 = nullptr;

    delete conta_poupanca;
    conta_poupanca = nullptr;
    delete conta_poupanca2;
    conta_poupanca2 = nullptr;

    delete conta_salario;
    conta_salario = nullptr;

    delete clientes[0];
    delete clientes[1];

    return 1;
}