#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final
	
	printf("Digite o CPF a ser cadstrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo e o "w" cria e escreve no file
	fprintf(file,cpf);  //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//inicio da string
	char cpf[40];
	char conteudo[200];
	//final da string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" significa READ que seria ler o arquivo
	
	if(file == NULL) //null = a nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");

}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}


 

int main()
         {
                 int opcao=0; //definindo variáveis
                 int laco=1;
                 char senhadigitada[]="a";
                 int comparacao;
                 
                 printf("### Cartório da EBAC ###\n\n");
                 printf("Login de administrador!\n\nDigite a sua senha: ");
                 scanf("%s",senhadigitada);
                 
                 comparacao = strcmp(senhadigitada, "admin");
            
				 if(comparacao == 0)
				 {
				     system("cls");
                     for(laco=1;laco=1;)
                     {
                 	
				      system("cls"); //reponsável por limpar a tela
				     
			    	  setlocale(LC_ALL, "Portuguese");//definindo a linguagem
				 
				 				 
	                  printf("### Cartório da EBAC ###\n\n");//inicio do menu     
				  
	                  printf("Escolha a opção desejada do menu:\n\n");
                      printf("\t1 - Registrar nome\n");
	                  printf("\t2 - Consultar nomes\n");
	                  printf("\t3 - Deletar nomes\n\n");
	                  printf("\t4 - Sair do sistema\n\n");
			    	  printf("Opção: ");//fim do menu
				   
	                  scanf("%d", &opcao);//armazenando a escolha do usuário
	             
	                  system("cls");
	                 
	                   //inicio da seleção
	                  switch(opcao)
	                   {
	                    	case 1:
	                 	 registro();	//chamada de funções
	                 	 break;
	                 	
	                 	 case 2:
	                 	 consulta();	
						 break;
						
						 case 3:
						 deletar();
				   	     break;
				   	    
				   	     case 4:
				   	     printf("Obrigado por utilizar o sistema!\n");
				   	     return 0;
				   	     break;
				   	       	    
				   	     default:
				   	     printf("Essa opção não está disponível\n");
				   	     system("pause");	
				   	     break;
				   	          //fim da seleção	
				        }
	                 
			         }
				  
		        }
		  
		 else
		    printf("Senha incorreta!"); 
         		 
		 }
		  
