2021\_final
===========

\[20 Points\] Let\'s Build Great Great Walls
--------------------------------------------

### Description

<div>

利姆路是隻可愛的始萊姆，雖然是它只是隻始萊姆，但它統領著森林中的魔物們。自古以來，魔物們最大的威脅莫過於人類的殺戮，利姆路為了保護它所管理的魔物們，它決定讓魔物們在村莊四周蓋上城牆，但是在它領導的眾多魔物村莊中，僅有部份村莊生產建造城牆所需的材料，因此其他村莊需要向這些村莊下訂這些材料。經過一年汲汲營營的建造，利姆路的辦公桌上積滿了來自各個村莊下訂建材的訂單，請你寫一個程式幫助它統整這些訂單。

在這題中，你僅需要完成程式的特定函式，在這個函式中，你會拿到**由訂單組成的
linked-list**，其中每筆訂單都會包含以下資訊：訂單的編號、下定的村莊、下定的建材編號以及數量。請注意：**建材數量的資訊被包裝在
union
中**，你必須根據建材編號讀取特定的欄位。你要實做的函式需要**替每個村莊收集屬於它的訂單**，並將它們串接成**獨立的
linked-list**，其中的訂單須按照**訂單編號由少至多**進行排序，並且，請替每個村莊**計算過去這年它共花了多少錢**購買建材（不同建材的單價可以在
loader code
中找到）。最後，為了簡化之後的查詢速度，請**將村莊按照名稱排列**。

------------------------------------------------------------------------

Rimuru is a cute slime who was killed by a random murder in his previous
life, now he becomes the leader of the monsters live in the forest. To
help the monsters prevent threads from the human world, he plans to make
monsters build great walls around their villages. Since there are lots
of villages in his monster kingdom, and only several of them are able to
supply the building parts, they must trade those ingredients between the
villages. After a year went through, the orders between villages are
piled up like a mountain, please, help him to unify the orders.

In the following program, you will get **several orders constructed as a
linked-list**, each order contains following things: order id, consumer
of the order, the ingredient id and the amount of the ingredient. Please
notice that **the amount of the ingredient are packed in an union**, you
have to retrieve it from the specific member depends on the ingredient
id. For each village, your program should not only **gather the orders
belongs to it**, **reconstruct them into an independent linked-list**,
**sort the orders in ascending order by the order id**, but also
**calculate the total cost** of all orders (the unit cost of each
ingredient can be found in the loader program). Finally, your program
should **sort the result list of villages via their name**.

![](https://steamuserimages-a.akamaihd.net/ugc/947342913895300025/7FC9DECBD7B41332CD3D264AA6B07A4BD8674D2C/)

</div>

### Input

輸入的第一行有兩個整數：V 跟 O，分別代表村莊的數量跟訂單的總筆數，接著有
V 行村莊的名字，剩下的 O
行為訂單的內容，訂單內容為以下格式：「訂單編號:建材編號/建材數量-下訂村莊」。
限制： 1. 1 \<= V \<= 75 2. 1 \<= O \<= 1024 3. 1 \<= 建材數量 \<= 1024
4. 村莊名稱 \< 16 5. 訂單編號是一個 16 進位的字串，長度為 8 The first
line contains two integers V, O that indicates the number of villages
and orders, the next V lines are the village names. The rest of O lines
are the orders which are in the format
\"order\_id:integration\_id/amount-consumer\", each order occupies a
line. restrictions: 1. 1 \<= V \<= 75 2. 1 \<= O \<= 1024 3. 1 \<=
amount \<= 1024 4. length of village name \< 16 5. order id is a hex
string with length 8

### Output

程式須輸出每個村莊的名、它一年來的建材費用以及排序後，屬於該村莊的訂單的編號。
Each village and its total cost to get the ingredients followed by the
id of the orders belong to the village, the output ids should be sorted
in ascending order.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>
    #include <‍string.h>

    #define ORDER_ID_LEN 8
    #define MAX_VILLAGE_NAME_LEN 15

    typedef struct order_s {
        struct order_s *next;
        char order_id[ORDER_ID_LEN + 1];
        char consumer[MAX_VILLAGE_NAME_LEN + 1];
        enum {
            INGRED_A = 1,
            INGRED_B,
            INGRED_C,
        } ingredient_id;
        union {
            char ing_a[8];
            long ing_b;
            double ing_c;
        } amount;
    } order_t;

    typedef struct village_s {
        char name[MAX_VILLAGE_NAME_LEN + 1];
        unsigned long total_cost;
        order_t *order_list;
    } village_t;

    static const long unit_costs[] = {
        [INGRED_A] = 256,
        [INGRED_B] = 512,
        [INGRED_C] = 1024,
    };

    static village_t *init_village_array(int v_cnt);
    static order_t *init_order_list(int o_cnt);
    static void unify_orders(village_t *vills, int v_cnt, order_t *orders);
    static void print_result(village_t *vills, int v_cnt);

    int main()
    {
        int village_cnt, order_cnt;
        scanf("%d%d", &village_cnt, &order_cnt);
        village_t *villages = init_village_array(village_cnt);
        if (!villages) {
            goto init_village_failed;
        }
        order_t *orders = init_order_list(order_cnt);
        if (!orders)  {
            goto init_order_failed;
        }
        unify_orders(villages, village_cnt, orders);
        print_result(villages, village_cnt);
        free(orders);

    init_order_failed:
        free(villages);

    init_village_failed:
        return 0;
    }

    static village_t *init_village_array(int v_cnt)
    {
        village_t *villages = malloc(sizeof(village_t) * v_cnt);
        if (!villages) { // Ran out of memory
            return NULL;
        }
        for (int i = 0; i <‍ v_cnt; i++) {
            scanf("%s", villages[i].name);
        }
        return villages;
    }

    static order_t *init_order_list(int o_cnt)
    {
        order_t *orders = malloc(sizeof(order_t) * o_cnt);
        if (!orders) { // Ran out of memory
            return NULL;
        }
        for (int i = 0; i <‍ o_cnt; i++) {
            // Read the content of order
            // the term %[^c] will use 'c' as delimiter while scanning the input
            scanf(" %[^:]:%u/%[^-]-%s",
                    orders[i].order_id,
                    &orders[i].ingredient_id,
                    orders[i].amount.ing_a,
                    orders[i].consumer);
            
            switch (orders[i].ingredient_id) {
                case INGRED_B:
                    orders[i].amount.ing_b = atol(orders[i].amount.ing_a);
                    break;
                case INGRED_C:
                    orders[i].amount.ing_c = atof(orders[i].amount.ing_a);
                    break;
                default:
                    break;
            }
            // Construct orders into linked-list
            if (i) {
                orders[i - 1].next = orders + i;
            }
        }
        // End the linked-list
        orders[o_cnt - 1].next = NULL;
        return orders;
    }

    static void print_result(village_t *vills, int v_cnt)
    {
        for (int i = 0; i <‍ v_cnt; i++) {
            printf("%s %ld\n  ->", vills[i].name, vills[i].total_cost);
            for (order_t *optr = vills[i].order_list; optr; optr = optr->next) {
                printf(" %s", optr->order_id);
            }
            printf("\n");
        }
    }

<div>

### Sample1

#### Input

    3 15
    Guanmiao
    Sinsing
    Taoyuan
    79B3801D:3/59-Guanmiao
    48D32269:2/834-Guanmiao
    3A699371:3/249-Taoyuan
    3C52083B:1/337-Guanmiao
    6916A3F4:2/299-Taoyuan
    753181AF:2/84-Taoyuan
    158C8543:1/260-Guanmiao
    4C9470D9:3/624-Guanmiao
    76FDD0A1:2/723-Taoyuan
    34C1A646:1/788-Sinsing
    49C2EB29:1/772-Sinsing
    657D29BB:1/746-Taoyuan
    24335A5C:3/940-Taoyuan
    526BB92A:3/171-Guanmiao
    6761B64C:3/117-Taoyuan

#### Output

    Guanmiao 1454336
      -> 158C8543 3C52083B 48D32269 4C9470D9 526BB92A 79B3801D
    Sinsing 399360
      -> 34C1A646 49C2EB29
    Taoyuan 2094592
      -> 24335A5C 3A699371 657D29BB 6761B64C 6916A3F4 753181AF 76FDD0A1

</div>

<div>

### Sample2

#### Input

    4 18
    Yujing
    Yanshuei
    Sinsing
    Gangshan
    059D0501:2/441-Sinsing
    362B46E0:3/992-Sinsing
    34713753:2/167-Sinsing
    1C1E24ED:3/679-Yanshuei
    6504A3FD:1/487-Yujing
    598BD3F5:1/491-Sinsing
    6F8037D0:2/725-Yujing
    28B56E0C:3/891-Yanshuei
    3931CEF1:1/109-Yanshuei
    39B15E23:2/789-Sinsing
    572EC1A6:2/2-Yujing
    5137318F:2/458-Yujing
    12117749:2/701-Sinsing
    0D23AF31:2/821-Yanshuei
    2B897B63:3/462-Yujing
    19A04B37:2/126-Yujing
    50005E7A:3/1019-Yanshuei
    44AA8935:1/533-Gangshan

#### Output

    Gangshan 136448
      -> 44AA8935
    Sinsing 2215680
      -> 059D0501 12117749 34713753 362B46E0 39B15E23 598BD3F5
    Yanshuei 3099392
      -> 0D23AF31 1C1E24ED 28B56E0C 3931CEF1 50005E7A
    Yujing 1268992
      -> 19A04B37 2B897B63 5137318F 572EC1A6 6504A3FD 6F8037D0

</div>

<div>

### Sample3

#### Input

    5 20
    South
    Sinshih
    Danei
    Daliao
    Hunei
    166C47E2:1/245-Sinshih
    7375D5C3:2/553-South
    12B62880:2/762-South
    58C3A4C6:1/403-Daliao
    37B7F642:3/38-Sinshih
    44369036:2/338-Daliao
    052D5D75:1/626-Sinshih
    2DACD55A:3/245-Danei
    75F41330:1/350-Sinshih
    6EE8A654:2/269-Daliao
    2A0633F4:3/371-South
    0CA3ECFD:2/970-Hunei
    0380EBFD:2/778-Hunei
    31EC81E4:1/366-Danei
    60BCEDD1:1/647-Danei
    7C8F0D3E:3/105-Danei
    05B5E563:1/355-Sinshih
    1987954B:2/653-Danei
    50C09674:1/506-Danei
    52654703:3/689-Danei

#### Output

    Daliao 413952
      -> 44369036 58C3A4C6 6EE8A654
    Danei 1787136
      -> 1987954B 2DACD55A 31EC81E4 50C09674 52654703 60BCEDD1 7C8F0D3E
    Hunei 894976
      -> 0380EBFD 0CA3ECFD
    Sinshih 442368
      -> 052D5D75 05B5E563 166C47E2 37B7F642 75F41330
    South 1053184
      -> 12B62880 2A0633F4 7375D5C3

</div>

<div>

### Sample4

#### Input

    7 25
    Annan
    Zuojhen
    Nanhua
    River
    Daliao
    Alian
    Maolin
    1A299881:3/197-River
    229EC19C:1/1021-Zuojhen
    46BA7EA1:3/618-Annan
    402C8159:3/319-River
    4AFA3035:2/551-Maolin
    07C76667:3/191-River
    1F5F8051:3/589-Daliao
    16609029:2/282-Daliao
    690461E6:1/22-Alian
    0C16D905:3/145-Maolin
    0F046D3F:1/133-Maolin
    0EDDACF7:2/652-Alian
    2416050E:3/401-Zuojhen
    72A828B7:1/566-Nanhua
    0F34EE9E:3/486-Nanhua
    21A00A47:1/883-River
    412F50DC:2/945-Alian
    12091799:3/393-Alian
    688A9F39:1/882-Annan
    7BC3E7D0:1/349-Annan
    2143B6AD:3/84-Daliao
    4E385D3A:2/109-Zuojhen
    1BD4570B:3/673-Annan
    0CE41551:1/384-Nanhua
    4F1BFD9A:1/16-Alian

#### Output

    Alian 1229824
      -> 0EDDACF7 12091799 412F50DC 4F1BFD9A 690461E6
    Annan 1637120
      -> 1BD4570B 46BA7EA1 688A9F39 7BC3E7D0
    Daliao 833536
      -> 16609029 1F5F8051 2143B6AD
    Maolin 464640
      -> 0C16D905 0F046D3F 4AFA3035
    Nanhua 740864
      -> 0CE41551 0F34EE9E 72A828B7
    River 950016
      -> 07C76667 1A299881 21A00A47 402C8159
    Zuojhen 727808
      -> 229EC19C 2416050E 4E385D3A

</div>

\[20 Points\] String Combination
--------------------------------

### Description

<div>

沒有錯，又是組合！

給予 n 個字串及數字 k，請將所有可能的組合列出來。

例如：給予 `n = 5`, `k = 2`，以及 `andy becky cindy jacky willy`
五個字串，

代表從 5 個字串中挑選 2
個出來，注意，須根據字串給予時的順序組合進行列印。詳細請見範例。

------------------------------------------------------------------------

Yah, Combination Again!

Given n strings and number k, please print all possible combinations
out.

For example, given `n = 5`, `k = 2`, and `andy becky cindy jacky willy`
five strings,

which means that you have to choose 2 strings from the 5 strings.

Notice that you need print out them according to the given order. See
examples.

</div>

### Input

輸入第一行為 n 跟 k，第二行有 n 個字串（以空格分開）。 1 \<= n \<=
20，且每個字串不超過十個字。 Print out k strings from the n strings,
according to the given order in the input.

### Output

印出 n 個字串取 k 個的結果，須根據字串給予時的順序組合進行列印。 Print
out k strings from the n strings, according to the given order in the
input.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    5 2
    andy becky cindy jacky willy

#### Output

    andy becky 
    andy cindy 
    andy jacky 
    andy willy 
    becky cindy 
    becky jacky 
    becky willy 
    cindy jacky 
    cindy willy 
    jacky willy 

</div>

<div>

### Sample2

#### Input

    5 3
    andy becky cindy jacky willy

#### Output

    andy becky cindy 
    andy becky jacky 
    andy becky willy 
    andy cindy jacky 
    andy cindy willy 
    andy jacky willy 
    becky cindy jacky 
    becky cindy willy 
    becky jacky willy 
    cindy jacky willy 

</div>

<div>

### Sample3

#### Input

    8 1
    andy becky cindy jacky larry mandy sandy willy

#### Output

    andy 
    becky 
    cindy 
    jacky 
    larry 
    mandy 
    sandy 
    willy 

</div>

\[25 Points\] Birdy\'s Network
------------------------------

### Description

<div>

Birdy 是一個網路管理員，他想要使用一個 **鄰接表** (adjacency list)
來紀錄他負責管理的網路。\
我們可以使用一條 list 紀錄當前節點的所有相鄰節點(neighbor
node)，並將所有的節點資訊儲存於一條陣列中，\
以下是本鄰接表的示意圖：

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAesAAAFLCAYAAAD276RPAAAGUnRFWHRteGZpbGUAJTNDbXhmaWxlJTIwaG9zdCUzRCUyMmFwcC5kaWFncmFtcy5uZXQlMjIlMjBtb2RpZmllZCUzRCUyMjIwMjItMDEtMDZUMDMlM0EyOCUzQTQzLjk4OVolMjIlMjBhZ2VudCUzRCUyMjUuMCUyMChYMTEpJTIyJTIwZXRhZyUzRCUyMlZaWjFFNWFWX1BHUy03WjNrN254JTIyJTIwdmVyc2lvbiUzRCUyMjE2LjIuMiUyMiUyMHR5cGUlM0QlMjJkZXZpY2UlMjIlM0UlM0NkaWFncmFtJTIwaWQlM0QlMjJ5RXcwbjAzRGUtWXJEbU1BWEI1NCUyMiUyMG5hbWUlM0QlMjJQYWdlLTElMjIlM0U3VnRkYjlzZ0ZQMDFlVnhsQTg3SDQ1WjIzY01tYldxbHJVOFRpbW5zempFUklZbWRYejljZzc5b0V5ZXBBNWJ5RXBuckN6YUhjeTVjY0Fad3VranVHVjRHUDZoUG9nRnclMkZHUUFid2NBdUFpSTM4eVE1Z2FFUnJsaHprSmYlMkJwU0doM0JIcE5HUjFuWG9rMVhOa1ZNYThYQlpOODVvSEpNWnI5a3dZM1JiZDN1bVVmMnBTendubXVGaGhpUGQlMkJqdjBlWkJieDU1VDJyJTJCUmNCNm9KN3VPdkxQQXlsa2FWZ0gyNmJaaWduY0RPR1dVOHZ4cWtVeEpsR0duY01ucmZYM25idkZpak1TOFRZWDd5U05JMGQ5Zk94WTk3c0xOMDg3ZDNINlNyV3h3dEpZZEZ1NzU2JTJGSlVZY0RvT3ZaSjFvd3pnRiUyQjJRY2pKd3hMUHNydGJNZWpDRnZCRkpFcXV1SlFORXNaSjh1NmJ1a1glMkZCVzhJWFJET1V1RWlLNHdsWXFuaWtDeHZLd01nVFVFRmV5aHRXQTc1dkdpNFJFVmNTR0NPQUFsb0lNVWs0ZGJCTkRJTUUlMkJ3Qmw0QmpHQ1RVQ3k0ViUyRlRjRms5Y0hMZzBOZ3pUc0I1Y21obUZTU3dtN3lGUkVJaFclMkJYZE13NldzQkslMkJpa0FXVjZPZURxdXJPQVR4RFl4cWVSblh6U2dETE5KOVdGQ2liRUYwbUlMRkxHQXpxbk1ZN3VTdXVYT21xbHozZEtseEtyRjhKNUtqTXF2T2EwamlSSlF2NG5xMzdqeWRKVDVjNXRJbHQlMkJMYVNxRUl2JTJCVmlwbHhhZnF2YkxhYTBuVnklMkZ1WGRXciUyRm1Ba002SnJOeUQ2d25MY0hsNUVJODNCVGY4QmJReVdyJTJGcVNoZUhSQkN2YzlVcWdtT0daendtV3R4b0FYcjNFR0IlMkZRNUN2c3Y1MmxseFJuOVYyU3RzSlBKM1hUT0FheGNLRGFuTE9OWkI3QjBxYWdCWlRydkFQcWtaUUdmbWxPV2VUNk43ZVNUQnBScFBrRmdJNThRc294UFVOODdzb0pQR2xERyUyQldSbGZOTEN1T21VSDFvYW41cEFGZkhLMkJiU1dNUGttTnpEUFMlMkYzVU5ldk9jVE5TQ1VpaDVJUFE2bUhpZ1Y1S3JEUDBYdWJCTWZsS0o4WncybkZZWm5sSHF0S3k4MFVwbmtlTVBhcTlEanM3em9OT3VWdjhLRjVqc0t3SXN6elJQa2NSdEdVUnBTSmNreGpjcUc4cCUyQjJtd2JBejRjS3JjRnNMVngwY0h4UXVza0c0QUIwblhEV3BkQ3RjZlhlNGw4SnR1OVR0VHJpVHEzQmJDeGUwRlM2MFFialFPVks0azBzSVY4OUElMkJ5bmNscWV0blFrWDZUbHFQNEE4TlR2ckxnUWlEVGk3UTFvOSUyRkI0TzF4OFpBbEhiRURnMEVRSmhrMXNIMWk2YSUyRjBYV0x2cEhOejFWcnZIRml3N2NkZkd5ZHhlZ2pYTEhOaWpYOVk1VDdtVzJDJTJGVGp2WDRxdCUyQjNYR04wcDE3c3F0N1Z5aDIyVk96S2hYTlE4NURvdzUyciUyQkY1bHo5UlBuZmlqMzFMUFc3dklPJTJGY2luSDBpZWVzcllIWkw2cVZBJTJGa0R6MTI3NFRrQlRGOGk4cGVUQW8lMkY5Y0Q3JTJGNEQlM0MlMkZkaWFncmFtJTNFJTNDJTJGbXhmaWxlJTNF9Aj3CQAAIABJREFUeJzt239oVff9x3Exa72aSAjc/DiYQEL9Sy3YlmwRwmamswRcHKLQSTUgLF7hSgspMkEwSlkDrVqnLilbiQgddH9kE/9SqGb0CkJ1/yzCjAZKQqbS7jZWe+/aal7fP0pO9Wszr55z73nfz3k+4PNHbtJzPr7e535evTWdJwAAYNq8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)

同時，他也希望鄰接表上的節點按照 id 由小到大的排序。\
請你幫助他建立並排序這張鄰接表。

------------------------------------------------------------------------

Birdy is a network administrator. He wants to use an **adjacency list**
to represent his network. One representation of adjacency list is an
array of linked lists which records the neighbors for each node. The
structure of the adjacency list is shown as following:

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAesAAAFLCAYAAAD276RPAAAGUnRFWHRteGZpbGUAJTNDbXhmaWxlJTIwaG9zdCUzRCUyMmFwcC5kaWFncmFtcy5uZXQlMjIlMjBtb2RpZmllZCUzRCUyMjIwMjItMDEtMDZUMDMlM0EyOCUzQTQzLjk4OVolMjIlMjBhZ2VudCUzRCUyMjUuMCUyMChYMTEpJTIyJTIwZXRhZyUzRCUyMlZaWjFFNWFWX1BHUy03WjNrN254JTIyJTIwdmVyc2lvbiUzRCUyMjE2LjIuMiUyMiUyMHR5cGUlM0QlMjJkZXZpY2UlMjIlM0UlM0NkaWFncmFtJTIwaWQlM0QlMjJ5RXcwbjAzRGUtWXJEbU1BWEI1NCUyMiUyMG5hbWUlM0QlMjJQYWdlLTElMjIlM0U3VnRkYjlzZ0ZQMDFlVnhsQTg3SDQ1WjIzY01tYldxbHJVOFRpbW5zempFUklZbWRYejljZzc5b0V5ZXBBNWJ5RXBuckN6YUhjeTVjY0Fad3VranVHVjRHUDZoUG9nRnclMkZHUUFid2NBdUFpSTM4eVE1Z2FFUnJsaHprSmYlMkJwU0doM0JIcE5HUjFuWG9rMVhOa1ZNYThYQlpOODVvSEpNWnI5a3dZM1JiZDN1bVVmMnBTendubXVGaGhpUGQlMkJqdjBlWkJieDU1VDJyJTJCUmNCNm9KN3VPdkxQQXlsa2FWZ0gyNmJaaWduY0RPR1dVOHZ4cWtVeEpsR0duY01ucmZYM25idkZpak1TOFRZWDd5U05JMGQ5Zk94WTk3c0xOMDg3ZDNINlNyV3h3dEpZZEZ1NzU2JTJGSlVZY0RvT3ZaSjFvd3pnRiUyQjJRY2pKd3hMUHNydGJNZWpDRnZCRkpFcXV1SlFORXNaSjh1NmJ1a1glMkZCVzhJWFJET1V1RWlLNHdsWXFuaWtDeHZLd01nVFVFRmV5aHRXQTc1dkdpNFJFVmNTR0NPQUFsb0lNVWs0ZGJCTkRJTUUlMkJ3Qmw0QmpHQ1RVQ3k0ViUyRlRjRms5Y0hMZzBOZ3pUc0I1Y21obUZTU3dtN3lGUkVJaFclMkJYZE13NldzQkslMkJpa0FXVjZPZURxdXJPQVR4RFl4cWVSblh6U2dETE5KOVdGQ2liRUYwbUlMRkxHQXpxbk1ZN3VTdXVYT21xbHozZEtseEtyRjhKNUtqTXF2T2EwamlSSlF2NG5xMzdqeWRKVDVjNXRJbHQlMkJMYVNxRUl2JTJCVmlwbHhhZnF2YkxhYTBuVnklMkZ1WGRXciUyRm1Ba002SnJOeUQ2d25MY0hsNUVJODNCVGY4QmJReVdyJTJGcVNoZUhSQkN2YzlVcWdtT0daendtV3R4b0FYcjNFR0IlMkZRNUN2c3Y1MmxseFJuOVYyU3RzSlBKM1hUT0FheGNLRGFuTE9OWkI3QjBxYWdCWlRydkFQcWtaUUdmbWxPV2VUNk43ZVNUQnBScFBrRmdJNThRc294UFVOODdzb0pQR2xERyUyQldSbGZOTEN1T21VSDFvYW41cEFGZkhLMkJiU1dNUGttTnpEUFMlMkYzVU5ldk9jVE5TQ1VpaDVJUFE2bUhpZ1Y1S3JEUDBYdWJCTWZsS0o4WncybkZZWm5sSHF0S3k4MFVwbmtlTVBhcTlEanM3em9OT3VWdjhLRjVqc0t3SXN6elJQa2NSdEdVUnBTSmNreGpjcUc4cCUyQjJtd2JBejRjS3JjRnNMVngwY0h4UXVza0c0QUIwblhEV3BkQ3RjZlhlNGw4SnR1OVR0VHJpVHEzQmJDeGUwRlM2MFFialFPVks0azBzSVY4OUElMkJ5bmNscWV0blFrWDZUbHFQNEE4TlR2ckxnUWlEVGk3UTFvOSUyRkI0TzF4OFpBbEhiRURnMEVRSmhrMXNIMWk2YSUyRjBYV0x2cEhOejFWcnZIRml3N2NkZkd5ZHhlZ2pYTEhOaWpYOVk1VDdtVzJDJTJGVGp2WDRxdCUyQjNYR04wcDE3c3F0N1Z5aDIyVk96S2hYTlE4NURvdzUyciUyQkY1bHo5UlBuZmlqMzFMUFc3dklPJTJGY2luSDBpZWVzcllIWkw2cVZBJTJGa0R6MTI3NFRrQlRGOGk4cGVUQW8lMkY5Y0Q3JTJGNEQlM0MlMkZkaWFncmFtJTNFJTNDJTJGbXhmaWxlJTNF9Aj3CQAAIABJREFUeJzt239oVff9x3Exa72aSAjc/DiYQEL9Sy3YlmwRwmamswRcHKLQSTUgLF7hSgspMkEwSlkDrVqnLilbiQgddH9kE/9SqGb0CkJ1/yzCjAZKQqbS7jZWe+/aal7fP0pO9Wszr55z73nfz3k+4PNHbtJzPr7e535evTWdJwAAYNq8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)He
also wants to make the order of the adjacency list ascending. Please
help him load the data to an adjacency list and reorganize its order.

Note that the connection is directed.

</div>

### Input

Input contains multiple lines (\<= 1000 lines). The first number in each
line is node id. The numbers after \"-\>\" are the neighbor ids of
current node (in ascending order). The last number in each line is
always 0, which indicates the end of the line. All ids are positive
integers (1 \<= id \<= 2147483647).

### Output

Output contains the neighbor ids of each node (list in ascending order).

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>

    struct node {
        int id;
        struct node *next;
    };

    struct node *read_data(int *size); // TODO: implement this function

    void print_data(struct node *adj, int size) {
        if (!adj) {
            return;
        }
        for (int i = 0; i <‍ size; ++i) {
            printf("%d -> ", adj[i].id);
            for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next) {
                printf("%d ", ptr->id);
            }
            putchar('\n');
        }
        return;
    }

    void free_data(struct node *adj, int size) {
        if (!adj) {
            return;
        }
        for (int i = 0; i <‍ size; ++i) {
            struct node *ptr = adj[i].next;
            while (ptr) {
                adj[i].next = ptr->next;
                free(ptr);
                ptr = adj[i].next;
            }
        }
        free(adj);
        return;
    }

    int main() {
        int size;
        struct node *adj = read_data(&size);
        if (!adj) {
            fprintf(stderr, "Error allocating memory.");
            exit(1);
        }
        print_data(adj, size);
        free_data(adj, size);
        return 0;
    }

<div>

### Sample1

#### Input

    100356 -> 4 458 0
    4 -> 458 0
    458 -> 0

#### Output

    4 -> 458
    458 -> 
    100356 -> 4 458

</div>

<div>

### Sample2

#### Input

    32 -> 14 22 0
    37 -> 14 32 0
    8 -> 22 37 0
    14 -> 8 22 32 37 0
    22 -> 8 14 32 37 0

#### Output

    8 -> 22 37
    14 -> 8 22 32 37
    22 -> 8 14 32 37
    32 -> 14 22
    37 -> 14 32

</div>

\[25 Points\] Order Recovery
----------------------------

### Description

<div>

小混蛋工廠最近遇到了大麻煩！

他們的系統不知道出了什麼問題，接收到的訂單可能會少字，並以奇怪的格式呈現。

請協助他們恢復訂單內容，並告訴他們該訂單要的貨到底是什麼！

舉例來說，當訂單收到的是 `ter:mel`，代表要的貨有兩個（以 `:`
隔開），其中一個包含字串 `ter`，另一個包含字串 `mel`。

然而，工廠內有太多東西了，以符合 `ter` 來說，可能是 `water`，可能是
`battery`，也可能是 `butter`。（沒錯，這間工廠什麼都有。）

因此小混蛋工廠的員工決定只選擇「最先符合該字串」的物品，當作客人要的貨，上述三項的話，將會選擇
`water` 當作結果。

（因為 `water`
是在第三個字母開始符合，其他兩者都是在第四個字母才開始符合。）

當然，若有兩個以上字串符合上述情況，則優先選擇字數最短的字串，字數相同時，則比較兩字串各字元，優先選擇字元較前面的字串。

例如：訂單要求 `ham`，則 `hammer` 和 `hamburger` 將選擇 `hammer`。

又例如：訂單要求 `yo`，則 `yolk` 和 `yoyo` 將選擇 `yolk`（因為順序上 `l`
比 `y` 前面）。

最後回到訂單的舉例，若 `ter` 選出的貨為 `water`，`mel` 選出的貨為
`melon`，則最後以 `+` 連結，輸出 `water+melon`。

另外，每張訂單最少有 1 樣物品，但最多不會超過 30 樣物品。

------------------------------------------------------------------------

Bestards\' Factory has a big trouble!

Somewhere is wrong in their system, so the order they received may miss
some characters, and is showed in a strange way.

Please help them recover the order, and tell they what the customers
want.

For example, if the order\'s content is `ter:mel`, it means there are
two items（separated by `:`）, one includes substring `ter`, and the
other includes substring `mel`.

However, there are too many goods, we use `ter` as an example, it may be
`water`, `battery`, or `butter`. (Yah, the factory sells everything!)

Hence we choose the goods that 「is matched by the substring from the
more forward position」, as the goods that the customers want.

In the example, we will choose `water`. (Since `water` matches `ter`
from the third position, while the other two match from the fourth
position.)

If there are at least two goods meet the condition, then we choose the
string with shorter length.

If the length are the same, then compare two strings, and choose the one
that is less than the other.

For example, if `ham`, then `hammer` and `hamburger`, we choose
`hammer`.

Another example, if `yo`, then `yolk` and `yoyo`, we choose `yolk`.
(Since in ascii, `l` is prior to `y`.)

Back to the first example, if `ter` represents for `water`, and `mel`
represents for `melon`, then concatenate them by using `+` and print out
`water+melon` as the result.

Every order orders at least 1 goods, but won\'t exceed 30 goods.

</div>

### Input

輸入為一字串，其中以 \':\' 分隔訂單物品。 The input is a string, and the
goods are separated by \':\'.

### Output

將各物品以 \'+\' 連結，輸出該筆訂單內容。 Concatenate each goods by
using \'+\', and then print it out.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍stdlib.h>
    #include <‍string.h>
    #define GOODS_SIZE 120
    #define MAX_ORDER_SIZE 30
    #define MAX_NAME_LEN 15

    void recovering_order(char *, char **);

    char names[GOODS_SIZE][MAX_NAME_LEN] = {
        "aluminum", "ammunition", "orange", "aspirin", "ax",
        "basketball", "zipper", "bell", "blanket", "drum",
        "canvas", "flute", "eraser", "mirror", "comb",
        "eggplant", "diamond", "zucchini", "door", "butter",
        "egg", "dart", "chair", "encyclopedia", "china",
        "fan", "glue", "elevator", "flower", "hat",
        "garlic", "strawberry", "glove", "flour", "ice",
        "ship", "hammer", "fur", "key", "honey",
        "grape", "icecream", "lock", "iron", "ivory",
        "jacket", "oil", "uniform", "kiwi", "pan",
        "helmet", "keyboard", "yoyo", "jet", "knife",
        "tie", "lemon", "xerox", "ink", "mutton",
        "newspaper", "melon", "coconut", "motorcycle", "longan",
        "nail", "rice", "magnet", "peanut", "ointment",
        "oar", "jeans", "nut", "arrow", "oven",
        "jewel", "wool", "noodle", "pencil", "lamp",
        "refrigerator", "needle", "roast", "vest", "yarn",
        "saw", "hamburger", "soap", "glass", "wine",
        "tangerine", "pillow", "umbrella", "zinc", "train",
        "uglifruit", "toast", "underwear", "vanilla", "jeep",
        "unicycle", "vase", "rope", "violin", "warship",
        "volleyball", "water", "yogurt", "submarine", "passionfruit",
        "yacht", "rose", "window", "yolk", "kite",
        "liquor", "xylophone", "toothbrush", "battery", "doll"
    };

    int main(void) {
        char order[500] = "", *result = NULL;
        scanf("%s", order);
        recovering_order(order, &result);
        printf("%s", result);
        free(result);
        return 0;
    }

<div>

### Sample1

#### Input

    ter:mel

#### Output

    water+melon

</div>

<div>

### Sample2

#### Input

    nut:il

#### Output

    nut+oil

</div>

<div>

### Sample3

#### Input

    in:lo:low

#### Output

    ink+lock+flower

</div>

\[30 Points\] Magic Bug
-----------------------

### Description

<div>

司波達也是名魔法工程師，平常的工作是替客戶調校及改善魔法道具（想不到吧，魔法也跟程式一樣喔～），今天他接到了一個棘手的案子，不管用什麼方式都找不到
Bug
在哪裡，因此他決定直接把魔法道具的記憶體倒出來看看，請你幫他開寫一支程式來印出魔法道具的記憶體內容。

你的程式會得到兩個數字：stb 跟 num，其中 num 是長度固定為 8
位元組的數字，而 stb
代表司波想要檢測的記憶體內容的開頭。司波每次固定檢查從 stb 開始的 8
個位元，為了避免模糊焦點，請將不需要被檢測的記憶體內容設為 0。

Tatsuya is a magic engineer whose daily job is to calibrate and improve
the magic tools. One day he got sucked in a tricky job that an unknown
bug takes him a week and still no progress. To find out the mistake of
the magic program, he decides to dump the entire memory of the magic
tool, please help him to fulfill that.

Your program will recieve two integer: stb and num, where num is an
8-byte number, and stb indicates the begining bit that Tatsuya
interested in. Notice that only 8 bits will be checked each time, please
zero out the rest of bits to zero before print out the content.

![Screenshot from 2022-01-10
18-58-51.png](data:image/png;base64,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)

![](http://5b0988e595225.cdn.sohucs.com/images/20190310/8e8de645effc4993a1da8e22bbf7006d.gif)

</div>

### Input

輸入的第一行是一個整數 N 代表記憶體內容的數量，之後的 N
行皆是記憶體內容，且輸入符合「stb-num」的格式，其中 stb
代表要檢查的記憶體區段的起始位置，而 num 為一個固定為 8 位元組的 16
進位數字。 The first line contains an integer N that indicates the
number of memory contents to print. The rest of N lines are the memory
content in the format \"stb-num\" where stb indicates the start bit, and
num is an integer in hex format with fixed length in 8 bytes.

### Output

對於每行記憶體內容，請印出相對應的二進位內容。 N lines of integers in
binary format, there should be a whitespace between two bytes of with in
an integer.

### Loader Code

<div>

Your code will be judge using this program:

</div>

<div>

### Sample1

#### Input

    6
    6-0x36c3bf4154901a51
    24-0x6cd08f786630bc7d
    7-0x49662b322f44fe5
    4-0xd19c56a0052f04e
    24-0x50f25f5349ba72e6
    27-0x4486df6f6fdda642

#### Output

    00000000 00000000 00000000 00000000 00000000 00000000 00011010 01000000 
    00000000 00000000 00000000 00000000 01100110 00000000 00000000 00000000 
    00000000 00000000 00000000 00000000 00000000 00000000 01001111 10000000 
    00000000 00000000 00000000 00000000 00000000 00000000 00000000 01000000 
    00000000 00000000 00000000 00000000 01001001 00000000 00000000 00000000 
    00000000 00000000 00000000 00000111 01101000 00000000 00000000 00000000 

</div>

<div>

### Sample2

#### Input

    11
    48-0x3f9b91e666a0e8b
    15-0x64feb3044281b8ad
    25-0x5256e33a7882f5d1
    47-0x75f7469226eb2fdd
    27-0xe1013e93f389ce9
    45-0x74205f5211db3a0
    18-0xf58b2e3427ec21d
    15-0x65e523c00e7427f3
    9-0x49028dfe4917ca7e
    20-0x70222da20482132a
    30-0x373d4c0b087bcc49

#### Output

    00000000 11111001 00000000 00000000 00000000 00000000 00000000 00000000 
    00000000 00000000 00000000 00000000 00000000 00000001 10000000 00000000 
    00000000 00000000 00000000 00000000 01111000 00000000 00000000 00000000 
    00000000 01110111 00000000 00000000 00000000 00000000 00000000 00000000 
    00000000 00000000 00000000 00000001 00111000 00000000 00000000 00000000 
    00000000 00000010 00000000 00000000 00000000 00000000 00000000 00000000 
    00000000 00000000 00000000 00000000 00000010 01111100 00000000 00000000 
    00000000 00000000 00000000 00000000 00000000 01110100 00000000 00000000 
    00000000 00000000 00000000 00000000 00000000 00000001 11001010 00000000 
    00000000 00000000 00000000 00000000 00000100 10000000 00000000 00000000 
    00000000 00000000 00000000 00001011 00000000 00000000 00000000 00000000 

</div>

<div>

### Sample3

#### Input

    6
    7-0x1151b9a4384027f7
    26-0x5d63ecf71ec5a259
    54-0x606a23ce0dfa5d1c
    19-0x1f4b24710d61928b
    1-0xbd1352f748aa177
    42-0xad8c1441228c898

#### Output

    00000000 00000000 00000000 00000000 00000000 00000000 00100111 10000000 
    00000000 00000000 00000000 00000011 00011100 00000000 00000000 00000000 
    00100000 01000000 00000000 00000000 00000000 00000000 00000000 00000000 
    00000000 00000000 00000000 00000000 00000101 01100000 00000000 00000000 
    00000000 00000000 00000000 00000000 00000000 00000000 00000001 01110110 
    00000000 00000000 11000000 00000000 00000000 00000000 00000000 00000000 

</div>

<div>

### Sample4

#### Input

    1
    26-0x463180af3385451e

#### Output

    00000000 00000000 00000000 00000011 00110000 00000000 00000000 00000000 

</div>

\[30 Points\] Pull The Radish
-----------------------------

### Description

<div>

在開心農場裡，Ariel 種了 `N`
根蘿蔔，每個蘿蔔的間距為一公尺，今天是收成的日子，但 Ariel
不想要一次拔光所有蘿蔔，所以他決定以自己為起點 (起點為
`y`)，分別向左和向右，每隔 `x` 公尺就拔一根蘿蔔，請輸出 Ariel
今天總共收成了幾根蘿蔔，並告訴他現在農場的情況。\
\
`farm[N]` 表示農場狀況，若 `farm[i]` 為 1 ，表示在 index 為 `i`
時，有種一根蘿蔔 ; 若 `farm[i]` 為 0 ，表示在 index 為 `i`
時，沒有種蘿蔔。( index `i` 與 `i+1` 之間表示間隔為一公尺)

**Notice**: 請完成 `pull_radish`
函式，並回傳總共拔了幾個蘿蔔，注意參數是什麼 !

------------------------------------------------------------------------

In happy farm, Ariel planted `N` radishes. The radishes are spaced at
one-meter intervals. It is time to harvest, but Ariel doesn\'t want to
pull all radishes. Therefore, she deicides to start with herself
(starting point is `y`), and pulls radishes every `x` meters to left and
right, respectively. Please output how many radishes Ariel pulls and the
situation of farm.

`farm[N]` represents the situation of farm. If `farm[i]` is 1, that
means there is a radish at index `i` ; If `farm[i]` is 0, that means
there isn\'t a radish at index `i`.

**Notice**: Please finish `pull_radish` function, and return the number
of radishes that Ariel pulls. Pay attention to the parameter!

</div>

### Input

There are three number, integer N , y and x, represent the number of
radishes, Ariel\'s position and the interval.

### Output

Output the total of radishes which Ariel pulled and the array farm\[N\]

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include<‍stdio.h>
    #include<‍stdlib.h>

    int pull_radish(int *l, int *r, int *pos, int x);

    int main() {
        int N, y, x;
        scanf("%d %d %d", &N, &y, &x);
        int *farm = malloc(N * sizeof(int));

        // initialize farm[N]
        for(int i=0; i<‍N; i++) {
            farm[i] = 1;
        }

        int total = pull_radish(&farm[0], &farm[N-1], &farm[y], x);
        printf("%d\n", total);
        for(int i=0; i<‍N; i++) {
            printf("%d ", farm[i]);
        }

        return 0;
    }

<div>

### Sample1

#### Input

    8 2 2

#### Output

    3
    0 1 1 1 0 1 0 1 

</div>

<div>

### Sample2

#### Input

    15 14 5

#### Output

    2
    1 1 1 1 0 1 1 1 1 0 1 1 1 1 1 

</div>
