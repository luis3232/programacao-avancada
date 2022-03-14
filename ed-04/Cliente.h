/* TRABALHO ESTUDO DIRIGIDO 4
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include <iostream>
#include <string>

class Cliente {

	public:
		
		Cliente() : _nome(""), _email(""), _data_nascimento(""), _idade(0) {}

		Cliente(std::string nome, std::string email, std::string data_nascimento, int idade) :
			_nome(nome), _email(email), _data_nascimento(data_nascimento), _idade(idade) {
			std::cout << "\nInicializando o cliente " << nome << "!" << std::endl;
		}

		std::string getNome() const {
			return _nome;
		}

		std::string getEmail() const {
			return _email;
		}

		std::string getNascimento() const {
			return _data_nascimento;
		}

		int getIdade() const {
			return _idade;
		}

		void setNome(std::string nome) {
			_nome = nome;
		}

		void setEmail(std::string email) {
			_email = email;
		}

		void setNascimento(std::string data_nascimento) {
			_data_nascimento = data_nascimento;
		}

		void setIdade(int idade) {
			_idade = idade;
		}

	private:
		std::string _nome;
		std::string _email;
		std::string _data_nascimento;
		int _idade;
};

#endif