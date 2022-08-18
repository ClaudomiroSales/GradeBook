
#include "GradeBook.cpp"
#include "GradeBook.h"

//This is where the execution of program begins
int main()
{
 
   cout << "Usando sobrecarga e parametros default.\n\n";

   GradeBook gradebook0;
   GradeBook gradebook1( "Math" );
   const GradeBook GRADEBOOK2( "Physics", 2 );
   GradeBook gradebook3( "Geography", 10 );
   GradeBook gradebook4( 3 );
   const GradeBook GRADEBOOK5( GRADEBOOK2 );
   const GradeBook GRADEBOOK6( gradebook3 );

   cout << "\nDuas versoes do metodo displayMessage: const e nao const\n";
   GRADEBOOK2.displayMessage( );
   GRADEBOOK5.displayMessage( );
   gradebook3.displayMessage( );//Objects não const podem usar métodos const

   //ERROR: tentando usar método não const
   //GRADEBOOK5.setNumAlunos( 10 );

   //Variável pertence a classe
   cout << "\nTestando atributos statics.\n";
   cout << "Alunos em GradeBook3 " << gradebook3.getNumAlunos( ) << '\n';

   //gradebook3( "Geography", 10 )
   //GRADEBOOK6( gradebook3 )
   //Não pode ter 10 alunos pois ultrapassa o número máximo de alunos
   cout << "Alunos em GradeBook6 " << GRADEBOOK6.getNumAlunos( ) << '\n';

   cout << "Alunos que conseguiram vaga na escola " << gradebook3.getnumAlunosEscola( ) << '\n';
   cout << "Numero de GradeBooks instanciados: "    << gradebook3.getnumGradeBooks( ) << '\n';
   cout << "Numero de GradeBooks instanciados: "    << gradebook0.getnumGradeBooks( ) << '\n';
   
   return 0;
}