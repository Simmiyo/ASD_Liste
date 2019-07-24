#include <iostream>

using namespace std;

struct nod{int val;int pr;nod *urm;} *n=NULL;

void push(int x,int p)
{
    nod *q=new nod;
    q->val=x;
    q->pr=p;
    if(n==NULL)
    {
        q->urm=NULL;
        n=q;
    }
    else
    {
        q->urm=n;
        n=q;
    }
}

void pop1()
{
    int minim=n->pr;
    nod *q=new nod;
    nod *el=new nod;
    nod *prec=new nod;
    q=n; prec=NULL;
    while(q!=NULL)
    {
        if(minim>=q->pr)
        {
            minim=q->pr;
            el=prec;
        }
        prec=q;
        q=q->urm;
    }
    if(el==NULL)
        {
            nod *aux=n;
            n=n->urm;
            delete aux;
        }
    else if(el->urm->urm!=NULL)
        {
            nod *aux=el->urm;
            el->urm=el->urm->urm;
            delete aux;
        }
        else
        {   nod *aux=el->urm;
            el->urm=NULL;
            delete aux;
        }
}


void pop2()
{
    nod *minim=n;
    nod *q=new nod;
    nod *el=new nod;
    nod *prec=new nod;
    q=prec=n;
    while(q!=NULL)
    {
        if(minim->pr>=q->pr)
        {
            minim=q;
            el=prec;
        }
        prec=q;
        q=q->urm;
    }
    if(minim==el)
    {
        nod *aux=n;
        n=n->urm;
        delete aux;
    }
    else if(minim->urm!=NULL)
        {
            el->urm=el->urm->urm;
            delete minim;
        }
        else
        {
            el->urm=NULL;
            delete minim;
        }
}

void afis()
{
    if(n!=NULL)
    {
        nod *q=n;
        while(q->urm!=NULL)
        {
            cout<<q->val<<"-"<<q->pr<<" ";
            q=q->urm;
        }
        cout<<q->val<<"-"<<q->pr<<endl;
    }
}

int main()
{
    int n,i,x,z;
    cout<<"Introduceti nr valorilor care vor fi introduse: "; cin>>n;
    cout<<"Introduceti valorile care vor fi introduse si prioritatile lor: ";
    for(i=1;i<=n;i++)
    {
        cin>>x>>z;
        push(x,z);
    }
    afis();
    pop1();
    afis();
    pop2();
    afis();
    return 0;
}
