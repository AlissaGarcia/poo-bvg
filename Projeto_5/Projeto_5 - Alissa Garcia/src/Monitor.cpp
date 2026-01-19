//Código de Alissa Garcia ADS S3
#include "monitor.h"

// Construtor padrão
Monitor::Monitor() : Usuario(), Aluno(), Professor() {}

// Construtor parametrizado
Monitor::Monitor(string nome, string email, string tipo,
                 string matricula, string curso)
    : Usuario(nome, email, tipo),
      Aluno(nome, email, tipo, matricula, curso),
      Professor(nome, email, tipo) {
}

// Adiciona disciplina monitorada
void Monitor::adicionarDisciplinaMonitorada(string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

// Lista disciplinas monitoradas
void Monitor::listarDisciplinasMonitoradas() {
    cout << "Disciplinas monitoradas:" << endl;
    for (string d : disciplinasMonitoradas) {
        cout << "- " << d << endl;
    }
}

// Relatório completo do monitor
void Monitor::gerarRelatorio() {

    Usuario::gerarRelatorio();      //chamando a classe base
    Aluno::gerarRelatorio();       //chamando a classe base
    Professor::gerarRelatorio();  //chamando a classe base
    listarDisciplinasMonitoradas();
    cout << endl;
}
