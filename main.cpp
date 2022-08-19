
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

   //Static: A variável pertence a classe
   cout << "\nTestando metodos statics.\n";
   cout << "Alunos que conseguiram vaga na escola GradeBook:: " << GradeBook::getNumAlunosEscola( ) << '\n';
   cout << "Alunos que conseguiram vaga na escola GRADEBOOK6. " << GRADEBOOK6.getNumAlunosEscola( ) << '\n';
   cout << "Numero de GradeBooks instanciados: "    << GradeBook::getnumGradeBooks( ) << '\n';
   cout << "Numero de GradeBooks instanciados: "    << gradebook0.getnumGradeBooks( ) << '\n';
   
   return 0;
}