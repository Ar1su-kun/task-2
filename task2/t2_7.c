/* Вычисление значения выражения, содержащего цифры '0'-'9', знаки
* операций '+', '*' и скобки '(', ')''. ( Предполагается, что коды цифр
* упорядочены по возрастанию цифр и справедливо равенство '9'-'0'==9 как,
* например, в ASCII кодировке)
*/

#include <stdio.h>
#include <string.h>
#include <setjmp.h>

jmp_buf begin; /* точка начала диалога с пользователем */

char curlex; /* текущая лексема */

void getlex(void); /* выделяет из входного потока очередную лексему */
int expr(void);    /* распознает выражение и вычисляет его значение */
int add(void);     /* распознает слагаемое и вычисляет его значение */
int mult(void);    /* распознает множитель и вычисляет его значение */
void error(void);  /* сообщает об ошибке в выражении и передает управление
                    в начало функции main (точка begin) */
int power(void);

int main()
{
    int result;
    setjmp(begin);
    printf("==>");
    getlex();
    result = expr();
    if (curlex != '\n') error();
    printf("\n%d\n", result);
    return 0;
}

void getlex()
{
    while ((curlex = getchar()) == ' ');
}

void error(void)
{
    printf("\nОШИБКА!\n");
    while (getchar() != '\n');
    longjmp(begin, 1);
}

int expr()
{
    int e = add();
    while (curlex == '+' || curlex == '-')
    {
        if(curlex == '+')
        {
            getlex();
            e += add();
        }
        if (curlex == '-')
        {
            getlex();
            e -= add();
        }
    }
    return e;
}

int add()
{
    int a = mult();
    while(curlex == '*' || curlex == '/')
        if (curlex == '/')
        {
            getlex();
            int b = mult();
            if (b==0)
                error();
            else
                a /= b;
        }
        if (curlex == '*')
        {
            getlex();
            a *= mult();
        }
    return a;
}

int mult()
{
    int m = power();
    while (curlex == '^')
    {
        getlex();
        int b = mult();
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= m;
        m = res;
    }
    return m;
}
int power()
{
    int p;
    switch (curlex)
    {
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
        p = curlex - '0';
        break;
    case '(':
        getlex();
        p = expr();
        if (curlex == ')') break;
        /* иначе ошибка - нет закрывающей скобки */
    default:
        error();
    }
    getlex();
    return p;
}

/* Сравните прототипы (в начале программы) и заголовки функций
* (в соответствующих определениях) error() и getlex() : информацию
* о параметрах (в данном случае пустые списки параметров - void) можно
* опускать в заголовке, если она есть в объявлении прототипа (как в случае
* с getlex) или не указывать в прототипе, а указать только в заголовке
* (как в случае с error). Тип обех функций - "функция, не возвращающая
* значения с пустым списком аргументов"
*/
