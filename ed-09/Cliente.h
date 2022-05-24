/* ED 09 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA 

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

ALUNO: LEANDRO ROBERTO DOS SANTOS
RA: 2017207641 */

#ifndef __CLIENTES_H__
#define __CLIENTES_H__

#include <string>

class Cliente {
public:

	Cliente(std::string nome = "", std::string email = "", std::string celular = "", std::string cpf = "",
		float mensalidade = 0.0, std::string endereco = "", std::string bairro = "", std::string cidade = "",
		std::string estado = "", int numero = 0, std::string complemento = "") :
		Nome(nome),
		Email(email),
		Celular(celular),
		CPF(cpf),
		Mensalidade(mensalidade),
		Endereco(endereco),
		Bairro(bairro),
		Cidade(cidade),
		Estado(estado),
		Numero(numero),
		Complemento(complemento) {
	}

	const long& getID() const {
		return ID;
	}

	const std::string& getNome() const {
		return Nome;
	}

	void setNome(const std::string& nome) {
		Nome = nome;
	}

	const std::string& getEmail() const {
		return Email;
	}

	void setEmail(const std::string& email) {
		Email = email;
	}

	const std::string& getCelular() const {
		return Celular;
	}

	void setCelular(const std::string& celular) {
		Celular = celular;
	}

	const std::string& getCPF() const {
		return CPF;
	}

	void setCPF(const std::string& CPF_P) {
		CPF = CPF_P;
	}

	const float& getMensalidade() const {
		return Mensalidade;
	}

	void setMensalidade(const float& mensalidade) {
		Mensalidade = mensalidade;
	}

	const std::string& getEndereco() const {
		return Endereco;
	}

	void setEndereco(const std::string& endereco) {
		Endereco = endereco;
	}

	const std::string& getBairro() const {
		return Bairro;
	}

	void setBairro(const std::string& bairro) {
		Bairro = bairro;
	}

	const std::string& getCidade() const {
		return Cidade;
	}

	void setCidade(const std::string& cidade) {
		Cidade = cidade;
	}

	const std::string& getEstado() const {
		return Estado;
	}

	void setEstado(const std::string& estado) {
		Estado = estado;
	}

	const int& getNumero() const {
		return Numero;
	}

	void setNumero(const int& numero) {
		Numero = numero;
	}

	const std::string& getComplemento() const {
		return Complemento;
	}

	void setComplemento(const std::string& complemento) {
		Complemento = complemento;
	}

	virtual ~Cliente() {}

private:
	long ID;
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
};

#endif