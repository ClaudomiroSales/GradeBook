
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{

   GradeBook::printGrades( );
 
   GradeBook gradebook0;
   GradeBook gradebook1( "Math" );
   const GradeBook GRADEBOOK2( "Physics", 2 );
   GradeBook gradebook3( "Geography", 10 );
   GradeBook gradebook4( 3 );
   const GradeBook GRADEBOOK5( GRADEBOOK2 );//2 alunos
   const GradeBook GRADEBOOK6( gradebook3 );//10 alunos
   //Total de alunos na escolha 27

   gradebook3.displayMessage( );
   cout << "Numero de alunos na escolha: ";   
   cout << GradeBook::getNumAlunosEscola( ) << '\n';
   
   return 0;
}