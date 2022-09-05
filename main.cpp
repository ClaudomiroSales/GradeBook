
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
    
   //Apenas 4 turmas podem ser criadas
   //GradeBook.cpp: const int GradeBook::NUMTURMAS = 4;
   GradeBook gradebook1( "Math", 3 );
   GradeBook *gradebookPtr;
   int novosAlunos = 10;   
   
   gradebookPtr = new GradeBook( "Geografia", 3 );

   gradebookPtr->displayMessage( );

   gradebookPtr->setNumAlunos( novosAlunos );

   gradebookPtr->displayMessage( );   
   
   return 0;
}