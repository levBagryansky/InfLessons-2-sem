#include <stdio.h>

void func1()
{
    printf("It's over, Anakin! I have the high ground!");
}

void func2()
{
    printf("You underestimate my power!");
}

void hacker_func()
{

}

int main() {
  //  void* p_func1 = &func1;
  //  void* p_func2 = &func2;
    //printf("%li", p_func2 - p_func1);
  //  printf("grrrrrrrr");
 
	func1();
	func2();

    return 0;
}
