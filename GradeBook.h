#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
using std::string;

#include <vector>
using std::vector;

class GradeBook
{
public:

    GradeBook ( );    
    GradeBook( string , int = 0 );
    GradeBook( int );
    GradeBook( const GradeBook & );
    ~GradeBook( );
    
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

    void cadastrarRegInHist( int );

    void setNumAlunos( int );

private:

    string courseName;
    int numAlunos;
    //Número de alunos cadastrados em alunos
    //Usado em cadastrarAlunoGradeBook
    //alunos[ numAlunosCadastrados - 1 ] = novoAluno;
    int numAlunosCadastrados;
    const int MAXSIZENAME;
    bool check;
    static int numGradeBooks;
    //Error check. Static não pode instanciar no .h
    //static int numGradeBooks = 0;

    static int numAlunosEscola;
    
    //Número de notas E, B, R e I
    static const int NUMERODENOTAS = 4;
    static const string NOTAS[ NUMERODENOTAS ];

    //O número de alunos pode crescer dinamicamente
    vector< string * > alunos;   

    //Alocação dinâmica de memória
    //Guarda o histórico da quantidade de alunos
    //que fizeram a disciplina ao longo dos anos
    int *histPtr;

    //Tamanho alocado para histPtr
    int histSize;

    //Quantidade de registros em histPtr
    //Quantidades de alunos cadastrados ao longo do ano
    int nextEntrieInHist;

    void printHist( ) const;

    //Método para aumentar a memória disponível em histPtr
    void alocarHist( int );

};

#endif // GRADEBOOK_H