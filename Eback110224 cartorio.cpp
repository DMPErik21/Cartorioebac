#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço e memória
#include <locale.h> //biblioteca de alocações de testo por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Responsavel por cadastrar os usuários do sistema
{
	//Inicio criação de variáveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final das criação de variáveis/strign
   
   printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
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
		printf("O usuário não se encontra no sistema! \n");
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
    	printf("Não foi possivel abrir o arquivo, não encontrado!. \n");
	}
	    
    while(fgets(conteudo,200,file)!= NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}
int main()

{
  int opcao=0; //definindo variáveis
  int laco=1;
  
  for(laco=1;laco=1;)
  {   
  
    system("cls");

    setlocale(LC_ALL,"portuguese"); //Definido a linguagem
   
    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
    printf("Escolha a opção no menu abaixo:\n\n");
    printf("\t1 - registrar alunos\n");
    printf("\t2 - deletar alunos\n");
    printf("\t3 - consultar alunos\n\n");
    printf("opção: ");//fim do menu
    
    scanf("%d", &opcao); //Amazenando a escolha do usuário     
   
    system("cls");//Responsavel por limpar a tela
    
    switch(opcao)//Inicio da seleção do menu
    {
    	case 1:
    	registro(); //Chamada de fuções Registro
		break;
		
		case 2:
		deletar(); //Chamada de fuções Deletar
	    break;
	    
	    case 3:
	    consultar();//Chamada de funções Consultar
        break;
        
        default:
        printf("Essa opção não está disponível");
        system("pause");
        break;
         
	} 
   
  }

}
