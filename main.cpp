
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
   GradeBook::printGrades( );
 
   //Apenas 4 turmas podem ser criadas
   //GradeBook.cpp: const int GradeBook::NUMTURMAS = 4;
   GradeBook gradebook1( "Math", 3 );
   const GradeBook GRADEBOOK2( "Physics", 20 );
   GradeBook gradebook3( "Geography", 70 );
   GradeBook gradebook4( gradebook3 );   
   //Total de alunos na escolha 130. Por quê?

   gradebook1.displayMessage( );
   
   
   return 0;
}