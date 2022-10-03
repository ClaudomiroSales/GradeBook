#include "GradeBook.h"

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

//Instanciação de variáveis statics
int GradeBook::numGradeBooks = 0;
int GradeBook::numAlunosEscola = 0;
const string GradeBook::NOTAS[ NUMERODENOTAS ] = {"E","B","R","I"};

int GradeBook::getNumAlunosEscola( )
{ 
    return numAlunosEscola; 
}


GradeBook::GradeBook( )
:histPtr(0), courseName(""), numAlunos( 0 ), MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{  
      histSize = 0;
      numGradeBooks++;  

}

GradeBook::GradeBook( string name, int numAlunos )
:MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{
    nextEntrieInHist = 0;
    histSize = 0;
    histPtr = 0;
    setCourseName( name );
    setNumAlunos( numAlunos );  

    numGradeBooks++;
}

GradeBook::GradeBook( int numAlunos )
:courseName(""), MAXSIZENAME( 9 ), check( false ), numAlunosCadastrados( 0 )
{
    nextEntrieInHist = 0;
    histSize = 0;
    histPtr = 0;
    setNumAlunos( numAlunos ); 

    numGradeBooks++;
}

GradeBook::GradeBook( const GradeBook& other )
:MAXSIZENAME( other.MAXSIZENAME ), check( other.check ), numAlunosCadastrados( 0 )
{
    this->courseName = other.courseName;
    setNumAlunos( other.numAlunos );

    this->histSize = other.histSize;
    this->nextEntrieInHist = other.nextEntrieInHist;
    this->histPtr = new int[ this->histSize ];
    for( int i = 0; i < nextEntrieInHist; i++ )
        this->histPtr[ i ] = other.histPtr[ i ];

    this->alunos.resize( other.alunos.size() );
    for( auto i = 0; i < other.alunos.size( ); i++ )
        this->alunos[ i ] = other.alunos[ i ];    

    numGradeBooks++;
}

GradeBook::~GradeBook( )
{
    delete [] histPtr; 

    for( auto i = 0; i < alunos.size( ); i++ )
        delete this->alunos[ i ];  
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
    if ( GradeBook::numAlunosEscola > 0 )
        GradeBook::numAlunosEscola -= this->numAlunos;
        
    //Valor inválido para numAlunos
    if ( numAlunos <= 0 )
    {
        numAlunos = 0;
        return;
    }    
   
    this->numAlunos = numAlunos;
    GradeBook::numAlunosEscola += this->numAlunos;
    cadastrarRegInHist( numAlunos );  
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
        cout << "Imprimindo histórico de alunos.\n";
        printHist( );
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
        << " A Turma tem " << numAlunos << " alunos:\n"; 
        printListaAlunos( );
        cout << "Imprimindo historico de alunos.\n";
        printHist( );
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
    //O vector alunos pode crescer dinamicamente
    //Mas só pode aceitar numAlunos
    
    if( alunos.size( ) < numAlunos ) 
    {
        numAlunosCadastrados++;
        alunos.push_back( new string(novoAluno) );        
        return;
    }

    cout << "Nao eh possivel cadastrar " << novoAluno << '.' << " Turma cheia.\n";

}

void GradeBook::printListaAlunos( ) const
{
    for( int i = 0; i < alunos.size( ); i++ )
        cout << alunos[i] << '\t' << *alunos[ i ] << endl;
}

 void GradeBook::cadastrarRegInHist( int numAlunos )
 {
    if ( nextEntrieInHist < histSize )
    {
        histPtr[ nextEntrieInHist++ ] = numAlunos;
        return;
    }

    if( histSize == 0 )
    {
        histSize = 1;
        histPtr = new int[ histSize ];
        histPtr[ nextEntrieInHist++ ] = numAlunos;
        return;
    }       

    alocarHist( numAlunos );    
 }

 void GradeBook::printHist( ) const
 {
    for( int i = 0; i < nextEntrieInHist; i++ )
        cout << histPtr[ i ] << '\n'; 
    
 }

 void GradeBook::alocarHist( int numAlunos ) 
 {    
    //cout << "Allocating...\n";
    int *histTemp = new int[ histSize ];
    for( int i = 0; i < nextEntrieInHist; i++ )
        histTemp[ i ] = histPtr[ i ];

    delete [] histPtr;
    histSize += int( ceil( histSize * 0.5 ) );//Aumenta a memória em 50%
    //cout << "New histSize " << histSize << '\n';
    //cout << "And nextEntrieInHist " << nextEntrieInHist << '\n';
    histPtr = new int[ histSize ];
    for( int i = 0; i < nextEntrieInHist; i++ )
        histPtr[ i ] = histTemp[ i ];
    histPtr[ nextEntrieInHist++ ] = numAlunos;
    //cout << "histPtr[ nextEntrieInHist ] " << histPtr[ nextEntrieInHist - 1 ] << '\n';
    //cout << "And nextEntrieInHist " << nextEntrieInHist << '\n';
    //cout << "numAlunos " << numAlunos << '\n';

    delete [] histTemp;     
      
 }