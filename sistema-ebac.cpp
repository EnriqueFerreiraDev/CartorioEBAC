#include <stdio.h> //Biblioteca de comunicação com o usuario
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF que deseja cadastrar: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo (ou boco de notas)
	file = fopen(arquivo, "w"); //abre o arquivo (ou bloco de notas) e o "W" define que está iniciando um boco
	fprintf(file,cpf); //sava o valor da variavel CPF
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome do novo aluno: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome do novo aluno: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			printf("CPF não encontrado!\n");
		}
		
	while(fgets(conteudo, 100, file) != NULL)
		{
				printf("\nEssas são as informações do usuario: ");
				printf("%s", conteudo);
				printf("\n\n");
		}
		
		system("pause");
}

int excuir()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	
	printf("Digite o cpf do aluno que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)// NULL vc ta falando que ele não existe. SE O CPF NÃO ESTIVER NO SISTEMA...
	{
		printf("o CPF nunca foi cadastrado no sistema!\n");
		system("pause");
	}
	

}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Escoha da linguagem
	
		printf("***Sistema EBAC***\n\n"); //Inicio do menu
		printf("Escolha uma opção no menu\n\n");
		printf("\t1 - Registrar aluno\n");
		printf("\t2 - Consultar aluno\n");
		printf("\t3 - Excluir aluno\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escoha do usuario
	
		system("cls");	
		
		switch(opcao)
		{
			case 1:
			registro();
			break;	
			
			case 2:
			consulta();
			break;
			
			case 3:
			excuir();
			break;
			
			case 4:
			printf("obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
		}
	}
}

