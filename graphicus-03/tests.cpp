#include "tests.h"

void Tests::tests_unitaires_formes() {}
void Tests::tests_unitaires_couche() {}
void Tests::tests_unitaires_vecteur() {}
void Tests::tests_unitaires_canevas() {}
void Tests::tests_unitaires() {
  // Fait tous les tests unitaires
  tests_unitaires_formes();
  tests_unitaires_couche();
  tests_unitaires_vecteur();
  tests_unitaires_canevas();
}

void Tests::tests_application()
{
  // Fait tous les tests applicatifs
  tests_application_cas_01();
  tests_application_cas_02();
  tests_application_cas_03();
}

void Tests::tests_application_cas_01()
{
  std::cout << "TESTS APPLICATION (CAS 01)" << std::endl;
  Canevas *c = new Canevas();

  std::cout << "\n\nETAPE 1 & 2\n";
  c->display(cout);
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 3 @ 5\n";
  //~~~~~~~~~~~ Step 3 ~~~~~~~~~~~//
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();

  //~~~~~~~~~~~ Step 4 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~~ Step 5 ~~~~~~~~~~~//
  std::cout << "\nL'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 6 @ 9\n";
  //~~~~~~~~~~~ Step 6 ~~~~~~~~~~~//
  c->activateLayer(2);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(1,2,8));
  c->addShape(new Square(2,3,8));
  c->addShape(new Rectangle(3,3,4,9));
  c->addShape(new Circle(0,2,6));
  c->addShape(new Square(1,3,7));
  c->addShape(new Rectangle(2,4,5,10));

  //~~~~~~~~~~~ Step 7 ~~~~~~~~~~~//
  c->activateLayer(1);
  c->addShape(new Rectangle(0,0,12,3));

  //~~~~~~~~~~~ Step 8 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~~ Step 9 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 10 @ 13\n";
  //~~~~~~~~~~ Step 10 ~~~~~~~~~~~//
  c->activateLayer(0);
  c->addShape(new Rectangle(0,0,1,1));
  c->addShape(new Square(0,0,1));
  c->addShape(new Circle(0,0,1));

  //~~~~~~~~~~ Step 11 ~~~~~~~~~~~//
  c->activateLayer(2);
  c->translation(2,1);

  //~~~~~~~~~~ Step 12 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~ Step 13 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;

  std::cout << "\n\nETAPE 14 @ 20\n";
  //~~~~~~~~~~ Step 14 ~~~~~~~~~~~//
  c->activateLayer(0);
  c->removeShape(2);

  //~~~~~~~~~~ Step 15 ~~~~~~~~~~~//
  c->resetLayer(1);

  //~~~~~~~~~~ Step 16 ~~~~~~~~~~~//
  c->activateLayer(2);

  //~~~~~~~~~~ Step 17 ~~~~~~~~~~~//
  c->removeLayerCan(2);

  //~~~~~~~~~~ Step 18 ~~~~~~~~~~~//
  c->activateLayer(4);

  //~~~~~~~~~~ Step 19 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~ Step 20 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 21 @ 23\n";
  //~~~~~~~~~~ Step 21 ~~~~~~~~~~~//
  c->reset();

  //~~~~~~~~~~ Step 22 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~ Step 23 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 24 @ 27\n";
  //~~~~~~~~~~ Step 24 ~~~~~~~~~~~//
  c->activateLayer(3);
  c->addShape(new Square(10,10,10));
  c->addShape(NULL);

  //~~~~~~~~~~ Step 25 ~~~~~~~~~~~//
  c->activateLayer(6);

  //~~~~~~~~~~ Step 26 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~ Step 27 ~~~~~~~~~~~//
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  delete c;
}






void Tests::tests_application_cas_02() {
  std::cout << "TESTS APPLICATION (CAS 02)" << std::endl;
  Canevas *c = new Canevas();

  std::cout << "\n\nETAPE 1 & 2\n";
  c->display(cout);
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 3 @ 5\n";
  //~~~~~~~~~~~ Step 3 ~~~~~~~~~~~//
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();
  c->addLayerCan();

  //~~~~~~~~~~~ Step 4 ~~~~~~~~~~~//
  c->display(cout);

  //~~~~~~~~~~~ Step 5 ~~~~~~~~~~~//
  std::cout << "\nL'aire du canevas est: "
    << c->area() << std::endl;


  std::cout << "\n\nETAPE 6 @ 9\n";
  //~~~~~~~~~~~ Step 6 ~~~~~~~~~~~//
  c->activateLayer(2);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));

  c->activateLayer(1);
  c->addShape(new Rectangle(0,0,12,3));

  //~~~~~~~~~~~ Step 8 ~~~~~~~~~~~//
  c->display(cout);

  c->activateLayer(3);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));

  c->activateLayer(4);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));

  c->activateLayer(5);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));

  c->activateLayer(6);
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));
  c->addShape(new Circle(0,1,5));
  c->addShape(new Square(1,2,6));
  c->addShape(new Rectangle(2,3,4,9));



  c->display(cout);
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;

  c->removeLayerCan(6);

  c->display(cout);
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;

  c->reset();
  c->display(cout);
  std::cout << "L'aire du canevas est: "
    << c->area() << std::endl;

  delete c;
}



void Tests::tests_application_cas_03() {
  Canevas c = *new Canevas();

  /*cout << c;*/

  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();
  c.addLayerCan();


  c.activateLayer(2);
  c.nextLayer();
  c.nextLayer();


  c.activateLayer(2);
  c.prevLayer();
  c.prevLayer();
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.activateLayer(6);
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));
  c.addShape(new Circle(0,1,5));
  c.addShape(new Square(1,2,6));
  c.addShape(new Rectangle(2,3,4,9));

  cout << c << std::endl;

  // Trying with a pointer cause I desprate
  Canevas *ca = new Canevas();

  ca->reset();
  ca->addLayerCan();
  ca->activateLayer(0);
  ca->addShape(new Rectangle(2,3,4,9));

  cout << &ca << std::endl;
  delete ca;
}
