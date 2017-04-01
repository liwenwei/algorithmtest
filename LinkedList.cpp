#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

/*
* Delete Node in a Linked List
*/
void deleteNode(ListNode* node)
{
    ListNode* next = node->next;
    *node = *next;
    delete next;
}

/*
* Reverse a singly linked list
*/
ListNode* reserveList1(ListNode* head)
{
    ListNode* prev = NULL;
    while (head)
    {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/*
* 4->2->3->6
* => 2->4
* => 3->2->4
* => 6->3->2->4
*/
ListNode* reserveList(ListNode* head)
{
    ListNode* new_head = NULL;
    ListNode* curr = head;
    ListNode* temp = NULL;
    while (curr)
    {
        temp = new_head;
        new_head = curr;
        curr = curr->next;
        new_head->next = temp;
    }
    return new_head;
}

/*
* Reverse part of the linked list from m to n
* 1->2->3->4->5, m=2, n=4
* output: 1->4->3->2->5
*/
ListNode* reservePartList(ListNode* head, int m, int n)
{
    int i = 0;
    while (true)
    {

    }
}

/*
* Remove the duplicate node from sorted list
* 1->2->2->4->5
* output: 1->2->4->5
*/
void deleteDuplicates(ListNode* head)
{
    ListNode* curr = head;
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void deleteDuplicates1(ListNode* head)
{
    ListNode* curr = head;
    ListNode* temp = NULL;
    while (curr)
    {
        temp = curr;
        while (temp && temp->next && temp->val == temp->next->val)
        {
            temp = temp->next;
        }
        curr->next = temp->next;
        curr = curr->next;
    }
}

/*
* fast pointer & slow pointer
*/
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL) return false;
    ListNode *pSlow = head;
    ListNode *pFast = head->next;
    while (pSlow != pFast)
    {
        if (pFast == NULL || pFast->next == NULL) return false;
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }

    return true;
}

/*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
**/
ListNode* swapPairs1(ListNode* head)
{
    if (head == NULL || head->next == NULL) return head;

    ListNode *node = head->next;
    head->next = swapPairs1(head->next->next);
    node->next = head;

    return node;
}

ListNode* swapPairs(ListNode* head)
{
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *node = head;
    ListNode *newHead = head->next;

    while (node != NULL && node->next != NULL)
    {
        ListNode *temp = node;
        node = node->next;
        temp->next = node->next;
        node->next = temp;
        node = temp->next;
        if (node != NULL && node->next != NULL) temp->next = node->next;
    }

    return newHead;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(2);
    ListNode* forth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = forth;

    ListNode* result = swapPairs(head);
    deleteDuplicates(head);
    deleteDuplicates1(head);
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
}

