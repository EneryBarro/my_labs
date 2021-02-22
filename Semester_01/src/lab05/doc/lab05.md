# Лабораторна робота №5. Циклічні конструкції.

### Вимоги:

- Розробник: Дєнін Богдан.
- Загальне завдання: Реалізувати програму з використанням циклу.
- Идивідуальне завдання: Визначити, чи є ціле 6-значне число «щасливим» квитком («щасливий квиток» - квиток, в якому сума першої половини чисел номера дорівнює сумі другої половини). Наприклад, білет з номером 102300 є щасливим, бо 1 + 0 + 2 = 3 + 0 + 0.

### Опис програми:

- Функціональне призначення: Програма порівнює сумму лівої і правої частини 6-значного числа.

- Опис логічної структури:

  * Функція `main`. Порівнює сумму лівої і правої частини 6-значного числа. Схема алгоритму функції:

 ![block_shema](https://github.com/EneryBarro/HTTM/blob/main/lab05/doc/assets/block_shema.png)
 
- Структура програми:

```
├── dist
│   └── main.bin
├── doc
│   ├── assets
│   │   └── block_shema.png
│   └── lab05.md
├── Doxyfile
├── Makefile
├── README.md
└── src
    └── main.c
```

- Код програми:

```
#include <stdio.h>

int main()
{
	int num;
	int lsum = 0, rsum = 0;
	
	printf("Enter a 6-digit number : ");
	scanf("%d", &num);
	printf("\n");

	for (int i = 0, _num = num; i < 6; i++)
	{
		if (i < 3)  (lsum += _num % 10);
		else   (rsum += _num % 10);

		_num /= 10;
	}

	if (lsum == rsum)
	{
		printf("\n\t\t\t\t   TICKET %d IS HAPPY ! ! !\n", num);
	}
	else
	{
		printf("\n\t\t\t\t   TICKET %d IS UNHAPPY :(\n", num);
	}

	return 0;
}
```

- Варіанти використання:

Вписав 6-значне число, яке відповідає умові «щасливого» квитка.

 ![Primer_1](https://github.com/EneryBarro/HTTM/blob/main/lab05/doc/assets/Primer_1.png)
 
Вписав 6-значне число, яке не відповідає умові «щасливого» квитка.
 
 ![Primer_2](https://github.com/EneryBarro/HTTM/blob/main/lab05/doc/assets/Primer_2.png)

### Висновки:

Навчився використовувати цикли при написанні програми.












