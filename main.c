#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Diario
{
    // data, horário, nome, local, duração e observação.
    int id;
    int dia, mes, ano;
    int h, min;
    char nome[25];
    char local[25];
    char duracao[25];
    char observacao[100];
    struct Diario *next;
} * head;

int adicionar(int id, int dia, int mes, int ano, int h, int min, char *nome, char *local, char *duracao, char *observacao)
{

    struct Diario *diario = (struct Diario *)malloc(sizeof(struct Diario));
    diario->id = id;
    diario->dia = dia;
    diario->mes = mes;
    diario->ano = ano;
    diario->h = h;
    diario->min = min;

    strcpy(diario->nome, nome);
    strcpy(diario->local, local);
    strcpy(diario->duracao, duracao);
    strcpy(diario->observacao, observacao);

    diario->next = NULL;

    if (head == NULL)
    {
        head = diario;
    }
    else
    {
        diario->next = head;
        head = diario;
    }
    return 1;
}

// data, horário, nome, local, duração e observação.
void pesquisar_id(int id)
{	
int registrado_id = 0;
    struct Diario *temp = head;
    while (temp != NULL)
    {
        if (temp->id ==  id)
        {
        	registrado_id = 1;
         	printf("Registro encontrado \n\n");
		    printf("ID: %d\n", temp->id);
            printf("Data: %d/%d/%d\n", temp->dia, temp->mes, temp->ano);
            printf("Horario: %d:%d\n", temp->h, temp->min);
            printf("Nome: %s\n", temp->nome);
            printf("Local: %s\n", temp->local);
            printf("Duracacao: %s\n", temp->duracao);
            printf("Obervacao: %s\n", temp->observacao);
            printf("\n---------------------------\n");
        }else if(registrado_id == 0)
		{
    		printf("Nao foi encontrado nenhum registro com o ID %d", id);
		}
		temp = temp->next;
    }
}


void pesquisar(char *nome)
{
	int registrado = 0;
    struct Diario *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->nome,  nome) == 0)
        {
        	registrado = 1;
            printf("Registro encontrado \n\n");
			printf("ID: %d\n", temp->id);
            printf("Data: %d/%d/%d\n", temp->dia, temp->mes, temp->ano);
            printf("Horario: %d:%d\n", temp->h, temp->min);
            printf("Nome: %s\n", temp->nome);
            printf("Local: %s\n", temp->local);
            printf("Duracacao: %s\n", temp->duracao);
            printf("Obervacao: %s\n", temp->observacao);
            printf("\n---------------------------\n");
        }else if(registrado == 0)
		{
    		printf("Nao foi encontrado nenhum registro com o nome %s", nome);
		}
		temp = temp->next;
    }
}

void atualizar(int id)
{

    struct Diario *temp = head;
    while (temp != NULL)
    {

        if (temp->id == id)
        {
            // data, horário, nome, local, duração e observação.
            printf("id %d encontrado !!!\n", id);
            printf("Entre com a nova data(dd mm aaaa): ");
            scanf("%d,%d,%d", temp->dia, temp->mes, temp->ano);
            
            
            printf("Entre com novo horario(hh mm): ");
            scanf("%d, %d", temp->h, temp->min);
			getchar();

            printf("Entre com o novo nome: ");
            scanf("%s", temp->nome);
            getchar();
            
            printf("Entre com o novo local: ");
            scanf("%s", temp->local);
            getchar();
            
            printf("Entre com a nova duracao: ");
            scanf("%s", temp->duracao);
            getchar();
            
            printf("Entre com novas observacoes ");
            scanf("%s", temp->observacao);
            getchar();

            printf("ATUALIZACAO FEITA COM SUCESSO!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Registro do id %d NAO foi encontrado !!!\n", id);
}

void deletar(int id)
{

    struct Diario *temp1 = head;
    struct Diario *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->id == id)
        {

            printf("registro do id %d foi encontrado !!!\n", id);

            if (temp1 == temp2)
            {

                head = head->next;
                free(temp1);
            }
            else
            {

                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Registro deletado com sucesso !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Registro do id %d NAO foi encontrado !!!\n", id);
}

void exibir()
{
    struct Diario *temp = head;
    while (temp != NULL)
    {
        // data, horário, nome, local, duração e observação.
        printf("\tID: %d\n", temp->id);
        printf("\tData: %2d/%2d/%4d\n", temp->dia, temp->mes, temp->ano);
        printf("\tHorario: %2d:%2d\n", temp->h, temp->min);
        printf("\tNome: %s \n", temp->nome);
        printf("\tLocal: %s \n", temp->local);
        printf("\tDuracao: %s \n", temp->duracao);
        printf("\tObservacao: %s \n", temp->observacao);
        printf("\t\n---------------------------\n");
        temp = temp->next;
    }
}
void main()
{
    head = NULL;

    char senha[] = "123456";
    char nova_senha[6];
    char confirmar_senha[6];

	int tentativas = 0;
    int op = 1;
    int id = 0;
    int i, escolha_pesquisa, id_pesquisa = 0;
    
    int dia, mes, ano;
    int h, min;
    char nome[25];
    char local[25];
    char duracao[25];
    char observacao[100];

    printf("****************************************");
    printf(" Bem-Vindo ao meu Diario eletronico ");
    printf("****************************************\n");
    do
    {
        if (strcmp(confirmar_senha, senha) == 0)
        {
            printf("\n \n \n[1] Adicionar novo registro\n[2] Pesquisar registros\n[3] Editar registro:\n[4] Remover registro\n[5] Listar todos os registros\n[0] Encerrar Programa");

            printf("\nEscolha: ");
            scanf("%d", &op);
            getchar();
            printf("\n\n");
            
            
            switch (op)
            {
            case 0:
                printf("Encerrando o programa !");
                break;
            case 1:
                printf("Insira o data(dd mm aaaa): ");
                scanf("%d%d%d", &dia, &mes, &ano);
                getchar();

                printf("Insira o horario(hh mm): ");
                scanf("%d%d", &h, &min);
                getchar();

                printf("Insira o nome: ");
                scanf("%25[^\n]", nome);
                getchar();

                printf("Insira o local: ");
                scanf("%25[^\n]", local);
                getchar();

                printf("Insira a duracao: ");
                scanf("%25[^\n]", duracao);
                getchar();

                printf("Insira as observacoes: ");
                scanf("%100[^\n]", observacao);
                getchar();

                printf("\t -------------------------- \n");
                id += adicionar(id, dia, mes, ano, h, min, nome, local, duracao, observacao);
                strcpy(confirmar_senha, nova_senha);
                break;

            case 2:
            	printf("Escola o modo de pesquisa \n[0] ID\n[1] NOME");
            	printf("\nEscolha: ");
				scanf("%d", &escolha_pesquisa);
				getchar();
				
				switch(escolha_pesquisa)
				{
					case 0:
						printf("Insira o ID para ser pesquisado: ");
						scanf("%d", &id_pesquisa);
						getchar();
            			printf("\n\n");
            			pesquisar_id(id_pesquisa);
					break;
					case 1:
						printf("Insira o nome para ser pesquisado: ");
                		scanf("%25[^\n]", nome);
               		    getchar();
           				printf("\n\n");
                		pesquisar(nome);
					break;
					default:
					printf("Opcao invalida");
					break;
				}
                
                break;
            case 3:
            	printf("Entre com o id para atualizar o registro: ");
                scanf("%d", &id);
                atualizar(id);
                break;
                
            case 4:
                printf("Entre com o id para deletar o registro: ");
                scanf("%d", &id);
                deletar(id);
                break;

            case 5:
                exibir();
                break;
            default:
                printf("Escolha uma opção valida");
                break;
            }
            strcpy(confirmar_senha, senha);
        }else
        if (tentativas >= 2)
        {
            printf("Tentatativas de login excedida. \n");
            printf("Por gentileza cadastre uma nova senha: ");
            scanf("%6[^\n]", nova_senha);
            getchar();
            strcpy(senha, nova_senha);

            tentativas = 0;

            printf("\n\n\n\n");
        }
        else
        {
            printf("Insira a senha do diario: \n");
            scanf("%6[^\n]", confirmar_senha);
            getchar();

            tentativas += tentativas + 1;
        }

    } while (op != 0);
}