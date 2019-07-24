#include <iostream>

using namespace std;

struct nod{int val;nod *ant;nod *urm;} *in=NULL,*sf=NULL;

void push(int x)
{
    nod *q=new nod;
    if(in==NULL)
    {
        q->val=x;
        q->urm=NULL;
        q->ant=NULL;
        in=q;
        sf=q;
    }
    else
    {
        q->val=x;
        q->urm=in;
        q->ant=NULL;
        in->ant=q;
        in=q;
    }
}

void pop()
{
    if(in!=NULL)
    {
        nod *q=new nod;
        sf->ant->urm=NULL;
        q=sf;
        sf=sf->ant;
        delete q;
    }
}

int peak()
{
    if(in!=NULL)
        return in->val;
    return NULL;
}

bool emptyy()
{
    if(in==NULL)
        return 1;
    return 0;
}

int searchh(int x)
{
    nod *q=new nod;
    q=in; int i=0;
    if(q!=NULL)
    {
        while(q->urm!=NULL && q->val!=x)
        {
            q=q->urm;
            i++;
        }
        if(q->urm==NULL && q->val!=x)
            return -1;
        return i;
    }
    return -1;
}

void afis()
{
    nod *q=new nod;
    q=in;
    if(q!=NULL)
    {
        while(q->urm!=NULL)
        {
            cout<<q->val<<" ";
            q=q->urm;
        }
        cout<<q->val;
        cout<<endl;
    }
}

int main()
{
    int i,n,x,k;
    cout<<"Introduceti nr de elem ce vor fi introduse in coada: "; cin>>n;
    cout<<endl<<"Introduceti elementele in coada: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        push(x);
    }
    afis();
    pop();
    cout<<"Inceput: "<<peak()<<endl;
    cout<<"Ce valoare doriti sa cautati in coada? "; cin>>x;
    k=searchh(x);
    cout<<"Pozitia valorii cautate: "<<k<<endl;
    if(emptyy()) cout<<"Coada e vida.";
    return 0;
}
