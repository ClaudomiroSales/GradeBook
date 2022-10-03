
#include "GradeBook.cpp"
#include "GradeBook.h"

#include <vector>
using std::vector;

//This is where the execution of program begins
int main()
{
    
   //Apenas 4 turmas podem ser criadas
   //GradeBook.cpp: const int GradeBook::NUMTURMAS = 4;
   GradeBook gradebook1( "Math", 3 );
   GradeBook *gradebookPtr;
   int novosAlunos = 5;

   //Criando uma lista de alunos
   vector< string * > alunos;
   alunos.push_back( new string( "Noemi") );  
   alunos.push_back( new string( "Sopia") );
   alunos.push_back( new string( "Catarina") ); 
   alunos.push_back( new string( "Raphael") ); 
   alunos.push_back( new string( "Ursula") ); 
   alunos.push_back( new string( "Natasha") ); 
   
   gradebookPtr = new GradeBook( "Geografia", 3 );

   gradebookPtr->displayMessage( );

   gradebookPtr->setNumAlunos( novosAlunos );

   gradebookPtr->displayMessage( );   

   //Cadastrando os alunos da lista no gradebook de Geografia
   for( int i = 0; i < alunos.size(); i++ )
      gradebookPtr->cadastrarAlunoGradeBook( *alunos[ i ] );
   
   cout << "\n\nUsando displayMessage com uma lista de alunos.\n";
   gradebookPtr->displayMessage( );

   GradeBook *gradebookPtr_extra = new GradeBook( *gradebookPtr );
   cout << "\n\nImprimindo informacoes de gradebookPtr_extra.\n";
   gradebookPtr_extra->displayMessage( );

   //Desalocando memória
   for( int i = 0; i < alunos.size(); i++ )
   {
      delete alunos[ i ];
      alunos.pop_back( );
   }

   delete gradebookPtr;
   delete gradebookPtr_extra;

   return 0;
}