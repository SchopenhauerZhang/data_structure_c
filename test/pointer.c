#include <stdio.h>
// ###########################C Pointer#######################################
// 数组指针 *pint++\++*pint\*++p 均合法(访问下一个元素) 


// 数组指针 *pint++\++*pint\*++p 均合法(访问下一个元素) 
int check_array_pointer(){
    int *pint,*pint1,*pint2;
    int j[] =  {1,2,3,4,5};

    pint1 = pint2 = pint = j;

    printf(":*pint1:::%d::\n",*++pint1);// 2
    printf(":*pint2:::%d::\n",++*pint2);// 2
    printf(":*pint:::%d::\n",*pint++);// 2

    return 0;
}
 

// 检查const 指针之间的关系,确认几种情况指针变量的区别
int check_const_pointer(){
    const char * cc_p;
    char * const  c_cp;
    const char * const c_c_p;
    char b, p;

    return 0;
}

int main(int argc, char* argv[])
{
    
    return 0;
}



