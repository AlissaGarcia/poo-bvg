//Código de Alissa Garcia ADS S3

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <string>
#include <iostram>

using namespace std;

class Professor : public Usuario {
    private:
        string areadeAtuacao;
       vector<string> disciplinasMinistradas; //atributos adicionais
    public:
    Professor(); //construtor padrão
    Professor(string nome, string email, string tipo, string areadeAtuacao); //Cosntrutor parametrizado
    void disciplinasAdicionadas(string disciplina); //vetor de strings
    void gerarRelatorio() override; //método sobrescrito

};

#endif //PROFESSOR_H
