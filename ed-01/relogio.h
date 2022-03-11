#ifndef __RELOGIO_H__
#define __RELOGIO_H__

#include <string>

class Relogio {

public:

    Relogio(){

        this->hora = 0;
        this->minuto = 0;
    }

    void setHora(int hora);

    void setMinutos(int minuto);

    std::string getMinutosTotais();

    std::string getHorarioFormatado();

    bool isHorariosValidos();

private:

    int hora;
    int minuto;

};

#endif
