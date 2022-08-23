
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
   //Ponteiro em C++
   //GradeBook *gradebookPtr;
   //Pode inicializar já com um endereço válido 
   //GradeBook *gradebookPtr = &gradebook1;
   //Ou inserir o endereço depois
   gradebookPtr = &gradebook1;


   //Lista de alunos
   const int NUMALUNOS = 4;
   const string alunos[ NUMALUNOS ] = { "Catarina", "Sophia", "Noemi", "Goo"};
   cout << "Imprimindo alunos fora:\n";
   for( int i = 0; i < NUMALUNOS; i++ )
        cout << alunos[i] << endl;
   
   //Cadastrando alunos para gradebook1
   gradebook1.cadastrarAlunoGradeBook( alunos[ 0 ] );
   gradebook1.cadastrarAlunoGradeBook( alunos[ 1 ] );
      //Cadastrando alunos em gradebook1 usando gradebookPtr
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 2 ] );
   gradebook1.displayMessage( );
   cout << "Imprimindo lista de alunos de gradebook1 usando o ponteiro gradebookPtr.\n";
   gradebookPtr->displayMessage( );
   cout << "Endereco de gradebook1: " << gradebookPtr << endl;
   gradebookPtr = &gradebook3;
   cout << "Agora gradebookPtr aponta para gradebook3.\n";
   cout << "Endereco de gradebook3: " << gradebookPtr << endl;
   return 0;
}