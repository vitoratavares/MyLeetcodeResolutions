class MyStack {
    class Node {
        char bracket;
        Node next = null;
    }

    Node head = new Node();

    boolean isEmpty() {
        return this.head.next == null;
    }

    void pushStack(char new_bracket) {
        Node new_node = new Node();
        new_node.bracket = new_bracket;

        new_node.next = this.head.next;
        this.head.next = new_node;
    }

    void popStack() {
        if(!this.isEmpty()) {
            this.head.next = this.head.next.next;
        }
    }

    char peekStack() {
        if(!this.isEmpty()) {
            return this.head.next.bracket;
        }

        return ' ';
    }
}

class Solution {
    public boolean isValid(String s) {
        // Criando minha pilha:
        MyStack stack_brackets = new MyStack(); // Armazena as "brackets" de fechamento

        for(int i = 0; i < s.length(); i++) {
            char bracket = s.charAt(i);
            if(bracket == '(') {
                stack_brackets.pushStack(')');
            }
            else if(bracket == '{') {
                stack_brackets.pushStack('}');
            }
            else if(bracket == '[') {
                stack_brackets.pushStack(']');
            }
            else {
                if(!stack_brackets.isEmpty()) {
                    if(bracket != stack_brackets.peekStack()) {
                        return false;
                    }
                    else {
                        stack_brackets.popStack();
                    }
                }
                else {
                    return false;
                }
            }
        }    

        if(!stack_brackets.isEmpty()) {
            return false;
        }   

        return true;
    }
}

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