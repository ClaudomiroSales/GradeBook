#include "GradeBook.h"

#include <iostream>
using std::cout;

//Instanciação de variáveis statics
int GradeBook::numGradeBooks = 0;
int GradeBook::numAlunosEscola = 0;
const int GradeBook::MAXNUMALUNOSESCOLA = 20;


int GradeBook::getNumAlunosEscola( )
{ 
    return numAlunosEscola; 
}


GradeBook::GradeBook( )
:courseName(""), numAlunos( 0 ), MAXSIZENAME( 9 ), check( false )
{  
      numGradeBooks++;  
}

GradeBook::GradeBook( string name, int numAlunos )
:MAXSIZENAME( 9 ), check( false )
{
    setCourseName( name );
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( int numAlunos )
:courseName(""), MAXSIZENAME( 9 ), check( false )
{
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( const GradeBook& other )
:MAXSIZENAME( other.MAXSIZENAME ), check( other.check )
{
    this->courseName = other.courseName;
    setNumAlunos( other.numAlunos );

    numGradeBooks++;
}

/* GradeBook::GradeBook( const GradeBook& other )
:courseName( other.courseName ), numAlunos( other.numAlunos ), check( other.check )
{
    numGradeBooks++;
}
} */

 void GradeBook::setCourseName( string name )
{
    if ( name.length( ) <= MAXSIZENAME )
        courseName = name;
    else   
        {
            courseName = name.substr( 0, MAXSIZENAME );
            cout << "Nome alterado. Excedeu o valor maximo. \n";
        }
}


void GradeBook::setNumAlunos( int numAlunos )
{    
    //Valor inválido para numAlunos ou a escola já tem o número máximo de alumos
    if ( numAlunos <= 0 || ( GradeBook::numAlunosEscola == MAXNUMALUNOSESCOLA ) )
    {
        numAlunos = 0;
        return;
    }

    //Tem mais vagas que o número de alunos que estão sendo requisitados
    if ( ( numAlunos + GradeBook::numAlunosEscola ) <= MAXNUMALUNOSESCOLA )
    {
        this->numAlunos = numAlunos;
        GradeBook::numAlunosEscola += this->numAlunos;    
        return;        
    }

    //O número de vagas é insuficiente para todos os alunos
    this->numAlunos =  MAXNUMALUNOSESCOLA - GradeBook::numAlunosEscola;
    GradeBook::numAlunosEscola = MAXNUMALUNOSESCOLA; 

    /*
    if ( numAlunos > 0 )
        if ( ( numAlunos + GradeBook::numAlunosEscola ) <= MAXNUMALUNOSESCOLA )
        {
            this->numAlunos = numAlunos;
            GradeBook::numAlunosEscola += this->numAlunos;            
        }
        else
            if( ( MAXNUMALUNOSESCOLA - GradeBook::numAlunosEscola ) > 0 )
            {
              this->numAlunos =  MAXNUMALUNOSESCOLA - GradeBook::numAlunosEscola;
              GradeBook::numAlunosEscola += this->numAlunos; 
            }
            else
              this->numAlunos = 0;
    else
        this->numAlunos = 0;    

    */
}

string GradeBook::getCourseName( )
{
    return courseName;
} 

void GradeBook::displayMessage( bool check ) const
{
    if( check )
    {
        if( courseName.size( ) > 0 )
            cout << "Welcome to the Grade Book for course " << courseName << '.';          
        else
            cout << "Welcome to the Grade Book. Curso sem nome.";

        cout << " A Turma tem " << numAlunos << " aluno.\n";  
    }

}

void GradeBook::displayMessage( bool check )
{
    //Atribuição dentro da classe
    this->check = check;

    if( this-check )
    {
        if( courseName.size( ) > 0 )
            cout << "Welcome to the Grade Book for course " << courseName << '.';          
        else
            cout << "Welcome to the Grade Book. Curso sem nome.";

        cout << " A Turma tem " << numAlunos << " aluno.\n";  
    }

}