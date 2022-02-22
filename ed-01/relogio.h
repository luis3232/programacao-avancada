#ifndef __RELOGIO_H__
#define __RELOGIO_H__

#include <string>

class Relogio {

public:

    void setHora(int hora);

    void setMinutos(int minuto);

    std::string RetornaMinutosTotais();

    std::string RetornaHorarioFormatado();

    bool isHorariosValidos();

private:

    int hora;
    int minuto;

};

#endif
