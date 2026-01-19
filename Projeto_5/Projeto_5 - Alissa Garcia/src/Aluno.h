//Código de Alissa Garcia ADS S3

#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
#include <iostram>

using namespace std;

class Aluno : virtual public Usuario {
    private:
        string matricula;
        string curso; //atributos adicionais
    public:
    Aluno(); //construtor padrão
    Aluno(string nome, string email, string tipo, string matricula, string curso); //Cosntrutor parametrizado

    void gerarRelatorio() override; //método sobrescrito

};

#endif //ALUNO_H
