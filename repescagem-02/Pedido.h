/* TRABALHO REPESCAGEM 02
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include <iostream>
#include <string>

#include "Produto.h"

class Pedido {

public:

    Pedido(Produto* produto, int prioridade_entrega, tm* dt_Entrega) :
        _produto(produto),
        _dt_Entrega(dt_Entrega),
        _prioridade_entrega(prioridade_entrega)
    {
       
    }

    ~Pedido() {
        delete _produto;
    }

    void setPrioridade(int prioridade_entrega) {
        _prioridade_entrega = prioridade_entrega;
    }

    void setDt_Entrega(tm* dt_Entrega) {
        _dt_Entrega = dt_Entrega;
    }

    void setProduto(Produto* produto) {
        _produto = produto;
    }

    const tm* getDt_Entrega() const {
        return _dt_Entrega;
    }

    const std::string getDt_Entrega_Formatado() const {

        std::string aux = "";

        aux = std::to_string(_dt_Entrega->tm_mday) + '-'
            + std::to_string(_dt_Entrega->tm_mon + 1) + '-'
            + std::to_string(_dt_Entrega->tm_year + 1900) + " - "
            + std::to_string(_dt_Entrega->tm_hour) + ":"
            + std::to_string(_dt_Entrega->tm_min);

        return aux;
    }

    const int getPrioridade() const {
        return _prioridade_entrega;
    }

    const Produto* getProduto() const {
        return _produto;
    }

private:
    int _prioridade_entrega;
    tm* _dt_Entrega;
	Produto* _produto;
};

#endif