/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-4/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
*
*/

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(position==0){
        SinglyLinkedListNode* n;
        n->data=data;
        n->next=llist;
        return n;
    }
    SinglyLinkedListNode* cur=llist;
    SinglyLinkedListNode* pr=nullptr;
    for(int i=0;i<position;i++){
        if(cur!=nullptr){
            pr=cur;
            cur=cur->next;
        }
    }
    SinglyLinkedListNode* toadd= new SinglyLinkedListNode(data);
    toadd->next=cur;
    pr->next=toadd;
    return llist;
}