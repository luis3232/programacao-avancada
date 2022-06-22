/* TRABALHO REPESCAGEM 02
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Pedido.h"

class Strategy {

public:

    Strategy(std::vector<Pedido*>* pedidos) : _pedidos(pedidos)
    {
    }

    virtual ~Strategy()
    {
        //delete[] _pedidos;
    }

    void setPedidos(std::vector<Pedido*>* pedidos) {
        _pedidos = pedidos;
    }

    std::vector<Pedido*>* getPedidos() const {
        return _pedidos;
    }

    void exibePedidos() const {
        for (int i = 0; i < _pedidos->size(); i++) {
            std::cout << "Pedido: " << (i + 1) << "\n"
                << "Prioridade: " << (*_pedidos)[i]->getPrioridade() << "\n"
                << "Produto: " << (*_pedidos)[i]->getProduto()->getNome() << "\n"
                << "Preco: " << (*_pedidos)[i]->getProduto()->getPreco() << "\n"
                << "Quantidade: " << (*_pedidos)[i]->getProduto()->getQuantidade() << "\n" << std::endl;
        }
    }

    virtual void ordenaListaPedidos() = 0;

private:
    std::vector<Pedido*>* _pedidos;
};

class Strategy_OrderByProductNameAsc : public Strategy {

public:

    Strategy_OrderByProductNameAsc(std::vector<Pedido*>* _pedidos) : Strategy(_pedidos) 
    {

    }

    virtual void ordenaListaPedidos() {
        auto lambda = [](Pedido* a, Pedido* b) -> bool {
            return a->getProduto()->getNome() < b->getProduto()->getNome();
        };

        sort(getPedidos()->begin(), getPedidos()->end(), lambda);
    }
};

class Strategy_OrderByPriorityDesc : public Strategy {

public:

    Strategy_OrderByPriorityDesc(std::vector<Pedido*>* _pedidos) : Strategy(_pedidos)
    {

    }

    virtual void ordenaListaPedidos() {
        auto lambda = [](Pedido* a, Pedido* b) -> bool {
            return a->getPrioridade() > b->getPrioridade();
        };

        sort(getPedidos()->begin(), getPedidos()->end(), lambda);
    }
};

class Strategy_OrderByProductPriceAsc : public Strategy {

public:

    Strategy_OrderByProductPriceAsc(std::vector<Pedido*>* _pedidos) : Strategy(_pedidos)
    {

    }

    virtual void ordenaListaPedidos() {
        auto lambda = [](Pedido* a, Pedido* b) -> bool {
            return a->getProduto()->getPreco() < b->getProduto()->getPreco();
        };

        sort(getPedidos()->begin(), getPedidos()->end(), lambda);
    }
};

#endif