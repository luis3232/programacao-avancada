/* ED 13 - 2 BIMESTRE PROGRAMAÇÃO AVANÇADA

ALUNO: LUIS AURELIO CAMPOS
RA: 2017207390

IMPLEMENTAÇÃO DO MEMENTO EM C++ */

#include <iostream>
#include <vector>

/*
 * Memento
 * armazena o estado original do objeto Originator and protege
 * contra objetos de externos, fora o originator
 */
 
class Memento
{
private:
    // acessivel apenas pelo Originator
    friend class Originator;

    Memento(const int s) : state(s) {}

    void setState(const int s)
    {
        state = s;
    }

    int getState()
    {
        return state;
    }

private:
    int state;
};

/*
 * Originator
 * cria o memento contendo um snapshot do seu estado interno atual
 * e usa o memento para retornar a um outro estado
 */
 
class Originator
{
public:

    void setState(const int s)
    {
        std::cout << "Alterado o status para: " << s << "." << std::endl;
        state = s;
    }

    int getState()
    {
        return state;
    }

    void setMemento(Memento* const m)
    {
        state = m->getState();
    }

    Memento *createMemento()
    {
        return new Memento(state);
    }

private:
    int state;
};

/*
 * CareTaker
 * é responsavel por armazenar o historico do memento
 * utiliza o Originator para salvar e retornar os estados
 */
 
class CareTaker
{
public:
    CareTaker(Originator* const o) : originator(o) {}

    ~CareTaker()
    {
        for (unsigned int i = 0; i < history.size(); i++)
        {
            delete history.at(i);
        }
        history.clear();
    }

    void salvarEstado()
    {
        std::cout << "Estado salvo!" << std::endl;
        history.push_back(originator->createMemento());
    }

    void retornarEstado()
    {
        if ( history.empty() )
        {
            std::cout << "Impossivel retornar o estado!" << std::endl;
            return;
        }

        Memento *m = history.back();
        originator->setMemento(m);
        std::cout << "Estado retornado!" << std::endl;

        history.pop_back();
        delete m;
    }

private:
    Originator *originator;
    std::vector<Memento*> history;
};


int main()
{
    Originator *originator = new Originator();
    CareTaker *caretaker = new CareTaker(originator);

    originator->setState(1);
    caretaker->salvarEstado();

    originator->setState(2);
    caretaker->salvarEstado();

    originator->setState(3);
    
    caretaker->retornarEstado();
    std::cout << "Estado atual: " << originator->getState() << "." << std::endl;
    
    caretaker->retornarEstado();
    std::cout << "Estado atual: " << originator->getState() << "." << std::endl;

    delete originator;
    delete caretaker;

    return 0;
}