class Solution:
    def isValid(self, s: str) -> bool:
        # Criando minha "pilha":
        stack_brackets = [] # Armazena as "brackets" de fechamento

        for element in s:
            if element == "(":
                stack_brackets.append(")")
            elif element == "{":
                stack_brackets.append("}")
            elif element == "[":
                stack_brackets.append("]")
            else:
                if len(stack_brackets) > 0:
                    if element != stack_brackets[-1]:
                        return False
                    else:
                        stack_brackets.pop(-1)
                else:
                    return False

        if len(stack_brackets) > 0:
            return False

        return True

'''
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
'''