//************************************************************************** 
// Author: Camila Lemus
// Carnet: 18272
//**************************************************************************

#include <SPI.h>
#include <SD.h>


int opcion; //Seleccionar opcion del menu
File myFile;

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
    // Open serial communications and wait for port to open:
      Serial.begin(115200);  //Baudrate
      while (!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
      }
    
      SPI.setModule(0);
    
      Serial.print("Inicializando tarjeta SD... ");
      pinMode(PA_3, OUTPUT);
    
      if (!SD.begin(PA_3)) {
        Serial.println("Error en inicializar SD");
        return;
      }
      Serial.println("Inicialización completa.");
      myFile = SD.open("/");
      printDirectory(myFile, 0);
      Serial.println("Terminada!");
    
      menu();

}


//********************************************************************
//                         LOOP PRINCIPAL
//********************************************************************

void loop()
{

  if (Serial.available() > 0) { //Bandera para ver si el buffer está habilitado
    opcion = Serial.read(); //Se lee lo que el usuario escribió
    if (opcion == '0') {
      myFile = SD.open("/");     // Ver los archivos que estan dentro
      printDirectory(myFile, 0);
      menu();
    }
    else if (opcion == '1') { //Imprimir imagen de muñequito explotado
      Explotado();
    }
    else if (opcion == '2') { //Imprimir imagen de la iguanita
      Iguanita();
    }
   
    else if (opcion == '3') { //Imprimir imagen del pikachu o no se que es
      Piki();
    }
    else {
      Serial.println("Error, ingrese un número válido "); //Progra defensiva
      menu();
    }
  }
}


//********************************************************************
//                   FUNCION DIRECTORIO DE LA SD
//********************************************************************


void printDirectory(File dir, int numTabs) {

  dir.rewindDirectory(); //Muestra el directorio completo
  while (true) {

    File entry =  dir.openNextFile(); //Abre el siguiente archivo
    if (! entry) { //Revisando el puntero
      // no more files
      break;
    }

    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
