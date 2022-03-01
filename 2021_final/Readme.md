2020\_final
===========

Find Maximum Fruit Number
-------------------------

### Description

<div>

`-英文題目-`

Given a sequence (char input\[\]), there are many fruits in this
sequence. (at most 20 kinds of fruit)

The fruits are connected with +\_+ symbol.

Please output every fruit which has the maximum number of
**occurrence.**

If there are many fruits which have the same maximum number of
occurrence, follow char fruit\[\]\[15\]\'s order.

`hint: answer can more than one fruit`

`-中文題目-`

給定一個 sequence，

該 sequence 包含很多種水果(最多會出現20種水果)，

並且每種水果以 +\_+ 符號隔開，

其中這20種可能出現的水果已經定義在 Loader，

也傳入 find\_fruit() (等同於 char fruit\[\]\[15\])，

例如: fruit\[0\] 代表第一種水果, fruit\[1\]代表第二種水果等等，

請將所有出現最多次的水果都印出來

`如果有相同出現次數的水果，順序請依照 char fruit[][15] 中的順序，例如優先印出 guava 再來 litchi`

相同次數印出的先後順序:

guava\>litchi\>longan\>watermelon\>pomelo\>pear\>banana\>papaya\>pumpkin\>tomato\>mango\>kiwi\>persimmon\>cantaloupe\>strawberry\>grape\>peach\>orange\>coconut\>lemon

`提示: 出現最多次的水果可能不只一種`

`提示: 請務必仔細閱讀 Loader code，來弄清楚整個程式的架構`

`hint: strtok()`

</div>

### Input

There is one line for the sequence (char input\[\]) and has at most
20000 char. The fruits are connected with +\_+ in this sequence (at
least one fruit in this sequence).

### Output

Output the fruit which has the maximum number of occurrence. (you need
to print \"\\n\" at the end of each line)。
如果有相同出現次數的水果，順序請依照 char fruit\[\]\[15\]
中的順序，例如優先印出 guava 再來 litchi 等等

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>
    #include <‍string.h>

    #define N 20000

    void find_fruit(char input[], char fruit[][15]);

    int main(void) {
        char fruit[20][15] = {
            "guava",
            "litchi",
            "longan",
            "watermelon",
            "pomelo",
            "pear",
            "banana",
            "papaya",
            "pumpkin",
            "tomato",
            "mango",
            "kiwi",
            "persimmon",
            "cantaloupe",
            "strawberry",
            "grape",
            "peach",
            "orange",
            "coconut",
            "lemon"
        };
        char input[N];
        scanf("%s", input);
        find_fruit(input, fruit);
        return 0;
    }

<div>

### Sample1

#### Input

    watermelon+_+watermelon+_+coconut+_+grape+_+coconut

#### Output

    watermelon
    coconut

</div>

<div>

### Sample2

#### Input

    pumpkin+_+coconut+_+guava+_+longan+_+peach+_+pomelo+_+coconut+_+litchi+_+lemon+_+coconut+_+persimmon+_+pear+_+coconut+_+banana+_+strawberry+_+tomato+_+cantaloupe+_+orange+_+coconut+_+pear+_+tomato+_+orange+_+grape+_+pomelo+_+litchi+_+grape+_+pumpkin+_+cantaloupe+_+strawberry+_+coconut+_+kiwi+_+grape+_+pumpkin+_+pomelo+_+tomato+_+pear+_+guava+_+papaya+_+coconut+_+kiwi+_+pear+_+mango+_+orange+_+peach+_+tomato+_+watermelon+_+orange+_+longan+_+guava+_+papaya+_+papaya+_+tomato+_+pomelo+_+grape+_+pear+_+pear+_+longan+_+pear+_+kiwi+_+pumpkin+_+watermelon+_+strawberry+_+watermelon+_+pomelo+_+mango+_+persimmon+_+litchi+_+kiwi+_+persimmon+_+lemon+_+longan+_+orange+_+litchi+_+kiwi+_+pear+_+mango+_+strawberry+_+longan+_+pomelo+_+grape+_+tomato+_+pomelo+_+peach+_+banana+_+lemon+_+longan+_+watermelon+_+litchi+_+papaya+_+strawberry+_+litchi+_+watermelon+_+litchi+_+pear+_+lemon+_+kiwi+_+tomato+_+guava+_+strawberry+_+litchi+_+kiwi+_+orange+_+kiwi+_+persimmon+_+pumpkin+_+pumpkin+_+watermelon+_+grape+_+watermelon+_+lemon+_+mango+_+pomelo+_+watermelon+_+coconut+_+mango+_+longan+_+guava+_+strawberry+_+grape+_+guava+_+guava+_+orange+_+grape+_+litchi+_+strawberry+_+strawberry+_+pear+_+grape+_+banana+_+lemon+_+tomato+_+orange+_+peach+_+persimmon+_+tomato+_+orange+_+guava+_+pomelo+_+persimmon+_+watermelon+_+pomelo+_+strawberry+_+pumpkin+_+papaya+_+persimmon+_+mango+_+longan+_+pear+_+pomelo+_+tomato+_+orange+_+pear+_+banana+_+pomelo+_+coconut+_+persimmon+_+mango+_+watermelon+_+pumpkin+_+peach+_+watermelon+_+tomato+_+cantaloupe+_+kiwi+_+litchi+_+strawberry+_+guava+_+cantaloupe+_+lemon+_+persimmon+_+tomato+_+grape+_+coconut+_+tomato+_+strawberry+_+watermelon+_+lemon+_+peach+_+pumpkin+_+pomelo+_+coconut+_+orange+_+litchi+_+pomelo+_+litchi+_+lemon+_+tomato+_+kiwi+_+grape+_+tomato+_+papaya+_+coconut+_+coconut+_+persimmon+_+litchi+_+kiwi+_+banana+_+longan+_+pomelo+_+pear+_+strawberry+_+pear+_+persimmon+_+pear+_+strawberry+_+papaya+_+pumpkin+_+strawberry+_+grape+_+pumpkin+_+coconut+_+cantaloupe+_+orange+_+kiwi+_+mango+_+coconut+_+mango+_+lemon+_+litchi+_+pear+_+pumpkin+_+guava+_+grape+_+coconut+_+persimmon+_+orange+_+tomato+_+mango+_+lemon+_+pear+_+pumpkin+_+pear+_+kiwi+_+guava+_+mango+_+pear+_+papaya+_+mango+_+lemon+_+watermelon+_+mango+_+tomato+_+peach+_+papaya+_+guava+_+banana+_+pear+_+watermelon+_+orange+_+coconut+_+guava+_+pear+_+coconut+_+peach+_+grape+_+longan+_+pear+_+peach+_+cantaloupe+_+pomelo+_+longan+_+cantaloupe+_+tomato+_+pear+_+cantaloupe+_+persimmon+_+mango+_+cantaloupe+_+strawberry+_+longan+_+peach+_+pear+_+kiwi+_+pomelo+_+persimmon+_+pomelo+_+watermelon+_+mango+_+papaya+_+guava+_+pumpkin+_+papaya+_+coconut+_+lemon+_+grape+_+pear+_+cantaloupe+_+guava+_+longan+_+coconut+_+peach+_+pomelo+_+kiwi+_+coconut+_+tomato+_+pear+_+mango+_+kiwi+_+coconut+_+peach+_+cantaloupe+_+banana+_+litchi+_+orange+_+longan+_+banana+_+cantaloupe+_+orange+_+peach+_+persimmon+_+mango+_+peach+_+lemon+_+guava+_+papaya+_+papaya+_+pear+_+cantaloupe+_+lemon+_+papaya+_+kiwi+_+peach+_+watermelon+_+grape+_+strawberry+_+pomelo+_+guava+_+peach+_+peach+_+mango+_+persimmon+_+litchi+_+pumpkin+_+banana+_+mango+_+longan+_+persimmon+_+watermelon+_+guava+_+guava+_+grape+_+mango+_+pumpkin+_+papaya+_+mango+_+peach+_+strawberry+_+grape+_+tomato+_+cantaloupe+_+grape+_+persimmon+_+litchi+_+coconut+_+papaya+_+grape+_+watermelon+_+lemon+_+kiwi+_+lemon+_+litchi+_+pomelo+_+persimmon+_+litchi+_+mango+_+watermelon+_+pomelo+_+strawberry+_+banana+_+pomelo+_+banana+_+strawberry+_+banana+_+strawberry+_+litchi+_+peach+_+longan+_+papaya+_+watermelon+_+kiwi+_+persimmon+_+coconut+_+peach+_+strawberry+_+tomato+_+watermelon+_+tomato+_+persimmon+_+grape+_+cantaloupe+_+watermelon+_+peach+_+orange+_+papaya+_+coconut+_+lemon+_+mango+_+strawberry+_+pear+_+tomato+_+mango+_+kiwi+_+watermelon+_+peach+_+pear+_+peach+_+pomelo+_+pumpkin+_+grape+_+papaya+_+kiwi+_+papaya+_+coconut+_+lemon+_+cantaloupe+_+papaya+_+grape+_+watermelon+_+kiwi+_+mango+_+peach+_+banana+_+coconut+_+pear+_+cantaloupe+_+pumpkin+_+peach+_+pomelo+_+longan+_+cantaloupe+_+pear+_+persimmon+_+pomelo+_+pumpkin+_+pumpkin+_+litchi+_+peach+_+persimmon+_+litchi+_+kiwi+_+persimmon+_+pear+_+coconut+_+mango+_+pomelo+_+persimmon+_+tomato+_+lemon+_+papaya+_+guava+_+tomato+_+grape+_+coconut+_+pumpkin+_+persimmon+_+kiwi+_+pumpkin+_+guava+_+papaya+_+kiwi+_+cantaloupe+_+persimmon+_+watermelon+_+tomato+_+persimmon+_+pomelo+_+mango+_+pumpkin+_+pumpkin+_+pomelo+_+lemon+_+guava+_+tomato+_+mango+_+longan+_+pear+_+strawberry+_+watermelon+_+pear+_+cantaloupe+_+grape+_+banana+_+pumpkin+_+cantaloupe+_+banana+_+persimmon+_+pear+_+grape+_+persimmon+_+persimmon+_+banana+_+orange+_+pear+_+litchi+_+banana+_+orange+_+orange+_+pumpkin+_+coconut+_+coconut+_+pomelo+_+orange+_+mango+_+cantaloupe+_+lemon+_+cantaloupe+_+lemon+_+cantaloupe+_+peach+_+peach+_+banana+_+pomelo+_+longan+_+banana+_+orange+_+tomato+_+coconut+_+longan+_+peach+_+longan+_+grape+_+longan+_+lemon+_+persimmon+_+grape+_+orange+_+litchi+_+pear+_+coconut+_+lemon+_+watermelon+_+longan+_+tomato+_+cantaloupe+_+pumpkin+_+pumpkin+_+banana+_+lemon+_+longan+_+grape+_+grape+_+guava+_+lemon+_+tomato+_+papaya+_+peach+_+mango+_+orange+_+kiwi+_+banana+_+guava+_+coconut+_+guava+_+kiwi+_+mango+_+peach+_+litchi+_+watermelon+_+litchi+_+lemon+_+watermelon+_+peach+_+litchi+_+persimmon+_+tomato+_+tomato+_+guava

#### Output

    pear

</div>

Happy Happy Warehouse Manager
-----------------------------

### Description

<div>

Mr. Huang is a worker who works in a warehouse. He loves to stake things
up to build a tower, Every time the factory sends him newly manufactured
goods, he will stack them on the top of his tower. Once a shop asking
for goods, the goods that are on the top of the tower will be sent out
first. After a busy day, goods on that tower may change a lot, which
left him a difficult job to record. Now, you are asked to help him to
maintain his happy tower.

There are three kinds of goods: `Juice`, `Wine` and `Laptop`. (I know
that stacking laptop with drinks is a bad idea, but Mr. Huang loves to
do that\...) These are defined in the loader.

Then you will receive a list of records that represents what happened
today, the record looks like:

`Produce Juice 5`, this means that factory sends Mr. Huang 5 boxes of
juice.

`Consume 7`, means a shop asking for 7 boxes of goods (You don\'t need
to concern what is in those box, just send them out).

After a busy day, you have to list the things left on the tower from the
top.

`Hint`: You may implement using linked list to maintain that stack.

黃桑是一個快樂的倉儲工，他最喜歡把所有的東西都疊成高高塔。當工廠送來了新的貨物，他都會將他們疊到他的高塔上，而當有商店要批貨時，他也會直接將高塔頂端的貨物寄出去給他們。由於業務繁忙，因此每天高塔上的貨物變動會很大，這會讓每天的結算變得非常麻煩，現在要麻煩你替他設計一個倉儲系統，幫幫黃桑統計每天的貨物吧\~!

黃桑經手的貨物總共有三種:
`果汁`、`紅酒`跟`筆記型電腦`。(我知道把這些東西疊在一起不是個好主意，但親愛的黃先生喜歡\.....)詳細的定義請見Loader。

每天結束後，你都會從黃桑那拿到一張記滿當日進出貨物的紀錄，紀錄長得像這樣:

`Produce Juice 5`, 代表工廠送來了5箱果汁。

`Consume 7`,
代表有商店批了7箱貨(你不需要在意箱子裡裝的是甚麼東西，把東西送出去就對了)。

當你統計完之後，請將塔上剩餘的東西從上至下列出。

`系統提示`: 或許你可以用linked list 的方式在你的電腦中蓋出虛擬的高塔。

</div>

### Input

A list of records with EOF terminated. Hint: To generate EOF manually
while you are testing your code locally, press ctrl+Z on windows and
ctrl+D on linux.

### Output

A list of remained goods from top to bottom. The output format is:
\"Good\_type x remain\_count\" follows a newline character. If the tower
is empty, you need to print \"Empty\" followed by a newline character.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>
    #include <‍string.h>

    const char *good_types[] = {
        "Juice",
        "Wine",
        "Laptop"
    };

    void *produce(void *top_of_stack, const char *good_type, size_t count);
    void *consume(void *top_of_stack, size_t count);
    void list_remain(void *top_of_stack);

    int main() {
        char record[64], *job, *good;
        size_t count;
        void *top_of_stack = NULL;
        while (fgets(record, 64, stdin)) {
            job = strtok(record, " ");
            if (!strcmp(job, "Produce")) {
                good = strtok(NULL, " ");
                count = atol(strtok(NULL, " "));
                for (int i = 0; i <‍ 3; i++) {
                    if (!strcmp(good, good_types[i])) {
                        top_of_stack = produce(top_of_stack, good_types[i], count);
                        break;
                    }
                }
            }
            else if (!strcmp(job, "Consume")) {
                count = atol(strtok(NULL, " "));
                top_of_stack = consume(top_of_stack, count);
            }
        }
        list_remain(top_of_stack);
        return 0;
    }

<div>

### Sample1

#### Input

    Produce Juice 10
    Produce Laptop 5
    Consume 3
    Consume 3
    Produce Wine 2

#### Output

    Wine x 2
    Juice x 9

</div>

<div>

### Sample2

#### Input

    Produce Juice 1
    Consume 1

#### Output

    Empty

</div>

<div>

### Sample3

#### Input

    Produce Juice 2
    Produce Laptop 10
    Produce Wine 1
    Produce Juice 100
    Produce Juice 10

#### Output

    Juice x 110
    Wine x 1
    Laptop x 10
    Juice x 2

</div>

Move the Maximum to the Tail
----------------------------

### Description

<div>

Given `n` **different positive** integers, please move the maximum value
to the tail of the linked list.

給定`n`個**相異的正整數**，請你將當中最大的那個數字移到該Linked-List的最後面。

</div>

### Input

5 \<= n \<= 1000, each value will be less 100000.

### Output

The content of the linked list.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>

    struct node {
        int val;
        struct node *next;
    };
    struct node *head = NULL;
    struct node *tail = NULL;
    void MoveToTail();

    int main(void) { 
        int n;
        scanf("%d", &n);
        for(int i = 1; i <‍= n; ++i) {
            struct node *tmp = malloc(sizeof(struct node));
            scanf("%d", &tmp->val);
            tmp->next = NULL;
            if(i == 1)
                head = tmp;
            else
                tail->next = tmp;
            tail = tmp;
        }
        MoveToTail();
        for(struct node *cur = head; cur != NULL; cur = cur->next) {
            printf("%d ", cur->val);
        }
        return 0;
    }

<div>

### Sample1

#### Input

    5
    1 2 5 4 3

#### Output

    1 2 4 3 5 

</div>

Permutation
-----------

### Description

<div>

Given a string with n alphabets(A\~Z), print all permutations of it in
alphabetical order. For example, if the input string is `ABC`, then
output should be

`ABC`

`ACB`

`BAC`

`BCA`

`CAB`

`CBA`

**Hint**: You can use recursion to solve this problem.

![Image](https://ncchen99.github.io/ckjudgedumper/ckjudge/2020_final/Permutation/images/152d2e4bbad027b8fac1f21a65ef0dcf47ad80db.png)

------------------------------------------------------------------------

給定一字串有 n 個相異的字母(A\~Z)，請列出此 n
個字母的所有排列可能性。(依照字典序輸出)

例如輸入為 `ABC`則輸出

`ABC`

`ACB`

`BAC`

`BCA`

`CAB`

`CBA`

**Hint**: 遞迴

</div>

### Input

A string with n alphabets.(1\<=n\<=6)

### Output

Print out n! kinds of permutations. Each permutation is followed by a
newline character \'\\n\'.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    BAKQ

#### Output

    ABKQ
    ABQK
    AKBQ
    AKQB
    AQBK
    AQKB
    BAKQ
    BAQK
    BKAQ
    BKQA
    BQAK
    BQKA
    KABQ
    KAQB
    KBAQ
    KBQA
    KQAB
    KQBA
    QABK
    QAKB
    QBAK
    QBKA
    QKAB
    QKBA

</div>

<div>

### Sample2

#### Input

    ACEG

#### Output

    ACEG
    ACGE
    AECG
    AEGC
    AGCE
    AGEC
    CAEG
    CAGE
    CEAG
    CEGA
    CGAE
    CGEA
    EACG
    EAGC
    ECAG
    ECGA
    EGAC
    EGCA
    GACE
    GAEC
    GCAE
    GCEA
    GEAC
    GECA

</div>

Rearrange Chatting History
--------------------------

### Description

<div>

Nowadays, \"LINE\" is a well known communication application. \"LINE\"
provides a feature that you can store your chatting history into text
files(`.txt`). Unfortunately, you get a text file with incorrect order.
Therefore, your task is to rearrange the chatting history into the
ascending order with timestamp (**00:00 - 23:59**). Assume that at most
one message per minute and the history is always on the same day.

現今，\"LINE\"是個知名的通訊應用程式。"
LINE"提供了一項功能，你可以將聊天記錄存儲到文本文件(`.txt`)中。很不幸的是，你拿到了一份錯誤順序的文本文件。因此，你的任務就是將聊天紀錄依照時間升序(**00:00
- 23:59**)重新排序。假設每分鐘最多只有一則訊息且記錄一定都是在同一天。

</div>

### Input

First line is the total message (\<= 100). Then, the followings are the
each message information separated by newline with the format:
hour:miniute name content.

### Output

All message information in correct order with the format same as Input.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>
    #define MESSAGE_LENGTH 64
    #define NAME_LENGTH 10

    struct timestamp {
        int hour, minute;
    };

    struct message_info {
        struct timestamp time;
        char name[NAME_LENGTH];
        char message[MESSAGE_LENGTH];
    };

    int cmp(const void *a, const void *b);
    void sort_message(struct message_info *m, int *total);

    int main(void) {
        struct message_info m[100];
        int total;
        scanf("%d", &total);
        for(int i = 0; i <‍ total; i++) {
            scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);
        }
        sort_message(m, &total);
        for(int i = 0; i <‍ total; i++) {
            printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
        }
        return 0;
    }

<div>

### Sample1

#### Input

    9
    09:30 STUDENT I'm worried that I won't pass PD1.
    09:00 TA Hello everyone.
    09:35 TA Why do you think so?
    09:46 TA Send a sticker.
    09:41 STUDENT However, today is the final exam.
    09:01 TA If anyone has question about PD1.
    09:45 TA Well, I can just say "Haiya".
    09:02 TA If no. Hope everyone will be statisfied with your grade.
    09:40 STUDENT Because I still have lots of practices to do.

#### Output

    09:00 TA Hello everyone.
    09:01 TA If anyone has question about PD1.
    09:02 TA If no. Hope everyone will be statisfied with your grade.
    09:30 STUDENT I'm worried that I won't pass PD1.
    09:35 TA Why do you think so?
    09:40 STUDENT Because I still have lots of practices to do.
    09:41 STUDENT However, today is the final exam.
    09:45 TA Well, I can just say "Haiya".
    09:46 TA Send a sticker.

</div>

<div>

### Sample2

#### Input

    5
    10:27 B Good morning.
    00:14 A Good night.
    17:41 B Good evening.
    12:54 A Good afternoon.
    22:50 A Good night again.

#### Output

    00:14 A Good night.
    10:27 B Good morning.
    12:54 A Good afternoon.
    17:41 B Good evening.
    22:50 A Good night again.

</div>

Sudoku Solver
-------------

### Description

<div>

Sudoku is a logical based, combinatorial number-placement puzzle. The
objective is to fill a **9×9** grid with digits so that **each column,
each row, and each of the nine 3×3 subgrids that compose the grid
contain all of the digits from 1 to 9**.

For example:

![Image](data:image/jpeg;base64,/9j/4AAQSkZJRgABAQEAYABgAAD/2wBDAAMCAgMCAgMDAwMEAwMEBQgFBQQEBQoHBwYIDAoMDAsKCwsNDhIQDQ4RDgsLEBYQERMUFRUVDA8XGBYUGBIUFRT/2wBDAQMEBAUEBQkFBQkUDQsNFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBT/wAARCAIRAlsDASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD9PaKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAoqDUNQtdJsLm+vrmKzsraNpp7idwkcUaglnZjwAACST0Arzm1/aQ8BXeh3uqrqGpxx2k1vA1lPoGoRX8rT58jybN4BcTLJhtrRxsG2OQfkbCv/XrovvHZnptFeT6l+0h4X0/UNLnMu/wvdeHdT8RXGtFZVe0jspbeOWJ7by/MDgzsGQgOjRFSm7IHTeJPjF4P8ISawmsaytkdHtbO9vi8EpEMN1K8Nu5IQg7pI3HGSuMtgYNU00rv+rNr80xf1+X+a+9HZUV5Zpv7Tnw71XUrewi1TUob2S9j06WC80DULZrK4kKiGO7EkC/ZDKXTy/P2eZn5N1aPh34/eBvFXiweHNL1W5uNTa5ubJGbS7uO1kubcsJ4EuXiELSp5bkxhy21S2Mc0Wb/r+u6Ft/X9dj0KiiikMKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKAOa+JvgpPiR8OvE3hSS6NiutadcaeboRiTyvMjZN+w8NjOcHrjFebax4S+K3ii30LWNRsfB1nrvhjU4b/AEvSLXVbt7W8P2ee2uDPdm2Vot0dySiLbvsaIZdw+E9uooV1t5fgO+ln5/c9H9/39up8yal+yz4h17R72C91TS7a61jw74osr825dkt73VrqC4URfIvmQxeW6l22M+A20FiF02+DfxB8Wat4n1nxDH4a0m91W18O2sNnpmo3F3HGNP1Ca5lZpXtoid6SDaAnB4JwNx+iKKpSsklstvLVv9Qk3Lf1+9pv8Yo8Y8cfBfW/EsHjhLW60+M654k0PWLbzpHGyGzexaVXwhw5FrJtAyDlckZOKvhv4G69o/8AwgnnXenN/YPjTW/Edz5ckh3295/aPlImU5kH22LcDgDa+GOBn3GilF8qsv60S/RDcm48r2/4DX5NhRRRSJCiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACilxSe/agAoo+lLQB8leEbSzt/HngjxPZQ26+PNX+IGv6Rrt7Dhrq4sYl1HbbzvgM0MSwWRRWOF2xFeoz9aVh2fgPw1p/iy+8U2vh3SrbxNfRLBd61DYxJe3EahQqSTBd7KAiYBJHyj0FbtP7Kj2/rTy/zHL3puXf/ADb189beiW2wlFLSUhBRRRQB4N8YPCrx/H74L+IZdc1a5V9fuLSDSHnVbC2H9kX5eRY0RS8jFV+aVnKgEJsDMG95qpe6PYaldWNzd2VvdXFjKZ7SaaJXe3kKNGXjJGUYo7rkYOGYdCat0+iQ5e9JS8kv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)

The puzzle is represented using a 9 by 9 structure array
(`struct element grid[9][9]`), and each element\'s `num` is an integer
between 0\~9 (**0 means there is no value yet, corresponding to the
white area in the figure, and** `can_modify` **is set to true**). **The
elements that you should not change are the gray shaded area in the
figure** and they belong to this problem (`can_modify` **is set to
false**).

Implement the `solve()` function that can automatically solve a given
sudoku puzzle (you should directly modify `grid[9][9]` and fill in the
correct answer).

Note: There is exactly one solution for each testcase.

------------------------------------------------------------------------

數獨是一個邏輯和數字組合的遊戲。其目標是將數字填入 9x9
的格子內，並使其每一行，列，和 3x3 的格子皆由 1～9 的數字所組成。

例如：如上圖

本次題目中，數獨由一個 9x9 的 struct array 表示
(`struct element grid[9][9]`)，而每個 element 的 `num` 為介於 0\~9 的
integer (0 表示還沒有填入任何數字，且其 `can_modify` 設為
true)。不應更改圖中灰色區域的格子，這些格子為題目 (`can_modify` 設為
false)。

實作 `solve()` 函數來自動解出給定的數獨 (直接修改 `grid[9][9]` 即可)。

註：每個測資都會是唯一解。

</div>

### Input

The input is a sudoku puzzle. The elements, which you should fill in,
are represented by \'.\'.

### Output

The output is the solved sudoku puzzle.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdbool.h>

    struct element {
        int num;        // 1~9: valid, 0: don't have value yet
        bool can_modify;       // true: white area in the figure, false: gray area in the figure
    };

    void solve(struct element (*grid_p)[9]);
    void print_grid(struct element (*grid_p)[9]) {
        for (int i = 0; i <‍ 9; ++i) {
            for (int j = 0; j <‍ 9; ++j) {
                printf("%d ", grid_p[i][j].num);
            }
            printf("\n");
        }
    }

    int main(void) {
        struct element grid[9][9];
        char ch;
        for (int i = 0; i <‍ 9; ++i) {
            for (int j = 0; j <‍ 9; ++j) {
                scanf(" %c", &ch);
                if (ch == '.') {    // can_modify assign true, num assign 0
                    grid[i][j].num = 0;
                    grid[i][j].can_modify = true;
                }
                else {      // value gotten from input, so we can't change this
                    grid[i][j].num = ch - '0';
                    grid[i][j].can_modify = false;
                }
            }
        }
        solve(grid);
        print_grid(grid);
        return 0;
    }

<div>

### Sample1

#### Input

    . 3 . 4 . 9 . . 7
    . . . . . 1 . 9 2
    2 . . . . . . . .
    4 . 2 . 1 5 . 8 .
    . 1 . . 7 . 3 . .
    3 . . 2 4 . . 7 .
    . . 7 . . . 9 . .
    5 . . . . . . . 8
    . . 1 . 5 . . 3 .

#### Output

    1 3 6 4 2 9 8 5 7 
    7 5 8 6 3 1 4 9 2 
    2 9 4 5 8 7 1 6 3 
    4 7 2 3 1 5 6 8 9 
    6 1 5 9 7 8 3 2 4 
    3 8 9 2 4 6 5 7 1 
    8 2 7 1 6 3 9 4 5 
    5 6 3 7 9 4 2 1 8 
    9 4 1 8 5 2 7 3 6 

</div>

