#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
 

	int registro() //funçao responsavel por cadastrar os usuários no sistema
{ 
        //inicio criação de variáveis/string
        char arquivo[40];
 	    char cpf[40];
 	    char nome[40];
 	    char sobrenome[40];
 	    char cargo[40];
 	    //final de criação de variáveis/string
 	    
 	    printf("Digite o cpf a ser cadastrado: ");
 	    scanf("%s", cpf);
 		
 	    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
 	
 	    FILE *file; //cria o arquivo
 	    file = fopen(arquivo, "w"); //cria o arquivo
 	    fprintf(file,cpf); //salva o valor da variavel
 	    fclose(file); //fecha o arquivo
 	
 	    file = fopen(arquivo, "a");
 	    fprintf(file, ",");
 	    fclose(file);
 	
 	    printf("Digite o nome a ser cadastrado: ");
 	    scanf("%s", nome);
	 
	  	file = fopen(arquivo, "a");
 	    fprintf(file, nome);
 	    fclose(file);
 	    
 	    file = fopen(arquivo, "a");
 	    fprintf(file, ",");
 	    fclose(file);
 	    
 	    printf("Digite o sobrenome a ser cadastrado:");
 	    scanf("%s,", sobrenome);
 	    
 	    file = fopen(arquivo, "a");
 	    fprintf(file, sobrenome);
 	    fclose(file);
 	    
 	    file = fopen(arquivo, "a");
 	    fprintf(file, ",");
 	    fclose(file);
		 
		 printf("Digite o cargo a ser cadastrado: ");
		 scanf("%s", cargo);
		 
		 file = fopen(arquivo, "a");
		 fprintf(file, cargo);
		 fclose(file);
		 
		system("pause"); //comando que exibe a mensagem "Pressione qualquer tecla para continuar".
}
	
   int consulta()	
    {
	   setlocale (LC_ALL, "PORTUGUESE"); //Definindo a linguagem
	
 	   char cpf[40]; //criar de novo o arquivo cpf
 	   char conteudo[200]; //variavel string(conteudo)
 	
 	   printf("Digite o cpf a ser consultado: ");
 	   scanf("%s",cpf); //scanf salva na variavel, na string cpf
 	
 	   FILE *file; //acessa o arquivo e consulta o arquivo
 	   file = fopen(cpf,"r"); //abre o arquivo cpf e leia
 	   fclose(file);
 	
    if(file == NULL) //If(Se) o arquivo for nulo
       {
	   printf("Não foi possivel abrir arquivo, não localizado!\n");
       }
		
       while(fgets(conteudo, 200, file) != NULL) //enquanto tiver escrevendo na variavel ou string conteudo até 200 valores que estão dentro do arquivo, enquanto for diferente de nulo 
       { 
  	    printf("Essas são as informações do usuário:\n "); //Resposta do usuário
  	    printf("%s,", conteudo); //salvando na variavel conteudo
  	    printf("\n\n"); //pular linhas
        } 
        system("pause"); //comando que exibe a mensagem "Pressione qualquer tecla para continuar".
	
	} 

    int deletar() //função deletar
       {
        char cpf[40]; //variável cpf
        
 	    printf("Digite o cpf do usuário a ser deletado: "); //mensagem usuário
 	    scanf("%s", cpf); //scanf faz a leitura da string e armazena na variavel cpf
 	  
        remove(cpf); //serve para deletar o arquivo cpf
    
	    FILE *file; //entrar na biblioteca e puxar os arquivos
	    file = fopen(cpf, "r"); //abre a pasta e procura o arquivo cpf
    
        if(file == NULL) //avalia se a variavel é verdadeira
        {
    	printf("Usuário não se encontra no sistema!.\n");
    	system("pause");
	    }

        }
   
   int main() //função principal
 {
 	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
 	
	int opcao=0; //Definindo as variáveis 
    int laco=1;
    char senhadigitada[10] ="a"; 
    int comparacao;
    
	printf("### Cartório da EBAC ###\n\n");
	printf("login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
    
	comparacao = strcmp(senhadigitada, "admin"); //A função "strcmp" compara duas strings
	
	if(comparacao == 0) //Avaliação da variável "comparação" com valor zero
	{
		system("cls"); //comando para limpar a tela
		
		for(laco=1; laco=1;) //Inicío do laço de repetição
	   {
			setlocale (LC_ALL, "PORTUGUESE"); //Definindo a linguagem
	    
            printf("### cartório da EBAC ###\n\n");
       	    printf("escolha a opção desejada do menu:\n\n"); //inicio do menu
            printf("\t1 - registrar nomes\n");
            printf("\t2 - consultar nomes\n");
            printf("\t3 - deletar nomes\n\n");
            printf("\t4 - Sair do sistema\n\n");
	        printf("opção:"); //Final do menu
	    
	    
		    scanf("%d", &opcao); //armazenando a escolha do usuário
		    
			system("cls"); //comando para limpar a tela
		
		    switch (opcao)//incio da seleção
		    {
			    case 1:
		        registro(); //chamada de funções
    	        break;
    	    
    	        case 2:
    	        consulta(); //chamada de funções
    	        break;
    	    
    	        case 3:
    	        deletar(); //chamada de funções
    	        break;
    	        
    	        case 4:
    	        printf("Obrigado por utilizar o sistema!\n"); //mensagem para usuário
    	        return 0;
    	        break;
    	    
    	        default: 
    	        printf("Esta opção não está disponivel\n!");
		        system("pause");
		        break;
    	    } //fim da seleção
		}
	}
    else //executa o codigo quando a condição não for verddeira
    printf("A senha está incorreta");
}
