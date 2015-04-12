#include "LLStack.h"

int main(){
LLStack l;
l.Push(55);
l.Push(100);

cout << l.Peek() << endl;
cout << l.Pop() << endl;
cout << l.Pop() << endl;
}