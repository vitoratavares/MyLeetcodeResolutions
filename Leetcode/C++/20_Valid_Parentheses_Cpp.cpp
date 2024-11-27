typedef struct Node {
    char bracket;
    Node *next;
} Node;

Node *newNode(char new_bracket) {
    Node *new_node = new Node();
    new_node->bracket = new_bracket;
    new_node->next = NULL;

    return new_node;
}

bool isEmpty(Node *stack) {
    return stack->next == NULL;
}

Node *pushNode(Node *stack, char new_bracket) {
    Node *new_node = newNode(new_bracket);
    new_node->next = stack->next;
    stack->next = new_node;

    return stack;
}

Node *popNode(Node *stack) {
    if(!isEmpty(stack)) {
        stack->next = stack->next->next;
    }

    return stack;
}

char peekStack(Node *stack) {
    if(!isEmpty(stack)) {
        return stack->next->bracket;
    }

    return ' ';
}

class Solution {
public:
    bool isValid(string s) {
        // Criando minha pilha:
        Node *stack_brackets = newNode(' '); // Armazena as "brackets" de fechamento

        for(int i = 0; i < s.length(); i++) {
            char bracket = s.at(i);
            if(bracket == '(') {
                stack_brackets = pushNode(stack_brackets, ')');
            }
            else if(bracket == '{') {
                stack_brackets = pushNode(stack_brackets, '}');
            }
            else if(bracket == '[') {
                stack_brackets = pushNode(stack_brackets, ']');
            }
            else {
                if(!isEmpty(stack_brackets)) {
                    if(bracket != peekStack(stack_brackets)) {
                        return false;
                    }
                    else {
                        stack_brackets = popNode(stack_brackets);
                    }
                }
                else {
                    return false;
                }
            }
        }    

        if(!isEmpty(stack_brackets)) {
            return false;
        }   

        return true;
    }
};

/*
Sempre que um "bracket" é aberto, o próximo fechamento esperado é em relação à ele.
Ou seja, se eu começo com "(", o próximo fechamento esperado seria ")". Porém, se após uma 
abertura vier outra nova abertura como "[", o novo fechamento esperado seria "]".

Exemplo: 
s = "([)]"

s NÃO é válido, pois embora a quantidade de "brackets" abertas e fechadas estejam corretas, e a ordem
(individualmente falando) também, a ordem geral de abertura e fechamento de "brackets" não está correta.

# RESUMO:
É um problema de PILHA!

Basta criar uma lógica de pilha em que sempre que um elemento de abertura for lido,
é necessário empilhar um elemento de fechamento correspondente, e assim ir desempilhando
e verificando se o elemento desempilhado é o correspondente com a entrada.
*/