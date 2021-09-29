class Cliente:
    def __init__(self, numero, saldo):
        self.numero = numero
        self.saldo = saldo
    
class ContaBancaria:
#Usa uma tabela Hash p/ registrar em um espaço da lista as informações de uma conta

    def __init__(self):
        self.table_size = 10
        self.array = [None] * self.table_size

    def get_hash(self, key):
        h = 0
        for char in key:
            h += ord(char)

        return h

    def hashDivisao(self, key):
        key = self.get_hash(key)
        return (key & int(0x7FFFFFFF)) % self.table_size

    def abrir_conta(self, numero, saldo): #Abre a conta e coloca em um espaço vazio na tabela
        new_conta = Cliente(numero, saldo)
        pos = self.hashDivisao(numero)
        for i in range(self.table_size):
            if self.array[pos] == None: 
                self.array[pos] = new_conta

    def depositar(self, numero, valor):
        for i in range(self.table_size): #calcula a posição em relação a conta e atualiza os valores
            pos = self.hashDivisao(numero)
            current = self.array[pos]
            if current == None:
                return 0 
            if current.numero == numero:
                atual = self.array[pos]
                atual.saldo = atual.saldo + valor
                break

    def saque(self, numero, saida):
        for i in range(self.table_size): #calcula a posição em relação a conta e atualiza os valores
            pos = self.hashDivisao(numero)
            current = self.array[pos]
            if current == None:
                return 0
            elif current.numero == numero:
                atual = self.array[pos]
                atual.saldo = atual.saldo - saida
                break

    def imprime_saldo(self, numero): #calcula a posição e imprime o que está nesse espaço da tabela
        for i in range(self.table_size):
            pos = self.hashDivisao(numero)
            current = self.array[pos]
            if current == None:
                return 0
            elif current.numero == numero:
                val = self.array[pos]

        print("Conta N° {}" .format(numero))
        print("Saldo: ")
        print(val.saldo)


if __name__ == '__main__':

    banco = ContaBancaria()

    banco.abrir_conta("12345", 0)
    banco.imprime_saldo("12345")

    banco.depositar("12345", 100)
    banco.imprime_saldo("12345")

    banco.saque("12345", 25)
    banco.imprime_saldo("12345")

    banco.abrir_conta("56748", 0)
    banco.depositar("56748", 20)
    banco.saque("56748", 10)
    banco.depositar("56748", 8)

    banco.imprime_saldo("56748")