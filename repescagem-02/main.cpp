/* TRABALHO REPESCAGEM 02
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#pragma warning(disable:4996)

#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include "Strategy.h"
#include "Context.h"

using namespace std;

int main()
{
	std::vector<Pedido*>* _pedidos = new std::vector<Pedido*>;

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	tm* dt_current = new tm;

	Produto* Produto1 = new Produto("batata", 10.50, 3);
	Produto* Produto2 = new Produto("arroz", 15, 10);
	Produto* Produto3 = new Produto("feijao", 5, 5);

	Pedido* Pedido1 = new Pedido(Produto1, 5, dt_current);
	Pedido* Pedido2 = new Pedido(Produto2, 3, dt_current);
	Pedido* Pedido3 = new Pedido(Produto3, 2, dt_current);

	_pedidos->push_back(Pedido1);
	_pedidos->push_back(Pedido2);
	_pedidos->push_back(Pedido3);

	Strategy_OrderByProductNameAsc* Strategy1 = new Strategy_OrderByProductNameAsc(_pedidos);

	Context* context = new Context(Strategy1);

	context->ordenaPedido();

	std::cout << "\n\nPedidos ordenados por nome do produto asc: \n" << std::endl;

	context->getStrategy()->exibePedidos();

	Strategy_OrderByPriorityDesc* Strategy2 = new Strategy_OrderByPriorityDesc(_pedidos);

	context->setStrategy(Strategy2);

	context->ordenaPedido();

	std::cout << "\n\nPedidos ordenados pela prioridade desc: \n" << std::endl;

	context->getStrategy()->exibePedidos();

	Strategy_OrderByProductPriceAsc* Strategy3 = new Strategy_OrderByProductPriceAsc(_pedidos);

	context->setStrategy(Strategy3);

	context->ordenaPedido();

	std::cout << "\n\nPedidos ordenados pelo preco do produto asc: \n" << std::endl;

	context->getStrategy()->exibePedidos();

	delete dt_current;

	delete Pedido3;
	delete Pedido2;
	delete Pedido1;

	delete Produto3;
	delete Produto2;
	delete Produto1;

	delete Strategy3;
	delete Strategy2;
	delete Strategy1;

	delete _pedidos;

	delete context;
 }