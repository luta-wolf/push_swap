![image](https://user-images.githubusercontent.com/58044383/150656131-5d2e991e-b7b2-49d6-af81-3b04c3e88c2d.png)

``` console
                                     d8
                                     88
          88d888b. dP    dP ,d888'   88d8888b.        ,d888'   dP  dP  dP .d8888b. 88d888b.
          88'  '88 88    88 Y8ooooo. 88'   `88        Y8ooooo. 88  88  88 88'  `88 88'  '88
          88.  .88 88.  .88       88 88     88              88 88.88b.88' 88.  .88 88.  .88
          8Y888P'  `888888' `88888P' 8P     dP d8888P `88888P' 8888P Y8P  `88888P8 8Y888P'
          88                                                                       88
          8P                                                                       8P
```
Push_swap
=========

Школьный алгоритмический проект **push_swap**: цель состоит в том, чтобы сортировать данные, используя только два стека и ограниченный набор инструкций.

Команды
-------
- pa : push a — взять первый элемент в верхней части b и поместить его в
				верхнюю часть a. Ничего не делать, если b пусто.
- pb : push b — взять первый элемент в верхней части a и поместить его в
				верхнюю часть b. Ничего не делать, если a пусто.
- sa : swap a — поменять местами первые 2 элемента в верхней части стека a.
			Ничего не делать, если есть только один элемент или его нет).
- sb : swap b — поменять местами первые 2 элемента в верхней части стека b.
			Ничего не делать, если есть только один элемент или его нет).
- ss : sa и sb одновременно.
- ra : rotate a - сдвигает вверх все элементы стека a на 1.
			Первый элемент становится последним.
- rb : rotate b - сдвинуть вверх все элементы стека b на 1.
			Первый элемент становится последним.
- rr : ra и rb одновременно.
- rra : reverse rotate a - сдвигает вниз все элементы стека a на 1.
			Последний элемент становится первым.
- rrb : reverse rotate b - сдвинуть вниз все элементы стека b на 1.
			Последний элемент становится первым.
- rrr : rra и rrb одновременно.

Компиляция
----------
для push swap
```
make
```
для чекера
```
make bonus
```
Запуск
------
Тестеры и визуализатор лежат в папке /tests. После компиляции перенесите в эту папку файл push_swap
```
mv push_swap tests
```
Запускаем визуализатор, отправляем 100 чисел:
```
python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
```
Запускаем 20 тестов от 1 до 100
```
bash test.sh 1 100 20
```
Запуск тестов benchmark
```
bash benchmar3.sh
```

Запуск алгоритма сортировки (отображает только использованные команды):
```
./push_swap 5 2 3 4 1
```
Запуск алгоритма сортировки и проверки (отображает результат работы):
```
ARG="5 3 6 0 2 1 4"; ./push_swap $ARG | ./checker $ARG
```
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```


Визуализация
------------
![pushswap](https://user-images.githubusercontent.com/38796098/57738594-6b6ae500-76b0-11e9-9d29-0f59ee825e8e.gif)

Алгоритм (быстрая сортировка)
-------
1) Парсинг
- склеить строку по пробелам и расплитовать по пробелам
- проверить что подаются только числа (Error)
- проверить числа на повторяемость (Error)
- проверка на max и min int (Error)
- отсортировать стек пузырьком/ вставкой/ выбором
- прописть каждому числу его индекс
- добавить аргументы в стек а (min_a = 1)

2) Сортировка
- проверить что стек отсортирован (тогда выходим)
- написать команды push/swap/rotate/reverse
- написать сортировку для 3-х и 5-ти чисел
- поиск медианы
- переброс в стек б все что меньше медианы 
- запуск цикла основного алгоритма (выход когда стек отсортирован)
- переброс в стек а по поколениям
- поиск в стеках a и б минимального числа
- оптимизация основного алгоритма

3) Чистим стек
- после сортировки всю память очищаем и выходим
![image](https://user-images.githubusercontent.com/58044383/150677927-ac949e02-1f44-41cc-94d3-44e5fdd32dce.png)



Полезные материалы при написании проекта
- Руководство по написанию https://vk.com/@forum42intra-push-swap
- Видео https://www.youtube.com/watch?v=KeDXVukgd9g&ab_channel=Edu_events_mow
