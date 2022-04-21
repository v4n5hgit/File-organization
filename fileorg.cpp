#include<bits/stdc++.h>
using namespace std;
int size;

struct page
{
    vector<int> a;
    int free;
};

struct heaps
{
    vector<page> b;
    int pages;
};

heaps h;

void newpage(void){
    page c;
    for(int i = 0; i < size; i++)
        c.a.push_back(0);
    c.a[size - 1] = 0;
    c.a[size - 9] = h.pages - 1;
    c.a[size - 13] = 0;
    c.free = size  - 16;
    h.b[h.pages - 1].a[size - 5] = h.pages;
    h.b.push_back(c);
    h.pages++;
}

void insert(int s, int n){
    if(h.pages == 0){
        page c;
        for(int i = 0; i < size; i++)
            c.a.push_back(0);
        c.a[size - 1] = 0;
        c.a[size - 9] = h.pages - 1;
        c.a[size - 13] = 0;
        c.free = size  - 16;
        h.b.push_back(c);
        h.pages++;
    }
    int i;
    for(i = 0; i < h.pages; i++){
        if(h.b[i].free >= s + 4)
            break; 
    }
    if(i == h.pages){
        newpage();
        insert(s,n);
    }
    else{
        h.b[i].a[h.b[i].a[size - 13]] = n;
        h.b[i].a[size - h.b[i].a[size - 1]*4 - 17] = h.b[i].a[size - 13];
        h.b[i].a[size - 13] = h.b[i].a[size - 13] + s;
        h.b[i].a[size - 1]++;
        h.b[i].free = h.b[i].free - s - 4; 
    }
}

void search(int n){
    int i, j, found = 0;
    for(i = 0; i < h.pages; i++){    
        for(j = 0; j < h.b[i].a[size-1]; j++){
            if(h.b[i].a[h.b[i].a[size - j*4 - 17]] == n){
                cout << i << " " << j << endl;
                found = 1;
            }
        }
    }
    if(found == 0){
        cout << "-1 -1"<<endl;
    }
}

void display(void){
    cout << h.pages << " ";
    for(int i = 0; i < h.pages; i++){
        cout << h.b[i].a[size - 1] << " "; 
    }
    cout << endl;
    int i, j;
    for(i = 0; i < h.pages; i++){    
        for(j = 0; j < h.b[i].a[size-1]; j++){
            cout << h.b[i].a[h.b[i].a[size - j*4 - 17]] << " ";
        }
       cout << endl;
    }
}

int main(){
    cin>>size;
	int choice;
	int n , s;
	while(1)
	{
		cin>>choice;
		switch(choice)
		{
			case 1:
				cin>>s>>n;
				insert(s,n);
				break;
			case 2:
				display();
				break;
			case 3:
                cin >> n;
                search(n);
                break;
            case 4:
				exit(0);
			default:
				cout<<"Invalid Input"<<endl;
		}
	}
}
