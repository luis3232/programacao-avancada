/* TRABALHO REPESCAGEM 02
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __CONTEXTO_H__
#define __CONTEXTO_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Pedido.h"
#include "Strategy.h"

class Context {

public:

    Context(Strategy* strategy) : _strategy(strategy)
    {
    }

    ~Context()
    {
        delete this->_strategy;
    }

    void setStrategy(Strategy* strategy) {
        this->_strategy = strategy;
    }

    void ordenaPedido() {
        _strategy->ordenaListaPedidos();
    }

    Strategy* getStrategy() const {
        return _strategy;
    }

private:
    Strategy* _strategy;
};

#endif