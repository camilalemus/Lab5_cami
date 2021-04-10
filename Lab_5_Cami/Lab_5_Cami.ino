//************************************************************************** 
// Author: Camila Lemus
// Carnet: 18272
//**************************************************************************

#include <SPI.h>
#include <SD.h>


//********************************************************************
//                         MENU
//********************************************************************

void menu(void) {
  Serial.println("");
  Serial.println("");
  Serial.println(" Escriba el número correspondiente a la imagen que quiere ver: ");
  Serial.println(" 0 para mostrar los archivos de la SD: ");
  Serial.println(" 1 para mostrar la imagen del muñequito explotado: ");
  Serial.println(" 2 para mostrar la imagen de la iguanita: ");
  Serial.println(" 3 para mostrar la imagen del gatito tipo pikachu: ");
  Serial.println("");
  Serial.println(" ");
}


//********************************************************************
//                         IMPRIMIR IMAGENES
//********************************************************************

void Explotado(void) { //Imprimir al muñequito explotado
  myFile = SD.open("Explotado.txt");
  if (myFile) {
    Serial.println("Explotado.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening Explotado.txt");
  }
  menu();
}


void Iguanita(void) { //Imprimir a la iguanita
  myFile = SD.open("Iguanita.txt");
  if (myFile) {
    Serial.println("Iguanita.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening Iguanita.txt");
  }
  menu();
}


void Piki(void) { //Imprimir al gatito tipo pikachu
  myFile = SD.open("Piki.txt");
  if (myFile) {
    Serial.println("Piki.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening Piki.txt");
  }
  menu();
}

//********************************************************************
//                        SETUP
//********************************************************************
void setup() {
  // put your setup code here, to run once:

}


//********************************************************************
//                         LOOP PRINCIPAL
//********************************************************************

void loop()
{

  if (Serial.available() > 0) { //Bandera para ver si el buffer está habilitado
    seleccion = Serial.read(); //Se lee lo que el usuario escribió
    if (seleccion == '0') {
      myFile = SD.open("/");     // Ver los archivos que estan dentro
      printDirectory(myFile, 0);
      menu();
    }
    else if (seleccion == '1') { //Imprimir imagen de muñequito explotado
      Explotado();
    }
    else if (seleccion == '2') { //Imprimir imagen de la iguanita
      Iguanita();
    }
   
    else if (seleccion == '3') { //Imprimir imagen del pikachu o no se que es
      Piki();
    }
    else {
      Serial.println("Error, ingrese un número válido "); //Progra defensiva
      menu();
    }
  }
}
