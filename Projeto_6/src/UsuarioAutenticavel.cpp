//Código de Alissa Garcia ADS - s3

#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel() : Usuario() {
    this->senha = "";
}

UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string email, std::string tipo, std::string senha)
    : Usuario(nome, email, tipo), senha(senha) {}

void UsuarioAutenticavel::setSenha(std::string novaSenha) {
    this->senha = novaSenha;
}