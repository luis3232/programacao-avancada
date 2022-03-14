/* TRABALHO ESTUDO DIRIGIDO 3
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#include <iostream>

#include "Cliente.h"
#include "Conta.h"
#include "Hora.h"

using namespace std;

int main()
{
    Cliente *cliente1 = new Cliente("luis", "luis.hihi", "17/09/1998", 23);

    Conta conta("26735-0", "997", cliente1);

    conta.deposita(500);
    conta.retira(10000);
    conta.retira(200);
    conta.deposita(50);
    conta.imprimeSaldo();

    Cliente *cliente2 = new Cliente("joao", "joao.hihi", "17/09/2006", 16);

    conta.alteraCliente(cliente2);

    conta.imprimeSaldo();

    Hora hora1(22, 10, 15);
    Hora hora2(23, 56, 0);

    hora1.soma(hora2);

    delete cliente1;
	cliente1 = nullptr;
	
    delete cliente2;
	cliente2 = nullptr;
}