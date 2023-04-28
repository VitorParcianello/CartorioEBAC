#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//fun��o respons�vel por cadastrar os usu�rios
{
		//inicio da cria��o de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//fim da cria��o de variaveis
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
		scanf("%s",cpf); //%s se refere as strings
		
		strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
		
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
			printf ("CPF n�o foi encontrado! \n");
		}
		
		while(fgets(conteudo, 250, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		system("pause");
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		
	{
		printf ("O usu�rio n�o se encontra no sistema!.\n ");
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
    
		printf ("!!!site Da secretaria da educa��o!!!\n\n"); //inicio do menu
		printf ("Escolha a op��o desejada:\n\n");
		printf ("\t1 - Registrar Nome\n");
		printf ("\t2 - Consultar Nome\n");
		printf ("\t3 - Deletar Nome\n\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Op��o:"); //fim do menu
	
		scanf ("%d", &opcao); //armazenando a escolha do usu�rio
	
		system ("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
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
			printf("Essa op��o n�o existe\n");
			system("pause");	
			break;
	}
}
}


