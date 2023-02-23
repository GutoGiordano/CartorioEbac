#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de textos por região, que no nosso caso vai ser o Português
#include <string.h> //blilioteca responsável pelas strings

int registro() //Função responsável pelo cadastro de usuários
{
	//ínicio das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variáveis/strings
	
	//cabeçalho inicio
	printf("\n\n"); 
	printf("======> Cartório da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//cabeçalho fim
	
	//coletando inormações do user
	printf ("\n\n");
	printf(" > Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s comando que salva o dado dentro da string
	
	strcpy(arquivo, cpf); //copia os dados nas strings
	
	FILE *file; //Cria o arquivo cpf
	file = fopen(arquivo, "w"); //abre o arquivo - (w) escrever
	fprintf(file, cpf);
	fclose(file); // Fechando o arquivo que foi aberto - Não esquecer de fechar o processo
	
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
	
	system("pause"); //comando que pausa o programa até o user interagir	
}

int consulta() //Consulta de dados cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
	//inicio das variáveis
	char cpf[40];
	char conteudo[200];
	//fim das variáveis
		
	//cabeçalho inicio
	printf("\n\n");
	printf("======> Cartório da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//cabeçalho fim
	
	printf("\n\n\n");
	printf(" > Digite o CPF a ser consultado: "); //interação com o user
	scanf("%s", cpf); //pesquisa os dados e salva - (s) salvar
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o dado cpf e ler - (r) ler
		
	if(file == NULL) // == comparação
	{
		printf("\n\n");
		printf("# CPF não encontrado no sistema!"); //resposta para negaiva para o user
		printf("\n\n\n");
	}
	
	while(fgets(conteudo,200,file)!= NULL) //procurar os dados até enquanto ainda estiverem, algo nesse sentido
	{
		printf("\n\n");
		printf("# Essas são as informações do usuário: "); //retorno com os dados pesquisados pelo user
		printf("%s", conteudo); //pesquisa os dados e salva - (s) salvar
		printf("\n\n\n");
	}
	
	fclose(file); //fecha o arquivo que foi aberto (percebi quer estava faltando esse cod para fechar o arquivo,
					//por isso enquanto fazia a consuta e colocava para deletar, a função não funcionava.
	system("pause");
		
}

int deletar() //Função para deletar os nomes
{
	char cpf[40];
	
	//inicio cabeçalho
	printf("\n\n");
	printf("======> Cartório da EBAC\n");
	printf("        Sistema de Registo de Pessoas\n\n");
	//fim do cabeçalho
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); // Computador salva o dado digitado,(%que dado ele vai receber, o dado cpf)
	printf("\n\n");
	
	FILE *file;
	file = fopen(cpf, "r"); //Abre o arquivo e lê - (r) lê		
	if(file != NULL) //função de comparação de dados - != diferente
	{
		fclose(file);
		remove(cpf); //comando que deleta os dados
		printf("# O usuário foi deletado com sucesso!\n\n\n"); //resposta positiva de interação
		system("pause"); //pausa o sistema	
	}
	else //e se
	{
		printf("# O usuário não se encontra cadastrado no sistema!\n\n\n"); //resposta negativa de interação
		system("pause"); //pausa o sistema
	}
	
}

	
int main() //Função inicial do programa
{
	int opcao=0; //Definindo variáveis e a alocação de memória
	int lopping=1; //Repetição do menu
	
	for(lopping=1;lopping=1;) //dei o nome de looping para eu poder entender melhor
	{
	
		system("cls"); //comando que limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
		
		//cabeçalho inicio
		printf("\n\n");
		printf("======> Cartório da EBAC\n");
		printf("        Sistema de Registo de Pessoas\n\n");
		//cabeçalho inicio
		
		//Início do Menu
		printf("\tEscolha a opção desejada:\n\n");
		printf("\t#1 - Registrar nomes\n");
		printf("\t#2 - Consultar nomes\n");
		printf("\t#3 - Deletar nomes\n");
		printf("\t#4 - Sair do sistema\n\n");
		printf("\tDigite o número <enter>:  "); //Acrescentei a palavra "número" e a função "enter" para sugerir ao user a tecla a apertar (UX)
		//Fim do Menu - espaçamento por questões estéticas
		
		scanf("%d", &opcao); //Armazenando as escolhas do user - (d) armazena a variável inteira
		
		system("cls"); //comando que limpa a tela
		
		
		switch(opcao) //início da interação com o user
		{
			case 1:
			registro(); //Chama as funções. Registro de user
			break; //Fim de case
			
			case 2:
			consulta(); //Chama as funções. Consulta de cadastros
			break;
			
			case 3:
			deletar(); //Chama as funções. Deleta cadastros
			break;
			
			case 4: //Logoff do sistema
			printf("\n\n"); 
			printf("======> Cartório da EBAC\n");
			printf("        Sistema de Registo de Pessoas\n\n");
			printf("# Obrigado por utilizar nosso sistema!\n\n\n"); 
			return 0; //Comando onde digo para o computador que estamos saindo do sistema
			break;
			
			default: //Resposta de opção de menu inválida
			
			//cabeçalho inicio
			printf("\n\n"); 
			printf("======> Cartório da EBAC\n");
			printf("        Sistema de Registo de Pessoas\n\n");
			//cabeçalho fim
			
			printf("\n");
			printf(" # Opção inválida!");
			printf("\n");
			printf("   Escolha entre as opções 1, 2, 3 ou 4.\n\n\n");
			system("pause");
			break;
		}
	} //Fim da interação com user


//rodapé
printf("\n\n\n\n\n\n\n");
printf("Desenvolvido por Guto Giordano e livre para alunos da EBAC.");
	
} 
