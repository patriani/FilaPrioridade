/*Fila de Prioridade Máxima(priority_queue):

http://www.cplusplus.com/reference/queue/priority_queue/

Uma estrutura de lista encadeada (para criar uma lista de tamanho dinâmico) 
em que a lista de prioridade máxima assume que a chave do maior elemento esteja
na primeira posição. Essa implementação utiliza a chave do elemento como seu conteúdo
para entendimento dos mecanismos de manipulação da estrutura de dados: "Fila de Prioridade
Máxima".
*/

//inclui o leitor de lista de prioridade

#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int elem;
    NODE* next;
};

int isEmpty(NODE* root){
    if(root == NULL)
        return 1; 
    else 
        return 0; 
}

NODE* createNode(int number){
    NODE* node = new NODE;
    node->next = NULL;
    node->elem = number;
    return(node);
}

NODE* insert(NODE* root,int elem_temp){

    if(isEmpty(root)){
        root = createNode(elem_temp);
        return(root);
    }

    // inicialização após a condição para evitar alocação desnecessária
    NODE* temp_addr1 = new NODE; //ponteiro de atraso para auxiliar 
    NODE* temp_addr2 = new NODE; //ponteiro de navegação que compara o conteudo de um nó
    temp_addr1 = NULL;
    temp_addr2 = root;
    
    while(temp_addr2!=NULL){ //enquanto não chega ao final
        if(temp_addr2->elem < elem_temp){ //encontrou um primeiro elemento menor para inserir
            if(temp_addr2 == root){ //primeiro da fila
                root = createNode(elem_temp);
                root->next = temp_addr2;
                return(root);
            }else{
                temp_addr1->next = createNode(elem_temp);
                temp_addr1 = temp_addr1->next;
                temp_addr1->next = temp_addr2;
                return(root);
            }
        }else if(temp_addr2->next == NULL){
            temp_addr2->next = createNode(elem_temp);
            temp_addr2 = temp_addr2->next;
            temp_addr2 = NULL;
            return(root);
        }else{
            temp_addr1 = temp_addr2;
            temp_addr2 = temp_addr2->next;
            
        }
    }
    return(root);
}

int main(){
    NODE* root = new NODE;
    int opt = -1;
    root = NULL;
    
    while(true){
        system("cls");

        printf("\n-1 quit");
        printf("\n 0 push ");
        printf("\n 1 pop ");
        printf("\n 2 return all\n");
        scanf("%d",&opt);

        switch(opt){

            case -1:
                exit(0);
                break;

            case 0:
                {
                int total = 0; // recebe numero total de entradas
                int i = 0;

                printf("\n Quantidade elementos: ");
                scanf("%d",&total);

                while(i < total){
                    int elem_temp = 0;

                    printf("entrada %d = ",i);
                    scanf("%d",&elem_temp);
                    root = insert(root,elem_temp);

                    i++;
                }
                break;
            }
            case 2:
                NODE* temp_print = new NODE;
                int it = 0;
                int fake_ch;
                temp_print = root;

                while(temp_print!=NULL){
                    printf("\nelemento %d: %d",it,temp_print->elem);
                    temp_print = temp_print->next;
                    it++;
                }
                printf("\ncontinue? [y/n]\n");
                scanf("%d",fake_ch);
                if(fake_ch == 121)
                    break;
                else    
                    printf("\nCtrl+C para sair\n");
            
        }
    }
    
    return 0;
}
