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
void pesquisar(char *nome)
{
    struct Diario *temp = head;
    while (temp != NULL)
    {
        if (temp->nome == nome)
        {
            printf("ID: %d\n", temp->id);
            printf("Data: %d/%d/%d\n", temp->dia, temp->mes, temp->ano);
            printf("Horario: %d:%d\n", temp->h, temp->min);
            printf("Nome: %s\n", temp->nome);
            printf("Local: %s\n", temp->local);
            printf("Duracacao: %s\n", temp->duracao);
            printf("Obervacao: %s\n", temp->observacao);
            return;
        }
        temp = temp->next;
    }
    printf("Nao foi encontrado nenhum registro com o nome %s", nome);
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

            printf("Entre com o novo nome: ");
            scanf("%s", temp->nome);
            printf("Entre com o novo local: ");
            scanf("%s", temp->local);
            printf("Entre com a nova duracao: ");
            scanf("%s", temp->duracao);
            printf("Entre com novas observacoes ");
            scanf("%s", temp->observacao);

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

    char psw[] = {"123456"};
    char cpsw[6];
    char npsw[6];

    int tentativas = 0;
    int op;
    int id = 0;

    int dia, mes, ano;
    int h, min;
    char horario[5];
    char nome[25];
    char local[25];
    char duracao[25];
    char observacao[100];

    printf("****************************************");
    printf(" Bem-Vindo ao meu Diario eletronico ");
    printf("****************************************\n");
    do
    {

        if (strcmp(cpsw, psw) == 0)
        {
            printf("\n \n \n[1] Adicionar novo registro\n[2] Pesquisar registros\n[3] Editar registro:\n[4] Remover registro\n[5] Listar todos os registros\n[0] Encerrar Programa");

            printf("\nEscolha: ");
            scanf("%d", &op);
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
                break;

            case 2:
                printf("Insira o nome para pegar pesquisar: ");
                scanf("%s", &nome);
                pesquisar(nome);
                break;
            case 3:
                printf("Entre com o id para deletar o registro: ");
                scanf("%d", &id);
                deletar(id);
                break;
            case 4:
                printf("Entre com o id para atualizar o registro: ");
                scanf("%d", &id);
                atualizar(id);
                break;

            case 5:
                exibir();
                break;
            default:
                printf("Escolha uma opção valida");
                break;
            }
            strcpy(cpsw, "123456");
        }
        else if (tentativas >= 2)
        {
            printf("Tentatativas de login excedida. \n");
            printf("Por gentileza cadastre uma nova senha: ");
            scanf("%6[^\n]", npsw);
            getchar();
            strcpy(psw, npsw);

            tentativas = 0;

            printf("\n\n\n\n");
        }
        else
        {
            printf("Insira a senha do diario: \n");
            scanf("%6[^\n]", cpsw);
            getchar();

            tentativas += tentativas + 1;
        }

    } while (op != 0);
}