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
    
    void setNumAlunos( int );

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

private:

    string courseName;
    int numAlunos;
    const int MAXSIZENAME;
    bool check;
    static int numGradeBooks;
    //Error check. Static não pode instanciar no .h
    //static int numGradeBooks = 0;

    static int numAlunosEscola;

    //Pode inicializar aqui ou no cpp
    //const static int MAXNUMALUNOSESCOLA = 100;
    static const int MAXNUMALUNOSESCOLA;

    //Número de notas E, B, R e I
    static const int NUMERODENOTAS = 4;
    static const string NOTAS[ NUMERODENOTAS ];

    //Cada GradeBook tem o seu número fixo de alunos
    static const int NUMALUNOS = 50;
    string alunos[ NUMALUNOS ];

};

#endif // GRADEBOOK_H