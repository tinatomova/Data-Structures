/*
*
Problem:
https://www.hackerrank.com/contests/sda-hw-4/challenges/find-the-merge-point-of-two-joined-linked-lists
*
*/

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
if(head1==head2){
        return head1->data;
    }
    int size1=0,size2=0;
    SinglyLinkedListNode* last1=head1;
    SinglyLinkedListNode* last2=head2;
    while(last1!=nullptr){
        last1=last1->next;
        size1++;
    }
    while(last2!=nullptr){
        last2=last2->next;
        size2++;
    }
    if(size1>size2){
        for(int i=0;i<size1-size2;i++){
            head1=head1->next;
        }
    }
    if(size2>size1){
        for(int i=0;i<size2-size1;i++){
            head2=head2->next;
        }
    }   
    while(head1!=head2&&head1->next!=nullptr){
        head1=head1->next;
        head2=head2->next;
    }
    return head1->data;
}