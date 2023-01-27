#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define quantidade 1000

typedef struct 
{
    int Num[quantidade];
    int Posicao;
    bool Iniciada;
} pi;

bool vazio(pi *p);
bool cheio(pi *p);
bool iniciada(pi *p);

void inicia_renicia(pi *p);

void inserir(pi *p);
void excluir(pi *p);
void buscar(pi *p);
void n_elementos(pi *p);

void imprimir(pi *p);

int main()
{
    printf("Bem-Vindo ao sistema de estrutura de dados de idade!\n");
    pi *p;
    p->Iniciada = false;
    int opcao;
    do
    {
        printf("\n");
        opcao = 0;
        printf("Escolha uma opção:\n");
        printf("1 – Iniciar/Reiniciar\n2 – Inserir\n3 – Excluir\n4 – Imprimir\n5 – Buscar\n6 - Nº de Elementos\n7 - Fim\n");
        printf("Escolha: ");
        scanf("%d",&opcao);
        printf("\n");
        switch(opcao)
        {
            case 1:
                inicia_renicia(p);
                break;
            case 2:
                inserir(p); 
                break;
            case 3:
                excluir(p); 
                break;
            case 4:
                imprimir(p); 
                break;
            case 5:
                buscar(p);
                break;
            case 6:
                n_elementos(p);
                break;
            case 7:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Erro na escolha no menu, número inserido não existe!\n");
        }
    }while(opcao != 7);
    

}

void inicia_renicia(pi *p)
{
    if(p->Iniciada)
    {
        int opcao;
        printf("Deseja mesmo reiniciar a lista, 1-Sim, 2-Não? ");
        scanf("%d",&opcao);
        opcao == 1? p->Posicao = -1, printf("Reniciado!\n"):printf("Não foi reiniciado!");
    }else
    {
        printf("Pilha criada com sucesso!\n");
        p->Iniciada = true;
        p->Posicao = -1;
    }
    
}

void inserir(pi *p)
{
    if(iniciada(p))
    {
        if(cheio(p))
        {
            printf("Erro ao inserir, pilha está cheia!\n");
            printf("Tente remover um elemento!\n");
        }else
        {
            int elemento;
            printf("Insira aqui: ");
            scanf("%d",&elemento);
            p->Posicao++;
            p->Num[p->Posicao] = elemento;
        }
    }
}

void excluir(pi *p)
{
    if(iniciada(p))
    {
        if(vazio(p))
            printf("Error ao remover, pilha está vazia!\n");
        else
        {
            bool achou = false;
            int elemento;
            printf("Insira a posição da idade que você quer excluír: ");
            scanf("%d",&elemento);
            for(int i = p->Posicao; i > -1; i--)
            {
                if(i == elemento)
                {
                    for(int y = i; y < (p->Posicao); y++)
                    {
                        p->Num[y] = p->Num[y+1];
                    }
                    achou = true;
                }
            }
            if(achou)
            {
                p->Posicao--;
                printf("Excluído com sucesso!\n");
            }else
            {
                printf("A posição não foi encontrada!\n");
            }
        }          
    }
}

void imprimir(pi *p)
{
   if(iniciada(p))
   {
       if(vazio(p))
       {
            printf("Erro ao imprimir, pilha está vazia!\n");
       }else
       {
            printf("Idades:\n");
            for(int i = p->Posicao; i > 0; i--)
            {
                printf("%d, ",p->Num[i]);
            }
            printf("%d\n",p->Num[0]);
       }
       
   }
}

void buscar(pi *p)
{
    if(iniciada(p))
    {
        if(vazio(p))
        {
            printf("Erro ao buscar, pilha está vazia!\n");
        }else
        {
            bool achou = false;
            int repete;
            int elemento;
            printf("Insira a idade que que você quer buscar: ");
            scanf("%d",&elemento);
            for(int i = p->Posicao; i > -1; i--)
            {
                if(p->Num[i] == elemento)
                {
                    if(achou == false)
                        printf("Foi encontrado na posição:\n");
                    printf("%d\n",i);
                    achou = true;
                }
            }
            if(achou == false)
            {
                printf("O elemento não foi encontrado!\n");
            }
        }
    }
}

void n_elementos(pi *p)
{
    if(iniciada(p))
    {
        if(vazio(p))
        {
            printf("A pilha está vazia!\n");
        }else
        {
            int num =0;
            for(int i = p->Posicao; i > -1; i--)
            {
                num++;
            }
            printf("O total de nº de elementos da sua pilha é %d\n",num);
        }
    }
}

bool iniciada(pi *p)
{
    if(p->Iniciada)
    {
        return true;
    }else
    {
        printf("Erro de operação, pilha não foi iniciada!\n");
        return false;
    }
}

bool vazio(pi *p)
{
    if(p->Posicao == -1)
        return true;
    else
        return false;
}

bool cheio(pi *p)
{
    if(p->Posicao == quantidade-1)
        return true;
    else
        return false;
}
