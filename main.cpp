// queue::push/pop
#include "Evaluador.h"
#include "NodoAVL.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

//Devuelve la cantidad de usuarios que tiene 18 anios o mas dado el nombre de un archivo XML
int contarMayoresDeEdadXML(string nombre_archivo)
{
    int n = 0;
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* pasteles = doc.FirstChildElement("Usuarios");
    for(XMLElement* pastel = pasteles->FirstChildElement("Usuario");
            pastel!=NULL;
            pastel=pastel->NextSiblingElement())
    {
        string edad =pastel->Attribute("edad");
        int intEdad;
        //intEdad = edad;
        if (intEdad >= 18){
            n++;
        }
    }
    return n;
}

//Devuelve el numero anterior del nodo raiz de un Arbol dado
int obtenerNumeroAnterior(NodoAVL* raiz)
{
    int s=0;
    if(raiz->izq->num<raiz->num){
        if (raiz->izq->der->num<raiz->num){
            if (raiz->izq->der->der->num<raiz->num){
                s = raiz->izq->der->der->num;
            }else{
            s = raiz->izq->der->num;
            }
        }else{
            s = raiz->izq->num;
        }
    }
    return s;
}

//Devuelve el numero siguiente del nodo raiz de un Arbol dado
int obtenerNumeroSiguiente(NodoAVL* raiz)
{
    int s=0;
    if(raiz->der->num<raiz->num){
        if (raiz->der->izq->num<raiz->num){
            if (raiz->der->izq->der->num<raiz->num){
                s = raiz->der->izq->der->num;
            }else{
            s = raiz->der->izq->num;
            }
        }else{
            s = raiz->der->num;
        }
    }
    return s;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
