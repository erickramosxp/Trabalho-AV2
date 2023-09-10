#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define CAP 10
#include<limits.h>
#define TRUE 1
#define FALSE 0;

int inserirnumero(int vetor[],int *numero,int *quantidade);

int removernumero(int vet[],int numero,int *quantidade);

int alterar(int vet[], int numero,int novo, int *quantidade);

int buscarvetor(int vetor[],int busca,int *posicao,int qtd);

int imprimirvetor(int vetor[],int *tamanho);

int main() 
{

	int vetor[CAP], opcao,n, quant=0, remover, alterarnum,novo, buscar, resp, posicao = 0;

	do 
	{


		printf("\n\t\t\t\tSELECIONE UMA OPCAO.\n");
		printf("\n1 . Inserir um numero no vetor.\t\t 4 . Busca de determinado elemento no vetor.");
		printf("\n2 . Remover numero do vetor.\t\t 5 . Exibir todos os elementos do vetor.");
		printf("\n3 . Alterar um valor por outro valor.\t\t 6 . Sair do programa.");


		printf("\n\nSelecione uma opcao: ");
		scanf("%d", &opcao);

		switch(opcao) {
			case 1 :
				printf("\n");
				printf("Insira o valor para preencher o vetor: ");
				scanf("%d", &n);

				inserirnumero(vetor, &n, &quant);

				break;

			case 2 :
				printf("\nDigite qual numero deseja remover : ");
				scanf("%d", &remover);

				removernumero(vetor, remover, &quant);

				break;
			case 3 :

				printf("\nSelecione o valor deseja alterar :");
				scanf("%d", &alterarnum);

				resp = buscarvetor(vetor, alterarnum, &posicao, quant);

				if(resp==TRUE) 
				{
					printf("\nInsira o novo valor :");
					scanf("%d", &novo);

					alterar(vetor, alterarnum, novo, &quant);
				}
				else 
				{
					printf("VALOR NAO ENCONTRADO.");
				}

				break;
			case 4 :
				printf("Digite o numero que deseja buscar: ");
				scanf("%d", &buscar);

				resp = buscarvetor(vetor, buscar, &posicao, quant);

				if(resp==TRUE) 
				{
					printf("O numero %d foi encontrado, sua posicao no vetor e %d\n", buscar, posicao);
				} 
				else 
				{
					printf("O numero NAO foi encontrado");
				}
				break;
			case 5 :
				printf("\nNUMEROS DISPONIVEIS:\n");
				imprimirvetor(vetor, &quant);

		}
		if((opcao<1)||(opcao>6)) 
		{
			printf("\nOPCAO INEXISTENTE. ");
		}

	}while(opcao!=6);


}
int inserirnumero(int vetor[],int *numero,int *quantidade) 
{

	int resp, posicao = 0, quant=0, i;

	if(*quantidade!=CAP) {


		resp = buscarvetor(vetor, *numero, &posicao, *quantidade);

		if(resp!=TRUE) 
		{
			if(*numero<vetor[*quantidade-1]) 
			{
				for(i=*quantidade; i>posicao; i--) 
				{
					vetor[i]=vetor[i-1];
				}
				vetor[i]=*numero;
			} 
			else 
			{
				vetor[*quantidade]=*numero;
			}
			*quantidade=*quantidade+1;
			printf("VALOR INSERIDO C/SUCESSO.");
		}
		else 
		{
			printf("VALOR JA INSERIDO.");
		}
	} 
	else 
	{
		printf("VETOR CHEIO.");
	}

}
int removernumero(int vet[],int numero,int *quantidade) 
{

	int i, posicao = 0, resp;

	resp = buscarvetor(vet, numero, &posicao,*quantidade);

	if(resp==TRUE) 
	{
		for(i=posicao; i<*quantidade-1; i++) 
		{
			vet[i]=vet[i+1];
		}
		*quantidade=*quantidade-1;
		printf("VALOR REMOVIDO C/ SUCESSO.\n");
	}
	else 
	{
		printf("\nValor nao encontrado no vetor");
	}

}

int alterar(int vet[], int numero,int novo, int *quantidade) 
{

	int posicao, resp, i, novapos;

	resp = buscarvetor(vet, numero, &posicao, *quantidade);

	if(resp==TRUE) 
	{
		resp = buscarvetor(vet, novo, &posicao, *quantidade);
		if(resp!=TRUE)
		{
		novapos=*quantidade;
		removernumero(vet, numero, &novapos);
		
		inserirnumero(vet,&novo,&novapos);
		*quantidade=novapos;
		}
		else
		{
		 printf("\nValor ja inserido.");	
		}
	} 
	else 
	{
		printf("\nValor nao existe no vetor.");
	}


}
int buscarvetor(int vetor[],int busca,int *posicao, int qtd) 
{

	int i;

	for(i=0; i<=qtd; i++) 
	{

		if(vetor[i]==busca) 
		{
			*posicao=i;
			return TRUE;
		} 
		else if(vetor[i]>busca) 
		{
			*posicao=i;
			return -1;
		}
	}
}

int imprimirvetor(int vetor[],int *tamanho) 
{

	int i;

	for(i=0; i<*tamanho; i++) 
	{
		printf("%d  ", vetor[i]);
	}
	printf("\n");
}
