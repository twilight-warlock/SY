// while(currNode->data != inputVal){
//     prevNode = currNode;
//     currNode = currNode->next;
// }
// prevNode->next = currNode->next;
// currNode->next = null;
Node *prevNode, *delNode;

prevNode = head;

While(prevNode->next->data != delData)

    prevNode = prevNode->next;

delNode = prevNode->next;

prevNode->next = delNode->next;

Int x = delNode->data;

delNode->next = NULL;

Free(delNode);

Return x;