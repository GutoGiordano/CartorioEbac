#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de textos por regi�o, que no nosso caso vai ser o Portugu�s
#include <string.h> //blilioteca respons�vel pelas strings

int registro() //Fun��o respons�vel pelo cadastro de usu�rios
{
	//�nicio das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis/strings
	
	//cabe�alho inicio
	printf("\n\n"); 
	printf("======> Cart�rio da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//cabe�alho fim
	
	//coletando inorma��es do user
	printf ("\n\n");
	printf(" > Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s comando que salva o dado dentro da string
	
	strcpy(arquivo, cpf); //copia os dados nas strings
	
	FILE *file; //Cria o arquivo cpf
	file = fopen(arquivo, "w"); //abre o arquivo - (w) escrever
	fprintf(file, cpf);
	fclose(file); // Fechando o arquivo que foi aberto - N�o esquecer de fechar o processo
	
	file = fopen(arquivo, "a"); //"a" abrir
	fprintf(file, ", "); //inclui uma , entre os dados
	fclose(file); //fecha o arquivo aberto
	
	printf(" > Digite o nome a ser cadastrado: "); //cadastrando o nome
	scanf("%s", nome); //salva o que o iser digitar
	
	file = fopen(arquivo, "a"); 
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); //adiciona uma , entre os dados
	fclose(file); //fecha o arquivo que foi aberto
	
	printf(" > Digite o sobrenome a ser cadastrado: "); //cadastrando sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo que foi aberto
	
	printf(" > Digite o cargo a ser cadastrado: "); //cadastrando o cargo
	scanf("%s", cargo);
	printf("\n\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo que foi aberto
	
	printf("# Cadastro realizado com sucesso!"); //Resposta para o user
	printf("\n\n\n");
	
	system("pause"); //comando que pausa o programa at� o user interagir	
}

int consulta() //Consulta de dados cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
	
	//inicio das vari�veis
	char cpf[40];
	char conteudo[200];
	//fim das vari�veis
		
	//cabe�alho inicio
	printf("\n\n");
	printf("======> Cart�rio da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//cabe�alho fim
	
	printf("\n\n\n");
	printf(" > Digite o CPF a ser consultado: "); //intera��o com o user
	scanf("%s", cpf); //pesquisa os dados e salva - (s) salvar
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o dado cpf e ler - (r) ler
		
	if(file == NULL) // == compara��o
	{
		printf("\n\n");
		printf("# CPF n�o encontrado no sistema!"); //resposta para negaiva para o user
		printf("\n\n\n");
	}
	
	while(fgets(conteudo,200,file)!= NULL) //procurar os dados at� enquanto ainda estiverem, algo nesse sentido
	{
		printf("\n\n");
		printf("# Essas s�o as informa��es do usu�rio: "); //retorno com os dados pesquisados pelo user
		printf("%s", conteudo); //pesquisa os dados e salva - (s) salvar
		printf("\n\n\n");
	}
	
	fclose(file); //fecha o arquivo que foi aberto (percebi quer estava faltando esse cod para fechar o arquivo,
					//por isso enquanto fazia a consuta e colocava para deletar, a fun��o n�o funcionava.
	system("pause");
		
}

int deletar() //Fun��o para deletar os nomes
{
	char cpf[40];
	
	//inicio cabe�alho
	printf("\n\n");
	printf("======> Cart�rio da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//fim do cabe�alho
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); // Computador salva o dado digitado,(%que dado ele vai receber, o dado cpf)
	printf("\n\n");
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo e l� - (r) l�		
	if(file != NULL) //fun��o de compara��o de dados - != diferente
	{
		fclose(file);
		remove(cpf); //comando que deleta os dados
		printf("# O usu�rio foi deletado com sucesso!\n\n\n"); //resposta positiva de intera��o
		system("pause"); //pausa o sistema	
	}
	else //e se
	{
		printf("# O usu�rio n�o se encontra cadastrado no sistema!\n\n\n"); //resposta negativa de intera��o
		system("pause"); //pausa o sistema
	}
	
}

	
int main() //Fun��o inicial do programa
{
	int opcao=0; //Definindo vari�veis e a aloca��o de mem�ria
	int lopping=1; //Repeti��o do menu
	
	for(lopping=1;lopping=1;) //dei o nome de looping para eu poder entender melhor
	{
	
		system("cls"); //comando que limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
		
		//cabe�alho inicio
		printf("\n\n");
		printf("======> Cart�rio da EBAC\n");
		printf("        Sistema de Registo de Pessoas\n\n");
		//cabe�alho inicio
		
		//In�cio do Menu
		printf("\tEscolha a op��o desejada:\n\n");
		printf("\t#1 - Registrar nomes\n");
		printf("\t#2 - Consultar nomes\n");
		printf("\t#3 - Deletar nomes\n");
		printf("\t#4 - Sair do sistema\n\n");
		printf("\tDigite o n�mero <enter>:  "); //Acrescentei a palavra "n�mero" e a fun��o "enter" para sugerir ao user a tecla a apertar (UX)
		//Fim do Menu - espa�amento por quest�es est�ticas
		
		scanf("%d", &opcao); //Armazenando as escolhas do user - (d) armazena a vari�vel inteira
		
		system("cls"); //comando que limpa a tela
		
		
		switch(opcao) //in�cio da intera��o com o user
		{
			case 1:
			registro(); //Chama as fun��es. Registro de user
			break; //Fim de case
			
			case 2:
			consulta(); //Chama as fun��es. Consulta de cadastros
			break;
			
			case 3:
			deletar(); //Chama as fun��es. Deleta cadastros
			break;
			
			case 4: //Logoff do sistema
			printf("\n\n"); 
			printf("======> Cart�rio da EBAC\n");
			printf("        Sistema de Registo de Pessoas\n\n");
			printf("# Obrigado por utilizar nosso sistema!\n\n\n"); 
			return 0; //Comando onde digo para o computador que estamos saindo do sistema
			break;
			
			default: //Resposta de op��o de menu inv�lida
			
			//cabe�alho inicio
			printf("\n\n"); 
			printf("======> Cart�rio da EBAC\n");
			printf("        Sistema de Registo de Pessoas\n\n");
			//cabe�alho fim
			
			printf("\n");
			printf(" # Op��o inv�lida!");
			printf("\n");
			printf("   Escolha entre as op��es 1, 2, 3 ou 4.\n\n\n");
			system("pause");
			break;
		}
	} //Fim da intera��o com user


//rodap�
printf("\n\n\n\n\n\n\n");
printf("Desenvolvido por Guto Giordano e livre para alunos da EBAC.");
	
} 
