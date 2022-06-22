/* TRABALHO REPESCAGEM 02
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __PRODUTO_H__
#define __PRODUTO_H__

#include <iostream>
#include <string>

class Produto {

public:

    Produto(std::string nome, float preco, int quantidade) :
        _nome(nome),
        _preco(preco),
        _quantidade(quantidade)
    {

    }

    void setNome(std::string nome) {
        _nome = nome;
    }

    void setPreco(float preco) {
        _preco = preco;
    }

    void setQuantidade(int quantidade) {
        _quantidade = quantidade;
    }

    const std::string getNome() const {
        return _nome;
    }

    const float getPreco() const {
        return _preco;
    }

    const int getQuantidade() const {
        return _quantidade;
    }
		
private:
	std::string _nome;
	float _preco;
	int _quantidade;
};

#endif