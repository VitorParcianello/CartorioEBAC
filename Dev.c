#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço de memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string

int registro()//função responsável por cadastrar os usuários
{
		//inicio da criação de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//fim da criação de variaveis
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
		scanf("%s",cpf); //%s se refere as strings
		
		strcpy(arquivo, cpf); // responsável por copiar os valores das string
		
		FILE *file;//cria o arquivo
		file = fopen (arquivo, "w");//cria o arquivo
		fprintf(file,cpf);//salva o arquivo
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo, "a");
		fprintf (file, ",");
		fclose(file);
		
		printf ("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen (arquivo, "a");
		fprintf (file,nome);
		fclose (file);
		
		file=fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf ("Digite o sobrenome a ser cadastrado: ");
		scanf ("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf (file, sobrenome);
		fclose (file);
		
		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf ("Digite o cargo a ser cadastrado: ");
		scanf ("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf (file, cargo);
		fclose (file);
		
		file = fopen (arquivo, "a");
		fprintf(file, ",");
		fclose(file);
			
		system ("pause");
		
}

int consulta()
{
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	    
		char cpf[40];
		char conteudo[250];
		
		printf ("digite o cpf a ser cadastrado: ");
		scanf ("%s", cpf);
		
		FILE *file;
	    file = fopen(cpf, "r");
		
		if (file == NULL)
		{
			printf ("CPF não foi encontrado! \n");
		}
		
		while(fgets(conteudo, 250, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		
	{
		printf ("O usuário não se encontra no sistema!.\n ");
		system ("pause");
	}
		
}

int main()
	{
	 	int opcao=0; //definindo variavel
	 	int laco=1;
	 
	 	for(laco=1;laco=1;)
		{
	
		system("cls");
		
    	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
    
		printf ("!!!site Da secretaria da educação!!!\n\n"); //inicio do menu
		printf ("Escolha a opção desejada:\n\n");
		printf ("\t1 - Registrar Nome\n");
		printf ("\t2 - Consultar Nome\n");
		printf ("\t3 - Deletar Nome\n\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Opção:"); //fim do menu
	
		scanf ("%d", &opcao); //armazenando a escolha do usuário
	
		system ("cls"); //responsável por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
	  
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema");
			return 0;
			break;
			
			default:
			printf("Essa opção não existe\n");
			system("pause");	
			break;
	}
}
}


