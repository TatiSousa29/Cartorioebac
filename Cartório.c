#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //funçao responsavel por cadastrar os usuários no sistema
{  
    //inicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informações do usuáriuo
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
    	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo,"a"); //abrindo arquivo e "a" significa atualizar
	fprintf(file, ","); 
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome a ser acadastrado: "); 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo e "a" significa atualizar
	fprintf(file, nome); //salva o valor da variável
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome); // salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar  
	fprintf(file, ",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo e "a" significa atualizar
	fprintf(file, cargo); // salva o valor da variável
	fclose(file); //fecha o arquivo
		
	system("pause"); //pausa o sistema		

}

int consulta() //função consulta
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40]; //variavel
	char conteudo[200]; //variavel do tipo inteiro
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file; //abre arquivo e procura o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL) //função (se) arquivo for igual ou nulo
	{
	    printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //função (enquanto)
	{
	    printf("\nEssas são as informaçoes do usuário: ");
	    printf("%s", conteudo); //coletando as informações
	    printf("\n\n"); //pular linha
	}
	
	system("pause"); //pausa o sistema
}



int deletar() //função deletar
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o arquivo
	
	FILE *file; //abre o arquivo e procura o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e digita o arquivo
	
	if(file == NULL) // função se
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}

}

int main() //função principal onde roda o nucleo do projeto
    {
	int opcao=0; //definindo as variáveis
	int laco=1; //definindo as variáveis
	
	for (laco=1;laco=1;) //laço de repetição
	{
	    
		system("cls"); //Responsavel por limpar a tela
	     
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //início do menu
	    printf("Escolha a opção desejada do menu:\n\n ");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); //fim do menu
	    printf("\t4 - Sair do sistema\n\n");
	    printf("opção: ");
	    
        scanf("%d,", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //comando de limpar a tela
	
	
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada de funcções
	    	break;
	    	
			case 2:	
			consulta(); //chamada de funções
		    break;
		    
		    case 3:
		    deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utulizar o sistema!\n");
			return 0;
			break;
			
			default: 
		    printf("Essa opção não está disponivel!\n"); 
		    system("pause");
		    break;
		    } //fim da deleção
  }
}


