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

    ContaCorrente* conta_corrente   = new ContaCorrente("22222-0", "997", clientes[0]);
    ContaPoupanca* conta_poupanca   = new ContaPoupanca("11111-0", "997", clientes[1]);
    ContaSalario* conta_salario     = new ContaSalario("33333-0", "997", clientes[1]);

    conta_corrente->deposita(1000);
    conta_poupanca->deposita(1000);

    conta_corrente->imprimeSaldo();
    conta_corrente->aplicaJurosDiarios(20);

    conta_poupanca->imprimeSaldo();
    conta_poupanca->aplicaJurosDiarios(20);

    conta_corrente->imprimeSaldo();
    conta_poupanca->imprimeSaldo();

    delete conta_corrente;
    conta_corrente = nullptr;

    delete conta_poupanca;
    conta_poupanca = nullptr;

    delete[] clientes;

    return 1;
}