#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca de aloca��es de testo por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Responsavel por cadastrar os usu�rios do sistema
{
	//Inicio cria��o de vari�veis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final das cria��o de vari�veis/strign
   
   printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
   scanf("%s", cpf);//%s refere-se a string
   
   strcpy(arquivo, cpf); //responsavel por copia os valores das string
   
   FILE *file; //criar arquivo
   file = fopen(arquivo, "w");//cria o arquivo e o"w" significa escrever
   fprintf(file,cpf);//salvar o valor da variavel
   fclose(file);//fechar o arquivo
   
   file = fopen (arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen (arquivo, "a");
   fprintf(file,",");
   fclose(file);

   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%S",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
		
	}
	   
}
int consultar()
{
	setlocale(LC_ALL,"portuguese"); //Definido a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o encontrado!. \n");
	}
	    
    while(fgets(conteudo,200,file)!= NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}
int main()

{
  int opcao=0; //definindo vari�veis
  int laco=1;
  
  for(laco=1;laco=1;)
  {   
  
    system("cls");

    setlocale(LC_ALL,"portuguese"); //Definido a linguagem
   
    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
    printf("Escolha a op��o no menu abaixo:\n\n");
    printf("\t1 - registrar alunos\n");
    printf("\t2 - deletar alunos\n");
    printf("\t3 - consultar alunos\n\n");
    printf("\t4 - sair do sistema\n\n");
    printf("op��o: ");//fim do menu
    
    scanf("%d", &opcao); //Amazenando a escolha do usu�rio     
   
    system("cls");//Responsavel por limpar a tela
    
    switch(opcao)//Inicio da sele��o do menu
    {
    	case 1:
    	registro(); //Chamada de fu��es Registro
		break;
		
		case 2:
		deletar(); //Chamada de fu��es Deletar
	    break;
	    
	    case 3:
	    consultar();//Chamada de fun��es Consultar
        break;
        
        case 4:
        printf("Obrigado por utilizar o sistema!");
        return 0;
        break;
        
        default:
        printf("Essa op��o n�o est� dispon�vel");
        system("pause");
        break;
         
	} 
   
  }

}
