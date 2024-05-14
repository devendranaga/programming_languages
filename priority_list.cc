#include <cstdint>
#include <iostream>

template <typename T>
struct priority_item {
    uint32_t priority;
    T *data;
};

template <typename T>
struct priority_list {
    priority_item<T> item;
    priority_list *next;
};

template <typename T>
class prio_list_impl {
    public:
        explicit prio_list_impl() : head(nullptr), tail(nullptr) { }
        ~prio_list_impl() {
            if (!head)
                return;

            priority_list<T> *r;

            while (head) {
                r = head;
                head = head->next;
                free(r);
            }
            head = nullptr;
            tail = nullptr;
        }

        int add(T *i, int p);
        void print();

    private:
        priority_list<T> *head, *tail;
};

template <typename T>
int prio_list_impl<T>::add(T *i, int p)
{
    priority_list<T> *t;

    t = (priority_list<T> *)calloc(1, sizeof(priority_list<T>));
    if (!t)
        return -1;

    t->item.priority = p;
    t->item.data = i;

    if (!head) {
        head = t;
        tail = t;
    } else {
        priority_list<T> *it, *it_o;

        it = it_o = head;

        if (it->item.priority > p) {
            t->next = head;
            head = t;
        } else {
            while (it) {
                if (it->item.priority > p) {
                    it_o->next = t;
                    t->next = it;
                    break;
                }
                it_o = it;
                it = it->next;
            }
        }
    }

    return 0;
}

template <typename T>
void prio_list_impl<T>::print()
{
    priority_list<T> *t;

    for (t = head; t != nullptr; t = t->next) {
        printf("t->priority %d->%d\n", t->item.priority, *(t->item.data));
    }
}


int main()
{
    int a[10] = {9, 1, 2, 3, 10, 12, 4};
    prio_list_impl<int> p;

    p.add(&a[0], 10);
    p.add(&a[1], 1);
    p.add(&a[2], 2);
    p.add(&a[3], 3);
    p.add(&a[4], 6);
    p.add(&a[5], 5);

    p.print();

    return 0;
}
