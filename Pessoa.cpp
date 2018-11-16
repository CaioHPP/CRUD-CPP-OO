#include "GUI.h"

int main(){
 GUI gui;
 while(1){

  gui.menu();
  switch(gui.obtemEscolha()){
   case 'f':
   {
    gui.cadF();
    break;    
  }
  case 'j':
  {
    gui.cadJ();
    break;
  }
  case 'a':
  {
    gui.cadA();
    break;
  }
  case 'v':
  {
    gui.showBuscas();
    break;
  }

  case'x':
  {
   return 0;
 }

}
}

}







