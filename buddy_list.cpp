#include <bits/stdc++.h>
using namespace std;

class slnode
{
	int info;
	slnode *next;
	public:
		slnode() {
			info = 0;
			next = NULL;
		}
		slnode(int x, slnode *p){
			info = x;
			next = p;
		}
};

class singlell
{
	slnode *head;
	int count;
	public:
		singlell() {
			head = NULL;
			count = 0;
		}
		singlell(slnode *p, int x)
		{
			head = p;
			count = x;
		}

		void insertBeg(int x);
		void insertMid(int x,int i);
		void insertEnd(int x);

		void delbeg();
		void delmid(int i);
		void delend();

		bool isEmpty();
		bool search(int x);
		void display();
		int F();

		~singlell()
		{
			slnode *p=head;
			while(p!=NULL)
			{
				head=p->next;
				delete[] p;
				p=head;

			}
			//cout<<"List Destructor!\n";
		}
};

int singlell::F()
{
	return head->info;
}

bool singlell::isEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
}

void singlell::insertBeg(int x)
{
	head=new slnode(x,head);
	count++;
	//cout<<x<<" has been inserted!\n";
}

void singlell::delbeg()
{
	if(!count)
	{
		cout<<"Underflow!\n";
		return;
	}
	slnode* temp=head;
	head=head->next;
	//cout<<temp->info<<" has been deleted!\n";
	delete[] temp;
	count--;
}

bool singlell::search(int x)
{
	slnode *temp=head;
	while(temp!=NULL)
	{
		if(temp->info == x)
			return true;
		temp=temp->next;
	}
	return false;
}

void singlell::display()
{
	cout<<"["<<count<<"]"<<"->";
	slnode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->info<<"->";
		temp=temp->next;
	}
	cout<<"|||---\n";
}

void singlell::delend()
{
	slnode *temp=head;
	if(count==0)
	{
		cout<<"Underflow!\n";
		return;
	}
	else if(count==1)
	{
		head=NULL;
		count--;
		return;
	}

	while(temp->next->next!=NULL)
		temp=temp->next;
	slnode *a=temp->next;
	temp->next=NULL;
	count--;
	delete [] a;
}
void singlell::insertEnd(int x)
{
	slnode *temp=new slnode(x,NULL);
	slnode *t=head;
	if(count==0)
		head=temp;
	else
	{
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
	count++;
}


class Hash
{
	public:
		singlell *H;
		int M;

	Hash(int x)
	{
		H=new singlell[x];
		M=x;
	}
	
	void Hash_insert(int x,int val);
	bool hisempty(int x);
	void Del(int x);
	int HF(int x);
	void Hash_display();
};

int Hash::HF(int x)
{
	return H[x].F();
}

void Hash::Hash_insert(int x,int val)
{
	H[x].insertBeg(val);
}

void Hash::Hash_display()
{
	for(int i=0;i<M;i++)
	{
		cout<<"Index : "<<i<<" = ";
		H[i].display();
	}
}
void Hash::Del(int x)
{
	H[x].delbeg();
}

bool Hash::hisempty(int x)
{
	if(H[x].isEmpty())
		return true;
	else
		return false;
}


int main()
{
	Hash H(11);
	H.Hash_insert(10,0);
	vector <pair<int,int>> V;
	for(int j=0;j<5;j++)
	{
		int n;
		cin>>n;

		n=ceil(log(n)/log(2));
		int i=n;

		while(H.hisempty(i))
			i++;
		while(pow(2,i)!=pow(2,n))
		{
			int x=H.HF(i);
			H.Del(i);
			H.Hash_insert(i-1,x+pow(2,i-1));
			H.Hash_insert(i-1,x);
			i--;
		}
		int y=H.HF(i);
		V.push_back(make_pair(y,y+pow(2,i)-1));
		H.Del(i);
	}
	for(int i=0;i<5;i++)
		cout<<V[i].first<<" "<<V[i].second<<"\n";
		H.Hash_display();


}