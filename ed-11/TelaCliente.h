/* ED 11 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

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
        std::cout << "\n\n|== Clientes ==|" << std::endl;
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
        try {
            std::cout << "\n\n== Posicao a ser acessada ==" << std::endl;

            int posicao;
            std::cout << "Posicao: ";
            std::cin >> posicao;

            return posicao;
        }
        catch (std::string erro) {

        }
    }

    void imprimirClientes(const std::vector<Cliente>& lista) const {
        std::cout << "\n\n== Clientes ==" << std::endl;

        for (int i = 0; i < lista.size(); i++) {
            if (lista[i].getNome().empty()) {
                continue;
            }

            std::cout << "ID......: " << lista[i].getID() << std::endl;
            std::cout << "Posicao......: " << i << std::endl;
            std::cout << "Nome......: " << lista[i].getNome() << std::endl;
            std::cout << "Documento......: " << lista[i].getCPF() << std::endl;
            std::cout << "Ativo......: " << lista[i].getisAtivo() << std::endl;
            std::cout << std::endl;
        }
    }

    void visualizarCliente(const std::vector<Cliente>& lista) const {

        int posicao = lerPosicao();

        if (posicao < 0 || posicao > lista.size()) {
            std::cout << "Nao foi possivel acessar este registro" << std::endl;
            return;
        }

        if (lista[posicao].getID() == 0 || lista[posicao].getNome().empty()) {
            return;
        }

        std::cout << "\n\n== Cliente - " << lista[posicao].getNome() << " == " << std::endl;
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

    void exibirMensagemErro(const char* erro) {
        std::cerr << erro << std::endl;
    }


    Cliente lerNovoCliente(long ID) {

        try {
            std::string Nome;
            std::string Email;
            std::string Celular;
            std::string CPF;
            float Mensalidade;
            std::string Endereco;
            std::string Bairro;
            std::string Cidade;
            std::string Estado;
            int Numero;
            std::string Complemento;
            int isAtivo;

            std::cout << "\n\n== Dados do Cliente ==" << std::endl;

            std::cout << "Nome......: ";
            std::getline(std::cin, Nome);

            std::cout << "Email......: ";
            std::getline(std::cin, Email);

            std::cout << "Celular......: ";
            std::getline(std::cin, Celular);

            std::cout << "CPF......: ";
            std::getline(std::cin, CPF);

            std::cout << "Mensalidade......: ";
            std::cin >> Mensalidade;

            std::cin.ignore();
            std::cout << "Endereco......: ";
            std::getline(std::cin, Endereco);

            std::cout << "Bairro......: ";
            std::getline(std::cin, Bairro);

            std::cout << "Cidade......: ";
            std::getline(std::cin, Cidade);

            std::cout << "Estado......: ";
            std::getline(std::cin, Estado);

            std::cout << "Numero......: ";
            std::cin >> Numero;

            std::cin.ignore();
            std::cout << "Complemento......: ";
            std::getline(std::cin, Complemento);

            std::cout << "Ativo (0 ou 1)......: ";

            do {
                std::cin >> isAtivo;
            } while (isAtivo != 0 && isAtivo != 1);

            return Cliente(ID, Nome, Email, Celular, CPF, Mensalidade, Endereco, Bairro, Cidade, Estado, Numero, Complemento, isAtivo);
        }
        catch (std::string erro) {

        }
    }

    void alterarCliente(Cliente& cliente) {

        try {
            std::string Nome;
            std::string Email;
            std::string Celular;
            std::string CPF;
            float Mensalidade;
            std::string Endereco;
            std::string Bairro;
            std::string Cidade;
            std::string Estado;
            int Numero;
            std::string Complemento;
            int isAtivo;

            std::cout << "== Dados do Cliente ==" << std::endl;

            std::cin.ignore();
            std::cout << "Nome......: ";
            std::getline(std::cin, Nome);
            cliente.setNome(Nome);

            std::cout << "Email......: ";
            std::getline(std::cin, Email);
            cliente.setEmail(Email);

            std::cout << "Celular......: ";
            std::getline(std::cin, Celular);
            cliente.setCelular(Celular);

            std::cout << "CPF......: ";
            std::getline(std::cin, CPF);
            cliente.setCPF(CPF);

            std::cout << "Mensalidade......: ";
            std::cin >> Mensalidade;
            cliente.setMensalidade(Mensalidade);
            std::cin.ignore();

            std::cout << "Endereco......: ";
            std::getline(std::cin, Endereco);
            cliente.setEndereco(Endereco);

            std::cout << "Bairro......: ";
            std::getline(std::cin, Bairro);
            cliente.setBairro(Bairro);

            std::cout << "Cidade......: ";
            std::getline(std::cin, Cidade);
            cliente.setNome(Nome);

            std::cout << "Estado......: ";
            std::getline(std::cin, Estado);
            cliente.setEstado(Estado);

            std::cout << "Numero......: ";
            std::cin >> Numero;
            cliente.setNumero(Numero);
            std::cin.ignore();

            std::cout << "Complemento......: ";
            std::getline(std::cin, Complemento);
            cliente.setComplemento(Complemento);

            std::cout << "Ativo (0 ou 1)......: ";

            do {
                std::cin >> isAtivo;
            } while (isAtivo != 0 && isAtivo != 1);

            cliente.setisAtivo(isAtivo);
        }
        catch (std::string erro) {

        }
    }
};

#endif