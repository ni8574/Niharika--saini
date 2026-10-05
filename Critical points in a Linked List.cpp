int solve(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return 0;

    int count = 0;

    Node* prev = head;
    Node* curr = head->next;
    Node* next = curr->next;

    while (next != nullptr) {
        if ((curr->data > prev->data && curr->data > next->data) ||
            (curr->data < prev->data && curr->data < next->data)) {
            count++;
        }

        prev = curr;
        curr = next;
        next = next->next;
    }

    return count;
}
