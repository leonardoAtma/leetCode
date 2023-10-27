#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int countNumberL1 = 0;
    ListNode *currentL1 = l1;
    while (true)
    {
        countNumberL1++;
        if (currentL1->next == nullptr)
        {
            break;
        }
        currentL1 = currentL1->next;
    }

    int arrL1[countNumberL1];
    currentL1 = l1;
    for (int i = 0; i < countNumberL1; i++)
    {
        arrL1[i] = currentL1->val;
        currentL1 = currentL1->next;
    }

    int countNumberL2 = 0;
    ListNode *currentL2 = l2;
    while (true)
    {
        countNumberL2++;
        if (currentL2->next == nullptr)
        {
            break;
        }
        currentL2 = currentL2->next;
    }
    int arrL2[countNumberL2];
    currentL2 = l2;
    for (int i = 0; i < countNumberL2; i++)
    {
        arrL2[i] = currentL2->val;
        currentL2 = currentL2->next;
    }

    int nextSum = 0;
    ListNode *_result = nullptr;
    int count = (countNumberL2 > countNumberL1) ? countNumberL2 : countNumberL1;
    printf("\ncount => %i\n", count);
    for (int i = 0; i < count; i++)
    {
        int val = 0;
        if (countNumberL2 > i)
        {
            printf("arrL2[%i] = %i", i, arrL2[i]);
            val += arrL2[i];
        }
        if (countNumberL1 > i)
        {
            printf(" + arrL1[%i] = %i", i, arrL1[i]);

            val += arrL1[i];
        }
        if (nextSum > 0)
        {
            val++;
        }
        printf(" == %i, index %i;\n", val, i);
        if (val >= 0)
        {
            if (val >= 10)
            {
                nextSum = 1;
                val -= 10;
            }
            else
            {
                nextSum = 0;
            }

            if (_result == nullptr)
            {
                _result = new ListNode(val);
            }
            else
            {
                ListNode *current = new ListNode(val, _result);
                _result = current;
            }
        }
    }
    if (nextSum > 0)
    {
        ListNode *current = new ListNode(1, _result);
        _result = current;
    }
    ListNode *_return = nullptr;
    ListNode *_currentReturn = nullptr;

    while (true)
    {
        if (_return == nullptr)
        {
            _return = new ListNode(_result->val);
            _currentReturn = _result->next;
        }
        if (_currentReturn == nullptr)
        {
            break;
        }
        else
        {
            int val = _currentReturn->val;
            _currentReturn = _currentReturn->next;
            ListNode *current = new ListNode(val, _return);
            _return = current;
        }
    }

    return _return;
}

int main()
{
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    printf("run");
    // ListNode *r = addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4))));
    ListNode *r = addTwoNumbers(l1, l2);

    ListNode *currentL1 = r;
    while (true)
    {
        printf("\n%i", currentL1->val);
        if (currentL1->next == nullptr)
        {
            break;
        }

        currentL1 = currentL1->next;
    }
    return 0;
}