#include <iostream>
using namespace std;


class Animal
{
public:
    virtual void cry() = 0;// ���麯��
    virtual void doHome() = 0;// ���麯��

};

class Dog :public Animal {
public:
    Dog()
    {
        this->a = 0;
    }

    Dog(int a){
        this->a = a;

    }
    virtual void cry()  {
        cout << "wangwang ~~" << endl;

    }

    void doHome() {
        cout << "watch home ---" << endl;

    }
    int a;

};

class Cat :public Animal {
public:
    virtual void cry() {
        cout << "miaomiao~~" << endl;

    }
    void doHome() {
        cout << "seize rat----" << endl;

    }

};


class Tree
{
public:
    Tree(){
        age = 10;

    }
    virtual void printT() {
        cout << "i am a tree" << endl;

    }
    int age1;
    int age; //������ڴ��ڲ�

};

int main(void)
{
    Animal *animal = new Dog(100);
    animal->cry();


    Tree* tree = reinterpret_cast<Tree*>(animal); //C++�� ������ǿ��ת��
    if (tree != NULL) {
        cout << "SUCC" << endl;
        cout << tree->age << endl;
        tree->printT(); //vptr

    }
    else {
        cout << "fail" << endl;

    }

    return 0;

}
