#include <iostream>
#include "Persistencia.h"
#include "SinalHandler.h"
#include "Professor.h"
#include "Aluno.h"

int main() {
    std::cout << "Inicializando sistema acadêmico resiliente...\n";

    Persistencia persist("data");

    // registrar persistencia no SinalHandler para que o tratador consiga salvar
    SinalHandler::registrarPersistencia(&persist);
    SinalHandler::inicializar();

    try {
        persist.carregar();
        std::cout << "Dados carregados com sucesso.\n";
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cerr << "Aviso: " << e.what() << " - continuando com dados vazios.\n";
    } catch (const PermissaoNegadaException& e) {
        std::cerr << "Erro de permissão ao carregar: " << e.what() << "\n";
        return 1;
    } catch (const ConversaoDadosException& e) {
        std::cerr << "Erro de conversão ao carregar: " << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado ao carregar: " << e.what() << "\n";
        return 1;
    }

    // Exemplo de uso: criar professor e aluno e persistir
    try {
        Professor p("Carlos Silva", "carlos@uni.edu", "senha123", "Matemática");
        p.disciplinasAdicionadas("Cálculo I");
        persist.adicionarProfessor(p);

        Aluno a("Mariana Souza", "mariana@uni.edu", "mypass", "2025001", "Sistemas");
        a.adicionarHistorico("Cálculo I", 2024, 8.5f);
        persist.adicionarAluno(a);

        persist.adicionarDisciplina("Programação Estruturada");

        std::cout << "Dados de exemplo adicionados e salvos.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Erro ao adicionar/salvar: " << ex.what() << "\n";
    }

    std::cout << "Programa finalizando normalmente. Salvando antes de sair...\n";
    try {
        persist.salvar();
    } catch (const std::exception& ex) {
        std::cerr << "Erro ao salvar na finalização: " << ex.what() << "\n";
    }

    return 0;
}
