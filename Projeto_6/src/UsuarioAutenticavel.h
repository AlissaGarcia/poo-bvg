//Código de Alissa Garcia ADS - S3 

#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
protected:
    std::string senha;

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(std::string nome, std::string email, std::string tipo, std::string senha);
    virtual ~UsuarioAutenticavel() = default;

    // Método abstrato para autenticação
    virtual bool autenticar(std::string senha) const = 0;

    // Setter para senha (pode ser usado para alterar senha)
    void setSenha(std::string novaSenha);
};

#endif // USUARIO_AUTENTICAVEL_H

