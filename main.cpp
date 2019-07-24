#include <iostream>

using namespace std;

struct nod{int val;struct nod *urm;};

struct nod *n = NULL;

void adaugare_final(int x)
{
    struct nod *q=new nod;
    if(n==NULL)
    {
        q->val=x;
        q->urm=NULL;
        n=q;
    }
    else
    {
        q=n;
        while(q->urm!=NULL)
        {
            q=q->urm;
        }
        struct nod *el=new nod;
        el->val=x;
        el->urm=NULL;
        q->urm=el;
    }
}

void adaugare_inceput(int x)
{
    struct nod *q=new nod;
    if(n==NULL)
    {
        q->val=x;
        q->urm=NULL;
        n=q;
    }
    else
    {
        q->val=x;
        q->urm=n;
        n=q;
    }
}

void adaugare_pozitie(int x,int k)
{
    nod *q=new nod;
    if(n==NULL)
    {
        q->val=x;
        q->urm=NULL;
        n=q;
    }
    else
    {
        q=n; int i=1;
        while(q->urm!=NULL && i<k-1)
        {
            q=q->urm;
            i++;
        }
        nod *el=new nod;
        el->val=x;
        if(q==n && k!=2)
        {
            el->urm=q;
            n=el;
        }
        else
        {
            el->urm=q->urm;
            q->urm=el;
        }

    }
}

int cautare_val(int x)
{
    nod *q=new nod;
    q=n; int i=1;
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

int cautare_poz(int k)
{
    nod *q=new nod;
    q=n; int i=1;
    if(q!=NULL && k>0)
    {
        while(q->urm!=NULL && i<k)
        {
            q=q->urm;
            i++;
        }
        if(q->urm==NULL && i!=k)
            return -1;
        return q->val;
    }
    return -1;
}

void stergere_val(int x)
{
    nod *q=new nod;
    nod *p=new nod;
    q=n;
    if(q!=NULL)
    {
        while(q->urm!=NULL && q->val!=x)
            {
                p=q;
                q=q->urm;
            }
        if(q->val==x)
        {
            if(q==n)
                n=q->urm;
            else
                p->urm=q->urm;
            delete q;
        }
    }
}

void stergere_val0(int x)
{
    struct nod *q=n;
    if(q!=NULL)
    {
	if(q->val==x)
	{
	    n=q->urm;
	    delete q;	
	}
	else
	{
	    while(q->urm!=NULL && q->urm->val!=x)
	        q=q->urm;
	    if(q->urm!=NULL)
	    {
		struct nod *el=q->urm;
		q->urm=q->urm->urm;
		delete el;
	    }
	}
    }
}

void stergere_poz(int k)
{
    nod *q=new nod;
    nod *p=new nod;
    q=n; int i=1;
    if(q!=NULL)
    {
        while(q->urm!=NULL && i<k)
            {
                p=q;
                q=q->urm;
                i++;
            }
        if(i==k)
        {
            if(q==n)
                n=q->urm;
            else
                p->urm=q->urm;
            delete q;
        }
    }
}

void stergere_totala()
{
    nod *q=new nod;
    while(n!=NULL)
        {
            q=n;
            n=q->urm;
            delete q;
        }
}

void afis()
{
    struct nod *i=new nod;
    i=n;
    if(i!=NULL)
    {
        while(i->urm!=NULL)
        {
            cout<<i->val<<" ";
            i=i->urm;
        }
        cout<<i->val<<endl;
    }
}

int main()
{
    int i,n,x,k;
    cout<<"Introduceti numarul de valori care vor fi adaugate: "<<endl; cin>>n;
    cout<<"Introduceti valorile elementelor care vor fi adaugate: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2==1)
            adaugare_final(x);
        else adaugare_inceput(x);
    }
    afis();
    cout<<"Introduceti pozitia pe care vreti sa introduceti alt element: "<<endl; cin>>k;
    cout<<"Introduceti valoarea pe care vreti sa o adaugati: "<<endl; cin>>x;
    adaugare_pozitie(x,k);
    afis();
    cout<<"Introduceti valoarea cautata: "<<endl; cin>>x;
    cout<<"Element gasit pe pozitia: "<<cautare_val(x)<<endl;
    cout<<"Introduceti pozitia cautata: "<<endl; cin>>k;
    cout<<"Valoarea elementului de pe pozitia indicata: "<<cautare_poz(k)<<endl;
    cout<<"Introduceti valoarea pe care vreti sa o stergeti: "<<endl; cin>>x;
    stergere_val(x);
    afis();
    cout<<"Introduceti pozitia de pe care vreti sa stergeti: "<<endl; cin>>k;
    stergere_poz(k);
    afis();
    stergere_totala();
    afis();
    return 0;
}
