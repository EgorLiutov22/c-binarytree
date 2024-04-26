

#include <iostream>
using namespace std;

struct tnode{
    int field;
    struct tnode *left;
    struct tnode *right;
    
    
};

struct tnode * addnode(int x, tnode *tree) {
    if (tree == NULL) { // Если дерева нет, то формируем корень
    tree =new tnode; // память под узел
    tree->field = x;   // поле данных
    tree->left =  NULL;
    tree->right = NULL; // ветви инициализируем пустотой
  }else  if (x < tree->field)   // условие добавление левого потомка
    tree->left = addnode(x,tree->left);
  else    // условие добавление правого потомка
    tree->right = addnode(x,tree->right);
  return(tree);
}
    
void treeprint(tnode *tree) {
  if (tree!=NULL) { //Пока не встретится пустой узел
    cout << tree->field; //Отображаем корень дерева
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}




int main()
{
    struct tnode* root;
    int x;
    cin>>x;
    root = NULL;
    while (x!=0){
        root = addnode(x, root);
        cin>>x;
    }
    treeprint(root);

    return 0;
}
