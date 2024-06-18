#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
 

	int registro() //fun�ao responsavel por cadastrar os usu�rios no sistema
{ 
        //inicio cria��o de vari�veis/string
        char arquivo[40];
 	    char cpf[40];
 	    char nome[40];
 	    char sobrenome[40];
 	    char cargo[40];
 	    //final de cria��o de vari�veis/string
 	    
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
	   printf("N�o foi possivel abrir arquivo, n�o localizado!\n");
       }
		
       while(fgets(conteudo, 200, file) != NULL) //enquanto tiver escrevendo na variavel ou string conteudo at� 200 valores que est�o dentro do arquivo, enquanto for diferente de nulo 
       { 
  	    printf("Essas s�o as informa��es do usu�rio:\n "); //Resposta do usu�rio
  	    printf("%s,", conteudo); //salvando na variavel conteudo
  	    printf("\n\n"); //pular linhas
        } 
        system("pause"); //comando que exibe a mensagem "Pressione qualquer tecla para continuar".
	
	} 

    int deletar() //fun��o deletar
       {
        char cpf[40]; //vari�vel cpf
        
 	    printf("Digite o cpf do usu�rio a ser deletado: "); //mensagem usu�rio
 	    scanf("%s", cpf); //scanf faz a leitura da string e armazena na variavel cpf
 	  
        remove(cpf); //serve para deletar o arquivo cpf
    
	    FILE *file; //entrar na biblioteca e puxar os arquivos
	    file = fopen(cpf, "r"); //abre a pasta e procura o arquivo cpf
    
        if(file == NULL) //avalia se a variavel � verdadeira
        {
    	printf("Usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
	    }

        }
   
   int main() //fun��o principal
 {
 	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
 	
	int opcao=0; //Definindo as vari�veis 
    int laco=1;
    char senhadigitada[10] ="a"; 
    int comparacao;
    
	printf("### Cart�rio da EBAC ###\n\n");
	printf("login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
    
	comparacao = strcmp(senhadigitada, "admin"); //A fun��o "strcmp" compara duas strings
	
	if(comparacao == 0) //Avalia��o da vari�vel "compara��o" com valor zero
	{
		system("cls"); //comando para limpar a tela
		
		for(laco=1; laco=1;) //Inic�o do la�o de repeti��o
	   {
			setlocale (LC_ALL, "PORTUGUESE"); //Definindo a linguagem
	    
            printf("### cart�rio da EBAC ###\n\n");
       	    printf("escolha a op��o desejada do menu:\n\n"); //inicio do menu
            printf("\t1 - registrar nomes\n");
            printf("\t2 - consultar nomes\n");
            printf("\t3 - deletar nomes\n\n");
            printf("\t4 - Sair do sistema\n\n");
	        printf("op��o:"); //Final do menu
	    
	    
		    scanf("%d", &opcao); //armazenando a escolha do usu�rio
		    
			system("cls"); //comando para limpar a tela
		
		    switch (opcao)//incio da sele��o
		    {
			    case 1:
		        registro(); //chamada de fun��es
    	        break;
    	    
    	        case 2:
    	        consulta(); //chamada de fun��es
    	        break;
    	    
    	        case 3:
    	        deletar(); //chamada de fun��es
    	        break;
    	        
    	        case 4:
    	        printf("Obrigado por utilizar o sistema!\n"); //mensagem para usu�rio
    	        return 0;
    	        break;
    	    
    	        default: 
    	        printf("Esta op��o n�o est� disponivel\n!");
		        system("pause");
		        break;
    	    } //fim da sele��o
		}
	}
    else //executa o codigo quando a condi��o n�o for verddeira
    printf("A senha est� incorreta");
}
