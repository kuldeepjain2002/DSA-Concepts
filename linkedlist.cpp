#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

#define rep(i, n) for (long long int i = 0; i < n; i++)
#define repinv(i, n) for (long long int i = n - 1; i >= 0; i--)
#define for1(i, n) for (long long int i = 1; i <= n; i++)
#define loop(i, a, b, k) for (long long int i = a; i <= b; i = i + k)

#define pb push_back
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define uii unordered_map<int, int>
#define vc vector<char>
#define vb vector<bool>
#define vstr vector<string>
#define vd vector<double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define maxpq priority_queue<int, vector<int>>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vii vector<pair<int, int>>
#define vll vector<pair<long long, long long>>
#define mp make_pair

#define modulo 1000000007
#define longmodulo 1000000000000000000
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};
Node *rev(Node *list)
{
    Node *curr = list;
    while (curr->next)
    {
        Node *t1 = new Node(curr->next->val);
        t1->next = list;
        list = t1;
        curr->next = curr->next->next;
    }
    Node *c = list;
    // while(c){
    // cout<<c->val<<" ";
    // c=c->next;
    // }
    // cout<<endl;
    return list;
}

pair<Node *, Node *> revp(Node *list)
{
    Node *curr = list;
    while (curr->next)
    {
        Node *t1 = new Node(curr->next->val);
        t1->next = list;
        list = t1;
        curr->next = curr->next->next;
    }
    Node *c = list;
    // while(c){
    // cout<<c->val<<" ";
    // c=c->next;
    // }
    // cout<<endl;
    return {list, curr};
}

Node *revK(Node *list, int k)
{
    Node *curr = list;
    Node *head = list;
    Node *uh = NULL;
    Node *last = NULL;
    bool b = true;
    while (curr)
    {
        for (int i = 0; (i < k - 1 && curr); i++)
        {
            curr = curr->next;
        }
        if (!curr)
        {
            pair<Node *, Node *> pa = revp(head);
            last->next = pa.first;
            last = pa.second;
            last->next = NULL;
            break;
        }
        else
        {
            Node *h = curr->next;
            curr->next = NULL;
            pair<Node *, Node *> pa = revp(head);
            if (b)
            {
                b = false;
                uh = pa.first;
                last = pa.second;
            }
            else
            {
                last->next = pa.first;
                last = pa.second;
            }

            curr = h;
            head = curr;
            // cout<<curr->val<<"h"<<endl;
        }
    }
    return uh;
}

Node *mid(Node *list)
{
    if (!list)
    {
        cout << "none" << endl;
        ;
    }
    Node *slow = list;
    Node *fast = list;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void isPalindrome(Node *list)
{
    Node *middle = mid(list);
    // cout<<middle->val<<endl;
    Node *temp = list;
    while (temp->next != middle)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    middle = rev(middle);
    Node *l1 = list;
    Node *l2 = middle;
    bool b = true;
    while (middle && list)
    {
        // cout<<list->val<<" "<< middle->val<<endl;
        if (list->val != middle->val)
        {
            b = false;
            cout << "NO PL" << endl;
            break;
        }
        middle = middle->next;
        list = list->next;
    }
    if (b)
    {
        cout << "YES PL" << endl;
    }
}

void removeDuplicates(Node *list)
{
    Node *prev = list;
    Node *curr = list->next;
    while (curr)
    {
        if (prev->val == curr->val)
        {
            curr = curr->next;
            prev->next = curr;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
}

void printt(Node *list)
{
    Node *temp = list;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void swp(Node *list, int k)
{
    Node *s = list;
    Node *f = list;
    for (int i = 0; i < k - 1; i++)
    {
        f = f->next;
    }
    Node *n1 = f;
    while (f->next)
    {
        s = s->next;
        f = f->next;
    }
    Node *n2 = s;
    int temp = n1->val;
    n1->val = n2->val;
    n2->val = temp;
}

Node *oddeve(Node *list)
{
    Node *odd = list;
    Node *eve = list->next;
    Node *evestart = eve;
    Node *oddstart = odd;
    while (eve->next && eve->next->next)
    {
        odd->next = eve->next;
        odd = odd->next;
        eve->next = odd->next;
        eve = eve->next;
    }
    if (eve->next)
    {
        odd->next = eve->next;
        odd = odd->next;
        eve->next = NULL;
    }
    odd->next = evestart;
    return oddstart;
}
void swppair(Node *list)
{
    if (!list->next)
    {
        return;
    }
    Node *odd = list;
    Node *eve = list->next;
    int t = odd->val;
    odd->val = eve->val;
    eve->val = t;
    // Node* evestart = eve;
    // Node* oddstart = odd;
    while (eve->next && eve->next->next)
    {

        odd = eve->next;
        // odd= odd->next;
        eve = odd->next;
        // eve = eve->next;
        int t = odd->val;
        odd->val = eve->val;
        eve->val = t;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Node *list = NULL;
    Node *temp = new Node(v[0]);
    list = temp;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node(v[i]);
        temp->next = t;
        temp = temp->next;
    }

    removeDuplicates(list);
    printt(list);
    swp(list, 2);
    printt(list);
    Node *od = oddeve(list);
    printt(od);
    swppair(list);
    printt(list);

    Node *of = revK(list, 3);
    printt(of);
    return 0;
}