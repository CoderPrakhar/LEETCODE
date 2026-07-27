/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* next=curr->next;
            if(curr->child!=NULL){
                //flatten the child nodes
                
                curr->next=flatten(curr->child);
                curr->next->prev=curr;

                curr->child=NULL; //CONNECTION BREAK
            

            //FIND TAIL
            while(curr->next!=NULL){
                curr=curr->next; //UPDATE
            }

            //ATTACH TAIL WITH NEXT PTR
            if(next!=NULL){
                curr->next=next;
                next->prev=curr;
            }
            }
            curr=curr->next;
        }
        return head;
    }
};