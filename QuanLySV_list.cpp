#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name, id;
    double gpa;
};

struct SV
{
    student s;
    SV *next;
};

typedef struct SV* sv;

sv makeNode()
{
    student s;
    cout << "- Nhap vao thong tin sinh vien : " << endl;
    cout << "- Nhap vao id : ";
    cin >> s.id; 
    cout << "- Nhap ten sinh vien : ";
    cin.ignore();
    getline(cin, s.name);
    cout << "- Nhap vao gpa : ";
    cin >> s.gpa;
    sv temp = new SV();
    temp->s = s;
    temp->next = nullptr;
    return temp;
}

bool empty(sv a)
{
    return a == nullptr;
}

int size_sv(sv a)
{
    int count = 0;
    while (a != nullptr)
    {
        count++;
        a = a->next;
    }
    return count;
}

void insertFirst(sv &a)
{
    sv temp = makeNode();
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        temp->next = a;
        a = temp;
    }
}

void insertLast(sv &a)
{
    sv temp = makeNode();
    if (a == nullptr)
    {
        a = temp;
    }
    else
    {
        sv p = a;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp; 
    }
}

void insertMid(sv &a, int pos)
{
    int n = size_sv(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout << "Khong hop le !!!" << endl;
        return ;
    }
    if (pos == 1)
    {
        insertFirst(a);
        return;
    }
    else if (pos = n + 1)
    {
        insertLast(a);
        return;
    }

    sv p = a;

    for (int i = 1; i < pos - 1; i++)
    {
        p = p = p->next;
    }

    sv temp = makeNode();
    temp->next = p->next;
    p->next = temp;
}

void deleteFirst(sv &a)
{
    if (a == nullptr)
    {
        return;
    }
    a = a->next;
}

void deleteLast(sv &a)
{
    if (a == nullptr)
    {
        return;
    }
    sv truoc = nullptr, sau = a;
    while (sau->next != nullptr)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr)
    {
        a == nullptr;
    }
    else
    {
        truoc->next = nullptr;
    }
}

void deleteMid(sv &a, int pos)
{
    if (pos <= 0 || pos > size_sv(a))
    {
        return;
    }
    sv truoc = nullptr, sau = a;
    for (int i = 0; i < pos; i++)
    {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == nullptr)
    {
        sau = sau->next;
    }
    else
    {
        truoc->next = sau->next;
    }
}

void in(student s)
{
    cout<<"- ID : "<<s.id<<endl;
    cout<<"- Name : "<<s.name<<endl;
    cout<<"- GPA : "<<fixed<<setprecision(2)<<s.gpa<<endl;
}

void inds(sv a)
{
    cout<<"Danh sach sinh vien : "<<endl;
    while (a != nullptr)
    {
        in(a->s);
        a = a->next;
    }
    cout<<endl;
}

void sapxep(sv &a)
{
    for(sv p = a; p->next != nullptr; p = p->next)
    {
        sv min = p;
        for(sv q = p->next; q != nullptr; q = q->next)
        {
            if (q -> s.gpa < min->s.gpa)
            {
                min = q;
            }
        }    
        student temp = min->s;
        min->s = p->s;
        p->s = temp;
    }
}

int main()
{
    sv head = nullptr;
    int choose;
    choose = 99;

    int n;
    cout<<"Nhap vao danh sach sinh vien ban dau : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        insertLast(head);
    }
    
    while (choose != 0)
    {
        cout << endl;
        cout << "1. Chen sinh vien vao dau" << endl;
        cout << "2. Chen sinh vien vao cuoi" << endl;
        cout << "3. Chen sinh vien vao giua" << endl;
        cout << "4. Xoa sinh vien o dau" << endl;
        cout << "5. Xoa sinh vien o cuoi" << endl;
        cout << "6. Xoa sinh vien o giua" << endl;
        cout << "7. In " << endl;
        cout << "8. Sap xep cac sinh vien theo gpa tang dan" << endl;
        cout << "0. Ket thuc chuong trinh !!!";
        cout << "\nNhap vao lua chon : ";
        cin >> choose;
        if (choose == 1)
        {
            insertFirst(head);
        }
        else if (choose == 2)
        {
            insertLast(head);
        }
        else if (choose == 3)
        {              
            int pos;
            cout << "\nNhap vi tri can chen : ";
            cin >> pos;
            insertMid(head, pos);
        }
        else if (choose == 4)
        {
            deleteFirst(head); 
        }
        else if (choose == 5)
        {
            deleteLast(head);
        }
        else if (choose == 6)
        {
            int pos;
            cout << "Nhap vao vi tri muon xoa : ";
            cin >> pos;
            deleteMid(head, pos);
        }
        else if (choose == 7)
        {
            inds(head);
        }
        else if (choose == 8)
        {
            sapxep (head);
        }
    }
    cout << "Da ket thuc chuong trinh !!!";
    return 0;
}