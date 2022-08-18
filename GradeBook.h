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

    inline int getnumGradeBooks( ) { return numGradeBooks; }
    inline int getnumAlunosEscola( ) { return numAlunosEscola; }

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
    const static int MAXNUMALUNOSESCOLA;

};

#endif // GRADEBOOK_H