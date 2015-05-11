Scribbler2-Cpp
===============

Código C++ para controlar a través de bluetooth el robot Scribbler2 (S2)
con la tarjeta Fluke2 (F2), ver detalles en www.betterbots.com / www.parallax.com.

* Implementa todas las funciones del S2 (Firmware IPRE)
* Implementa la mayoría de las funciones de la tarjeta F2

El problema mayor lo genera la Fluke2 dado que al interactuar con el Scribbler2 maneja un timeout
de 3000ms. Si el Scribbler2 tarda más de ese tiempo algunos comandos quedarán
fuera de sincronismo.

La documentacón se encuentra en JavaDoc en el proyecto Scribbler2-Java


##Ambiente de desarrollo
Todo el desarrollo se realiza utilizando CodeLite

***
##Historia
* May 10, 2015: Implementa el resto de los Módulos (tomados del proyecto Scribbler2-Java)
* May 9, 2015: Implementa Módulos de LEDs, Microfono, Motores y Parlantes
