/* ED 10 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __CONTROLE_CLIENTE_H__
#define __CONTROLE_CLIENTE_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

#include "Cliente.h"
#include "TelaCliente.h"

class ControleCliente {

public:

    ControleCliente() : 
        _clientes(std::vector<Cliente>()),
        _tela_cliente(TelaCliente())
    {
        // vazio
    }

    void executar() {
        while (true) {

            // Exibir o menu principal
            _tela_cliente.exibirMenuClientes();

            // Usuário escolhe uma opção
            int opcao = _tela_cliente.lerOpcao();

            // Tratamento da opção
            switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                _tela_cliente.imprimirClientes(_clientes);
                break;
            case 3:
                _tela_cliente.visualizarCliente(_clientes);
                break;
            case 4:
                alterarCliente();
                break;
            case 5:
                return;
                break;
                return;
            }
        }
    }

    void cadastrarCliente() {
        Cliente cliente = _tela_cliente.lerNovoCliente();

        cliente.insereCliente(_clientes, cliente);
    }

    void alterarCliente() {
        try {
            int posicao = _tela_cliente.lerPosicao();
            _tela_cliente.alterarCliente(_clientes[posicao]);
            
            _clientes[posicao].alterarCliente(_clientes, _clientes[posicao], posicao);
        }
        catch (const char* erro) {
            _tela_cliente.exibirMensagemErro(erro);
        }
    }

    std::vector<Cliente> retornaClientes() {
        return _clientes;
    }

private:
    TelaCliente _tela_cliente;
    std::vector<Cliente> _clientes;
};

#endif