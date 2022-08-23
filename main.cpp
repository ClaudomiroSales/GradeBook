
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
    
   //Apenas 4 turmas podem ser criadas
   //GradeBook.cpp: const int GradeBook::NUMTURMAS = 4;
   GradeBook gradebook1( "Math", 3 );
   const GradeBook GRADEBOOK2( "Physics", 20 );
   GradeBook gradebook3( "Geography", 70 );
   GradeBook *gradebookPtr;   
   //Lista de alunos
   const int NUMALUNOS = 4;
   const string alunos[ NUMALUNOS ] = { "Catarina", "Sophia", "Noemi", "Goo"};
   cout << "Imprimindo alunos fora:\n";
   for( int i = 0; i < NUMALUNOS; i++ )
        cout << alunos[i] << endl;
   
   gradebook1.cadastrarAlunoGradeBook( alunos[ 0 ] );
   gradebook1.cadastrarAlunoGradeBook( alunos[ 1 ] );
   gradebook1.cadastrarAlunoGradeBook( alunos[ 2 ] );
   gradebook1.displayMessage( );
   
   return 0;
}