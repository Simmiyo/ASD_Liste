#include <iostream>

using namespace std;

struct nod{int val;nod *urm;nod *ant;} *in=NULL,*sf=NULL;

void adaugare_inceput(int x)
{
    nod *q=new nod;
    q->val=x;
    if(in==NULL)
    {
        q->ant=NULL;
        q->urm=NULL;
        in=q;
        sf=q;
    }
    else
    {
        q->ant=NULL;
        q->urm=in;
        in->ant=q;
        in=q;
    }
}

void adaugare_sfarsit(int x)
{
    nod *q=new nod;
    q->val=x;
    if(sf==NULL)
    {
        q->ant=NULL;
        q->urm=NULL;
        in=q;
        sf=q;
    }
    else
    {
        q->ant=sf;
        q->urm=NULL;
        sf->urm=q;
        sf=q;
    }
}

void adaugare_interior(int x,int k)
{
    nod *q=new nod;
    q=in; int i=0;
    if(q!=NULL)
    {
        while(q->urm!=NULL && i<k)
        {
            q=q->urm;
            i++;
        }
        nod *el=new nod;
        el->val=x;
        if(i==0)
        {
            el->ant=NULL;
            el->urm=in;
            in->ant=el;
            in=el;
        }
        else if(i==k)
             {
                el->ant=q->ant;
                el->urm=q;
                q->ant->urm=el;
                q->ant=el;
             }
             else
             {
                el->urm=NULL;
                el->ant=sf;
                sf->urm=el;
                sf=el;
             }
    }
}

void afis1()
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
        cout<<q->val<<endl;
    }
    cout<<endl;
}

void afis2()
{
    nod *q=new nod;
    q=sf;
    if(q!=NULL)
    {
        while(q->ant!=NULL)
        {
            cout<<q->val<<" ";
            q=q->ant;
        }
        cout<<q->val<<endl;
    }
    cout<<endl;
}

void stergere_poz(int k)
{
    nod *q=new nod;
    q=in; int i=0;
    if(q!=NULL)
    {
        while(q->urm!=NULL && i<k)
        {
            q=q->urm;
            i++;
        }
        nod *el=new nod;
        if(i==0)
        {
            el=in;
            in=in->urm;
            delete el;
            in->ant=NULL;
        }
        else if(q->urm!=NULL)
             {
                 q->ant->urm=q->urm;
                 q->urm->ant=q->ant;
                 delete q;
             }
             else
                {
                    el=sf;
                    sf=sf->ant;
                    sf->urm=NULL;
                    delete el;
                }
    }
}

void stergere_val(int x)
{
    nod *q=new nod;
    q=in;
    if(q!=NULL)
    {
        while(q->urm!=NULL && q->val!=x)
            q=q->urm;
        nod *el=new nod;
        if(q->ant==NULL)
        {
            el=in;
            in=in->urm;
            delete el;
            in->ant=NULL;
        }
        else if(q->urm!=NULL)
             {
                 q->ant->urm=q->urm;
                 q->urm->ant=q->ant;
                 delete q;
             }
             else if(q->val==x)
                {
                    el=sf;
                    sf=sf->ant;
                    sf->urm=NULL;
                    delete el;
                }
    }
}

int main()
{
    int  x,i,k,c,n;
    bool ok=true;
    while(ok)
    {
        cout<<"Meniu:"<<endl;
        cout<<"1. Aduagati la inceput. "<<endl;
        cout<<"2. Adaugati la sfarsit. "<<endl;
        cout<<"3. Adaugati la interior. "<<endl;
        cout<<"4. Stergeti de la o pozitie. "<<endl;
        cout<<"5. Stergeti o valoare. "<<endl;
        cout<<"6. Afisare stanga-dreapta. "<<endl;
        cout<<"7. Afisare dreapta-stanga. "<<endl;
        cout<<"8. Exit." <<endl;
        cout<<"Introdueti caomanda: "; cin>>c; cout<<endl;
        switch(c)
        {
            case 1:
                cout<<"Introduceti nr de elemente: "; cin>>n;
                for(i=1;i<=n;i++)
                {
                    cin>>x;
                    adaugare_inceput(x);
                }
            break;
            case 2:
                cout<<"Introduceti nr de elemente: "; cin>>n;
                for(i=1;i<=n;i++)
                {
                    cin>>x;
                    adaugare_sfarsit(x);
                }
            break;
            case 3:
                cout<<"Introduceti pozitia pe care vreti sa adugati: "; cin>>k;
                cout<<"Introduceti valoarea pe care vreti sa o adugati: "; cin>>x;
                    adaugare_interior(x,k);
            break;
            case 4:
                cout<<"Introduceti pozitia de pe care vreti sa stergeti: "; cin>>k;
                    stergere_poz(k);
            break;
            case 5:
                cout<<"Introduceti valoare pe care vreti sa o stergeti: "; cin>>x;
                    stergere_val(x);
            break;
            case 6:
                afis1();
            break;
            case 7:
                afis2();
            break;
            case 8:
                ok=false;
            break;
            default:
                break;
        }
    }

    return 0;
}
