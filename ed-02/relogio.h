/* TRABALHO ESTUDO DIRIGIDO 2
AUTOR: LUIS AURELIO CAMPOS
RA: 2017207390 */

#ifndef __RELOGIO_H__
#define __RELOGIO_H__

#include <sstream>
#include <string>

/* METODOS CONSTANTES DA CLASSE (QUE NÃO MODIFICAM O OBJETO):

getMinutosTotais()
getHorarioFormatado()
isHorariosValidos()
getStringValue(int)

*/

class Relogio {

public:

    Relogio() {
    }
    
    Relogio(int hora_p, int minuto_p): hora(hora_p), minuto(minuto_p) {}

    void setHora(int hora) {
        this->hora = hora;
    }

    void setMinutos(int minuto) {
        this->minuto = minuto;
    }

    std::string getMinutosTotais() const {
        int horas_totais = (this->hora * 60) + this->minuto;
        
        return this->getStringValue(horas_totais);
    }

    std::string getHorarioFormatado() const;

    bool isHorariosValidos() const;
    
    std::string getStringValue(int) const;

private:

    int hora;
    int minuto;
    
    const int HORA_MAX = 23;
    const int MINUTO_MAX = 59;
    const int HORA_MINUTO_MIN = 0;

};

inline bool Relogio::isHorariosValidos() const
{
    return this->hora >= this->HORA_MINUTO_MIN && this->hora <= this->HORA_MAX 
        && this->minuto >= this->HORA_MINUTO_MIN && this->minuto <= this->MINUTO_MAX;
}

#endif
