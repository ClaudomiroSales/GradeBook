
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
    
   //Apenas 4 turmas podem ser criadas
   //GradeBook.cpp: const int GradeBook::NUMTURMAS = 4;
   GradeBook gradebook1( "Math", 3 );
   GradeBook *gradebookPtr;
   //Ponteiro em C++
   //GradeBook *gradebookPtr;
   //Pode inicializar já com um endereço válido 
   //GradeBook *gradebookPtr = &gradebook1;
   //Ou inserir o endereço depois
   cout << "Criando um objeto e colocando o endereco no ponteiro.\n";
   gradebookPtr = new GradeBook( "Geografia", 3 );

   //Lista de alunos
   const int NUMALUNOS = 4;
   const string alunos[ NUMALUNOS ] = { "Catarina", "Sophia", "Noemi", "Goo"};
   cout << "Imprimindo alunos fora:\n";
   for( int i = 0; i < NUMALUNOS; i++ )
        cout << alunos[i] << endl;
   
   //Cadastrando alunos
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 0 ] );
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 1 ] );
      //Cadastrando alunos em gradebook1 usando gradebookPtr
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 2 ] );
   cout << "Imprimindo lista de alunos de gradebook1 usando o ponteiro gradebookPtr.\n";
   gradebookPtr->displayMessage( );
   cout << "Endereco de gradebook1: " << gradebookPtr << endl;

   cout << "Deletando o objeto.\n";
   delete gradebookPtr;
   gradebookPtr = 0;
   cout << "\n\n";

   cout << "Criando outro objeto e colocando o endereco no ponteiro.\n";
   gradebookPtr = new GradeBook( gradebook1 );

   //Cadastrando dois alunos
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 0 ] );
   gradebookPtr->cadastrarAlunoGradeBook( alunos[ 1 ] );
   gradebookPtr->displayMessage( );
   
   return 0;
}