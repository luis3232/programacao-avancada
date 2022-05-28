/* ED 10 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __TELA_PRINCIPAL_H__
#define __TELA_PRINCIPAL_H__

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

class TelaPrincipal {

public:

    void exibirMenuPrincipal() const {
        std::cout << "|== Menu principal ==|" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Registros de Entrada e Saida" << std::endl;
        std::cout << "2. Clientes" << std::endl;
        std::cout << "3. Mapa de Vagas" << std::endl;
        std::cout << "4. Sair" << std::endl;
    }

    int lerOpcao() const {
        std::cout << ":> ";
        int opcao;
        std::string buffer;
        std::cin >> opcao;
        std::getline(std::cin, buffer);

        return opcao;
    };

};

#endif