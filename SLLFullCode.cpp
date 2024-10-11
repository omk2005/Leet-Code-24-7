//SLL
#include <iostream>
using std::cout, std::swap, std::endl, std::string;
#include <vector>
using std::vector;
#include <algorithm>

class Node
{
    public:
        int val;
        Node *next;
        Node(int v, Node *next)
        {
            this->val = v;
            this->next = next;
        }
};

class List
{
    private:
        Node *head;
        Node *tail;
    public:
        List()
        {
            head = tail = nullptr;
        }
        ~List()
        {
            Node *cur = head;
            Node *delnode;
            while (cur != nullptr)
            {
                delnode = cur;
                cur = cur->next;
                delete delnode;
            }
        }
        Node* getHead() const;//
        Node* getTail() const;//
        Node* getMiddleNode() const;//
        bool isEmpty() const;//
        bool contains(int val) const;//
        void addToHead(int val);//
        void addToTail(int val);//
        void Insert(int pos, int val);
        void remove_head();//
        void remove_tail();//
        bool remove(int val);//
        int removeAllOccurs(int val);  //Removes and returns count of val
        void removeDuplicate();//
        int deletePos(int pos); //
        Node* rev(Node *node);   //for palindrome function only
        bool palindrome(); //
        int getSize() const;//
        int get_max() const;//
        bool isSorted() const;//
        void selection_sort();//
        bool check_seq(int k, int val) const;//
        bool check_seq3(int val) const;//
        void Update(int ind, int val);
        int getAt(int ind) const;
        void Reverse();    // Actually reverses the list
        void print() const;//
        void printOdd() const; //
        void printEven() const;//
        void printrev(Node* node);    // basic reverse print without format
        void print_reverse(Node* i);         // Only prints the list in reverse
};

bool List::isEmpty() const {return head == NULL;}

Node* List::getHead() const {return head;}

Node* List::getTail() const {return tail;}

int List::getSize() const
{
    int cnt = 0;
    //Loop until current node doesn't point to null pointer
    for (Node *i = head; i != nullptr; i = i->next)
        cnt += 1;
    return cnt;
}

bool List::isSorted() const
{
    if (head==tail)   //if less than 2 elements
        return true;
    for (Node *i = head; i != tail; i = i->next)
    {
        if (i->val > i->next->val)
            return false;
    }
    return true;
}

void List::addToHead(int val)
{
    Node *newn = new Node(val, head);
    if (tail == nullptr)
        tail = newn;
    head = newn;
}

void List::addToTail(int val)
{
    Node *newn = new Node(val, nullptr);
    if (head == nullptr)
        head = newn;
    else
        tail->next = newn;
    tail = newn;
}

void List::Insert(int pos, int val)     //head check, cnt = 1, cnt<=index
{
    if (pos < 0)
        throw string("Index error: below 0.\n");
    if (pos == 0)
    {
        addToHead(val);
        return;
    }
    Node *i = head, *j = head->next;
    int cnt = 1;  //head is already passed
    while (j != nullptr && cnt<=pos)
    {
        if (cnt == pos)
        {
            i->next = new Node(val, j);
            return;
        }
        i = i->next;
        j = j->next;
        cnt += 1;
    }
    if (i != nullptr)
        addToTail(val);
    else
        throw string("Index error: too high.\n");
}

void List::remove_head()
{
    if (head == nullptr)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr)
        tail = nullptr;
}

void List::remove_tail()
{
    if (head == nullptr)
        return;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != tail)
        temp = temp->next;
    delete tail;
    temp->next = nullptr;
    tail = temp;
}

bool List::remove(int val)
{
    if (isEmpty())
        return false;
    if (val == head->val)
    {
        remove_head();
        return true;
    }
    if (val == tail->val)
    {
        remove_tail();
        return true;
    }
    Node *cur = head;
    Node *temp = head->next;
    while (temp != tail)
    {
        if (temp->val == val)
        {
            cur->next = temp->next;
            delete temp;
            return true;
        }
        temp = temp->next;
        cur = cur->next;
    }
    return false;
}

int List::removeAllOccurs(int v)
{
    int cnt = 0;
    if (head == nullptr)
        return cnt;
    while (head->val == v)
    {
        remove_head();
        cnt += 1;
    }
    if (head == tail)
        return cnt;
    Node *i = head;
    while (i->next !=nullptr)
    {
        if (i->next->val == v)
        {
            cnt += 1;
            Node *j = i->next;
            i->next = i->next->next;
            delete j;
            if (i->next == nullptr)
                tail = i;
            continue;
        }
        i = i->next;
    }
    return cnt;
}

void List::removeDuplicate()    //O(n) using vector
{
    if (head == tail)
        return;
    vector<int>v;
    v.push_back(head->val);
    Node *i = head;
    while (i->next != nullptr)
    {
        if (find(v.begin(), v.end(), i->next->val) != v.end())
        {
            Node *j = i->next;
            i->next = i->next->next;
            delete j;
            if (i->next == nullptr)
                tail = i;
            continue;
        }
        v.push_back(i->next->val);
        i = i->next;
    }
}

int List::deletePos(int pos)     //head check, cnt = 1, cnt<=index
{
    if (head==nullptr || pos<0)
        throw string("\nError!\n");
    int num;
    if (pos == 0)
    {
        num = head->val;
        remove_head();
        return num;
    }
    int cnt = 1;
    Node *i = head;
    while (i->next!=nullptr && cnt<=pos)
    {
        if (cnt == pos)
        {
            Node *j = i->next;
            i->next = i->next->next;
            num = j->val;
            delete j;
            if (i->next == nullptr)
                tail = i;
            return num;
        }
        cnt += 1;
        i = i->next;
    }
    throw string("\nError!\n");
}

Node* List::getMiddleNode() const
{
    if (head == nullptr)
        throw string("Error");
    if (head == tail)
        return head;
    int mid = 1;     //Middle node number, can omit this step tbh
    Node *i = head, *j = head->next;
    while (j!=nullptr && j->next!=nullptr)
    {
        mid += 1;
        i = i->next;
        j = j->next->next;
    }
    return i;
}

Node* List::rev (Node *curr)     //palindrome
{
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool List::palindrome()
{
    if (head == nullptr)
        return false;
    if (head == tail)
        return true;
    Node *mid = head, *fast = head->next;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        mid = mid->next;
        fast = fast->next->next;
    }
    Node *headdd = rev(mid->next);
    mid->next = nullptr;
    bool flag = true;
    Node *i = head;
    Node *j = headdd;
    while (i!=nullptr && j!=nullptr)
    {
        if (i->val != j->val)
        {
            flag = false;
            break;
        }
        i = i->next;
        j = j->next;
    }
    mid->next = rev(headdd);
    return flag;
}

bool List::contains(int val) const
{
    for (Node *i = head; i != nullptr; i = i->next)
        if (i->val == val)
            return true;
    return false;
}

int List::get_max() const
{
    if (head == nullptr)
        throw string("Error, empty list.\n");
    int maxi = head->val;
    for (Node *i = head->next; i != nullptr; i = i->next)
    {
        if (i->val > maxi)
            maxi = i->val;
    }
    return maxi;
}

void List::selection_sort()
{
    for (Node *i = head; i != tail; i = i->next)
    {
        Node *mini = i;
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (j->val < mini->val)
                mini = j;
        }
        if (mini != i)
            swap(mini->val, i->val);
    }
}

bool List::check_seq(int k, int val) const
{
    if (k==0)
        return true;
    if (k<0)
        return false;
    int cnt = 0;
    for (Node *i = head; i != nullptr; i = i->next)
    {
        if (i->val == val)
            cnt += 1;
        else
            cnt = 0;
        if (cnt == k)
            return true;
    }
    return false;
}

bool List::check_seq3(int val) const
{
    if (head == tail || head->next == tail)
        return false;
    Node *i = head;
    while (i->next->next != nullptr)
    {
        if (i->val==val && i->next->val==val && i->next->next->val==val)
            return true;
        i = i->next;
    }
    return false;
}

int List::getAt(int ind) const     //no head check, cnt = 0, cnt!=index
{
    if (head==nullptr || ind<0)
        throw string("Error, invalid request.\n");
    Node *i = head;
    int cnt = 0;
    while (i!=nullptr && cnt!=ind)
    {
        i = i->next;
        cnt += 1;
    }
    //if (cnt == ind)
        //return tail->val;
    if (i!=nullptr)
        return i->val;
    throw string("Error, index exceeds limit.\n");
}

void List::Update(int ind, int val)     //no head check, cnt = 0, cnt!=index
{
    if (head==nullptr || ind<0)
        throw string("Error, invalid request.\n");
    Node *i = head;
    int cnt = 0;
    while (i!=nullptr && cnt!=ind)
    {
        i = i->next;
        cnt += 1;
    }
    //if (cnt == ind)
        //return tail->val;
    if (i!=nullptr)
        i->val = val;
    else
        throw string("Error, index exceeds limit.\n");
}

void List::Reverse()
{
    Node *prev = nullptr, *cur = head;
    while (cur != nullptr)
    {
        Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    swap(head, tail);
}

void List::print() const
{
    cout<<"\n[";
    for (Node* i = head; i != nullptr; i = i->next)
    {
        cout<<i->val;
        if (i->next != nullptr)
            cout<<", ";
    }
    cout<<"]\n";
}

void List::printOdd() const
{
    cout<<"\n[";
    for (Node *i = head; i != nullptr; i = i->next->next)
    {
        cout<<i->val;
        if (i->next == nullptr || i->next->next == nullptr)
            break;
        cout<<", ";
    }
    cout<<"]\n";
}

void List::printEven() const
{
    if (head==tail)
    {
        cout<<"\n[]\n";
        return;
    }
    cout<<"\n[";
    for (Node *i = head->next; i != nullptr; i = i->next->next)
    {
        cout<<i->val;
        if (i->next == nullptr || i->next->next == nullptr)
            break;
        cout<<", ";
    }
    cout<<"]\n";
}

void List::printrev(Node* node)
{
    if (node == nullptr)
        return;
    printrev(node->next);
    cout<<node->val<<" ";
}

void List::print_reverse(Node *i)
{
    if (head == nullptr)
    {
        cout<<"\n[]\n";
        return;
    }
    if (i == tail)
        cout<<"\n[";
    else if (i == nullptr)
        return;
    print_reverse(i->next);
    cout<<i->val;
    if (i == head)
        cout<<"]\n";
    else
        cout<<", ";
}

int main()
{
    List L1;
    L1.addToHead(18);
    L1.addToHead(16);
    for (int i=1; i<=5; i++)
        L1.addToHead(i);
    for (int j=7; j>=3; j--)
        L1.addToTail(j);
    L1.addToHead(4);
    L1.addToTail(14);
    L1.addToTail(5);
    cout<<"Print";
    L1.print();
    cout<<"\nRemoving duplicates:";
    L1.removeDuplicate();
    L1.print();
    cout<<"\nInsert 5 at index 9: ";
    L1.Insert(9, 5);
    L1.print();
    if (L1.palindrome())
        cout<<"\nYes, a palindrome.\n";
    else
        cout<<"\nNo, not a palindrome.\n";
    cout<<"\nMiddle node = "<<(L1.getMiddleNode())->val<<endl;
    cout<<"Head: "<<L1.getHead()->val<<"\nTail: "<<L1.getTail()->val<<endl;
    //cout<<"L1[10] = "<<L1.getAt(10);
    cout<<"\nPrinting even elements:";
    L1.printEven();
    L1.selection_sort();
    L1.print();
    int cnt = L1.removeAllOccurs(5);
    cout<<"\nNumber of 5s removed = "<<cnt<<endl;
    cout<<endl<<L1.getTail()->val<<endl<<endl;
    if (L1.check_seq(2, 4))
        cout<<"\nYes\n";
    else
        cout<<"\nNo\n";
    L1.print_reverse(L1.getHead());
    //L1.Reverse();
    //L1.print();
    return 0;
}
