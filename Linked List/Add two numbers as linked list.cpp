/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* ans = new Node();
    Node* head = ans;
    int carry = 0;
    while(num1 or num2 or carry){
        int sm = 0;
        if(num1){
            sm += num1-> data;
            num1 = num1->next;
        }
        if(num2){
            sm += num2-> data;
            num2 = num2->next;
        }
        
        sm +=carry;
        carry = sm/10;
        Node* newnode = new Node(sm%10);
        ans->next = newnode;
        ans = ans -> next;
    }
    return head->next;
}
