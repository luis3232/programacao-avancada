/* ED 09 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TELA_CLIENTE_H__
#define __TELA_CLIENTE_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"

class TelaCliente {

public:

    void exibirMenuClientes() const {
        std::cout << "|== Clientes ==|" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Cadastrar" << std::endl;
        std::cout << "2. Visualizar Todos" << std::endl;
        std::cout << "3. Visualizar Especifico" << std::endl;
        std::cout << "4. Alterar" << std::endl;
        std::cout << "5. Retornar Menu Principal" << std::endl;
    }

    int lerOpcao() const {
        std::cout << ":> ";
        int opcao;
        std::string buffer;
        std::cin >> opcao;
        std::getline(std::cin, buffer);

        return opcao;
    };

    int lerPosicao() const {
        std::cout << "== Posição a ser acessada ==" << std::endl;

        int posicao;
        std::cout << "Posição: ";
        std::cin >> posicao;

        return posicao;
    }

    void imprimirClientes(const std::vector<Cliente>& lista) const {
        std::cout << "== Clientes ==" << std::endl;

        for (int i = 0; i < lista.size(); i++) {
            std::cout << "ID......: " << lista[i].getID() << std::endl;
            std::cout << "Nome......: " << lista[i].getNome() << std::endl;
            std::cout << "Documento......: " << lista[i].getCPF() << std::endl;
            std::cout << "Ativo......: " << lista[i].getisAtivo() << std::endl;
            std::cout << std::endl;
        }
    }

    void visualizarCliente(const std::vector<Cliente>& lista, int posicao) const {

        if (posicao < 0 || posicao > lista.size()) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        std::cout << "== Cliente - " << lista[posicao].getNome() << " == " << std::endl;
        std::cout << "ID......: " << lista[posicao].getID() << std::endl;
        std::cout << "Nome......: " << lista[posicao].getNome() << std::endl;
        std::cout << "Email......: " << lista[posicao].getEmail() << std::endl;
        std::cout << "Celular......: " << lista[posicao].getCelular() << std::endl;
        std::cout << "Documento......: " << lista[posicao].getCPF() << std::endl;
        std::cout << "Mensalidade......: " << lista[posicao].getMensalidade() << std::endl;
        std::cout << "Endereco......: " << lista[posicao].getEndereco() << std::endl;
        std::cout << "Bairro......: " << lista[posicao].getBairro() << std::endl;
        std::cout << "Cidade......: " << lista[posicao].getCidade() << std::endl;
        std::cout << "Estado......: " << lista[posicao].getEstado() << std::endl;
        std::cout << "Numero......: " << lista[posicao].getNumero() << std::endl;
        std::cout << "Complemento......: " << lista[posicao].getComplemento() << std::endl;
        std::cout << "Ativo......: " << lista[posicao].getisAtivo() << std::endl;
        std::cout << std::endl;
    }

    bool cadastrarCliente(std::vector<Cliente>& lista, Cliente cliente) {

        lista.push_back(cliente);

        std::cout << "Cliente inserido com sucesso!" << std::endl;

        return true;
    }

    bool alterarCliente(std::vector<Cliente>& lista, Cliente cliente, int posicao) {

        if (posicao < 0 || posicao > lista.size()) {
            return false;
        }

        lista[posicao] = cliente;

        std::cout << "Cliente alterado com sucesso!" << std::endl;

        return true;
    }

};

#endif