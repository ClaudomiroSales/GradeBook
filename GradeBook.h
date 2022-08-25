#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using std::string;

class GradeBook
{
public:

    GradeBook ( );    
    GradeBook( string , int = 0 );
    GradeBook( int );
    GradeBook( const GradeBook & );
    
    void setCourseName( string );
    
    string getCourseName( );

    void displayMessage( bool = true ) const;
    void displayMessage( bool = true );

    int getNumAlunos( ) const { return numAlunos; }

    //ERROR: métodos statis não podem ser const
    //ERROR: static int getnumGradeBooks( ) const { return numGradeBooks; }
    //Implementação no .h
    static int getnumGradeBooks( )  { return numGradeBooks; }
    //Implementação no .cpp
    static int getNumAlunosEscola( );// { return numAlunosEscola; }

    static void printGrades( );

    //Para tipos não nativos usar o const _ &
    void cadastrarAlunoGradeBook( const string & );

    void printListaAlunos( ) const;

private:

    string courseName;
    int numAlunos;
    int numAlunosCadastrados;
    const int MAXSIZENAME;
    bool check;
    static int numGradeBooks;
    //Error check. Static não pode instanciar no .h
    //static int numGradeBooks = 0;

    static int numAlunosEscola;

    //Pode inicializar aqui ou no cpp
    //const static int MAXNUMALUNOSESCOLA = 100;
    static const int MAXNUMALUNOSESCOLA;

    //Número de turmas
    static const int NUMTURMAS;

    //Número de notas E, B, R e I
    static const int NUMERODENOTAS = 4;
    static const string NOTAS[ NUMERODENOTAS ];

    //Cada GradeBook tem o seu número fixo de alunos
    static const int NUMALUNOSPORTURMA = 50;
    string alunos[ NUMALUNOSPORTURMA ];

    //Método privado
    void setNumAlunos( int );

    //Alocação dinâmica de memória
    //Guarda o histórico da quantidade de alunos
    //que fizeram a disciplina ao longo dos anos
    int *histPtr;
};

#endif // GRADEBOOK_H