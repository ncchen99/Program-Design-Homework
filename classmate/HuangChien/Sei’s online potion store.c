#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char hour;
    unsigned char minute;
} hm_t;

typedef struct {
    const char *item_name;
    unsigned cost;
    unsigned cnt;
} item_t;

typedef struct {
    unsigned order_id;
    hm_t pick_up_time;
    unsigned total_cost;
    unsigned item_cnt;
    item_t *items;
} order_t;

const item_t avaliable_items[] = {
    {"Prod_A", 10},
    {"Prod_B", 20},
    {"Prod_C", 15},
    {"Prod_D", 30},
    {"Prod_E", 50},
    {"Prod_F", 60},
    {"Prod_G", 75},
    {"Prod_H", 5},
    {"Prod_I", 25},
    {"Prod_J", 80},
    {"Prod_K", 100},
    {"Prod_L", 90},
    {"Prod_M", 45},
    {"Prod_N", 40},
    {"Prod_O", 85},
};

const unsigned avaliable_item_cnt = 15;
#define MAX_ORDER_CNT 1024

unsigned fetch_orders(order_t orders[]);
void sum_total_costs(order_t orders[], unsigned order_cnt);
void reorder(order_t orders[], unsigned order_cnt);
void print_result(order_t orders[], unsigned order_cnt);
void clean_up(order_t orders[], unsigned order_cnt);

int main() {
    order_t orders[MAX_ORDER_CNT];
    unsigned order_cnt = fetch_orders(orders);
    sum_total_costs(orders, order_cnt);
    reorder(orders, order_cnt);
    print_result(orders, order_cnt);
    clean_up(orders, order_cnt);
    return 0;
}

unsigned fetch_orders(order_t orders[]) {
    unsigned order_cnt;
    scanf("%u", &order_cnt);

    // Prepare the orders.
    order_t *curr = orders;
    for (unsigned i = 0; i < order_cnt; i++, curr++) {
        hm_t *curr_pu = &(curr->pick_up_time);
        scanf("%u %hhu:%hhu %u",
              &(curr->order_id),
              &(curr_pu->hour),
              &(curr_pu->minute),
              &(curr->item_cnt));

        // Create a variable length array with malloc.
        item_t *curr_items = curr->items = malloc(sizeof(item_t) * curr->item_cnt);
        for (unsigned j = 0; j < curr->item_cnt; j++) {
            char item_name[32];
            scanf("%s", item_name);
            for (unsigned k = 0; k < avaliable_item_cnt; k++) {
                if (!strcmp(item_name, avaliable_items[k].item_name)) {
                    // Copy the memory content from avaliable_items to curr_items.
                    curr_items[j] = avaliable_items[k];
                    break;
                }
            }
            scanf("%u", &(curr_items[j].cnt));
        }
    }
    return order_cnt;
}

void print_result(order_t orders[], unsigned order_cnt) {
    for (unsigned i = 0; i < order_cnt; i++) {
        printf("#%u %u\n", orders[i].order_id, orders[i].total_cost);
    }
}

void clean_up(order_t orders[], unsigned order_cnt) {
    for (unsigned i = 0; i < order_cnt; i++) {
        free(orders[i].items);
    }
}

void sum_total_costs(order_t orders[], unsigned order_cnt) {
    int res, k = 0;
    for (int i = 0; i < order_cnt; i++) {
        orders[i].total_cost = 0;
        for (int w = 0; w < orders[i].item_cnt; w++)
            for (int j = 0; j < 15; j++) {
                // printf("orders[%d].items->item_name:%s\n", i, orders[i].items->item_name);
                res = strcmp(orders[i].items[w].item_name, avaliable_items[j].item_name);
                if (res == 0)
                    orders[i].total_cost += (avaliable_items[j].cost) * (orders[i].items[w].cnt);
            }
    }
}

void swap(order_t *x, order_t *y) {
    order_t tmp = *x;
    *x = *y;
    *y = tmp;
}

int clacTime(order_t a) {
    return (a.pick_up_time.hour) * 60 + (a.pick_up_time.minute);
}
void reorder(order_t orders[], unsigned order_cnt) {
    for (int i = 0; i < order_cnt; i++) {
        for (int j = i + 1; j < order_cnt; j++) {
            if (clacTime(orders[i]) > clacTime(orders[j])) {
                swap(&(orders[i]), &(orders[j]));
            }
        }
    }
}