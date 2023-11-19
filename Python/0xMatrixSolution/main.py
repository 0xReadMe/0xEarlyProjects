import numpy as np

print('----------------------Решение 3-ех мерных матриц----------------------')
while True:
    entries_A = list(map(int, input('Пример: 1 3 5 1 8 9.... \n !Количество чисел должно быть = 9! \nВведите через '
                                    'пробел числа в матрице A: ').split()))
    A = np.array(entries_A).reshape(3, 3)
    entries_B = list(
        map(int, input('!Количество чисел должно быть = 9! \nВведите через пробел числа в матрице B: ').split()))
    B = np.array(entries_B).reshape(3, 3)

    print(f'Ваши матрицы: \n A = \n{A} \n B = \n{B}')

    znak = input('Введите действие: + -- сложение, - -- вычитание, * -- умножение ')

    if znak == '+':
        C = A + B
        print(f'Результат сложения: C = \n{C}')

    elif znak == '-':
        deystvie = input('A - B или B - A?:')
        if deystvie == 'A - B':
            C = A - B
            print(f'Результат вычитания: C = \n{C}')
        elif deystvie == 'B - A':
            C = B - A
            print(f'Результат вычитания: C = \n{C}')
    elif znak == '*':
        deystvie = input('A * B или B * A?:')
        if deystvie == 'A * B':
            C = A.dot(B)
            print(f'Результат умножения: C = \n{C}')
        elif deystvie == 'B * A':
            C = B.dot(A)
            print(f'Результат умножения: C = \n{C}')
    input()
