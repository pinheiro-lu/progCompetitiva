contador = 0
while (True):
    contador += 1
    # entrada = [int(x) for x in input().split()]
    entrada = input().split()
    N = int(entrada[0]) # numero de itens
    F = int(entrada[1]) # numero de amigos
    if N == 0 and F == 0: break

    soma = 0
    for i in range(N):
        entrada = int(input())
        soma += entrada
    
    valorporamigo = soma // F
    
    print('Bill #{} costs {}: each friend should pay {}\n'.format(contador, soma, valorporamigo))
