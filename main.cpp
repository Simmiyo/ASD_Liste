#include <iostream>

using namespace std;

struct nod{int val;nod *ant;} *vf=NULL;

void push(int x)
{
    nod *q=new nod;
    if(vf==NULL)
    {
        q->val=x;
        q->ant=NULL;
        vf=q;
    }
    else
    {
        q->val=x;
        q->ant=vf;
        vf=q;
    }
}

void pop()
{
    if(vf!=NULL)
    {
        nod *q=new nod;
        q=vf;
        vf=vf->ant;
        delete q;
    }
}

int peak()
{
    if(vf!=NULL)
        return vf->val;
    return NULL;
}

bool emptyy()
{
    if(vf==NULL)
        return 1;
    return 0;
}

int searchh(int x)
{
    nod *q=new nod;
    q=vf; int i=0;
    if(q!=NULL)
    {
        while(q->ant!=NULL && q->val!=x)
        {
            q=q->ant;
            i++;
        }
        if(q->ant==NULL && q->val!=x)
            return -1;
        return i;
    }
    return -1;
}

void afis1()
{
    nod *q=new nod;
    q=vf;
    if(q!=NULL)
    {
        while(q->ant!=NULL)
        {
            cout<<q->val<<" ";
            q=q->ant;
        }
        cout<<q->val;
        cout<<endl;
    }
}

void afis2(struct nod *q)
{
    if(q!=NULL)
    {
        if(q->ant!=NULL)
            afis2(q->ant);
        cout<<q->val<<" ";
    }
}

int main()
{
    int i,n,x,k;
    cout<<"Introduceti nr de elem ce vor fi introduse in stiva: "; cin>>n;
    cout<<endl<<"Introduceti elementele in stiva: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        push(x);
    }
    afis1();
    pop();
    afis2(vf);
    cout<<"Varf: "<<peak()<<endl;
    cout<<"Ce valoare doriti sa cautati in stiva? "; cin>>x;
    k=searchh(x);
    cout<<"Pozitia valorii cautate: "k<<endl;
    if(emptyy()) cout<<"Stiva e vida.";
    return 0;
}
