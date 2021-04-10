//************************************************************************** 
// Author: Camila Lemus
// Carnet: 18272
//**************************************************************************

#include <SPI.h>
#include <SD.h>

//Menu a desplegar
void menu(void) {
  Serial.println("");
  Serial.println("");
  Serial.println(" Escriba el número correspondiente a la imagen que quiere ver: ");
  Serial.println(" 0 para mostrar los archivos de la SD: ");
  Serial.println(" 1 para mostrar la imagen del muñequito explotado: ");
  Serial.println(" 2 para mostrar la imagen de la iguanita: ");
  Serial.println(" 3 para mostrar la imagen del gatito o pikachu: ");
  Serial.println("");
  Serial.println(" ");
}


void setup() {
  // put your setup code here, to run once:

}

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
      Iguana();

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
