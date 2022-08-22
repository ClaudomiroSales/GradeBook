#include "GradeBook.h"

#include <iostream>
using std::cout;
using std::endl;

//Instanciação de variáveis statics
int GradeBook::numGradeBooks = 0;
int GradeBook::numAlunosEscola = 0;
const int GradeBook::NUMTURMAS = 4;
const int GradeBook::MAXNUMALUNOSESCOLA = NUMTURMAS * NUMALUNOSPORTURMA;
const string GradeBook::NOTAS[ NUMERODENOTAS ] = {"E","B","R","I"};

int GradeBook::getNumAlunosEscola( )
{ 
    return numAlunosEscola; 
}


GradeBook::GradeBook( )
:courseName(""), numAlunos( 0 ), MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{  
      numGradeBooks++;  

}

GradeBook::GradeBook( string name, int numAlunos )
:MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{
    setCourseName( name );
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( int numAlunos )
:courseName(""), MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{
    setNumAlunos( numAlunos );

    numGradeBooks++;
}

GradeBook::GradeBook( const GradeBook& other )
:MAXSIZENAME( other.MAXSIZENAME ), check( other.check ), numAlunosCadastrados( 0 )
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
    //Valor inválido para numAlunos
    if ( numAlunos <= 0 )
    {
        numAlunos = 0;
        return;
    }

    //Número de alunos ultrapassou o número máximo por turma
    if ( numAlunos > NUMALUNOSPORTURMA )
    {
        this->numAlunos = NUMALUNOSPORTURMA;
        GradeBook::numAlunosEscola += this->numAlunos; 
        return;
    }

    //Tem mais vagas que o número de alunos que estão sendo requisitados
    this->numAlunos = numAlunos;
    GradeBook::numAlunosEscola += this->numAlunos;    
}

string GradeBook::getCourseName( )
{
    return courseName;
} 

void GradeBook::displayMessage( bool check ) const
{
    if( !check )
        return;
    if( courseName.size( ) > 0 )
    {
        cout << "Welcome to the Grade Book for course " << courseName << '.'
        << " A Turma tem " << numAlunos << " aluno.\n"; 
        printListaAlunos( );
        return;
    }                 

    cout << "Welcome to the Grade Book. Curso sem nome.";
}

void GradeBook::displayMessage( bool check )
{
    //Atribuição dentro da classe
    this->check = check;

    if( !this->check )
        return;
    if( courseName.size( ) > 0 )
    {
        cout << "Welcome to the Grade Book for course " << courseName << '.'
        << " A Turma tem " << numAlunos << " aluno:\n"; 
        printListaAlunos( );
        return;
    }         

    cout << "Welcome to the Grade Book. Curso sem nome.\n";    
}

void GradeBook::printGrades( )
{
    for( int i = 0; i < NUMERODENOTAS; i++ )
        cout << NOTAS[ i ] << ' ' << '(' <<&NOTAS[ i ] << ')' << '\n';
    
}

void GradeBook::cadastrarAlunoGradeBook( const string &novoAluno )
{
    //O array alunos[] tem tamanho máximo de NUMALUNOSPORTURMA
    //Mas só pode aceitar numAlunos, que foi configurado durante a inicialização 
    //através do método setNumAlunos
    //Necessário criar um atributo para controlar quanto alunos tem realmente na turma
    //que deve ser menor que numAlunos
    
    if( numAlunosCadastrados < numAlunos ) 
    {
        numAlunosCadastrados++;
        alunos[ numAlunosCadastrados - 1 ] = novoAluno;        
        return;
    }

    cout << "Nao possivel cadastrar novos alunos. Turma cheia.\n";

}

void GradeBook::printListaAlunos( ) const
{
    for( int i = 0; i < numAlunosCadastrados; i++ )
        cout << alunos[i] << endl;
}