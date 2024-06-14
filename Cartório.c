#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun�ao responsavel por cadastrar os usu�rios no sistema
{  
    //inicio cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��es do usu�riuo
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo,"a"); //abrindo arquivo e "a" significa atualizar
	fprintf(file, ","); 
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome a ser acadastrado: "); 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo e "a" significa atualizar
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); // salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar  
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file, cargo); // salva o valor da vari�vel
	fclose(file); //fecha o arquivo
		
	system("pause"); //pausa o sistema		

}

int consulta() //fun��o consulta
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40]; //variavel
	char conteudo[200]; //variavel do tipo inteiro
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file; //abre arquivo e procura o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL) //fun��o (se) arquivo for igual ou nulo
	{
	    printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //fun��o (enquanto)
	{
	    printf("\nEssas s�o as informa�oes do usu�rio: ");
	    printf("%s", conteudo); //coletando as informa��es
	    printf("\n\n"); //pular linha
	}
	
	system("pause"); //pausa o sistema
}



int deletar() //fun��o deletar
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o arquivo
	
	FILE *file; //abre o arquivo e procura o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e digita o arquivo
	
	if(file == NULL) // fun��o se
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}

}

int main() //fun��o principal onde roda o nucleo do projeto
    {
	int opcao=0; //definindo as vari�veis
	int laco=1; //definindo as vari�veis
	
	for (laco=1;laco=1;) //la�o de repeti��o
	{
	    
		system("cls"); //Responsavel por limpar a tela
	     
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n ");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); //fim do menu
	    printf("\t4 - Sair do sistema\n\n");
	    printf("op��o: ");
	    
        scanf("%d,", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //comando de limpar a tela
	
	
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada de func��es
	    	break;
	    	
			case 2:	
			consulta(); //chamada de fun��es
		    break;
		    
		    case 3:
		    deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utulizar o sistema!\n");
			return 0;
			break;
			
			default: 
		    printf("Essa op��o n�o est� disponivel!\n"); 
		    system("pause");
		    break;
		    } //fim da dele��o
  }
}


