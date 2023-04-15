#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>

#include <stdlib.h>                /* malloc, free   */
TreeNode  * FreePlace (TreeNode *pos);
int     Test (int,int);

void A_Print(FILE*f, TreeNode *root, int lev, int dir);

static int lev = 1;

/*---------------------------------------------------------------
 *  Add element to tree.
 *  Attention!  Tree is not left-to-right ordered.
 *  Parameters :
 *        x   -  new element,
 *       pos  -  start position in subtree.
 *  Return value:   pointer to root of the subtree after addition
 *                  or NULL if there is no memory
 */
TreeNode  * T_Add  (int x, TreeNode *pos)
{
   if (!pos)
   {  if ( !(pos=GetPlace()) ) return NULL;
      pos->value = x; 
      pos->right = pos->left = NULL;
   }
   else
   { 
      if ( pos->right==0 ) pos->right = T_Add(x,pos->right);
      else if ( pos->left==0 ) pos->left = T_Add(x,pos->left);
      else if ( Test(x,pos->value) ) pos->right = T_Add (x,pos->right);
      else   pos->left = T_Add (x,pos->left);
   }
   return pos;
}
int     Test (int x, int y)
{
    int cnt;
    unsigned int z = x*(y+lev);
    for (cnt=0; z; z>>=1) 
    if ( z&1 ) cnt++;
    return cnt&1;
}

/*---------------------------------------------------------------
 *  Get and free place for tree node
 */
TreeNode  * GetPlace (void)  { return new TreeNode; }
TreeNode  * FreePlace (TreeNode *pos)  {  if(pos) delete pos; return NULL; }

/*---------------------------------------------------------------
 *  Print subtree (to file)
 *  Parameters :
 *       pos  -  poiner to the root of subtree,
 *        f   -  poiner to file.
 */

#include <string.h>
//#define  STR_LEN   1024    /* suppose that's enough for the buffer */
//static int   level=0;
//static char trstr[STR_LEN];

void  T_Print (FILE *f, TreeNode *pos)
{
    A_Print(f,pos,0,0);
}




Tree::Tree(FILE *f)
{
    root = NULL;
    int val;
    if ( fscanf(f,"%d",&val)!=1 ) return;
    root = T_Add(val,root);
    
    while ( fscanf(f,"%d",&val)==1 ) T_Add(val,root); 
/*    for (int i=0;i<10;i++) {
        val = random()%100 - 50;
    printf("%d\n",val);
    T_Add(val,root);
    }
*/
}



void DelNode(TreeNode *pos)
{
    if (pos) {
    DelNode(pos->left);
    DelNode(pos->right);
    delete pos;
    }
}



Tree::~Tree()
{
    if ( root ) DelNode(root);
}


///////////////// smart print

static int mesh = 9;



/* code 
static int hl = '_';  // horiz line
static int vl = '|';  // vert line
static int ua = ' ';  // upper angle
static int la = '|';  // lower angle
*/

static int hl = '-';  // horiz line
static int vl = '|';  // vert line
static int ua = '/';  // upper angle
static int la = '\\';  // lower angle


/*  DOS code
static int hl = 196;  // horiz line
static int vl = 179;  // vert line
static int ua = 218;  // upper angle
static int la = 192;  // lower angle
*/

/*  KOI8 code 
static int hl = 128;  // horiz line
static int vl = 129;  // vert line
static int ua = 130;  // upper angle
static int la = 132;  // lower angle
*/


#define PBLEN 256
static char buf0[PBLEN]={0,0,0,0,0};
static char buf[PBLEN];


void A_Print(FILE*f, TreeNode *root, int level, int dir)
{
if(buf0[0]==0) { 
//fprintf(f,"set buf0\n");
memset(buf0,' ',PBLEN); buf0[PBLEN-1]=0; }

    if (root==NULL) return;

    char sss = hl;
    sss = (dir<0)? la : ua;

    A_Print(f,root->right,level+1,1);

    int len=0;
    int left = PBLEN-mesh*level;

    strcpy(buf,buf0);
//    if (lev>0 && left>2) sprintf(buf+mesh*lev-2,"%c%c",sss,hl);
    if (level>0 && left>2) sprintf(buf+mesh*level-2," %c",sss);
    if (left>2)  len = snprintf(buf+mesh*level,left,"(%3d)",root->value);   
    if (len>=left) buf[PBLEN-2]='>';
    fprintf(f,"%s\n",buf); 
    fflush(f);

    if (level>0 && dir>0) buf0[mesh*level-2] = vl;
    if (level>0 && dir<0) buf0[mesh*level-2] = ' ';
//fprintf(f,"%d:%s:\n",buf0[0],buf0);

    A_Print(f,root->left,level+1,-1);
}


// описание вершины дерева
struct TreeNode
{
        int  value;
        TreeNode *left,*right;
        TreeNode() { value = 0; left = right = NULL; }
};

// класс бинарное дерево
class  Tree
{
    public:
        TreeNode *root;   // указатель на корень дерева

        // Конструктор пустого дерева
        Tree () { root = NULL; }

        // Деструктор
        ~Tree ();

        // Конструктор заполнения дерева числами из открытого файла.
        //     f   -  указатель на файл,
        Tree (FILE *f);

};

    
        //  Распечатка поддерева в файл.
        //     f   -  указатель на файл,
        //    pos  -  указатель на корень поддерева.

        void  T_Print (FILE *f, TreeNode *pos);

       /*  Примечание:
        *     Дерево распечатывается "лежа на левом боку", т.е.
        *  корень стоит слева, правая ветвь идет направо-вверх,
        *  левая ветвь идет направо-вниз.
        */

#endif

#include "stdio.h"

int preobr(TreeNode *pos)
{
if (pos == nullptr) return 0;
int result = 1 + preobr(pos -> left) + preobr(pos -> right);
pos->value = result;
return result;
}


int  main(void)
{
    FILE *fin, *fout;

    // открываем и проверяем файлы
    if (!(fout = fopen("tree.res","w")))
        { printf("\n Cannot open file tree.res\n"); return -1; }
    if (!(fin = fopen("tree.dat","r")))
        { printf("\n Cannot open file tree.dat\n"); return -1; }

    // заполняем дерево числами из файла - работает конструктор с параметрами:
    Tree tr(fin);
    fclose(fin);

    // распечатаем исходное дерево на экране
    printf("\nThe tree is :\n");
    T_Print(stdout,tr.root);
    T_Print(fout,tr.root);

/* сюда следует вставить вызов Вашей функции для решения поставленной задачи */
	preobr(tr.root);
//	preobr(tr.root,0);
/*     
        int k;
        printf("\nВведи k=");scanf("%d",&k);
        preobr(tr.root,k,0);
*/

    // распечатаем преобразованное дерево в файл

    fprintf(fout,"\n======================\n");
    T_Print(fout,tr.root);

    // закрываем файл результата
    fclose(fout);
    return 0;
}

